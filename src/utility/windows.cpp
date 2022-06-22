//====================================================
//     Headers
//====================================================

// Windows headers
#ifdef _WIN32
#include <windows.h>
#endif

// My headers
#include "../../include/utility/windows.hpp"

// STD headers
#include <iostream>
#include <stdexcept>

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
  #if defined _WIN32 || defined _WIN64 || defined __MINGW32__ || defined __CYGWIN__
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
    #if defined _WIN32 || defined _WIN64 || defined __MINGW32__ || defined __CYGWIN__
  
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
    #if defined _WIN32 || defined _WIN64 || defined __MINGW32__ || defined __CYGWIN__
  
    // Reset console mode
    if( ! SetConsoleMode( stdoutHandle, outModeInit ) )
     {
      exit( GetLastError() );
     }
  
    #endif
   }
 }