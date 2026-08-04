#include "CustomLevelSelect.hpp"
using namespace geode::prelude;

// credits to iArtie
// for FreeGames mod

CustomLevelSelect* CustomLevelSelect::create(int pPage) {
    auto ret = new CustomLevelSelect();

    if (ret && ret->init(pPage)) {
        ret->autorelease();
        return ret;
    }
    
    CC_SAFE_DELETE(ret);
    return nullptr;
}

CCScene* CustomLevelSelect::scene(int pPage) {
    auto scene = CCScene::create();
    scene->addChild(CustomLevelSelect::create(pPage));
    return scene;
}

bool CustomLevelSelect::init(int pPage) {
    if (!LevelSelectLayer::init(pPage)) return false;

    m_scrollLayer->m_dynamicObjects->removeAllObjects();

    auto dotsArray = CCArrayExt<CCSprite*>(m_scrollLayer->m_dots);
    for (CCSprite* dot : dotsArray) {
        dot->removeFromParent();
    }
    m_scrollLayer->m_dots->removeAllObjects();

    for (int i = 6001; i <= 6012; i++) {
        m_scrollLayer->m_dynamicObjects->addObject(GameLevelManager::get()->getMainLevel(i, true));
    }

    auto comingSoon = GJGameLevel::create();
    comingSoon->m_levelID = -1;
    m_scrollLayer->m_dynamicObjects->addObject(comingSoon);

    auto batchNode = CCSpriteBatchNode::create("smallDot.png", 29);
    m_scrollLayer->addChild(batchNode, 5);

    for (int i = 0; i < m_scrollLayer->m_dynamicObjects->count(); i++) {
        auto sprite = CCSprite::create("smallDot.png");
        batchNode->addChild(sprite);
        m_scrollLayer->m_dots->addObject(sprite);
    }

    m_scrollLayer->updateDots(0.f);
    m_scrollLayer->updatePages();

    this->updatePageWithObject(
        m_scrollLayer->m_pages->objectAtIndex(pPage % 3),
        m_scrollLayer->m_dynamicObjects->objectAtIndex(pPage)
    );

    this->m_scrollLayer->repositionPagesLooped();

    return true;
}