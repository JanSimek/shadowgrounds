// Copyright 2002-2004 Frozenbyte Ltd.

#ifndef INCLUDED_FILESYSTEM_INPUT_FILE_STREAM_H
#define INCLUDED_FILESYSTEM_INPUT_FILE_STREAM_H

#include <boost/scoped_ptr.hpp>
#include "input_stream.h"

namespace frozenbyte {
    namespace filesystem {
        struct InputFileStreamBufferData;

        class InputFileStreamBuffer : public IInputStreamBuffer {
            boost::scoped_ptr<InputFileStreamBufferData> data;

        public:
            InputFileStreamBuffer(const std::string &fileName);
            ~InputFileStreamBuffer();

            unsigned char popByte();
            bool isEof() const;
            int getSize() const;

            void popBytes(char *buffer, int bytes);
        };

        InputStream createInputFileStream(const std::string &fileName);
        void setInputStreamErrorReporting(bool logNonExisting);

    } // end of namespace filesystem
}     // end of namespace frozenbyte

#endif
