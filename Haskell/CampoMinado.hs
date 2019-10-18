import Textos
import System.Random
--import Auxiliar

type Coordenadas = (Int, Int)
type Valor = Int
type Elem = (Coordenadas,Valor)
type Matriz = [Elem]

-- Cria uma matriz de valores igual ao terceiro parametro
criaMatriz:: Int -> Int -> Int -> Matriz
criaMatriz a b c = [((x,y), c) | x <-[1,2..a], y <-[1,2..b]]

-- Retorna uma lista de inteiros com os valores da linha passada como parametro
pegaValoresDaLinha :: Int -> Int -> Matriz -> [Int]
pegaValoresDaLinha linha 0 matriz = []
pegaValoresDaLinha linha coluna (((x, y), v):mtz)
    | linha == x = v:pegaValoresDaLinha linha (coluna-1) mtz
    | otherwise = pegaValoresDaLinha linha coluna mtz

-- O nome diz a que veio
converteListaIntParaString :: [Int] -> String
converteListaIntParaString [] = ""
converteListaIntParaString (h:t) = show h ++ " " ++ converteListaIntParaString t

-- Cria uma representacao em String da matriz passada como parametro.
-- Requer tambem as dimensoes da matriz
pegaValoresDaMatriz :: Int -> Int -> Int -> Matriz -> String
pegaValoresDaMatriz linha linhas colunas matriz
    | linha == (linhas+1) = ""
    | otherwise = converteListaIntParaString (pegaValoresDaLinha linha colunas matriz) ++ "\n" ++ pegaValoresDaMatriz (linha+1) linhas colunas matriz

-- Imprime a matriz, mas precisa saber as dimensoes dela
-- TODO: precisa fazer as conversoes de numeros para os simbolos usados (-1 = bomba, -2 = nao revelado...)
imprimeMatriz :: Int -> Int -> Matriz -> IO()
imprimeMatriz linhas colunas matriz = putStrLn (pegaValoresDaMatriz 1 linhas colunas matriz)

--inicia_jogo :: Int -> Int -> Int -> Int -> Matriz -> IO()
--inicia_jogo linhas colunas bombas semente campo_minado = do
--    let posicoes_aleatorias = Auxiliar.geraPosicoesAleatorias linhas colunas bombas semente []


main :: IO()
main = do
    Textos.mensagemBemVindo
    menu

    entrada <- getLine
    let info = words entrada
    let linhas = read (info !! 0) :: Int
    let colunas = read (info !! 1) :: Int
    let bombas = read (info !! 2) :: Int

    g <- newStdGen
    let (a,b) = randomR (1,999999 :: Int) g
    let semente = a

    -- <><><><>
    print ("linhas: " ++ show linhas)
    print ("colunas: " ++ show colunas)
    print ("bombas: " ++ show bombas)
    -- <><><><>

    let campo_minado = criaMatriz linhas colunas 0

    imprimeMatriz linhas colunas campo_minado

    --inicia_jogo linhas colunas bombas semente campo_minado

menu :: IO()
menu = do
    Textos.mainMenu
    escolha <- getLine
    
    if(escolha == "1") then do
        putStrLn "inicia_jogo"
    else if(escolha == "2") then do
        Textos.menuCreditos
        menu
    else if(escolha == "3") then do
        Textos.menuInstrucoes
        menu
    else if(escolha == "4") then do 
        return()
    else
        putStrLn "Opção inválida"
        