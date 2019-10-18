module Textos
( 
mensagemBemVindo
mensagemPerdeu
mensagemVenceu
mainMenu
menuCreditos
menuInstrucoes
)where


<<<<<<< HEAD
=======
mensagemCreditos::String
mensagemCreditos = "\n|-----------------------------------------------------------------------------|\n
                    |                                PLP 2019.2                                     |\n
                    |                           Everton L. G. Alves                                 |\n
                    |                                  Grupo:                                       |\n
                    |                           Diego Ribeiro Almeida                               |\n
                    |                            Iago Tito Oliveira                                 |\n
                    |                         Paulo Mateus Alves Moreira                            |\n
                    |                         Raiany Rufino Costa da Paz                            |\n
                    |-------------------------------------------------------------------------------|\n" 
>>>>>>> 986c445cc654724658d6756061fb744c094c9744



<<<<<<< HEAD
mensagemBemVindo :: String 
mensagemBemVindo = do
	putStr "██████╗ ███████╗███╗   ███╗    ██╗   ██╗██╗███╗   ██╗██████╗  ██████╗ " 
	putStr "██╔══██╗██╔════╝████╗ ████║    ██║   ██║██║████╗  ██║██╔══██╗██╔═══██╗" 
	putStr "██████╔╝█████╗  ██╔████╔██║    ██║   ██║██║██╔██╗ ██║██║  ██║██║   ██║" 
	putStr "██╔══██╗██╔══╝  ██║╚██╔╝██║    ╚██╗ ██╔╝██║██║╚██╗██║██║  ██║██║   ██║" 
	putStr "██████╔╝███████╗██║ ╚═╝ ██║     ╚████╔╝ ██║██║ ╚████║██████╔╝╚██████╔╝" 
    putStr "╚═════╝ ╚══════╝╚═╝     ╚═╝      ╚═══╝  ╚═╝╚═╝  ╚═══╝╚═════╝  ╚═════╝ " 
=======
instrucoesJogo::String
instrucoesJogo = "\n|-----------------------------------------------------------------------------|\n
                    |                           Instruções do Jogo                                |\n
                    |                R - Revela, exemplo: R A 2 - Revela posição A2.              |\n
                    |                F - Flag, exemplo: F A 2 - Insere uma flag na posição A2.    |\n
                    |                ? - Interrogação: ? A 2 - Insere uma ? na posição A2.        |\n
                    |-----------------------------------------------------------------------------|\n" 
>>>>>>> 986c445cc654724658d6756061fb744c094c9744

    
mensagemPerdeu :: String 
mensagemPerdeu = do
    putStr "██╗   ██╗ ██████╗  ██████╗███████╗    ██████╗ ███████╗██████╗ ██████╗ ███████╗██╗   ██╗██╗ " 
    putStr "██║   ██║██╔═══██╗██╔════╝██╔════╝    ██╔══██╗██╔════╝██╔══██╗██╔══██╗██╔════╝██║   ██║██║ "  
    putStr "██║   ██║██║   ██║██║     █████╗      ██████╔╝█████╗  ██████╔╝██║  ██║█████╗  ██║   ██║██║ " 
    putStr "╚██╗ ██╔╝██║   ██║██║     ██╔══╝      ██╔═══╝ ██╔══╝  ██╔══██╗██║  ██║██╔══╝  ██║   ██║╚═╝ " 
    putStr " ╚████╔╝ ╚██████╔╝╚██████╗███████╗    ██║     ███████╗██║  ██║██████╔╝███████╗╚██████╔╝██╗ " 
    putStr "  ╚═══╝   ╚═════╝  ╚═════╝╚══════╝    ╚═╝     ╚══════╝╚═╝  ╚═╝╚═════╝ ╚══════╝ ╚═════╝ ╚═╝ "

mensagemVenceu :: String
mensagemVenceu = do
    putStr "██╗   ██╗ ██████╗  ██████╗███████╗    ██╗   ██╗███████╗███╗   ██╗ ██████╗███████╗██╗   ██╗██╗" 
    putStr "██║   ██║██╔═══██╗██╔════╝██╔════╝    ██║   ██║██╔════╝████╗  ██║██╔════╝██╔════╝██║   ██║██║" 
    putStr "██║   ██║██║   ██║██║     █████╗      ██║   ██║█████╗  ██╔██╗ ██║██║     █████╗  ██║   ██║██║" 
    putStr "╚██╗ ██╔╝██║   ██║██║     ██╔══╝      ╚██╗ ██╔╝██╔══╝  ██║╚██╗██║██║     ██╔══╝  ██║   ██║╚═╝" 
    putStr " ╚████╔╝ ╚██████╔╝╚██████╗███████╗     ╚████╔╝ ███████╗██║ ╚████║╚██████╗███████╗╚██████╔╝██╗" 
    putStr "  ╚═══╝   ╚═════╝  ╚═════╝╚══════╝      ╚═══╝  ╚══════╝╚═╝  ╚═══╝ ╚═════╝╚══════╝ ╚═════╝ ╚═╝" 
    

mainMenu :: String
mainMenu = do
    putStr "" 
    putStr "|-----------------------------------------------------------------------------|" 
    putStr "|                                 Menu                                        |" 
    putStr "|                           (1) Iniciar Jogo                                  |" 
    putStr "|                           (2) Créditos                                      |" 
    putStr "|                           (3) Instruções do Jogo                            |" 
    putStr "|                           (4) Sair do Jogo                                  |" 
    putStr "|-----------------------------------------------------------------------------|" 

menuCreditos :: String
menuCreditos = do
    putStr "" 
    putStr "|-----------------------------------------------------------------------------|" 
    putStr "|                                 PLP 2019.2                                  |" 
    putStr "|                            Everton L. G. Alves                              |" 
    putStr "|                                                                             |" 
    putStr "|                                  Grupo:                                     |" 
    putStr "|                          Diego Ribeiro de Almeida                           |" 
    putStr "|                             Iago Tito Oliveira                              |" 
    putStr "|                        Paulo Mateus Alves Moreira                           |" 
    putStr "|                        Raiany Rufino Costa da Paz                           |" 
    putStr "|-----------------------------------------------------------------------------|" 


menuInstrucoes :: String
menuInstrucoes = do
    putStr "" 
    putStr "|-----------------------------------------------------------------------------|" 
    putStr "|                          Instruçoes do Jogo                                 |" 
    putStr "|                                                                             |" 
    putStr "|              R - Revela, exemplo: R A 2 - Revela posição A2.                |" 
    putStr "|              F - Flag, exemplo: F A 2 - Insere uma flag na posição A2.      |" 
    putStr "|              ? - Interrogação: ? A 2 - Insere uma ? na posição A2.          |" 
    putStr "|-----------------------------------------------------------------------------|" 
