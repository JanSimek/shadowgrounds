// Copyright 2002-2004 Frozenbyte Ltd.

#ifndef INCLUDED_EDITOR_OBJECT_SETTINGS_H
#define INCLUDED_EDITOR_OBJECT_SETTINGS_H

#include <boost/scoped_ptr.hpp>
#include <string>
#include <vector>
#include <map>

namespace frozenbyte {
    namespace editor {
        struct Storm;

        struct ObjectData {
            int         type;
            int         fallType;

            float       radiusX;
            float       radiusZ;
            float       height;

            float       originalCrapRadiusX;
            float       originalCrapRadiusZ;
            float       originalCrapHeight;

            bool        fireThrough;

            std::string explosionObject;
            std::string explosionEffect;
            std::string explosionProjectile;
            std::string explosionScript;
            std::string explosionSound;
            std::string material;
            std::string animation;
            int         hitpoints;
            int         breakTexture;

            int         physicsType;
            std::string physicsWeight;
            std::string physicsMaterial;
            std::string durabilityType;

            std::map<std::string, std::string> metaValues;

            ObjectData()
                :   type(-1), fallType(0), originalCrapRadiusX(0), originalCrapRadiusZ(0), originalCrapHeight(0),
                radiusX(0), radiusZ(0), height(0), fireThrough(false), hitpoints(5), breakTexture(0), physicsType(0) { }
        };

        struct EffectData {
            std::string name;
            std::string bullet;
        };

        struct ObjectSettingsData;

        class ObjectSettings {
            boost::scoped_ptr<ObjectSettingsData> data;

        public:
            ObjectSettings(Storm &storm);
            ~ObjectSettings();

            void saveSettings();
            std::vector<std::string> getMetaKeys() const;

            ObjectData&getSettings(const std::string &fileName);
            const ObjectData&getSettings(const std::string &fileName) const;
        };

    } // end of namespace editor
}     // end of namespace frozenbyte

#endif
