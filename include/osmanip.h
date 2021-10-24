#ifndef OSMANIP_H
#define OSMANIP_H

#include <string>
#include <map>

//Maps declaration:
extern std::map <std::string, std::string> col, sty;

//Functions declaration:
std::string feat ( std::map <std::string, std::string> & generic_map, std::string feat );

//Test functions declaration:
void feat_test( std::map <std::string, std::string> & generic_map_test );
       
#endif
