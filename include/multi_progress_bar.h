#ifndef MULTIPROGRESSBAR_H
#define MULTIPROGRESSBAR_h

#include <iostream>
#include <type_traits>
#include <tuple>
#include <functional>
#include <mutex>
#include <atomic>
#include <utility>
//#include <progress_bar.h>

namespace osm
 {
  //====================================================
  //     TYPE TO GENERATE INDICES FOR PARAMETER PACKS
  //====================================================
  template <size_t... Is>
  struct indices {};
  
  template <size_t N, size_t... Is>
  struct gen_indices: gen_indices <N - 1, N - 1, Is...> {};
  
  template <size_t... Is>
  struct gen_indices <0, Is...>: indices<Is...> {};
  
  //====================================================
  //     MAKE_MULTIPROGRESSBAR TEMPLATE CLASS
  //====================================================
  template <class... Indicators>
  class make_MultiProgressBar 
   {
    public:
  
     //====================================================
     //     CONSTRUCTORS
     //====================================================
     template <class... Inds>
     make_MultiProgressBar( Inds&&... bars ): bars_{ std::forward <Inds> ( bars )... } {}
  
     //====================================================
     //     OTHER PUBLIC METHODS
     //====================================================
     static size_t size() { return sizeof...( Indicators ); }
  
     template <class Func, class... Args>
     void for_one( size_t idx, Func&& func, Args&&... args )
      {
       //std::lock_guard<std::mutex> lock{mutex_};
       call_one( idx, gen_indices <sizeof...( Indicators )> (), std::forward <Func> ( func ), std::forward <Args> ( args )... );
      }
  
     template <class Func, class... Args>
     void for_each( Func&& func, Args&&... args ) 
      {
       //std::lock_guard<std::mutex> lock{mutex_};
       call_all( gen_indices <sizeof...( Indicators )> (), std::forward <Func> ( func ), std::forward <Args> ( args )... );
      }
  
    private:
  
     //====================================================
     //     OTHER PRIVATE METHODS
     //====================================================
     template <size_t... Ids, class Func, class... Args>
     void call_one( size_t idx, indices <Ids...>, Func func, Args&&... args )
      {
       std::lock_guard <std::mutex> lock{mutex_};
       [](...) {} 
        (
         (idx == Ids &&
          ( ( void ) std::forward <Func> ( func )( std::get <Ids> ( bars_ ), 
              std::forward <Args> ( args )... ), false ) )...
        );   
      }
  
     template <size_t... Ids, class Func, class... Args>
     void call_all( indices <Ids...>, Func func, Args&&... args )
      {
       //std::lock_guard<std::mutex> lock{mutex_};
       auto dummy = { ( func( std::get <Ids>( bars_ ), args...), 0 )... };
       ( void )dummy;
      } 
  
     //====================================================
     //     PRIVATE ATTRIBUTES
     //====================================================
     std::tuple <Indicators&...> bars_;
     std::mutex mutex_;
   };
  
  //====================================================
  //     HELPER FUNCTION FOR DEDUCTION GUIDES
  //====================================================
  template <class... Indicators>
  make_MultiProgressBar <typename std::remove_reference <Indicators>::type...>
  MultiProgressBar( Indicators&&... inds ) 
   {
    return { std::forward <Indicators> ( inds )... };
   }
  
  //====================================================
  //     FUNCTOR
  //====================================================
  template <class T> 
  struct type_identity 
   {
    using type = T;
   };
  
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