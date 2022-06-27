//====================================================
//     Preprocessor settings
//====================================================
#ifndef MULTIPROGRESSBAR_HPP
#define MULTIPROGRESSBAR_HPP

//====================================================
//     Headers
//====================================================

//My headers
#include "../manipulators/cursor.hpp"

//STD headers
#include <iostream>
#include <type_traits>
#include <tuple>
#include <functional>
#include <mutex>
#include <utility>

namespace osm
 {
  //====================================================
  //     indices
  //====================================================
  /**
   * @brief Type to generate indices for parameter packs.
   * 
   * @tparam Is The indices to generate.
   */
  template <size_t... Is>
  struct indices {};
  
  //====================================================
  //     gen_indices
  //====================================================
  /**
   * @brief Type to generate indices for parameter packs.
   * 
   * @tparam I The index to generate.
   * @tparam Is The indices to generate.
   */
  template <size_t N, size_t... Is>
  struct gen_indices: gen_indices <N - 1, N - 1, Is...> {};
  
  //====================================================
  //     gen_indices
  //====================================================
  /**
   * @brief Type to generate indices for parameter packs.
   * 
   * @tparam I The index to generate.
   * @tparam Is The indices to generate.
   */
  template <size_t... Is>
  struct gen_indices <0, Is...>: indices<Is...> {};
  
  //====================================================
  //     make_MultiProgressBar
  //====================================================
  /**
   * @brief Template class used to create multi progress bars.
   * 
   * @tparam Indicators The parameter pack of the various progress bar types.
   */
  template <class... Indicators>
  class make_MultiProgressBar 
   {
    public:
  
     //====================================================
     //     Constructors
     //====================================================
     /**
      * @brief Construct a new make MultiProgressBar object.
      * 
      * @tparam Inds The parameter pack of the various progress bar types indicators.
      * @param bars The progress bars.
      */
     template <class... Inds>
     make_MultiProgressBar( Inds&&... bars ): bars_{ std::forward <Inds> ( bars )... }, last_updated_index( 0 ) {}
  
     //====================================================
     //     size
     //====================================================
     /**
      * @brief Return the number of the indicators.
      * 
      * @return size_t The number of the indicators.
      */
     static size_t size() { return sizeof...( Indicators ); }

     //====================================================
     //     for_one
     //====================================================
     /**
      * @brief Method used to update the progress bar for one progress bar only.
      * 
      * @tparam Func 
      * @tparam Args 
      * @param idx 
      * @param func 
      * @param args 
      */
     template <class Func, class... Args>
     void for_one( size_t idx, Func&& func, Args&&... args )
      {
       call_one( idx, gen_indices <sizeof...( Indicators )> (), std::forward <Func> ( func ), std::forward <Args> ( args )... );
      }
  
     //====================================================
     //     for_each
     //====================================================
     /**
      * @brief Method used to update progress bars simultaneously.
      * 
      * @tparam Func 
      * @tparam Args 
      * @param func 
      * @param args 
      */
     template <class Func, class... Args>
     void for_each( Func&& func, Args&&... args ) 
      {
       call_all( gen_indices <sizeof...( Indicators )> (), std::forward <Func> ( func ), std::forward <Args> ( args )... );
      }
  
    private:
  
     //====================================================
     //     call_one
     //====================================================
     /**
      * @brief Method used to call only one progress bar for update.
      * 
      * @tparam Ids 
      * @tparam Func 
      * @tparam Args 
      * @param idx 
      * @param func 
      * @param args 
      */
     template <size_t... Ids, class Func, class... Args>
     void call_one( size_t idx, indices <Ids...>, Func func, Args&&... args )
      {
       std::lock_guard <std::mutex> lock{ mutex_ };
       int idx_delta = idx - last_updated_index;
       std::string direction;

       if( idx_delta < 0 )
        {
         direction = "up";
         idx_delta = -idx_delta;
        }
       else
        {
         direction = "down";
        }
       for( int i = 0; i < idx_delta; i++ )
        {                                                                                                               
         std::cout << feat( crs, direction, 1 );
        }
       last_updated_index = idx;
       [](...) {} 
       
        (
         (idx == Ids &&
          ( ( void ) std::forward <Func> ( func )( std::get <Ids> ( bars_ ), 
              std::forward <Args> ( args )... ), false ) )...
        );   
      }

     //====================================================
     //     call_all
     //====================================================
     /**
      * @brief Method used to call all progress bars for update.
      * 
      * @tparam Ids 
      * @tparam Func 
      * @tparam Args 
      * @param func 
      * @param args 
      */
     template <size_t... Ids, class Func, class... Args>
     void call_all( indices <Ids...>, Func func, Args&&... args )
      {
       std::lock_guard<std::mutex> lock{mutex_};
       auto dummy = { ( func( std::get <Ids>( bars_ ), args...), 0 )... };
       ( void )dummy;
      } 
  
     //====================================================
     //     Private attributes
     //====================================================
     std::tuple <Indicators&...> bars_;
     std::mutex mutex_;
     unsigned int last_updated_index;
   };
  
  //====================================================
  //     MultiProgressBar
  //====================================================
  /**
   * @brief Helper function used for deduction guides.
   * 
   * @tparam Indicators The parameter pack of the various progress bar types.
   * @param inds The progress bars.
   * @return make_MultiProgressBar <typename std::remove_reference <Indicators>::type...> The update of the various progress bars.
   */
  template <class... Indicators>
  make_MultiProgressBar <typename std::remove_reference <Indicators>::type...>
  MultiProgressBar( Indicators&&... inds ) 
   {
    return { std::forward <Indicators> ( inds )... };
   }
  
  //====================================================
  //     type_identity
  //====================================================
  /**
   * @brief Struct used to to typedef the functor.
   * 
   * @tparam T 
   */
  template <class T> 
  struct type_identity 
   {
    using type = T;
   };
  
  //====================================================
  //     updater
  //====================================================
  /**
   * @brief Functor used to call the ProgressBar class update method.
   * 
   */
  struct updater 
   { 
    template <template <class> class PB, class bar_type>
    auto operator()( PB <bar_type>& pb, typename type_identity <bar_type>::type v ) const
        -> decltype( pb.update( bar_type{} ) ) 
     {
      return pb.update( v );
     }
   };
 }

#endif