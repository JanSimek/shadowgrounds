// Copyright 2002-2004 Frozenbyte Ltd.

#ifndef INCLUDED_EDITOR_COLOR_COMPONENT_H
#define INCLUDED_EDITOR_COLOR_COMPONENT_H

#include <boost/scoped_ptr.hpp>
#include <windows.h>

namespace frozenbyte {
    namespace editor {
        struct ColorComponentData;

        class ColorComponent {
            boost::scoped_ptr<ColorComponentData> data;

        public:
            ColorComponent(HWND parentHandle, int xPosition, int yPosition, int xSize, int ySize);
            ~ColorComponent();

            unsigned int getColor() const;
            void setColor(unsigned int color);
        };

    } // end of namespace editor
}     // end of namespace frozenbyte

#endif
