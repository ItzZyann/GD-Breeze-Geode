#include <Geode/Geode.hpp>
#include <Geode/modify/GManager.hpp>
#include <Geode/modify/GameManager.hpp>
#include <Geode/modify/LevelSelectLayer.hpp>

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

class $modify(LevelSelectLayer) {
public:
    void onDownload(CCObject* pSender) {
        CCApplication::get()
        ->openURL("https://www.youtube.com/playlist?list=PLBBonLwBVoog");
    }
};