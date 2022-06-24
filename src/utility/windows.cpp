//====================================================
//     Headers
//====================================================

// Windows headers
#ifdef _WIN32
#include <windows.h>
#endif

// My headers
#include "../../include/utility/windows.hpp"

//Extra headers
#include <arsenalgear/system.hpp>
#include <arsenalgear/utils.hpp>

// STD headers
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

namespace osm
 {
  //====================================================
  //     Macros
  //====================================================
  #ifdef _WIN32
  #ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
  #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
  #endif
  #endif

  //====================================================
  //     Variables
  //====================================================
  #ifdef _WIN32
  static HANDLE stdoutHandle;
  static DWORD outModeInit;
  #endif
  
  //====================================================
  //     enableANSI
  //====================================================
  /**
   * @brief Function used to enable ANSI escape sequences on Windows (used for Windows only). 
   * 
   */
  void enableANSI()
   {
    // Settings for Windows mode
    #ifdef _WIN32

    DWORD outMode = 0;
    stdoutHandle = GetStdHandle( STD_OUTPUT_HANDLE );
    
    if( stdoutHandle == INVALID_HANDLE_VALUE )
     {
      exit( GetLastError() );
     }
    
    if( ! GetConsoleMode( stdoutHandle, &outMode ) )
     {
      exit( GetLastError() );
     }
    
    outModeInit = outMode;
    
    // Enable ANSI escape codes
    outMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    
    if( ! SetConsoleMode( stdoutHandle, outMode ) )
     {
      exit( GetLastError() );
     }
  
    #endif
   }
  
  //====================================================
  //     disableANSI
  //====================================================
  void disableANSI()
  /**
   * @brief Function used to disable ANSI escape sequences (used for Windows only).
   * 
   */
   {
    // Reset all styles and colors
    std::cout << "\033[0m";
  
    // Settings for Windows mode
    #ifdef _WIN32
  
    // Reset console mode
    if( ! SetConsoleMode( stdoutHandle, outModeInit ) )
     {
      exit( GetLastError() );
     }
  
    #endif
   }

  //====================================================
  //     enableUNICODE
  //====================================================
  /**
   * @brief Function used to enable UNICODE characters (used for Windows only).
   * 
   */
  void enableUNICODE()
   {
    // Settings for Windows mode
    #ifdef _WIN32

    std::string old_chcp_pre = agr::getCommandOut( "chcp" );
    old_chcp = agr::split_string( old_chcp_pre, " " ).back();

    system( "chcp 65001" );

    #endif
   }

  //====================================================
  //     disableUNICODE
  //====================================================
  /**
   * @brief Function used to disable UNICODE characters (used for Windows only).
   * 
   */
  void disableUNICODE()
   {
    // Settings for Windows mode
    #ifdef _WIN32

    std::ostringstream oss;
    oss << "chcp " << old_chcp;
    const char* return_chcp = oss.str();

    system( return_chcp );

    #endif
   }
 }