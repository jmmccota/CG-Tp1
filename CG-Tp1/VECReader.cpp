// VECReader.cpp : Defines the entry point for the console application.
//
 
#include "stdafx.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
 
struct VecFormat {
    char pts;
    float color[3];
    int coord[3];
};
 
int main()
{
    std::string line;
 
    std::ifstream vecfile("c:\\temp\\input.vec");
 
    if (vecfile) {
          while (getline(vecfile, line)) {
              std::string  p;
              float r, g, b;
 
              int x, y, rad;
 
              std::stringstream str(line);
              // discard empty strings
              if (line.length() == 0) continue;
 
              // read header 
              str >> p >> r >> g>> b;
              // Hmmmmm... if p=='C' then it is a circle... otherwise,
              // discard then (it's not suitable to be number of points... trust me!
              if ((p == "C")&& getline(vecfile,line)) {
                 
                  std::stringstream cstr(line);
                  cstr >> x >> y >> rad;
 
                  std::cout << "plotting a circle \n";
                  std::cout << "\twith center @(" << x << "," << y << ") with radius " << rad <<"\n";
                  std::cout << "\twith color rgb(" << r << "," << g << "," << b << ")\n";
              } else { // regular polygon
                  // read while line is valid. Stops if a space if found
                  std::cout << "plotting a polygon\n";
                  std::cout << "\twith color rgb(" << r << "," << g << "," << b << ")\n";
                  while (getline(vecfile, line)&&(line.length()>0)) {
                      std::stringstream pstr(line);
                     
                      pstr >> x >> y;
 
                      std::cout << "\txy(" << (float) x << "," << (float) y << ")\n";
                  }
              }
              std::cout << p;
          }
    }
    else
    {
          std::cout << "Arquivo nao pode ser aberto...";
    }
 
 return 0;
}