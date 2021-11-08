#ifndef OSMANIP_H
#define OSMANIP_H

#include <string>
#include <map>

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
   void setMax( int max );
   void setMin( int min );
   void setStyle( std::string style );
   void setMessage( std::string message );

   //Resetters declaration:
   void reset();
   void resetMax();
   void resetMin();
   void resetStyle();
   void resetMessage();

   //Getters declaration:
   int getMax() const;
   int getMin() const;
   std::string getStyle() const;

   //Other methods declaration:
   void update( int iterating_var );
  
  private:

   //Attributes declaration and initializations:
   int max_, min_, iterating_var_;
   std::string style_, conct_, message_;
   static const std::string error_;
 };
      
#endif
