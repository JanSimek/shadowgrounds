// Copyright 2002-2004 Frozenbyte Ltd.

#ifndef INCLUDED_EDITOR_TEXTURE_LAYER_H
#define INCLUDED_EDITOR_TEXTURE_LAYER_H

#include <boost/scoped_ptr.hpp>
#include <string>

namespace frozenbyte {
    namespace editor {
        class TerrainTextures;
        struct Storm;
        struct TextureLayerData;

        class TextureLayer {
            boost::scoped_ptr<TextureLayerData> data;

        public:
            TextureLayer(TerrainTextures &textures, Storm &storm);
            ~TextureLayer();

            bool show();
        };

    } // end of namespace editor
}     // end of namespace frozenbyte

#endif
