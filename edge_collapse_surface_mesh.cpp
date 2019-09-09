#include <iostream>
#include <fstream>
#include <CGAL/Simple_cartesian.h>
#include <CGAL/Surface_mesh.h>
#include <CGAL/Surface_mesh_simplification/edge_collapse.h>
#include <CGAL/Surface_mesh_simplification/Policies/Edge_collapse/Count_ratio_stop_predicate.h>
typedef CGAL::Simple_cartesian<double> Kernel;
typedef Kernel::Point_3 Point_3;
typedef CGAL::Surface_mesh<Point_3> Surface_mesh;
namespace SMS = CGAL::Surface_mesh_simplification;
int main(int argc, char** argv)
{
	if (argc != 4) {
		std::cout << "Invalid count of enviorment args" << std::endl;
		return EXIT_FAILURE;
	}

	std::cout << "Input mesh: " << argv[1] << std::endl;
	std::cout << "Output mesh: " << argv[2] << std::endl;
	std::cout << "Ratio: " << argv[3] << std::endl;

	Surface_mesh surface_mesh;

	std::ifstream is(argv[1]);
	is >> surface_mesh;
	if (!CGAL::is_triangle_mesh(surface_mesh)) {
		std::cerr << "Input geometry is not triangulated." << std::endl;
		return EXIT_FAILURE;
	}
	// In this example, the simplification stops when the number of undirected edges
	// drops below 10% of the initial count
	SMS::Count_ratio_stop_predicate<Surface_mesh> stop(std::stod(argv[3]));

	int r = SMS::edge_collapse(surface_mesh, stop);
	std::cout << "\nFinished...\n" << r << " edges removed.\n"
		<< surface_mesh.number_of_edges() << " final edges.\n";

	std::ofstream os(argc > 2 ? argv[2] : "out.off");
	os.precision(17);
	os << surface_mesh;

	std::cout << "Exit success";
	return EXIT_SUCCESS;
}