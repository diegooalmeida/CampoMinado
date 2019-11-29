# CampoMinado
Repositório para o projeto da cadeira de Paradigmas de Linguagens de Programação onde desenvolveremos um jogo de Campo Minado em: C++, Haskell e Prolog.

##### Para rodar o código em Haskell, siga o passo a passo para instalar as bibliotecas neecssárias.
 Primeiro é preciso ter o cabal instalado, pois é ele que irá instalar as bibliotecas: 

```
$ sudo apt install cabal-install
$ cabal update
```
Em seguida, use o cabal para instalar as bibliotecas Random e ExitCode:

```
$ cabal install random
$ cabal install exitcode
```

Em seguida, é só dar runhaskell campoMinado.hs e seguir as instruções do jogo.

##### Para rodar código em Prolog:
Compile o código:

```
$ swipl -q -f campo.pl
```

Chame a função iniciar, passando os parâmetros desejados para o campo (número de linhas, número de colunas e número de bombas):

```
$ iniciar(numLinhas, numColunas, numBombas).
```

A partir de agora, siga as instruções que aparecem no código sobre os tipos de jogadas.
