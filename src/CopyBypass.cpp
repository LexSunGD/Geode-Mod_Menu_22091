#include <Geode/Geode.hpp>
#include <Geode/modify/GJGameLevel.hpp>

using namespace geode::prelude;

class $modify(GJGameLevel) {
    bool canCopyLevel() {
        bool isBypassEnabled = Mod::get()->getSettingValue<bool>("bypass-copy");

        if (isBypassEnabled) {
            return true;
        }

        return GJGameLevel::canCopyLevel();
    }
};
