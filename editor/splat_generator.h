// Copyright 2002-2004 Frozenbyte Ltd.

#ifndef INCLUDED_SPLAT_GENERATOR_H
#define INCLUDED_SPLAT_GENERATOR_H

#include <boost/scoped_ptr.hpp>
#include <datatypedef.h>

namespace frozenbyte {
    namespace editor {
        class TerrainTextures;
        struct Storm;
        struct SplatGeneratorData;

        class SplatGenerator {
            boost::scoped_ptr<SplatGeneratorData> data;

        public:
            SplatGenerator(Storm &storm, TerrainTextures &textures);
            ~SplatGenerator();

            void generate(int textureId, const VC3 &position, int size, float strength);
        };

    } // editor
}     // frozenbyte

#endif
