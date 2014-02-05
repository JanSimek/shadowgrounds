// Copyright 2002-2004 Frozenbyte Ltd.

#ifndef INCLUDED_EDITOR_APPLICATION_H
#define INCLUDED_EDITOR_APPLICATION_H

#include <boost/scoped_ptr.hpp>

namespace frozenbyte {
    namespace editor {
        struct ApplicationData;

        class Application {
            boost::scoped_ptr<ApplicationData> data;

        public:
            Application();
            ~Application();

            void run();
        };

    } // end of namespace editor
}     // end of namespace frozenbyte

#endif
