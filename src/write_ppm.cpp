#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
  ////////////////////////////////////////////////////////////////////////////
  
  std::ofstream fi;
  fi.open(filename);
  if(!fi.is_open()){
    return false;
  }
  if (num_channels == 3){
    

    fi << "P3 \n"
      << "# feep.ppm \n"
      << width
      << " "
      << height
      << "\n"
      << "255"
      <<"\n";
    for (int i = 0; i < width * height * 3; i++){
      fi << (int)data[i] <<' ';
   
    }
  }
  else{fi << "P2 \n"
      << "# feep.ppm \n"
      << width
      << " "
      << height
      << "\n"
      << "255"
      <<"\n";
    for (int i = 0; i < width * height; i++){
      fi << (int)data[i] <<' ';
    }

  }

  fi.close();
  return true;
  ////////////////////////////////////////////////////////////////////////////
}
