---
layout: page
title: Apresentação
order: 1
---

## O que é?

A **ILP Game** é uma biblioteca de funções C++ que simplificam o desenvolvimento de aplicações multimídia com a biblioteca [SDL](https://www.libsdl.org/). Ela foi desenvolvida por [Rodrigo Rocha](https://rodrigorgs.github.io/) para apoiar a disciplina "Introdução à Lógica de Programação" do [DCC](http://www.dcc.ufba.br/)-[UFBA](https://ufba.br/).

A ILP Game possui poucas funções; na prática, você ainda precisará usar a SDL diretamente em várias situações, seguindo as orientações [nestes slides](https://rodrigorgs.github.io/aulas/mata37/sdl/) e na [documentação da SDL](https://wiki.libsdl.org/APIByCategory).

## Como usar?

Para usar, copie o arquivo [ilpgame.h](src/ilpgame.h) para o diretório onde está o seu arquivo fonte (`.c`, `.cc` ou `.cpp`).

Um programa mínimo que usa a ILP Game (abre uma janela e fecha imediatamente) tem o seguinte formato:

```c++
#include "ilpgame.h"

void init() {
}

void destroy() {
}

void processEvent(SDL_Event event) {
}

void update() {
}

void draw() {
}

int main(int argc, char *argv[]) {
  initSDL();
  gameLoop();
  return 0;
}
```

OBS.: Se você tiver múltiplos arquivos `.cc` ou `.cpp`, insira a linha `#define ILPGAME_HEADER_ONLY` antes do `#include` em todos os seus arquivos `.cc`/`.cpp` exceto um.

## Orientações

- [Dependências e instalação](instalacao): o que você precisa fazer antes de usar a ILP Game
- [Compilação](compilacao): como compilar um programa com ILP Game
- [Exemplos](exemplos): exemplos de uso da ILP Game
- [Funcionamento e referência](referencia): como funciona a ILP Game e que funções estão disponíveis

