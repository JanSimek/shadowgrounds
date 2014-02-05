// Copyright 2002-2004 Frozenbyte Ltd.

#ifndef INCLUDED_LWEXPORT_BONE_H
#define INCLUDED_LWEXPORT_BONE_H

#ifdef _MSC_VER
#  pragma warning(disable: 4786) // identifier truncate
#endif

#include <DataTypeDef.h>
#include <string>
#include <lwrender.h>

namespace frozenbyte {
    namespace exporter {
/**  @class LWBone
 *  @brief Collects bone data (rest transforms / hierarchy)
 *  @author Juha Hiekkamäki
 *  @version 1.0
 *  @date 2001
 */
        class LWBone {
            LWItemID lwId;
            LWItemID parentId;
            int exporterId;

            std::string name;
            std::string parentName;
            std::string weightMap;

            Vector minAngles;
            Vector maxAngles;

        public:
            explicit LWBone(LWItemID id);
            ~LWBone();

            const std::string&getWeightName() const;
            bool collectData();

            void getKey(float time, int ms);

        private:
            bool validateBone();
            //void collectKeys();
        };

    } // end of namespace export
}     // end of namespace frozenbyte

#endif
