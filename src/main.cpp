#include <Geode/Geode.hpp>
#include <Geode/modify/GManager.hpp>
#include <Geode/modify/GameManager.hpp>
#include <Geode/modify/LevelSelectLayer.hpp>
#include <Geode/modify/OptionsLayer.hpp>

using namespace geode::prelude;

class $modify(GManager) {
public:
    void setup() {
        auto compare = std::string(m_fileName);
        compare.insert(std::string_view(compare).find(".dat"), "-BREEZE");

        m_fileName = compare;
        GManager::setup();
    }
};

class $modify(GameManager) {
public:
    bool isIconUnlocked(int pID, IconType pType) { return true; }
    bool isColorUnlocked(int pID, UnlockType pType) { return true; }
};

class OSTAlertDelegate : public FLAlertLayerProtocol {
public:
    void FLAlert_Clicked(FLAlertLayer* alert, bool btn2) override {
        if (btn2) {
            CCApplication::get()
                ->openURL("https://www.youtube.com/playlist?list=PLBBonLwBVoog");
        }
    }
};

class $modify(LevelSelectLayer) {
    struct Fields {
        OSTAlertDelegate* m_delegate = nullptr;
    };

public:
    void onDownload(CCObject* pSender) {
        m_fields->m_delegate = new OSTAlertDelegate();

        auto alert = FLAlertLayer::create(
            m_fields->m_delegate,
            "Game Soundtracks",
            "Are you sure you want to go to the <cy>GD Breeze OST</c> playlist?",
            "Cancel",
            "Yes",
            300.0f
        );
        alert->show();
    }
};

class $modify(OptionsLayer) {
    struct Fields {
        OSTAlertDelegate* m_delegate = nullptr;
    };

public:
    void onSoundtracks(CCObject* pSender) {
        m_fields->m_delegate = new OSTAlertDelegate();

        auto alert = FLAlertLayer::create(
            m_fields->m_delegate,
            "Game Soundtracks",
            "Are you sure you want to go to the <cy>GD Breeze OST</c> playlist?",
            "Cancel",
            "Yes",
            300.0f
        );
        alert->show();
    }
};