#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "menu.h"
#include "scene.h"

GLFWwindow *initWindow(int width, int height, const char *title) {
  if (!glfwInit()) {
    std::cerr << "Failed to initialize GLFW\n";
    return nullptr;
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window = glfwCreateWindow(width, height, title, nullptr, nullptr);
  if (!window) {
    std::cerr << "Failed to create window\n";
    glfwTerminate();
    return nullptr;
  }

  glfwMakeContextCurrent(window);
  glewExperimental = GL_TRUE;

  if (glewInit() != GLEW_OK) {
    std::cerr << "Failed to initialize GLEW\n";
    glfwDestroyWindow(window);
    glfwTerminate();
    return nullptr;
  }

  return window;
}

int main() {
  // GLFW Initialize
  GLFWwindow *window = initWindow(800, 600, "BlackHole");
  if (!window)
    return -1;

  // Initialize of system scenes
  Scene *activeScene = new MenuScene();
  double lastTime = glfwGetTime();

  while (!glfwWindowShouldClose(window)) {
    double now = glfwGetTime();
    float dt = static_cast<float>(now - lastTime);
    lastTime = now;

    // physic and logic of curr state:
    SceneType nextScene = activeScene->update(dt);

    // active scene toggler
    if (nextScene != SceneType::NONE)
      delete activeScene;

    switch (nextScene) {
    case SceneType::MENU:
      activeScene = new MenuScene();
      break;
    case SceneType::SIM_2D:
      // activeScene = new Sim2DScene();
      break;
    case SceneType::EXIT:
      glfwSetWindowShouldClose(window, true);
      break;
    default:
      break;
    }
    // render curr scene:
    activeScene->render();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // cleaning up after:
  delete activeScene;
  glfwTerminate();

  return 0;
}
