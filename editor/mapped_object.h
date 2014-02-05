// Copyright 2002-2004 Frozenbyte Ltd.

#ifndef INCLUDED_EDITOR_MAPPED_OBJECT_H
#define INCLUDED_EDITOR_MAPPED_OBJECT_H

#include <boost/scoped_ptr.hpp>
#include <string>

class IStorm3D_Model;

namespace frozenbyte {
    namespace editor {
        struct MappedObjectData;

        class MappedObject {
            boost::scoped_ptr<MappedObjectData> data;

        public:
            MappedObject(const std::string &fileName, IStorm3D_Model &model);
            ~MappedObject();
        };

    } // end of namespace editor
}     // end of namespace frozenbyte

#endif
