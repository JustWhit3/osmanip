//====================================================
//     File data
//====================================================
/**
 * @file output_redirector.h
 * @author Joel Thomas (joelthomas.e@gmail.com)
 * @date 2022-10-5
 */

#pragma once

#include <streambuf>
#include <string>

namespace osm
{
  /**
   * @brief Object used to redirect std::cout output to a file.
   *    Not thread safe!
   *
   * @tparam filename_  Filename of the file to receive output.
   * @tparam streambuf_backup_  Buffer to store the cout stream buffer while output is being redirected.
   * @tparam output_stringbuf_  Buffer to store the redirected output.
   */
  class OutputRedirector
  {
    public:
    OutputRedirector();
    explicit OutputRedirector( std::string & filename );
    ~OutputRedirector();

    void end();
    void begin();
    void flush();
    void touch() const;
    void redirect_output( std::string & filename ) const;
    void clear_buffer();

    void set_filename( const std::string & filename );
    [[nodiscard]] const std::string & get_filename() const;

    private:
      void file_not_found_exception() const;

    private:
    std::string filename_ = "redirected_output.txt";
    std::streambuf * streambuf_backup_;
    std::stringbuf * output_stringbuf_;
  };

}      // namespace osm
