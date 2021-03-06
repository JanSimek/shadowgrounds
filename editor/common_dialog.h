// Copyright 2002-2004 Frozenbyte Ltd.

#ifndef INCLUDED_EDITOR_COMMON_DIALOG_H
#define INCLUDED_EDITOR_COMMON_DIALOG_H

#include <string>
#include <vector>

namespace frozenbyte {
    namespace editor {
        std::string getSaveFileName(const std::string &extension,
                                    const std::string &defaultDir = "",
                                    bool               useFilter = true);
        std::string getOpenFileName(const std::string &extension,
                                    const std::string &defaultDir = "",
                                    bool               useFilter = true);
        std::vector<std::string> getMultipleOpenFileName(const std::string &extension, const std::string &defaultDir);

        std::string getFileName(const std::string &fullFileName);
        std::string getDirName(const std::string &fullFileName);
        bool fileExists(const std::string &fileName);

    } // end of namespace editor
}     // end of namespace frozenbyte

#endif
