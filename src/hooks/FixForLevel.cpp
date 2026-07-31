#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/modify/EndLevelLayer.hpp>
#include "../classes/CustomLevelSelect.hpp"

using namespace geode::prelude;

class $modify(PauseLayer) {
public:
	void onQuit(CCObject* pSender) {
		auto GM = GameManager::sharedState();
		auto levelID = GM->m_playLayer->m_level->m_levelID;

		if (levelID > 6000 && levelID < 6013) {
			auto scene = CCScene::create();
			scene->addChild(CustomLevelSelect::create(levelID - 6001));

			CCDirector::get()
            ->replaceScene(
                CCTransitionFade::create(0.5f, scene)
            );
		}

		PauseLayer::onQuit(pSender);
	}
};

class $modify(EndLevelLayer) {
public:
	void onMenu(CCObject* pSender) {
		auto GM = GameManager::get();
		auto levelID = GM->m_playLayer->m_level->m_levelID;

		if (levelID > 6000 && levelID < 6013) {
			auto scene = CCScene::create();
			scene->addChild(CustomLevelSelect::create(levelID - 6001));

			CCDirector::get()
            ->replaceScene(
                CCTransitionFade::create(0.5f, scene)
            );
		}

		EndLevelLayer::onMenu(pSender);
	}
};