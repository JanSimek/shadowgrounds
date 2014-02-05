// Copyright 2002-2004 Frozenbyte Ltd.

#ifndef INCLUDED_EXPORT_MODEL_H
#define INCLUDED_EXPORT_MODEL_H

#ifdef _MSC_VER
#  pragma warning(disable: 4786) // identifier truncate
#  pragma warning(disable: 4710) // function not inlined
#endif

#include <vector>
#include <boost/shared_ptr.hpp>

#include "Export_Object.h"
#include "Export_Material.h"
#include "Export_Helper.h"

namespace frozenbyte {
    namespace exporter {
        class Model {
            std::vector<boost::shared_ptr<Object> > objects;
            std::vector<Material> materials;
            std::vector<Helper> helpers;

        public:
            Model();
            ~Model();

            std::string getSummary() const;
            std::string getDetails() const;

            const std::vector<boost::shared_ptr<Object> >&getObjects() const;
            const std::vector<Material>&getMaterials() const;
            const std::vector<Helper>&getHelpers() const;
            std::vector<boost::shared_ptr<Object> >&getObjects();

            void saveToFile(const std::string       &fileName,
                            std::vector<std::string> objectNames,
                            int                      boneId,
                            bool                     copyTextures,
                            int                      transformType,
                            bool                     chop,
                            bool                     optimizeVcache,
                            bool                     hasBones) const;

            int addObject(const boost::shared_ptr<Object> &object);
            int addMaterial(const Material &material);
            int addHelper(const Helper &helper);

            void buildObjectHierarchy();
            void buildHelperHierarchy();
            int removeRedundantMaterials();
            int collapseMaterials();
            void chopObjects();

            void setCollisionFlags();
            void remapIndices();
            void removeJunctions();

        private:
            void getMaterials(std::vector<int>                              &result,
                              const std::vector<std::string>                &objectNames,
                              const std::vector<boost::shared_ptr<Object> > &objects) const;
            std::vector<std::string> getTextures( const std::vector<std::string> &objectNames,
                                                  const std::vector<boost::shared_ptr<Object> > &objects,
                                                  const std::vector<Material> &lightMaterials =
                                                      std::vector<Material>() ) const;
        };

    } // end of namespace export
}     // end of namespace frozenbyte

#endif
