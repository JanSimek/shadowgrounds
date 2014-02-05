// Copyright 2002-2004 Frozenbyte Ltd.

#ifndef INCLUDED_FILESYSTEM_OUTPUT_COMPRESSED_FILE_STREAM_H
#define INCLUDED_FILESYSTEM_OUTPUT_COMPRESSED_FILE_STREAM_H

#include <boost/scoped_ptr.hpp>

#include "output_stream.h"

namespace frozenbyte {
    namespace filesystem {
        struct OutputCompressedFileStreamBufferData;

        class OutputCompressedFileStreamBuffer : public IOutputStreamBuffer {
            boost::scoped_ptr<OutputCompressedFileStreamBufferData> data;

        public:
            OutputCompressedFileStreamBuffer(const std::string &fileName);
            ~OutputCompressedFileStreamBuffer();

            void putByte(unsigned char c);
        };

        OutputStream createOutputCompressedFileStream(const std::string &fileName);

    } // end of namespace filesystem
}     // end of namespace frozenbyte

#endif
