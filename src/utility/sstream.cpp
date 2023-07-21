//====================================================
//     File data
//====================================================
/**
 * @file sstream.cpp
 * @author Joel Thomas (joelthomas.e@gmail.com)
 * @date 2022-11-2
 * @copyright Copyright (c) 2022 Gianluca Bianco under the MIT license.
 */

//====================================================
//     Headers
//====================================================

// My headers
#include <osmanip/utility/iostream.hpp>
#include <osmanip/utility/output_redirector.hpp>
#include <osmanip/utility/sstream.hpp>

// STD headers
#include <memory>

namespace osm {
    // Stringbuf
    //====================================================
    //     Constructor and destructor
    //====================================================

    // Default constructor
    /**
     * @brief Construct a new Stringbuf object. Default constructor will set the
     * main attributes to default values.
     *
     */
    Stringbuf::Stringbuf() = default;

    // Destructor
    /**
     * @brief Destructs OutputRedirector object. Calls this->pubsync() before
     * being destroyed.
     *
     */
    Stringbuf::~Stringbuf() {
        // Flush before destroying
        this->pubsync();
    }

    //====================================================
    //     Getters
    //====================================================

    // getMutex
    /**
     * @brief Get the mutex for the object.
     *
     * @return the mutex of the object.
     *
     */
    std::mutex &Stringbuf::getMutex() { return mutex_; }

    //====================================================
    //     Virtual methods
    //====================================================

    // sync
    /**
     * @brief Calls the base class sync() function.
     *
     * @return the error state of the underlying buffer.
     *
     */
    int32_t Stringbuf::sync() { return basic_streambuf::sync(); }

    // Ostreambuf
    //====================================================
    //     Constructors and destructors
    //====================================================

    // Default constructor
    /**
     * @brief Construct a new Ostreambuf object. Default constructor will set
     * the main attributes to default values.
     *
     */
    Ostreambuf::Ostreambuf() : ostream_(nullptr) {}

    // Parametric constructor
    /**
     * @brief Construct a new Ostreambuf object.
     *
     * @param out the std::ostream object to use to output the buffer data.
     *
     */
    Ostreambuf::Ostreambuf(std::ostream *out) : ostream_(out) {}

    // Destructor
    /**
     * @brief Destructs OutputRedirector object. Calls this->pubsync() before
     * being destroyed.
     *
     */
    Ostreambuf::~Ostreambuf() {
        // Flush before destroying
        this->pubsync();

        ostream_ = nullptr;
    }

    //====================================================
    //     Setters
    //====================================================

    // setOstream
    /**
     * @brief Sets the std::ostream* object to route output. If there is already
     * an std::ostream* present, it will be flushed before it is replaced.
     *
     */
    void Ostreambuf::setOstream(std::ostream *out) {
        std::scoped_lock<std::mutex> slock{this->getMutex()};
        if (ostream_) {
            ostream_->flush();
        }

        ostream_ = out;
    }

    //====================================================
    //     Getters
    //====================================================

    // getOstream
    /**
     * @brief Returns the current std::ostream* object.
     *
     * @return if present, the std::ostream* object. Otherwise, nullptr.
     *
     */
    std::ostream *Ostreambuf::getOstream() {
        std::scoped_lock<std::mutex> slock{this->getMutex()};
        return ostream_;
    }

    //====================================================
    //     Virtual methods
    //====================================================

    // sync
    /**
     * @brief Synchronizes the buffer with the specified object.
     *
     * @return the error state of the stream buffer.
     *
     */
    int32_t Ostreambuf::sync() {
        if (redirout.isEnabled()) {
            sync_redirection();
            return redirout.rdstate();
        } else if (ostream_) {
            sync_output();
            return ostream_->rdstate();
        }

        return std::ios::failbit;
    }

    //====================================================
    //     Private methods
    //====================================================

    // sync_output
    /**
     * @brief Synchronizes the buffer with the specified std::ostream object and
     * calls flush() on the object.
     *
     */
    void Ostreambuf::sync_output() {
        std::scoped_lock<std::mutex> buf_lock(this->getMutex());
        *ostream_ << this << std::flush;
        this->str("");
    }

    // sync_redirection
    /**
     * @brief Synchronizes the buffer with the output redirection object and
     * calls flush() on the object.
     *
     */
    void Ostreambuf::sync_redirection() {
        std::scoped_lock<std::mutex> buf_lock(this->getMutex());
        redirout << this << std::flush;
        this->str("");
    }
}  // namespace osm