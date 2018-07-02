#!/bin/bash
# Usado para fins de testes

echo "tut-arquivo[12].cc"
./build-tut2arquivos.sh

for x in `ls tut-*.cc jogo-*.cc demo-*.cc | grep -v "arquivo[12]"`; do
  echo $x
  ./compila.sh $x
done

