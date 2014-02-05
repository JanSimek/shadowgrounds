// Copyright 2002-2004 Frozenbyte Ltd.

#ifndef INCLUDED_EDITOR_GUI_H
#define INCLUDED_EDITOR_GUI_H

#include <boost/scoped_ptr.hpp>
#include <windows.h>

namespace frozenbyte {
    namespace editor {
        class Dialog;
        class Window;
        class IMode;
        class ICommand;
        class Mouse;
        struct GuiData;

        class Gui {
            boost::scoped_ptr<GuiData> data;

        public:
            Gui();
            ~Gui();

            void setMenuCommand(int id, ICommand *command);
            void reset();
            bool handleDialogs(MSG &message);

            Mouse&getMouse();

            Window&getMainWindow();
            Dialog&getRenderDialog();
            Dialog&getMenuDialog();

            Dialog&getTerrainDialog();
            Dialog&getSceneDialog();
            Dialog&getObjectsDialog();
            Dialog&getBuildingsDialog();
            Dialog&getUnitsDialog();
            Dialog&getDecoratorsDialog();
            Dialog&getParticleDialog();
            Dialog&getLightDialog();
        };

    } // end of namespace editor
}     // end of namespace frozenbyte

#endif
