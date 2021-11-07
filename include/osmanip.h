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
   template < typename any_type > inline void setMax( any_type max );
   template < typename any_type > inline void setMin( any_type min );
   template < typename any_type > inline void setStyle( any_type style );

   //Getters declaration:
   template < typename any_type > inline any_type getMax() const;
   template < typename any_type > inline any_type getMin() const;
   template < typename any_type > inline any_type getStyle() const;

   //Other methods declaration:
   template < typename any_type > void update( any_type iterating_var );
   void reset();
  
  private:

  //Attributes declaration and initializations:
   int max_, min_, iterating_var_;
   std::string style_, conct_;
   static const std::string error_;
 };
 
//ProgressBar setters definition:
template < typename any_type >
inline void ProgressBar::setMax( any_type max ) { max_ = any_type( max ); }

template < typename any_type >
inline void ProgressBar::setMin( any_type min ) { min_ = any_type( min ); }

template < typename any_type >
inline void ProgressBar::setStyle( any_type style )
 {
  style_ = any_type( style );
  if( style_ != "%" )
   {
    conct_.append( error_ );
    conct_.append( " \"" );
    conct_.append( style_ );
    conct_.append( "\" is not supported!\n" );
    throw std::runtime_error( conct_ );
   }
 }

//ProgressBar setters definition:
template < typename any_type >
inline any_type ProgressBar::getMax() const { return max_; }

template < typename any_type >
inline any_type ProgressBar::getMin() const { return min_; }

template < typename any_type >
inline any_type ProgressBar::getStyle() const { return style_; }
 
//ProgressBar other methods definition:
template < typename any_type >
void ProgressBar::update( any_type iterating_var )
 {
  iterating_var_ = 100 * ( iterating_var - min_ ) / ( max_ - min_ -1 );
  if( style_ == "%" )
   {
    conct_.append( "\u001b[100D" );
    conct_.append( std::to_string( iterating_var_ ++ ) );
    conct_.append( "%" );
    std::cout << conct_ << std::flush;
   }
 }
     
#endif
