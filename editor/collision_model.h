// Copyright 2002-2004 Frozenbyte Ltd.

#ifndef INCLUDED_EDITOR_COLLISION_MODEL_H
#define INCLUDED_EDITOR_COLLISION_MODEL_H

#include <boost/scoped_ptr.hpp>
#include <string>
#include <boost/utility.hpp>

#include "storm.h"
#include "object_settings.h"

namespace frozenbyte {
    namespace editor {
        struct Storm;
        struct ObjectData;
        struct CollisionModelData;
        struct CollisionVolumeData;

        class CollisionModel {
            boost::scoped_ptr<CollisionModelData> data;

        public:
            CollisionModel(ObjectData   &data_,
                           const COL    &color_,
                           const Vector &position_,
                           const VC3    &rotation,
                           Storm        &storm_);
            ~CollisionModel();

            void create();
            void clone(CollisionModel &rhs);
            void scale();

            void hide();
            void show();
        };

        struct CollisionData {
            VC3        rayOrigin;
            VC3        rayDirection;
            float      rayLength;

            bool       hasCollision;
            VC3        collisionPosition;

            ObjectData objectData;

            CollisionData()
                :   hasCollision(false), rayLength(0) { }
        };

        class CollisionVolume {
            boost::scoped_ptr<CollisionVolumeData> data;

        public:
            CollisionVolume(ObjectData &data_);
            ~CollisionVolume();

            void initialize(ObjectData &data_);
            bool testCollision(const VC3     &objectPosition,
                               const VC3     &rotation,
                               CollisionData &collisionData,
                               float          epsilon);
        };

    } // end of namespace editor
}     // end of namespace frozenbyte

#endif
