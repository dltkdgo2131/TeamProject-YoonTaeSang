#include "Game.h"

//전달받은 인자를 이용하여 Window, Renderer 생성
//각종 초기화, 그리기 색 지정
bool Game::init(const char* title, int xpos, int ypos,
 int height, int width, int flag) 
{
  if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
  {
    m_pWindow = SDL_CreateWindow( title, 
    xpos, ypos,
    width, height,
    flag);

    if(m_pWindow != 0)
    {
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

      if(m_pRenderer != 0)
      {
        SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
      } else{
        return false;
      }
    } else{
      return false;
    }
  } else{
    return false;
  }

  m_bRunning = true;
  return true;
}

void Game::update()
{

}

void Game::render()
{
  SDL_RenderClear(m_pRenderer); // 지정된 색으로 윈도우 지우기
  SDL_RenderPresent(m_pRenderer); // 이전 호출 이후 수행된 렌더링으로 화면 갱신 (더블버퍼링)
}

void Game::running()
{
  return m_bRunning;
}

//이벤트 처리를 위한 함수
//정상적인 애플리케이션 종료를 위해 SDL_QUIT 이벤트 처리 구현
//윈도우 종료(x 버튼) 클릭 시 게임루프 종료
void Game::handleEvents()
{
  SDL_Event event;
  if(SDL_PollEvent(&event)){
    switch(event.type)
    {
      case SDL_QUIT:
        m_bRunning = false;
        break;
      default:
        break;
    }
  }
}

void Game::clean()
{
  SDL_DestroyWindow(m_pWindow); //윈도우 삭제
  SDL_DestroyRenderer(m_pRenderer); //렌더러 삭제
  SDL_QUIT(); //SDL 서브 시스템 종료
}