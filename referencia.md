---
layout: page
title: Funcionamento
order: 5
---

## Como funciona?

A função `initSDL()` inicializa as bibliotecas SDL, SDL\_ttf (permite carregar fontes e escrever texto na tela) e SDL\_image (permite carregar diversos formatos de imagem). Além disso, ela também cria a janela do programa.

A função `gameLoop()` chama a função `init()` e então entra em um loop, no qual chama repetidamente as funções `processEvent()`, `update()` e `draw()`, várias vezes por segundo. Se alguma dessas funções chamar `endGameLoop()`, o loop se encerra e a função `destroy()` é chamada.

Informações adicionais:

- **`init()`**: chamada no início da execução do programa; aqui você deve carregar arquivos (imagens, fontes, áudio), inicializar variáveis etc.
- **`destroy()`**: chamada no final da execução do programa; aqui você deve liberar os recursos, usando funções como `SDL_FreeSurface()`, `TTF_CloseFont()`, dentre outras.
- loop (executado várias vezes por segundo):
  - **`processEvent()`**: aqui você deve tratar os eventos do SDL, como pressionar um botão, fechar janela, dentre outros; essa função pode ser chamada várias vezes dentro de uma iteração do loop.
  - **`update()`**: aqui você deve atualizar a sua simulação, alterando variáveis como posições de imagens, velocidades, dentre outros; aqui também pode ser útil ler o estado de teclas e do mouse, usando funções como `SDL_GetKeyboardState()` e `SDL_GetMouseState()`.
  - **`draw()`**: aqui você vai desenhar coisas na tela; note que a função `gameLoop()` limpa a tela antes de chamar `draw()`, de forma que você precisa redesenhar tudo a cada vez.

## Funções: Guia de Referência

- Inicialização
    - **`initSDL(w, h)`**: inicializa SDL e bibliotecas relacionadas, e cria janela com largura `w` e altura `h`. Se `w` e `h` forem omitidos, considera 800x600.
- Carregamento de arquivos
    - **`loadImage(filename)`**: carrega o arquivo de imagem `filename` e retorna um `SDL_Surface*` representando a imagem. Ex.: `SDL_Surface *img = loadImage("hello.bmp")`. Ao final, a imagem deve ser liberada com `SDL_FreeSurface(img)`.
    - **`loadFont(filename, size)`**: carrega o arquivo de fonte `filename` com tamanho de `size` pontos. Ex.: `TTF_Font *font = loadFont("OpenSans.ttf", 14)`. Ao final, a fonte deve ser liberada com `TTF_CloseFont(font)`.
- Desenho
    - **`drawImage(img, x, y)`**: desenha a imagem `img` (do tipo `SDL_Surface*`) de forma que seu canto superior esquerdo fique na posição (`x`, `y`) da tela.
    - **`drawCenteredImage(img, x, y)`**: desenha a imagem `img` (do tipo `SDL_Surface*`) de forma que o seu centro fique na posição (`x`, `y`) da tela.
    - **`drawText(text, font, color, x, y)`**: escreve o texto `text` na posição (`x`, `y`) da tela, usando a fonte `font` (carregada com `loadFont()`) e a cor `color` (do tipo `SDL_Color`).
    - **`drawLine(x1, y1, x2, y2, r, g, b)`**: desenha uma linha da posição (`x1`, `y1`) até a posição (`x2`, `y2`) da tela, usando a cor (`r`, `g`, `b`), onde cada componente da cor vai de 0 a 255.
- Game loop
    - **`gameLoop()`**: executa o game loop (`processEvent`, `update`, `draw`), precedido de `init()` e sucedido por `destroy()`.
    - **`endGameLoop()`**: finaliza a executação do game loop
    - **`isQuitEvent(event)`**: indica se o evento `event` corresponde a fechar a janela ou teclar Esc.
