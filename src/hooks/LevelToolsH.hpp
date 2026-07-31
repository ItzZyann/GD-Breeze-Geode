#pragma once
#include <Geode/Geode.hpp>
#include <Geode/modify/LevelTools.hpp>

class $modify(LevelToolsH, LevelTools) {
public:
    $override static GJGameLevel* getLevel(int pLevelID, bool pLoaded);
    $override static gd::string getAudioFileName(int pAudioID);
    $override static bool verifyLevelIntegrity(gd::string pStr, int pID);
};