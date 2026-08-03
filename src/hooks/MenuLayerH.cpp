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
    logo->setPositionY(logo->getPositionY() + 10.0f);

    auto fgLogo = CCSprite::create("GJ_breezeLogo.png");
    fgLogo->setScale(0.9f);
    fgLogo->setPosition(ccp(
        logo->getPositionX() + 152.0f,
        logo->getPositionY() - 45.5f
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

void MenuLayerH::onCreator(CCObject* pSender) { onOnlyFullVersion(nullptr); }
void MenuLayerH::onAchievements(CCObject* pSender) { onOnlyFullVersion(nullptr); }

void MenuLayerH::onCredits(CCObject* pSender) {
    auto dir = CCDirector::get();
    auto winSize = dir->getWinSize();

    auto alert = FLAlertLayer::create(nullptr, "CREDITS",
        "<cy>Game Owner: RobTop Games</c>"
        "\n<co>FanGame Developer: Andrexel</c>"
        "\n<cg>Mod Developer: ItzZyann</c>"
        "\n<cl>Special Thanks: Eplecentra,\nCapelling, iArtie and GDColon</c>",
        "OK", nullptr, 350.0f);

    auto layer = alert->m_mainLayer;
    auto menu = alert->m_buttonMenu;
    
    auto bgSpr = typeinfo_cast<CCScale9Sprite*>(layer->getChildByID("background"));
    auto title = typeinfo_cast<CCLabelBMFont*>(layer->getChildByID("title"));
    auto okBtn = typeinfo_cast<CCMenuItemSpriteExtra*>(menu->getChildByID("button-1"));

    bgSpr->setVisible(false);
    // title->setPositionY(title->getPositionY() + 5.0f);
    // okBtn->setPositionY(okBtn->getPositionY() - 5.0f);

    auto brownBgSpr = CCScale9Sprite::create("GJ_square01.png", {0.0f, 0.0f, 80.0f, 80.0f});
    brownBgSpr->setContentSize(bgSpr->getContentSize());
    brownBgSpr->setPosition(bgSpr->getPosition());
    brownBgSpr->setID("brown-background");
    layer->addChild(brownBgSpr, -2);

    auto brownBgSpr2 = CCScale9Sprite::create("GJ_square01.png", {0.0f, 0.0f, 80.0f, 80.0f});
    brownBgSpr2->setContentSize({
        bgSpr->getContentSize().width - 20.0f,
        bgSpr->getContentSize().height - 20.0f,

    });
    brownBgSpr2->setPosition(bgSpr->getPosition());
    brownBgSpr2->setColor(ccc3(0, 0, 0));
    brownBgSpr2->setOpacity(100);
    brownBgSpr2->setID("brown-background2");
    layer->addChild(brownBgSpr2, -1);

    // disable pop animation
    // instead use our custom ones
    alert->m_noElasticity = true;

    layer->setPositionX(-winSize.width);
    layer->runAction(
        CCEaseElasticOut::create(
            CCMoveTo::create(.5, CCPoint(0, 0)), 1
        )
    );

    alert->show();
}

void MenuLayerH::onOnlyFullVersion(CCObject* pSender) {
    // credits gdcologne
    // hehehe
    
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