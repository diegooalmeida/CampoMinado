import System.Random
import Data.Typeable
import Auxiliar

type Coordenadas = (Int, Int)
type Valor = Int
type Elem = (Coordenadas,Valor)
type Matriz = [Elem]

main :: IO()
main = do
    
    let m = [((1,1),0), ((1,2),2), ((4,5),10)]
    let x = 1
    let y= 2
    print 

