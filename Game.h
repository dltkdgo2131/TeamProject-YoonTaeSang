#pragma once
#include "SDL.h"

Class Game
{
public:
  Game() {}
  ~Game() {}

  bool init();
  void render();
  void update();
  void running();
  void handleEvents();
  void clean();

private:
  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;
  bool m_bRunning;
}