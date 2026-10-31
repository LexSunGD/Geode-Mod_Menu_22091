#include <Geode/Geode.hpp>
#include <Geode/modify/GameLevelManager.hpp>

using namespace geode::prelude;

class $modify(GameLevelManager) {
    bool canCopyLevel(GJGameLevel* level) {
        bool isBypassEnabled = Mod::get()->getSettingValue<bool>("bypass-copy");

        if (isBypassEnabled) {
            return true;
        }

        return GameLevelManager::canCopyLevel(level);
    }
};
