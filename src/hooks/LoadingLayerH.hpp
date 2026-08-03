#pragma once
#include <Geode/Geode.hpp>
#include <Geode/modify/LoadingLayer.hpp>

class $modify(LoadingLayerH, LoadingLayer) {
public:
    $override bool init(bool pRefresh);
};