#!/bin/bash
g++ -c tut-arquivo1.cc tut-arquivo2.cc -std=c++11 `sdl2-config --cflags`
g++ tut-arquivo1.o tut-arquivo2.o `sdl2-config --libs` -lSDL2_ttf -lSDL2_image -lSDL2_mixer