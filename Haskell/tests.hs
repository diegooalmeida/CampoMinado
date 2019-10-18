import System.Random
import Data.Typeable
import Auxiliar

main :: IO()
main = do
    
    g <- newStdGen
    let (a,b) = randomR (1,999999 :: Int) g
    let semente1 = a

    h <- newStdGen
    let (c,d) = randomR (1,999999 :: Int) h
    let semente2 = c

    print (semente1)
    print (semente2)

    print (Auxiliar.geraNumeroAleatorio 9 semente1)
    print (Auxiliar.geraNumeroAleatorio 9 semente2)

    
    let tuplas = Auxiliar.geraPosicoesAleatorias 10 10 6 semente1 semente2 []

    print (tuplas)

