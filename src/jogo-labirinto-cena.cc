#include "ilpgame.h"

using namespace std;

#define MAP_WIDTH 7
#define MAP_HEIGHT 8
#define IMG_WIDTH 16
#define IMG_HEIGHT 16
#define NUM_MAPAS 2

SDL_Surface *imgbrick;
SDL_Surface *imghero;
SDL_Surface *imgstar;
TTF_Font *font;
SDL_Color whiteColor = {255, 255, 255, 255};

int mapaAtual = 0;

int map[NUM_MAPAS][MAP_HEIGHT][MAP_WIDTH] = {
  {
    {1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 1, 0, 2, 1},
    {1, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1}
  },
  {
    {1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 2, 1},
    {1, 0, 1, 0, 1, 0, 1},
    {1, 1, 1, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1}
  }
};

typedef struct {
  int x, y;
} Posicao;

Posicao player;

// cena gameover

void gameover_init();
void gameover_destroy();
void gameover_draw();
void gameover_update();
void gameover_processEvent(SDL_Event event);

///

void init() {
  imgbrick = loadImage("brick.png");
  imghero = loadImage("hero.png");
  imgstar = loadImage("star.png");

  player.x = 1;
  player.y = 1;
}

void destroy() {
  SDL_FreeSurface(imgbrick);
  SDL_FreeSurface(imghero);
  SDL_FreeSurface(imgstar);
}

void draw() {
  int x, y, telax, telay;

  for (y = 0; y < MAP_HEIGHT; y++) {
    for (x = 0; x < MAP_WIDTH; x++) {
      telax = x * IMG_WIDTH;
      telay = y * IMG_HEIGHT;
      if (map[mapaAtual][y][x] == 1) {
        drawImage(imgbrick, telax, telay);
      } else if (map[mapaAtual][y][x] == 2) {
        drawImage(imgstar, telax, telay);
      } 
    }
  }

  telax = player.x * IMG_WIDTH;
  telay = player.y * IMG_HEIGHT;
  drawImage(imghero, telax, telay);
}

void processEvent(SDL_Event event) {
  SDL_Keycode keycode;
  Posicao vel = {0, 0};

  if (isQuitEvent(event)) {
    endGameLoop();
  } else if (event.type == SDL_KEYDOWN) {
    keycode = event.key.keysym.sym;

    if (keycode == SDLK_UP) {
      vel.y--;
    }
    else if (keycode == SDLK_DOWN) {
      vel.y++;
    }
    else if (keycode == SDLK_LEFT) {
      vel.x--;
    }
    else if (keycode == SDLK_RIGHT) {
      vel.x++;
    }
  }

  // se a proxima posicao estiver vazia, atualiza posicao
  if (map[mapaAtual][player.y + vel.y][player.x + vel.x] != 1) {
    player.x += vel.x;
    player.y += vel.y;
  }

  // checa condição de vitória
  if (map[mapaAtual][player.y][player.x] == 2) {
    mapaAtual++;
    if (mapaAtual >= NUM_MAPAS) {
      changeScene(gameover);
    } else {
      changeToDefaultScene();
    }
  }
}

void update() {
}

//////////


void gameover_init() {
  font = loadFont("FreeSans.ttf", 40);
}
void gameover_destroy() {
  TTF_CloseFont(font);
}
void gameover_draw() {
  drawText("Parabens!", font, whiteColor, 10, 30);
}
void gameover_update() {
}
void gameover_processEvent(SDL_Event event) {
  if (isQuitEvent(event)) {
    endGameLoop();
  }
}




/////


int main(int argc, char *argv[]) {
  initSDL();
  gameLoop();
  return 0;
}
