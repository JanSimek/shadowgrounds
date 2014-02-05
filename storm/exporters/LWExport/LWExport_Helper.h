// Copyright 2002-2004 Frozenbyte Ltd.

#ifndef INCLUDED_LWEXPORT_HELPER_H
#define INCLUDED_LWEXPORT_HELPER_H

#include <string>
#include <lwmeshes.h>
#include <lwrender.h>

namespace frozenbyte {
    namespace exporter {
        class LWHelper {
            LWItemID lwId;
            LWItemID parentId;

            std::string name;
            std::string parentName;

        public:
            explicit LWHelper(LWItemID id);
            ~LWHelper();

            bool collectData();
        };

    } // end of namespace export
}     // end of namespace frozenbyte

#endif
