// Copyright 2002-2004 Frozenbyte Ltd.

#ifndef INCLUDED_EDITOR_STORM_H
#define INCLUDED_EDITOR_STORM_H

#include <windows.h>

#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <set>

#include <DataTypeDef.h>
#include "align_units.h"

class IStorm3D;
class IStorm3D_Model;
class IStorm3D_Scene;
class IStorm3D_Terrain;

namespace ui {
    class LightManager;
} // ui

struct Storm3D_CollisionInfo;

namespace frozenbyte {
    namespace editor {
        class Mouse;

        struct Storm {
            IStorm3D           *storm;
            IStorm3D_Scene     *scene;
            IStorm3D_Terrain   *terrain;
            ::ui::LightManager *lightManager;

            VC2I            heightmapResolution;
            VC3             heightmapSize;

            AlignUnits      unitAligner;
            bool            viewerCamera;

            IStorm3D_Scene *floorScene;
            std::set<boost::weak_ptr<IStorm3D_Model> > floorModels;

            explicit Storm(HWND hwnd);
            ~Storm();

            void   recreate(HWND hwnd, bool disableBuffers = false);

            bool   rayTrace(Storm3D_CollisionInfo &info, const Mouse &mouse) const;
            float  getHeight(const VC2 &position) const;
            bool   onFloor(const VC2 &position) const;

        private:
            Storm(const Storm &);
            Storm &operator =(const Storm &);
        };

    } // end of namespace editor
}     // end of namespace frozenbyte

#endif
