// Copyright 2002-2004 Frozenbyte Ltd.

#ifndef INCLUDED_VIEWER_APPLICATION_H
#define INCLUDED_VIEWER_APPLICATION_H

#include <boost/scoped_ptr.hpp>
#include <string>

namespace frozenbyte {
    namespace viewer {
        struct ApplicationData;

        class Application {
            boost::scoped_ptr<ApplicationData> data;

        public:
            Application();
            ~Application();

            void run(const std::string &fileName);
        };

    } // end of namespace viewer
}     // end of namespace frozenbyte

#endif
