// Copyright 2002-2004 Frozenbyte Ltd.

#ifndef INCLUDED_EDITOR_TERRAIN_STORM_TEXTURE_H
#define INCLUDED_EDITOR_TERRAIN_STORM_TEXTURE_H

#include <boost/shared_ptr.hpp>
#include <string>

class Storm;
class IStorm3D_Texture;

namespace frozenbyte {
    namespace editor {
        boost::shared_ptr<IStorm3D_Texture> loadTexture(const std::string &fileName, Storm &storm);
        boost::shared_ptr<IStorm3D_Texture> createTexture(int width, int height, Storm &storm);

    } // end of namespace editor
}     // end of namespace frozenbyte

#endif
