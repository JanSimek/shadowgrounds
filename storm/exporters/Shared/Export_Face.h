// Copyright 2002-2004 Frozenbyte Ltd.

#ifndef INCLUDED_FACE_H
#define INCLUDED_FACE_H

#ifdef _MSC_VER
#  pragma warning(disable: 4514) // removed unreferenced inline function (stl)
#endif

#include <vector>

#include <DataTypeDef.h>
#include "Export_Types.h"

#pragma pack(push, export_face_h)
#pragma pack(1)

namespace frozenbyte {
    namespace exporter {
        class Face {
            int indices[3];
            short int materialId;

            FBVector normal;

        public:
            Face();
            ~Face();

            int getVertexIndex(int index) const;
            int getMaterialId() const;
            const FBVector&getNormal() const;

            void setVertexIndex(int index, int vertex_index);
            void setMaterialId(int id);
            void setNormal(const FBVector &normal);

            void correctMaterialIndices(const std::vector<int> &newIndices);
        };

    } // end of namespace export
}     // end of namespace frozenbyte

#pragma pack(pop, export_face_h)

#endif
