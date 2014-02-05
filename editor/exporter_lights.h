// Copyright 2002-2004 Frozenbyte Ltd.

#ifndef INCLUDED_EDITOR_EXPORTER_LIGHTS_H
#define INCLUDED_EDITOR_EXPORTER_LIGHTS_H

#include <boost/scoped_ptr.hpp>
#include <string>

#include <DataTypeDef.h>

namespace ui {
    struct SpotProperties;
} // ui

namespace frozenbyte {
    namespace editor {
        struct ExportOptions;
        struct ExporterScriptsData;
        struct UnitProperties;

        class ExporterLights {
            struct Data;
            boost::scoped_ptr<Data> data;

        public:
            ExporterLights();
            ~ExporterLights();

            void addSpot(const VC3 &position, float yAngle, const ui::SpotProperties &properties, bool pointLight);
            void addBuildingLight(const VC3 &position, const COL &color, float range);

            void save(const ExportOptions &options) const;
        };

    } // end of namespace editor
}     // end of namespace frozenbyte

#endif
