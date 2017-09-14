---
layout: page
title: Compilação
order: 3
---

Para compilar um programa que usa a biblioteca ILP Game, primeiramente abra um terminal (console, prompt de comando). Assumindo que seu arquivo fonte tem o nome `alomundo.cpp`, execute o comando de acordo com seu sistema operacional:

### Linux ou macOS

```bash
g++ alomundo.cpp -o alomundo `sdl2-config --cflags --libs` -lSDL2_ttf -lSDL2_image -lSDL2_mixer
```

Para rodar, basta executar o comando `./alomundo`.

## Windows (com MinGW)

```bash
g++ alomundo.cpp -o alomundo -I "C:\MinGW\include\SDL2" -mwindows -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer
```

(Se você tiver instalado o MinGW em um local diferente de `C:\MinGW`, altere o comando.)

Para rodar, basta executar o arquivo `alomundo.exe`.