// Copyright 2002-2004 Frozenbyte Ltd.

#ifndef INCLUDED_EDITOR_STRING_CONVERSIONS
#define INCLUDED_EDITOR_STRING_CONVERSIONS

#include <string>
#include <boost/lexical_cast.hpp>

namespace frozenbyte {
    namespace editor {
        template <class T> T convertFromString(const std::string &string, T defaultValue)
        {
            try {
                return boost::lexical_cast<T>(string);
            } catch (...) {
                return defaultValue;
            }
        }

        template <class T> inline std::string convertToString(T value)
        {
            std::stringstream stream;
            std::string result;

            stream << std::fixed;
            if ( !(stream << value) || !(stream >> result) || !(stream >> std::ws).eof() )
                return "";

            return result;
        }

    } // end of namespace editor
}     // end of namespace frozenbyte

#endif
