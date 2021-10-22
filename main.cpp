#include "Game.h"

int main(int argc, char* args[])
{
  TheGame::Instance()->init("Chapter 1", 100, 100, 640, 480, 0);
  while(TheGame::Instance()->running())
  {
    TheGame::Instance()->handleEvents();
    TheGame::Instance()->update();
    TheGame::Instance()->render();
    SDL_Delay(10);
  }
  TheGame::Instance()->clean();
  return 0;
}