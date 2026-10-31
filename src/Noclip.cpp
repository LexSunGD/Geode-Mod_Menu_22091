#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude;

class $modify(MyPlayLayer, PlayLayer) {
    void destroyPlayer(PlayerObject* player, GameObject* obstacle) {
        bool isNoclipActive = Mod::get()->getSettingValue<bool>("noclip-enabled");

        if (!isNoclipActive) {
            PlayLayer::destroyPlayer(player, obstacle);
        }
    }
};

class $modify(MyPauseLayer, PauseLayer) {
    
    CustomToggler* m_noclipToggle = nullptr;

    bool init() {
        if (!PauseLayer::init()) return false;

        bool isNoclipActive = Mod::get()->getSettingValue<bool>("noclip-enabled");

        m_fields->m_noclipToggle = CustomToggler::create(
            "sideBtn_damageOn_001.png",
            "sideBtn_damageOff_001.png",
            this,
            menu_selector(MyPauseLayer::onNoclipToggle)
        );

        m_fields->m_noclipToggle->toggle(isNoclipActive);

        if (auto rightMenu = this->getChildByID("right-button-menu")) {
            rightMenu->addChild(m_fields->m_noclipToggle);
            rightMenu->updateLayout();
        }

        return true;
    }

    void onNoclipToggle(CCObject* sender) {
        bool currentStatus = Mod::get()->getSettingValue<bool>("noclip-enabled");
        bool newStatus = !currentStatus;

        Mod::get()->setSettingValue("noclip-enabled", newStatus);
    }
};
