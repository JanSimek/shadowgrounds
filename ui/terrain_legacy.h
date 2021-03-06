#ifndef INCLUDED_UI_TERRAIN_LEGACY_H
#define INCLUDED_UI_TERRAIN_LEGACY_H

#include <boost/scoped_ptr.hpp>

#include <datatypedef.h>

class IStorm3D;
class IStorm3D_Terrain;

namespace Parser {
    class ParserGroup;
}
namespace frozenbyte {
    namespace ui {
        struct TerrainLegacyData;

        class TerrainLegacy {
            boost::scoped_ptr<TerrainLegacyData> data;

        public:
            TerrainLegacy();
            ~TerrainLegacy();

            void setTexturing(int baseIndex, int *indexArray);
            void setStorm(IStorm3D *storm, IStorm3D_Terrain *terrain);
            void setProperties(const VC2I &mapSize, float terrainScale);

            void apply(const Parser::ParserGroup &group);
            void clear();
        };

    } // ui
}     // frozenbyte

#endif
