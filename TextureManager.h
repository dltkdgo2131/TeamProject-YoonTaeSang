#include "SDL.h"
#include "string"
#include "map"

using namespace std;
class TextureManager{
public:

  TextureManager() {}
  ~TextureManager() {}

  bool load(string fileName, string id, SDL_Renderer* pRenderer);

  void draw(string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

  void drawFrame(string id, int x, int y, int width, int height, int currentRow, int currentFrame,
  SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
  map<string, SDL_Texture*> m_textureMap;
};