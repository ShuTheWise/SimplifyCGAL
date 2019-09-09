CLI usage:
SimplifyCGAL.exe <"input model path"> <"output model path"> <"ratio" - a decimal number from 0.0 to 1.0>

Example: SimplifyCGAL.exe inputModel.off outputModel.off 0.5  

Supported file format is Object File Format (\*.off). While it is not a very common mesh format you can certainly convert any mesh to a Object File Format. Among others you can use MeshLab http://www.meshlab.net/.

More information about the simplification method can be found here https://doc.cgal.org/latest/Surface_mesh_simplification/index.html

If you just want to test out the application please check out the release binaries.

For development purposes it is a little tricky and requires external dependencies:
- compiled CGAL library v.4-14 in directory C:\dev\CGAL-4.14  https://www.cgal.org/
- compiled boost library v.1-70 in directory C:\local\boost_1_70_0 https://www.boost.org/
The provided directories for CGAL and Boost libraries can be changed but you will have to resolve linking issues.
