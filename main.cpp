#include <iostream>
#include <ultimaille/volume.h>
#include <ultimaille/io/vtk.h>
#include <ultimaille/io/geogram.h>

int main(int argc, char *argv[]) {

    if(argc != 2) {
        std::cerr << "Wrong usage, it should be:" << std::endl;
        std::cerr << "\t vtk2geogram <input.vtk>" << std::endl;
        return 1;
    }

    std::string input_filename = argv[1];

    UM::PointSet ps;
    UM::PointSetAttributes ps_attr;
    ps_attr = UM::read_vtk(input_filename,ps);
    UM::write_geogram(input_filename + ".point_set.geogram",ps,ps_attr);

    UM::PolyLine pl;
    UM::PolyLineAttributes pl_attr;
    pl_attr = UM::read_vtk(input_filename,pl);
    UM::write_geogram(input_filename + ".polyline.geogram",pl,pl_attr);

    UM::Triangles t;
    UM::SurfaceAttributes s_attr;
    s_attr = UM::read_vtk(input_filename,t);
    UM::write_geogram(input_filename + ".triangles.geogram",t,s_attr);

    UM::Tetrahedra m;
    UM::VolumeAttributes attr;
    attr = UM::read_vtk(input_filename,m);
    UM::write_geogram(input_filename + ".tetrahedra.geogram",m,attr);

    return 0;
}