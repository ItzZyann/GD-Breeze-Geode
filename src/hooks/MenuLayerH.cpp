#include "MenuLayerH.hpp"
#include "../classes/CustomLevelSelect.hpp"
#include <Geode/binding/CCMenuItemSpriteExtra.hpp>
#include <Geode/binding/FLAlertLayer.hpp>
using namespace geode::prelude;

bool MenuLayerH::init() {
    if (!MenuLayer::init()) return false;

    m_fields->m_bottomMenu = typeinfo_cast<CCMenu*>(getChildByID("bottom-menu"));
    m_fields->m_mainMenu = typeinfo_cast<CCMenu*>(getChildByID("main-menu"));
    m_fields->m_rightSideMenu = typeinfo_cast<CCMenu*>(getChildByID("right-side-menu"));

    m_fields->m_achBtn = typeinfo_cast<CCMenuItemSpriteExtra*>(m_fields->m_bottomMenu->getChildByID("achievements-button"));
    m_fields->m_creatorBtn = typeinfo_cast<CCMenuItemSpriteExtra*>(m_fields->m_mainMenu->getChildByID("editor-button"));
    m_fields->m_dailyBtn = typeinfo_cast<CCMenuItemSpriteExtra*>(m_fields->m_rightSideMenu->getChildByID("daily-chest-button"));

    // dark out this
    // buttons
    m_fields->m_achBtn->setColor(ccc3(0xA6, 0xA6, 0xA6));
    m_fields->m_creatorBtn->setColor(ccc3(0xA6, 0xA6, 0xA6));

    // credits button
    // BUDGET lol
    auto creditsSpr = CCSprite::createWithSpriteFrameName("communityCreditsBtn_001.png");
    auto creditsBtn = CCMenuItemSpriteExtra::create(creditsSpr, this, menu_selector(MenuLayerH::onCredits));
    creditsBtn->setPosition(ccp(
        m_fields->m_dailyBtn->getPositionX(),
        m_fields->m_dailyBtn->getPositionY() + 45.0f
    ));
    m_fields->m_rightSideMenu->addChild(creditsBtn);

    // for fangame logo
    // bcuz yes
    auto logo = (CCSprite*)(getChildren()->objectAtIndex(1));
    auto fgLogo = CCLabelBMFont::create(
        "BREEZE",
        "goldFont.fnt"
    );

    fgLogo->setScale(1.1f);
    fgLogo->setPosition(ccp(
        logo->getPositionX() + 153.0f,
        logo->getPositionY() - 38.0f
    ));
    addChild(fgLogo, 100);
    
    // show this alert
    // info hehehe
    auto GM = GameManager::get();
    auto alert = FLAlertLayer::create(
        "SAVE INFO",
        "This <cy>mod</c> uses a different save file,"
        " all save data <cl>will be restored</c>"
        " when you turn off the mod.",
        "OK"
    );

    if (!GM->getGameVariable("2001")) {
        addChild(alert, 9999);

        GM->setGameVariable("2001", true);
    }

    return true;
}

void MenuLayerH::onPlay(CCObject* pSender) {
    CCDirector::get()
        ->replaceScene(
            CCTransitionFade::create(0.5f, CustomLevelSelect::scene(0))
        );
}

void MenuLayerH::onCreator(CCObject* pSender) {
    // FLAlertLayer::create(
    //     "Not available!",
    //     "This <cl>Feature</c> is only available in the full"
    //     " version of <cg>Geometry Dash</c>.",
    //     "OK"
    // )->show();

    onOnlyFullVersion(nullptr);
}

void MenuLayerH::onAchievements(CCObject* pSender) {
    // FLAlertLayer::create(
    //     "Not available!",
    //     "This <cl>feature</c> is only available in the full"
    //     " version of <cg>Geometry Dash</c>.",
    //     "OK"
    // )->show();

    onOnlyFullVersion(nullptr);
}

void MenuLayerH::onCredits(CCObject* pSender) {
    FLAlertLayer::create(nullptr, "CREDITS",
        "<cy>Game Owner: RobTop Games</c>"
        "\n<co>FanGame Developer: Andrexel</c>"
        "\n<cg>Mod Developer: ItzZyann</c>"
        "\n<cl>Special Thanks: Eplecentra,\nCapelling, iArtie and GDColon</c>",
        "OK", nullptr, 350.0f)->show();
}

void MenuLayerH::onOnlyFullVersion(CCObject* pSender) {
    int backgroundColor = 5;
    auto dialogLines = CCArray::create();

    dialogLines->addObject(DialogObject::create(
    	"The Mechanic",
    	"That is only available in the <cl>full</c> version of <cg>Geometry Dash</c>.",
    	37, 1.0f, false, ccWHITE
    ));

    DialogLayer* dialog = DialogLayer::createWithObjects(dialogLines, backgroundColor);
    dialog->updateChatPlacement(DialogChatPlacement::Center);
    dialog->animateInRandomSide();
    dialog->addToMainScene();
}