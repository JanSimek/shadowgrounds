// Copyright 2002-2004 Frozenbyte Ltd.

#ifndef INCLUDED_LWEXPORT_TRANSFORMS_H
#define INCLUDED_LWEXPORT_TRANSFORMS_H

#include <DataTypeDef.h>
#include <lwrender.h>

namespace frozenbyte {
    namespace exporter {
        class LWTransforms {
            // Not implemented
            LWTransforms();
            ~LWTransforms();

        public:
            static FBMatrix GetTransform(LWItemID itemId, float time = .0f);
            static FBMatrix GetBoneTransform(LWItemID itemId, float time);
            static FBMatrix GetLocalTransform(LWItemID itemId, float time = .0f);
            static FBMatrix GetPivotTransform(LWItemID itemId);
            static FBMatrix GetBoneRestTransform(LWItemID itemId);

            static double GetScale(LWItemID itemId, float time = .0f);
            static double GetBoneScale(LWItemID itemId);
        };

    } // end of namespace export
}     // end of namespace frozenbyte

#endif
