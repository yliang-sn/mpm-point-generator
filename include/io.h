#ifndef MPM_POINT_GEN_IO_H_
#define MPM_POINT_GEN_IO_H_

#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <utility>
#include <vector>

#include <boost/filesystem.hpp>
#include <eigen3/Eigen/Dense>

#include "tclap/CmdLine.h"
//! Alias for JSON
#include "json.hpp"
using Json = nlohmann::json;

#include "material_points.h"
#include "mesh.h"

//! \brief Input/Output handler
class IO {
 public:
  //! Constructor with argc and argv
  IO(int argc, char** argv);

  //! Return the number of points per coordinate
  unsigned ngauss_points() const;

  //! Return the dimension of the problem: 2 or 3
  unsigned dimension() const;

  //! Return json object for material properties
  std::vector<Json> material_properties() const;

  //! Return mesh file name
  std::string mesh_file_name() const;

  //! Create output file names
  boost::filesystem::path output_file(const std::string& attribute,
                                      const std::string& file_extension);

 private:
  //! Input directory
  std::string working_dir_;

  //! Input json object
  Json json_;
};

#endif  // MPM_POINT_GEN_IO_H_
