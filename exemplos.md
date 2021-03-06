---
layout: page
title: Exemplos
order: 4
---

Alguns exemplos requerem arquivos adicionais, como imagens, áudio ou fontes. Todos os arquivos podem ser encontrados em <https://github.com/rodrigorgs/ilpgame/tree/master/src>.

Exemplos básicos:

- [Carregar e mostrar uma imagem](src/tut-imagem.cc) (aperte Esc para sair)
- [Movimentar imagem ao pressionar tecla direcional](src/tut-keypress.cc)
- [Movimentar imagem de acordo com o estado das teclas direcionais](src/tut-keystate.cc) (experimente andar na diagonal)
  + Veja também os códigos de teclas na [documentação do SDL_Keycode](src/https://wiki.libsdl.org/SDL_Keycode).
- [Desenhar imagem sob o cursor do mouse](src/tut-mouse.cc) (ao segurar o botão esquerdo do mouse, a imagem muda), [Editor de pixel art (clicar desenha ou apaga, dependendo se foi o botão esquerdo ou direito do mouse)](src/tut-pixel-art.cc)
- [Desenhar texto](src/tut-texto.cc)
- [Escrever com o teclado](src/tut-escreve.cc): aceita teclas de A a Z e backspace
- [Contador de tempo](src/tut-timer.cc)
- [Limitar FPS](src/tut-limitfps.cc): limita a taxa de atualização do jogo (FPS) para que ele rode na mesma velocidade em todos os computadores
- [Áudio](src/tut-audio.cc)
- Como usar a ILP Game em projetos com múltiplos arquivos `.cc`/`.cpp`: [tut-arquivo1.cc](src/tut-arquivo1.cc), [tut-arquivo1.cc](src/tut-arquivo1.cc), [tut-arquivo.h](src/tut-arquivo.h)
- [Exemplo simples com cenas](src/tut-cena.cc), [jogo de labirinto com cenas](src/jogo-labirinto-cena.cc)

Demonstrações:

- [Bola quicando](src/demo-quica.cc): simula gravidade e coeficiente de restituição
- [Carro](src/demo-carro.cc): controle um carro usando as setas direcionais
- [Animação](src/demo-anima.cc): animação de uma pessoa andando formada por 4 imagens

Jogos:

- [Labirinto](src/jogo-labirinto.cc): movimente com setas direcionais, [Labirinto com itens](src/jogo-labirinto-itens.cc)
- [Runner](src/jogo-runner.cc): mova para os lados para se desviar dos obstáculos

