module Auxiliar
(
matriz
,ran
,add
,getRandomInt
)where

import System.IO.Unsafe
import System.Random

geraTuplaAleatoria :: Int -> Int -> [(Int, Int)] -> (Int, Int)
geraTuplaAleatoria linhas colunas lista
    | (x, y) `elem` lista = geraTuplaAleatoria linhas colunas lista
    | otherwise = (x, y)
    where x = getRandomR (1, linhas)
          y = getRandomR (1, colunas)

geraPosicoesAleatorias :: Int -> Int -> Int -> [(Int, Int)]
geraPosicoesAleatorias linhas colunas 0 lista = []
geraPosicoesAleatorias linhas colunas bombas lista =
    (geraTuplaAleatoria linhas colunas lista) ++ geraPosicoesAleatorias linhas colunas (bombas-1)
