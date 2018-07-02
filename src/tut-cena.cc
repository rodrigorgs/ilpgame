#include "ilpgame.h"

TTF_Font *font;
SDL_Color whiteColor = {255, 255, 255, 255};

// Declarações de cenas

void jogo_init();
void jogo_destroy();
void jogo_processEvent(SDL_Event event);
void jogo_update();
void jogo_draw();

// Cena "main"

void init() {
  cout << "init" << endl;
  font = loadFont("FreeSans.ttf", 40);
}

void destroy() {
  cout << "destroy" << endl;
  TTF_CloseFont(font);
}

void processEvent(SDL_Event event) {
  SDL_Keycode keycode;

  if (isQuitEvent(event)) {
    endGameLoop();
  } else if (event.type == SDL_KEYDOWN) {
    keycode = event.key.keysym.sym;
    if (keycode == SDLK_RETURN) changeScene(jogo);
  }
}

void update() {
}

void draw() {
  drawText("Pressione Enter para iniciar", font, whiteColor, 10, 30);
}

// Cena "jogo"

void jogo_init() {
  cout << "jogo_init" << endl;
  font = loadFont("FreeSans.ttf", 40);
}
void jogo_destroy() {
  cout << "jogo_destroy" << endl;
  TTF_CloseFont(font);
}
void jogo_processEvent(SDL_Event event) {
  SDL_Keycode keycode;

  if (isQuitEvent(event)) {
    endGameLoop();
  } else if (event.type == SDL_KEYDOWN) {
    keycode = event.key.keysym.sym;
    if (keycode == SDLK_RETURN) changeToDefaultScene();
  }
}
void jogo_update() {
}
void jogo_draw() {
  drawText("Jogo iniciado. Pressione Enter voltar", font, whiteColor, 10, 30);
}

// programa principal

int main(int argc, char *argv[]) {
  initSDL();
  gameLoop();

  return 0;
}

