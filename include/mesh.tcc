#include "mesh.h"
#include <numeric>
#include <sstream>
#include "point.tcc"
#include "input.tcc"


//! \brief Open and read gmsh file
//! \details read vertex id and coordinates
template <unsigned Tdim>
void Mesh <Tdim>::get_vertices() {


    //! Tdim is constant 3, because max dimensions 3
    std::unique_ptr<Input<3>> inputvertices(new Input<3>());
    inputvertices -> read_vertices();
    vertex_ = inputvertices ->return_vertices();
}

//! \brief Open and read gmsh file
//! \details read element id and vertices
//! \tparam Tdim = element type
template <unsigned Tdim>
void Mesh <Tdim>::get_elements() {

    std::cout<<vertex_.size();
    std::unique_ptr<Input<Tdim>> inputelements(new Input<Tdim>());
    inputelements -> read_elements();
    element_ = inputelements -> return_elements();

}

//! \brief Print Vertices Vector to text file
//! \details to Check data entry correct
template <unsigned Tdim>
void Mesh<Tdim>::output_vertices() {

    const std::string outputfilename = "vertexcheck.txt";
    std::fstream inputcheck;
    inputcheck.open(outputfilename, std::ios::out);


    if (inputcheck.is_open()) {

        //! Iterate through vector and print
        for (const auto &point : vertex_) {
            inputcheck << point->id() << '\t';
            inputcheck << point->coordinates().at(0) << " " << point->coordinates().at(1) << " "
                       << point->coordinates().at(2)<<  '\n';

        }
        inputcheck << "Am I the same as input.txt?";
        inputcheck.close();

    }
}

//! \brief Print Element Vector to text file
//! \details to Check data entry correct
template <unsigned Tdim>
void Mesh<Tdim>::output_elements(){

    const std::string outputfilename = "elementcheck.txt";
    std::fstream elementcheck;
    elementcheck.open(outputfilename, std::ios::out);


    if (elementcheck.is_open()) {

        //! Iterate through vector and print
        for (const auto &point : element_) {
            elementcheck << point->id() << '\t';
            elementcheck<< point->coordinates().at(0) << " " << point->coordinates().at(1) << " "
                       << point->coordinates().at(2) << " " << point->coordinates().at(3) << '\n';

        }
        elementcheck << "Am I the same as input.txt?";
        elementcheck.close();

    }
}