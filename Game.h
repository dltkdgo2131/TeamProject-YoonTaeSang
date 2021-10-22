#pragma once
#include "SDL.h"
#include "vector"
#include "TextureManager.h"
#include "SDLGameObject.h"
#include "Player.h"
#include "Enemy.h"
class Game
{
private:
  Game() {}
  static Game* s_pInstance;

  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;
  bool m_bRunning;
  int m_currentFrame;
//게임 오브젝트 생성
  std::vector<SDLGameObject*> m_gameObjects;
public:
  ~Game() {}
  static Game* Instance(){
    if (s_pInstance == 0)
    s_pInstance = new Game();
    return s_pInstance;
  }
  SDL_Renderer* getRenderer() const {
    return m_pRenderer;
  }

  bool init(const char* title, int xpos, int ypos,
 int height, int width, int flag) ;
  void render();
  void update();
  bool running();
  void handleEvents();
  void clean();

};
typedef Game TheGame;