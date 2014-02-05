// Copyright 2002-2004 Frozenbyte Ltd.

#ifndef INCLUDED_VIEWER_ITEMS_H
#define INCLUDED_VIEWER_ITEMS_H

#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <string>

class IStorm3D_Model;

namespace frozenbyte {
    namespace editor {
        class Parser;
        struct Storm;
    }

    namespace viewer {
        struct BoneItemsData;

        class BoneItems {
            boost::scoped_ptr<BoneItemsData> data;

        public:
            BoneItems();
            ~BoneItems();

            void showDialog(IStorm3D_Model *model);
            void applyToModel(boost::shared_ptr<IStorm3D_Model> model, editor::Storm &storm);

            void load(const editor::Parser &parser);
            void save(editor::Parser &parser);
        };

    } // end of namespace viewer
}     // end of namespace frozenbyte

#endif
