"""
Metropolia scene exporter

Version 0.1:
    - First working version.
    - Export obj per mesh.
    - Copy textures from the materials.
"""

import bpy
import bpy_extras.io_utils
import os.path
import shutil
import copy
import struct
import mathutils

class ObjectData(object):
    def __init__(self):
        self.m_meshFile = None
        self.m_textureFile = None
        self.m_position = None
        self.m_rotation = None

class MetropoliaExporter(object):
    def __init__(self, strFileName):
        print ("--------------------")
        self.m_file = None
        self.m_dir = "{0}\\scene".format(os.path.dirname(bpy.data.filepath))
        try:
            os.makedirs(self.m_dir)
        except:
            print("Folder already exsist.")
        self.m_strFileName = "{0}\\{1}".format(self.m_dir, strFileName)
    
    def ExportObj(self, oData):
        o = bpy.context.selected_objects[0]
        fn = "{0}\\{1}.obj".format(self.m_dir, o.name.lower())
        bpy.ops.export_scene.obj(filepath=fn, check_existing=True, axis_forward='-Z', axis_up='Y', filter_glob="*.obj;*.mtl", use_selection=True, use_animation=False, use_mesh_modifiers=True, use_edges=True, use_smooth_groups=False, use_smooth_groups_bitflags=False, use_normals=True, use_uvs=True, use_materials=False, use_triangles=True, use_nurbs=False, use_vertex_groups=False, use_blen_objects=False, group_by_object=False, group_by_material=False, keep_vertex_order=False, global_scale=1, path_mode='AUTO')
        oData.m_meshFile = "{0}.obj".format(o.name.lower())
        gm = bpy_extras.io_utils.axis_conversion(to_forward="-Z", to_up="Y").to_4x4()
        wm = o.matrix_world
        m = mathutils.Matrix()
        m = gm * wm * gm.transposed()  
        t = m.to_translation()
        r = m.to_euler()
        oData.m_position = t
        oData.m_rotation = r
        return oData
    
    def CopyTextures(self, oData):
        o = bpy.context.selected_objects[0]
        matslots = o.material_slots
        for s in matslots:
            nt = s.material.node_tree
            for n in nt.nodes:
                if n.type == 'TEX_IMAGE':
                    imgNode = n.image
                    fp = imgNode.filepath.split("//")[1]
                    sf = os.path.dirname(bpy.data.filepath)
                    shutil.copyfile(
                        "{0}\\{1}".format(sf, fp),
                        "{0}\\{1}".format(self.m_dir, fp))
                    print ("{0}\\{1}".format(self.m_dir, fp))
                    oData.m_textureFile = fp

    def Export(self):
        objects = []
        d = os.path.dirname(bpy.data.filepath)
        for o in bpy.data.objects:
            if (o.type == "MESH"):
                oData = ObjectData()
                bpy.ops.object.select_all(action='DESELECT')
                o.select_set(True)
                bpy.context.view_layer.objects.active = o
                self.ExportObj(oData)
                self.CopyTextures(oData)
                objects.append(copy.deepcopy(oData))
                
        self.m_file = open(self.m_strFileName, "wb")
        self.m_file.write(len(objects).to_bytes(4, "little"))
        print("--------------")
        for o in objects:
            l = len(o.m_meshFile)
            self.m_file.write(l.to_bytes(4, "little"))
            self.m_file.write(o.m_meshFile.encode("utf-8"))
            
            l = len(o.m_textureFile)
            self.m_file.write(l.to_bytes(4, "little"))
            self.m_file.write(o.m_textureFile.encode("utf-8"))
            
            v = bytearray(struct.pack("f", o.m_position.x)) 
            self.m_file.write(v)
            v = bytearray(struct.pack("f", o.m_position.y)) 
            self.m_file.write(v)
            v = bytearray(struct.pack("f", o.m_position.z)) 
            self.m_file.write(v)
            
            v = bytearray(struct.pack("f", o.m_rotation.x)) 
            self.m_file.write(v)
            v = bytearray(struct.pack("f", o.m_rotation.y)) 
            self.m_file.write(v)
            v = bytearray(struct.pack("f", o.m_rotation.z)) 
            self.m_file.write(v)
                        
            print(o.m_meshFile)
            print(o.m_textureFile)
            print(o.m_position)
            print(o.m_rotation)
            print("---")
        
        self.m_file.flush()
        self.m_file.close()
                
exp = MetropoliaExporter("scene.scn")
exp.Export()