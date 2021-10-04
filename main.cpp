#include <SDL.h>

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;
bool g_bRunning = false;

bool init(const char* title, int xpos, int ypos,
int height, int width, int flag);
void render();

int main(int argc, char* args[])
{
  if(init("Breaking Up HelloSDL",
          SDL_WINDOWPOS_CENTERED,
          SDL_WINDOWPOS_CENTERED,
          640, 480,
          SDL_WINDOW_SHOWN))
  {
    g_bRunning = true;
  }
  else
  {
    return 1; // 문제가 생겼을 때
  }

  while (g_bRunning)
  {
    // 입력 - 갱신 - 출력
    render();
  }
  SDL_Quit();
  return 0;
}