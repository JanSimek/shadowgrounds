// Copyright 2002-2004 Frozenbyte Ltd.

#ifndef INCLUDED_EDITOR_EDITOR_PARSER
#define INCLUDED_EDITOR_EDITOR_PARSER

#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>
#include <string>
#include <iosfwd>

namespace frozenbyte {
    namespace filesystem {
        class InputStream;

    } // filesystem

    namespace editor {
        struct ParserGroupData;
        struct ParserData;

        class ParserGroup {
            /*boost::scoped_ptr*/ boost::shared_ptr<ParserGroupData> data;

        public:
            ParserGroup();
            ParserGroup(const ParserGroup &rhs);
            ~ParserGroup();

            ParserGroup &operator =(const ParserGroup &rhs);

            const std::string&getValue(const std::string &name) const;
            const std::string&getValue(const std::string &name, const std::string &defaultValue) const;

            int getValueAmount() const;
            const std::string&getValueKey(int index) const;

            bool hasValueBeenReferenced(int index) const;

            const ParserGroup&getSubGroup(const std::string &name) const;
            ParserGroup&getSubGroup(const std::string &name);

            // Hax
            bool hasSubGroup(const std::string &name) const;
            int getSubGroupAmount() const;
            const std::string&getSubGroupName(int index) const;
            const ParserGroup&getSubGroup(int index) const;

            int getLineCount() const;
            const std::string&getLine(int index) const;

            void setValue(const std::string &name, const std::string &value);
            void addLine(const std::string &value);
            void addSubGroup(const std::string &name, ParserGroup &group);
            void removeSubGroup(const std::string &name);

            std::ostream&writeStream(std::ostream &stream, int tabCount) const;
            filesystem::InputStream&readStream(filesystem::InputStream &stream);

            // (used for the error logging options.)
            void setFlags(int flags);
        };

        inline filesystem::InputStream &operator >> (filesystem::InputStream &stream, ParserGroup &parserGroup)
        {
            return parserGroup.readStream(stream);
        }

        class EditorParser {
            /*boost::scoped_ptr*/ boost::shared_ptr<ParserData> data;

        public:
            // the new error whine to get rid of the f*ed up "silently ignore errors" feature. --jpk
            EditorParser(bool logUnreferenced = true, bool logNonExisting = true);
            ~EditorParser();

            const ParserGroup&getGlobals() const;
            ParserGroup&getGlobals();

            std::ostream&writeStream(std::ostream &stream) const;
            filesystem::InputStream&readStream(filesystem::InputStream &stream);
        };

        inline std::ostream &operator << (std::ostream &stream, const EditorParser &parser)
        {
            return parser.writeStream(stream);
        }

        inline filesystem::InputStream &operator >> (filesystem::InputStream &stream, EditorParser &parser)
        {
            return parser.readStream(stream);
        }

    } // end of namespace editor
}     // end of namespace frozenbyte

#endif
