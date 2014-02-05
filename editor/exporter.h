// Copyright 2002-2004 Frozenbyte Ltd.

#ifndef INCLUDED_EDITOR_EXPORTER_H
#define INCLUDED_EDITOR_EXPORTER_H

#include <boost/scoped_ptr.hpp>

#include <string>

namespace frozenbyte {
    namespace editor {
        class ExporterScene;
        class ExporterObjects;
        class ExporterUnits;
        class ExporterScripts;
        class ExporterLights;
        struct ExportOptions;
        struct ExporterData;

        class Exporter {
            boost::scoped_ptr<ExporterData> data;

        public:
            Exporter();
            ~Exporter();

            ExporterScene&getScene();
            ExporterObjects&getObjects();
            ExporterUnits&getUnits();
            ExporterScripts&getScripts();
            ExporterLights&getLights();

            void save(const ExportOptions &options) const;
        };

    } // end of namespace editor
}     // end of namespace frozenbyte

#endif
