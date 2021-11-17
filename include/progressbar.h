#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <string>
#include <chrono>

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
     void setMax( long long int max ),
          setMin( long long int min ),
          setStyle( std::string style ),
          setMessage( std::string message ),
          setBrackets( std::string brackets_open, std::string brackets_close ),
          setBegin(),
          setEnd(),

     //Resetters declaration:
          reset(),
          resetMax(),
          resetMin(),
          resetStyle(),
          resetMessage(),
          resetTime(),
          resetBrackets();

     //Getters declaration:
     long long int getMax() const,
                   getMin() const,
                   getTime() const,
                   getIteratingVar() const;
     std::string getStyle() const,
                 getMessage() const,
                 getBrackets_open() const,
                 getBrackets_close() const;

     //Other methods declaration:
     void update( long long int iterating_var ),
          print() const;
  
    private:

     //Attributes declaration and initializations:
     long long int max_, min_, iterating_var_, time_count_, width_;
     std::string style_, conct_, message_, brackets_open_, brackets_close_;
     static const std::string error_;
     std::chrono::steady_clock::time_point begin, end;
   };
  
  //Operator * redefinition declaration to multiply strings by an integer:
  std::string operator * ( const std::string & generic_string,  unsigned long long int integer );
 }
      
#endif