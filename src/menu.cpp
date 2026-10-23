#include "menu.h"
#include <iostream>

MenuScene::MenuScene() { std::cout << "Menu initialized\n"; }

MenuScene::~MenuScene() { std::cout << "Menu destroyed\n"; }

SceneType MenuScene::update(float dt) {
  // Handle menu logic here
  return SceneType::NONE;
}

void MenuScene::render() {
  // Glclear and ui
}
