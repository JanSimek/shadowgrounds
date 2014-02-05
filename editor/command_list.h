// Copyright 2002-2004 Frozenbyte Ltd.

#ifndef INCLUDED_EDITOR_COMMAND_LIST_H
#define INCLUDED_EDITOR_COMMAND_LIST_H

#include <boost/shared_ptr.hpp>

namespace frozenbyte {
    namespace editor {
        class ICommand;
        struct CommandListData;

        class CommandList {
            boost::shared_ptr<CommandListData> data;

        public:
            CommandList();
            ~CommandList();

            void addCommand(int id, ICommand *command);
            void execute(int id);
        };

    } // end of namespace editor
}     // end of namespace frozenbyte

#endif
