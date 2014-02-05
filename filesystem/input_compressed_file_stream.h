// Copyright 2002-2004 Frozenbyte Ltd.

#ifndef INCLUDED_FILESYSTEM_INPUT_COMPRESSED_FILE_STREAM_H
#define INCLUDED_FILESYSTEM_INPUT_COMPRESSED_FILE_STREAM_H

#include <boost/scoped_ptr.hpp>

#include "input_stream.h"

namespace frozenbyte {
    namespace filesystem {
        struct InputCompressedFileStreamBufferData;

        class InputCompressedFileStreamBuffer : public IInputStreamBuffer {
            boost::scoped_ptr<InputCompressedFileStreamBufferData> data;

        public:
            InputCompressedFileStreamBuffer(const std::string &fileName);
            ~InputCompressedFileStreamBuffer();

            unsigned char popByte();
            bool isEof() const;
            int getSize() const;

            void popBytes(char *buffer, int bytes);
        };

        InputStream createInputCompressedFileStream(const std::string &fileName);

    } // end of namespace filesystem
}     // end of namespace frozenbyte

#endif
