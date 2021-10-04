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

//전달받은 인자를 이용하여 Window, Renderer 생성
//각종 초기화, 그리기 색 지정
bool init(const char* title, int xpos, int ypos,
 int height, int width, int flag) 
{
  if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
  {
    g_pWindow = SDL_CreateWindow( title, 
    xpos, ypos,
    width, height,
    flag);

    if(g_pWindow != 0)
    {
      g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
    }
  }
  else
  {
    return false;
  }

  SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

  return true;
}

void render()
{
  SDL_RenderClear(g_pRenderer); // 지정된 색으로 윈도우 지우기
  SDL_RenderPresent(g_pRenderer); // 이전 호출 이후 수행된 렌더링으로 화면 갱신 (더블버퍼링)
}