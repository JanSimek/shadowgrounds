// Copyright 2002-2004 Frozenbyte Ltd.

#ifndef INCLUDED_EDITOR_COLOR_PICKER_H
#define INCLUDED_EDITOR_COLOR_PICKER_H

#include <boost/scoped_ptr.hpp>

namespace frozenbyte {
    namespace filesystem {
        class InputStream;
        class OutputStream;
    }

    namespace editor {
        struct ColorPickerData;

        class ColorPicker {
            boost::scoped_ptr<ColorPickerData> data;

        public:
            ColorPicker();
            ~ColorPicker();

            bool run(int originalColor);
            int getColor();
        };

        void readColors(filesystem::InputStream &stream);
        void writeColors(filesystem::OutputStream &stream);

    } // end of namespace editor
}     // end of namespace frozenbyte

#endif
