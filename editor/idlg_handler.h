#ifndef INCLUDED_EDITOR_IDLG_HANDLER_H
#define INCLUDED_EDITOR_IDLG_HANDLER_H

#include <windows.h>

namespace frozenbyte {
    namespace editor {
        class IDlgHandler {
        public:
            virtual BOOL handleMessages(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) = 0;
            virtual ~IDlgHandler() { }
        };

    }
}

#endif
