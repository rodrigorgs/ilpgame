#include "ilpgame.h"

using namespace std;

#define MAP_WIDTH 7
#define MAP_HEIGHT 8
#define IMG_WIDTH 16
#define IMG_HEIGHT 16

SDL_Surface *imgbrick;

int map[MAP_HEIGHT][MAP_WIDTH] = {
  {1, 1, 1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 1, 0, 0, 1},
  {1, 1, 1, 1, 1, 1, 1}
};


void init() {
  imgbrick = loadImage("brick.png");

}

void destroy() {
  SDL_FreeSurface(imgbrick);
}

void draw() {
  int x, y, telax, telay;

  for (y = 0; y < MAP_HEIGHT; y++) {
    for (x = 0; x < MAP_WIDTH; x++) {
      telax = x * IMG_WIDTH;
      telay = y * IMG_HEIGHT;
      if (map[y][x] == 1) {
        drawImage(imgbrick, telax, telay);
      }
    }
  }
}

void processEvent(SDL_Event event) {
  if (isQuitEvent(event)) {
    endGameLoop();
  } else if (event.type == SDL_MOUSEBUTTONDOWN) {
    int valor = 1;
    if (event.button.button == SDL_BUTTON_RIGHT) { 
      valor = 0;
    }
    
    int mapx = event.button.x / IMG_WIDTH;
    int mapy = event.button.y / IMG_HEIGHT;

    if (mapx >= 0 && mapx <= MAP_WIDTH && mapy >= 0 && mapy <= MAP_HEIGHT) {
      map[mapy][mapx] = valor;
    }
  }
}

void update() {
}

int main(int argc, char *argv[]) {
  initSDL();
  gameLoop();
  return 0;
}
