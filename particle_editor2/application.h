// Copyright 2002-2004 Frozenbyte Ltd.

#ifndef PARTICLE_APPLICATION_H
#define PARTICLE_APPLICATION_H

#include <boost/scoped_ptr.hpp>
#include <string>

namespace frozenbyte {
    namespace particle {
        struct ApplicationData;

        class Application {
            boost::scoped_ptr<ApplicationData> data;

        public:
            Application();
            ~Application();

            void run(std::string startupFilename);
        };

    } // end of namespace viewer
}     // end of namespace frozenbyte

#endif
