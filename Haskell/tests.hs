main :: IO()
main = do
    input <- getLine
    let infos = words input
    let linhas = infos !! 0
    let colunas = infos !! 1
    let bombas = infos !! 2
    print ("linhas: " ++ linhas)
    print ("colunas: " ++ colunas)
    print ("bomas: " ++ bombas)
