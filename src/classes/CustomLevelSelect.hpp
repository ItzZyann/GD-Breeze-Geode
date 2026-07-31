#pragma once
#include <Geode/Geode.hpp>

class CustomLevelSelect : public LevelSelectLayer {
public:
    static CustomLevelSelect* create(int pPage);
    static cocos2d::CCScene* scene(int pPage);
    
    bool init(int pPage);
};