#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <string>
#include <chrono>
#include <set>

namespace osm
 {
  //ProgressBar class declaration:
  class ProgressBar
   {
    public:

     //Constructors and destructors declaration:
     ProgressBar();
     ~ProgressBar();

     //Setters declaration:
     void setMax( long long int max );
     void setMin( long long int min );
     void setStyle( std::string style );
     void setMessage( std::string message );
     void setBrackets( std::string brackets_open, std::string brackets_close );
     void setBegin();
     void setEnd();

     //Resetters declaration:
     void reset();
     void resetMax();
     void resetMin();
     void resetStyle();
     void resetMessage();
     void resetTime();
     void resetBrackets();

     //Getters declaration:
     long long int getMax() const;
     long long int getMin() const;
     long long int getTime() const;
     long long int getIteratingVar() const;
     std::string getStyle() const;
     std::string getMessage() const;
     std::string getBrackets_open() const;
     std::string getBrackets_close() const;

     //Other methods declaration:
     void update( long long int iterating_var );
     void print() const;
  
    private:

     //Attributes declaration and initializations:
     long long int max_, min_, iterating_var_, time_count_, width_;
     std::string style_, conct_, message_, brackets_open_, brackets_close_;
     static const std::string error_;
     std::chrono::steady_clock::time_point begin, end;
     static std::set <std::string> set_p_, set_l_;
   };
  
  //Operator * redefinition declaration to multiply strings by an integer:
  std::string operator * ( const std::string & generic_string,  unsigned long long int integer );
 }
      
#endif