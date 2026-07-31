#include "LevelToolsH.hpp"
#include <Geode/Enums.hpp>
#include <Geode/binding/GJGameLevel.hpp>
#include <Geode/binding/LocalLevelManager.hpp>
using namespace geode::prelude;

GJGameLevel* LevelToolsH::getLevel(int pLevelID, bool pLoaded) {
    auto level = GJGameLevel::create();

    switch (pLevelID) {
        case 6001:
            level->m_levelName = "Over The Clouds";
            level->m_audioTrack = 101;
            level->m_stars = 3;
            level->m_difficulty = GJDifficulty::Normal;
            break;

        case 6002:
            level->m_levelName = "into the zone";
            level->m_audioTrack = 102;
            level->m_stars = 5;
            level->m_difficulty = GJDifficulty::Hard;
            break;

        case 6003:
            level->m_levelName = "Ghost Ship";
            level->m_audioTrack = 103;
            level->m_stars = 6;
            level->m_difficulty = GJDifficulty::Harder;
            break;

        case 6004:
            level->m_levelName = "Bitsplosion";
            level->m_audioTrack = 104;
            level->m_stars = 9;
            level->m_difficulty = GJDifficulty::Insane;
            break;

        case 6005:
            level->m_levelName = "Skittles";
            level->m_audioTrack = 105;
            level->m_stars = 6;
            level->m_difficulty = GJDifficulty::Harder;
            break;

        case 6006:
            level->m_levelName = "Hydra";
            level->m_audioTrack = 106;
            level->m_stars = 8;
            level->m_difficulty = GJDifficulty::Insane;
            break;

        case 6007:
            level->m_levelName = "Cloud Buster";
            level->m_audioTrack = 107;
            level->m_stars = 7;
            level->m_difficulty = GJDifficulty::Harder;
            break;

        case 6008:
            level->m_levelName = "Level Up";
            level->m_audioTrack = 108;
            level->m_stars = 7;
            level->m_difficulty = GJDifficulty::Harder;
            break;

        case 6009:
            level->m_levelName = "Prism";
            level->m_audioTrack = 109;
            level->m_stars = 8;
            level->m_difficulty = GJDifficulty::Insane;
            break;

        case 6010:
            level->m_levelName = "Peer Gynt";
            level->m_audioTrack = 110;
            level->m_stars = 9;
            level->m_difficulty = GJDifficulty::Insane;
            break;

        case 6011:
            level->m_levelName = "Ghost Retention";
            level->m_audioTrack = 111;
            level->m_stars = 6;
            level->m_difficulty = GJDifficulty::Harder;
            break;

        case 6012:
            level->m_levelName = "Anaconda";
            level->m_audioTrack = 112;
            level->m_stars = 5;
            level->m_difficulty = GJDifficulty::Hard;
            break;

        default:
            return LevelTools::getLevel(pLevelID, pLoaded);
    }

    level->m_levelID = pLevelID;
    level->m_coins = 3;
    level->m_levelType = GJLevelType::Main;
    level->m_levelString = LocalLevelManager::get()->getMainLevelString(pLevelID);

    return level;
}

gd::string LevelToolsH::getAudioFileName(int pAudioID) {
    switch (pAudioID) {
        case 101: return "PixelPig.mp3"_spr;
        case 102: return "IntoTheZone.mp3"_spr;
        case 103: return "GhostShip.mp3"_spr;
        case 104: return "Bitsplosion.mp3"_spr;
        case 105: return "Skittles.mp3"_spr;
        case 106: return "Hydra.mp3"_spr;
        case 107: return "CloudBuster.mp3"_spr;
        case 108: return "LevelUp2.mp3"_spr;
        case 109: return "Prism.mp3"_spr;
        case 110: return "PeerGynt.mp3"_spr;
        case 111: return "GhostRetention.mp3"_spr;
        case 112: return "Anaconda.ogg"_spr;

        default:
            return LevelTools::getAudioFileName(pAudioID);
    }
}

bool LevelToolsH::verifyLevelIntegrity(gd::string pStr, int pID) { return true; }