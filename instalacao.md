---
layout: page
title: Instalação
order: 2
---

Antes de usar a ILP Game, você precisa instalar suas dependências:

- compilador de C++ compatível com C++11 ou mais recente (preferencialmente o g++)
- biblioteca SDL2
- biblioteca SDL2\_image
- biblioteca SDL2\_ttf
- biblioteca SDL2\_mixer

Uma vez instaladas as dependências, basta copiar o arquivo [ilpgame.h](https://github.com/rodrigorgs/ilpgame/src/ilpgame.h) para o diretório onde está o seu arquivo fonte (`.c`, `.cc` ou `.cpp`).

As seções seguintes explicam como instalar as dependências no Windows, no Linux e no macOS.

## Windows

A biblioteca ILP Game foi testada com o ambiente MinGW (32-bit), que fornece o compilador g++ para Windows. As instruções estão disponíveis em dois vídeos:

- [Instalação do compilador de C++ (MinGW)](https://youtu.be/bEs-5IU_l9w) (vídeo)
- [Instalação da SDL (vídeo)](https://youtu.be/gvEWGHAPO8k) (vídeo)

## Linux

As instruções desta página são para Debian Linux, Ubuntu Linux ou outra distribuição Linux derivada.

Para instalar o compilador g++:

```bash
sudo apt-get install g++
```

Para instalar as bibliotecas:

```
sudo apt-get install libsdl2*dev
```

## macOS

Para instalar o compilador de C++, siga as instruções:

- Instale o [Xcode](https://developer.apple.com/xcode/).
- Abra um terminal e execute o comando `g++`.
- Siga as instruções para instalar o "command line developer tools".

Para instalar as bibliotecas, primeiramente, instale o gerenciador de pacotes [Homebrew](https://brew.sh/). Por fim, execute o seguinte comando no terminal:

```bash
brew install sdl2 sdl2_image sdl2_mixer sdl2_ttf
```
