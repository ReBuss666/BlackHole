#pragma once
#include "scene.h"

class MenuScene : public Scene {
public:
  MenuScene(); // camera and text in fut
  ~MenuScene() override;

  SceneType update(float dt) override;
  void render() override;
};
