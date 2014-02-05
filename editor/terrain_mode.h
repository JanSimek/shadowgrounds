// Copyright 2002-2004 Frozenbyte Ltd.

#ifndef INCLUDED_EDITOR_TERRAIN_MODE_H
#define INCLUDED_EDITOR_TERRAIN_MODE_H

#include "imode.h"

#include <DataTypeDef.h>

#include <boost/scoped_ptr.hpp>
#include <vector>

namespace frozenbyte {
    namespace ui {
        class TerrainLegacy;
    }

    namespace editor {
        class Dialog;
        class IEditorState;
        class Gui;
        struct Storm;
        struct TerrainModeData;

        struct HeightmapData {
            std::vector<unsigned short> &heightMap;
            const VC2I &mapSize;
            const VC3  &realSize;

            HeightmapData(std::vector<unsigned short> &heightMap_, const VC2I &mapSize_, const VC3 &realSize_)
                :   heightMap(heightMap_),
                mapSize(mapSize_),
                realSize(realSize_)
            {
            }
        };

        class TerrainMode : public IMode {
            boost::scoped_ptr<TerrainModeData> data;

        public:
            TerrainMode(Gui &gui, Storm &storm, IEditorState &editorState);
            ~TerrainMode();

            void tick();
            void reset();
            void update();

            HeightmapData loadHeightmap();
            void setHeightmap();
            void setTexturing();

            void doExport(Exporter &exporter) const;
            filesystem::OutputStream&writeStream(filesystem::OutputStream &stream) const;
            filesystem::InputStream&readStream(filesystem::InputStream &stream);
        };

    } // end of namespace editor
}     // end of namespace frozenbyte

#endif
