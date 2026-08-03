#include "LoadingLayerH.hpp"
using namespace geode::prelude;

bool LoadingLayerH::init(bool pRefresh) {
    if (!LoadingLayer::init(pRefresh)) return false;
    
    auto zipFilePath = Mod::get()->getResourcesDir() / "Assets.zip";
    auto unzipDir = Mod::get()->getResourcesDir();
    auto path = utils::file::Unzip::intoDir(zipFilePath, unzipDir, true);

    CCFileUtils::get()->addTexturePack(CCTexturePack{
        .m_id = Mod::get()->getID(),
        .m_paths = {string::pathToString(Mod::get()->getResourcesDir())}
    });

    // for fangame logo
    // bcuz yes
    auto bgSpr = (CCSprite*)(getChildren()->objectAtIndex(0));
    bgSpr->setVisible(false);

    auto newBgSpr = CCSprite::create(GameManager::get()->getBGTexture(32));
    newBgSpr->setColor(bgSpr->getColor());
    newBgSpr->setScale(bgSpr->getScale());
    newBgSpr->setAnchorPoint(bgSpr->getAnchorPoint());
    newBgSpr->setPosition(bgSpr->getPosition());
    addChild(newBgSpr, -1);

    auto logo = (CCSprite*)(getChildren()->objectAtIndex(1));
    auto rtLogo = (CCSprite*)(getChildren()->objectAtIndex(2));

    logo->setPositionY(logo->getPositionY() + 33);
    rtLogo->setPositionY(rtLogo->getPositionY() + 25);

    auto fgLogo = CCSprite::create("GJ_breezeLogo.png");
    fgLogo->setScale(1.0f);
    fgLogo->setPosition(ccp(
        logo->getPositionX() + 152.0f,
        logo->getPositionY() - 50.0f
    ));
    addChild(fgLogo, 100);

    // game manager things
    // also some var
    auto GM = GameManager::get();

    // load def
    // bg and g
    GM->loadBackground(32);
    GM->loadGround(9);

    // disable tos
    // and shopkeeper dialog
    GM->setUGV("30", true);
    GM->setUGV("17", true);

    // set this
    // to true
    GM->m_clickedEditor = true;

    return true;
}