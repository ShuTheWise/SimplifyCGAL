CLI usage:
SimplifyCGAL.exe "<input model path>.off" "output model path>.off" <ratio = (0.0 - 1.0)>

Example: SimplifyCGAL.exe inputModel.off outputModel.off 0.5  

More information about the simplification method can be found here https://doc.cgal.org/latest/Surface_mesh_simplification/index.html

For development purposes it requires external dependencies: 
 - compiled CGAL library v.4-14 in directory C:\dev\CGAL-4.14  https://www.cgal.org/
- compiled boost library v.1-70 in directory C:\local\boost_1_70_0 https://www.boost.org/
