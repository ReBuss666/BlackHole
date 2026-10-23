#pragma once

// scene state after update
enum class SceneType { NONE, MENU, SIM_2D, SIM_3D, EXIT };

class Scene {
public:
  virtual ~Scene() = default; // чтобы память наследников очищалась правильно
  virtual SceneType update(float dt) = 0;
  virtual void render() = 0;
};
