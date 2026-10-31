#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>

using namespace geode::prelude;

class $modify(LevelInfoLayer) {
    bool init(GJGameLevel* level, bool challenge) {
        bool isBypassEnabled = Mod::get()->getSettingValue<bool>("bypass-copy");

        if (isBypassEnabled && level) {
            level->m_password = 1;
        }

        return LevelInfoLayer::init(level, challenge);
    }
};
