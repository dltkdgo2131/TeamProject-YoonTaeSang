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
  //Texture 생성
  SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/rider.bmp");

  m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

  SDL_FreeSurface(pTempSurface);

  //원본상자의 너비/높이 설정
  // SDL_QueryTexture 함수를 이용하여 Texture의 크기 구하기
  SDL_QueryTexture(m_pTexture, NULL, NULL,
    &m_sourceRectangle.w, &m_sourceRectangle.h); // Texture의 크기로 원본상자의 너비, 높이 값 설정
  m_sourceRectangle.x = -50;
  m_sourceRectangle.y = -50;

  m_destinationRactangle.w = 50;
  m_destinationRactangle.h = 50;

  m_destinationRactangle.x = 0;
  m_destinationRactangle.y = 0;
  
  m_bRunning = true;
  return true;
}

void Game::update()
{

}

void Game::render()
{
  SDL_RenderClear(m_pRenderer); // 지정된 색으로 윈도우 지우기
  
  // 텍스쳐의 일부 영역을 Render의 일부 영역에 복사
  // 원본상자(m_sourceRectangle)의 픽셀을 대상상자(m_destinationRactangle)의 영역으로 복사
  // m_sourceRectangle: Texture의 일부 영역 정의
  // m_destinationRactangle: Redner의 일부 영역 정의

  // SDL_RenderClear()와 SDL_RenderPresent() 사이에 SDL_RenderCopy() 호출 추가
  // 화면을 지우고/SDL_RenderClear, 그리는 것/SDL_RenderCopy은 backbuffer에서 수행
  // 스크린 화면에 바로 반영되지 않음
  // SDL_RenderPresent를 호출하면 backbuffer에 그려진 최종 결과물을 화면에 게시
  SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRactangle);
  
  SDL_RenderPresent(m_pRenderer); // 이전 호출 이후 수행된 렌더링으로 화면 갱신 (더블버퍼링)

  
}

bool Game::running()
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
  SDL_Quit(); //SDL 서브 시스템 종료
}