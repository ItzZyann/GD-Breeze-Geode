#pragma once
#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

class $modify(MenuLayerH, MenuLayer) {
    struct Fields {
        cocos2d::CCMenu* m_bottomMenu;
        cocos2d::CCMenu* m_mainMenu;
        cocos2d::CCMenu* m_rightSideMenu;

        CCMenuItemSpriteExtra* m_achBtn;
        CCMenuItemSpriteExtra* m_creatorBtn;
        CCMenuItemSpriteExtra* m_dailyBtn;
    };

public:
    $override virtual bool init();
    $override void onPlay(cocos2d::CCObject* pSender);
    $override void onCreator(cocos2d::CCObject* pSender);
    $override void onAchievements(cocos2d::CCObject* pSender);

    void onCredits(cocos2d::CCObject* pSender);
    void onOnlyFullVersion(cocos2d::CCObject* pSender);
};