#ifndef OSMANIP_H
#define OSMANIP_H

#include <string>
#include <map>
#include <chrono>

namespace osm
 {
  //Maps declaration:
  extern std::map <std::string, std::string> col, sty, rst, crs;

  //Functions declaration:
  std::string feat ( std::map <std::string, std::string> & generic_map, std::string feat_string ),
              reset ( std::string reset_string );

  //Test functions declaration:
  void feat_test( std::map <std::string, std::string> & generic_map_test ),
       reset_test();
     
  //ProgressBar class declaration:
  class ProgressBar
   {
    public:

     //Constructors and destructors declaration:
     ProgressBar();
     ~ProgressBar();

     //Setters declaration:
     void setMax( long long int max ),
          setMin( long long int min ),
          setStyle( std::string style ),
          setMessage( std::string message ),
          setBegin(),
          setEnd(),

     //Resetters declaration:
          reset(),
          resetMax(),
          resetMin(),
          resetStyle(),
          resetMessage(),
          resetTime();

     //Getters declaration:
     long long int getMax() const,
                   getMin() const,
                   getTime() const,
                   getIteratingVar() const;
     std::string getStyle() const,
                 getMessage() const;

     //Other methods declaration:
     void update( long long int iterating_var );
  
    private:

     //Attributes declaration and initializations:
     long long int max_, min_, iterating_var_, time_count_;
     std::string style_, conct_, message_;
     static const std::string error_;
     std::chrono::steady_clock::time_point begin, end;
   };
 }
      
#endif