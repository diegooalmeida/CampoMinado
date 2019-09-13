#include <iostream>
#include "tabuleiro.h"
using namespace std;

/*
	Devido a impossibilidade de passarmos uma matriz com tamanho definido em tempo de execucao para uma funcao
	em C++, vamos simular uma matriz usando um vetor.

	Dessa forma, em vez de criamos ma matriz como:

		matriz[linhas][colunas];

	Criaremos:

		vetor[linhas * colunas];

	E em vez de acessarmos a posiçao como:

		matriz[i][j];

	Acessaremos usando:

		vetor[i*linhas + j];

	Isso facilitará o entendimento do codigo pois aumentara o encapsulamento do mesmo.
*/


// -=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=- Layouts -=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=- //
// Apresentacao inicial
void mensagem_apresentacao() {
	cout << endl;
	cout << "██████╗ ███████╗███╗   ███╗    ██╗   ██╗██╗███╗   ██╗██████╗  ██████╗ " << endl;
	cout << "██╔══██╗██╔════╝████╗ ████║    ██║   ██║██║████╗  ██║██╔══██╗██╔═══██╗" << endl;
	cout << "██████╔╝█████╗  ██╔████╔██║    ██║   ██║██║██╔██╗ ██║██║  ██║██║   ██║" << endl;
	cout << "██╔══██╗██╔══╝  ██║╚██╔╝██║    ╚██╗ ██╔╝██║██║╚██╗██║██║  ██║██║   ██║" << endl;
	cout << "██████╔╝███████╗██║ ╚═╝ ██║     ╚████╔╝ ██║██║ ╚████║██████╔╝╚██████╔╝" << endl;
	cout << "╚═════╝ ╚══════╝╚═╝     ╚═╝      ╚═══╝  ╚═╝╚═╝  ╚═══╝╚═════╝  ╚═════╝ " << endl;
}
// Perdeu o jogo
void mensagem_perdeu(){
    cout << endl;
    cout << "██╗   ██╗ ██████╗  ██████╗███████╗    ██████╗ ███████╗██████╗ ██████╗ ███████╗██╗   ██╗██╗ " << endl;
    cout << "██║   ██║██╔═══██╗██╔════╝██╔════╝    ██╔══██╗██╔════╝██╔══██╗██╔══██╗██╔════╝██║   ██║██║ " << endl; 
    cout << "██║   ██║██║   ██║██║     █████╗      ██████╔╝█████╗  ██████╔╝██║  ██║█████╗  ██║   ██║██║ " << endl;
    cout << "╚██╗ ██╔╝██║   ██║██║     ██╔══╝      ██╔═══╝ ██╔══╝  ██╔══██╗██║  ██║██╔══╝  ██║   ██║╚═╝ " << endl;
    cout << " ╚████╔╝ ╚██████╔╝╚██████╗███████╗    ██║     ███████╗██║  ██║██████╔╝███████╗╚██████╔╝██╗ " << endl;
    cout << "  ╚═══╝   ╚═════╝  ╚═════╝╚══════╝    ╚═╝     ╚══════╝╚═╝  ╚═╝╚═════╝ ╚══════╝ ╚═════╝ ╚═╝ " << endl;
	cout << endl << endl;
}
// Ganhou o jogo
void mensagem_ganhou(){
    cout << endl;
    cout << "██╗   ██╗ ██████╗  ██████╗███████╗    ██╗   ██╗███████╗███╗   ██╗ ██████╗███████╗██╗   ██╗██╗██╗██╗██╗██╗██╗██╗██╗" << endl;
    cout << "██║   ██║██╔═══██╗██╔════╝██╔════╝    ██║   ██║██╔════╝████╗  ██║██╔════╝██╔════╝██║   ██║██║██║██║██║██║██║██║██║" << endl;
    cout << "██║   ██║██║   ██║██║     █████╗      ██║   ██║█████╗  ██╔██╗ ██║██║     █████╗  ██║   ██║██║██║██║██║██║██║██║██║" << endl;
    cout << "╚██╗ ██╔╝██║   ██║██║     ██╔══╝      ╚██╗ ██╔╝██╔══╝  ██║╚██╗██║██║     ██╔══╝  ██║   ██║╚═╝╚═╝╚═╝╚═╝╚═╝╚═╝╚═╝╚═╝" << endl;
    cout << " ╚████╔╝ ╚██████╔╝╚██████╗███████╗     ╚████╔╝ ███████╗██║ ╚████║╚██████╗███████╗╚██████╔╝██╗██╗██╗██╗██╗██╗██╗██╗" << endl;
    cout << "  ╚═══╝   ╚═════╝  ╚═════╝╚══════╝      ╚═══╝  ╚══════╝╚═╝  ╚═══╝ ╚═════╝╚══════╝ ╚═════╝ ╚═╝╚═╝╚═╝╚═╝╚═╝╚═╝╚═╝╚═╝" << endl;
	cout << endl << endl;
}
// Menu do jogo
void mensagem_menu(){
		cout << "" << endl;
		cout << "|-----------------------------------------------------------------------------|" << endl;
		cout << "|                                 Menu                                        |" << endl;
		cout << "|                           (1) Iniciar Jogo                                  |" << endl;
		cout << "|                           (2) Créditos                                      |" << endl;
		cout << "|                           (3) Instruções do Jogo                            |" << endl;
		cout << "|                           (4) Sair do Jogo                                  |" << endl;
		cout << "|-----------------------------------------------------------------------------|" << endl;
		cout << endl << endl;
}
// Tela de créditos
// TODO: Pegar o sobrenome de Everton
void mensagem_creditos(){
		cout << "" << endl;
		cout << "|-----------------------------------------------------------------------------|" << endl;
		cout << "|                             PLP 2019.2                                      |" << endl;
		cout << "|                              Everton                                        |" << endl;
		cout << "|                                                                             |" << endl;
		cout << "|                               Grupo:                                        |" << endl;
		cout << "|                            Diego Ribeiro                                    |" << endl;
		cout << "|                             Iago Tito                                       |" << endl;
		cout << "|                            Paulo Mateus                                     |" << endl;
		cout << "|                            Raiany Rufino                                    |" << endl;
		cout << "|-----------------------------------------------------------------------------|" << endl;
}

void instrucoes(){
	cout << "" << endl;
		cout << "|-----------------------------------------------------------------------------|" << endl;
		cout << "|                          Instruçoes do Jogo                                 |" << endl;
		cout << "|                                                                             |" << endl;
		cout << "|              R - Revela, exemplo: R A 2 - revela posição A2                 |" << endl;
		cout << "|              F - Flah, exemplo: F A 2 - insere uma flag na posição A2       |" << endl;
		cout << "|              ? - Interrogação: ? A 2 - insere uma ? na posição A2           |" << endl;
		cout << "|-----------------------------------------------------------------------------|" << endl;
}



int main() {
	mensagem_apresentacao();

    string escolha; // escolha do menu informada pelo usuario
	 	
	// Menu do jogo
	while (!perdeu && !venceu) {
		mensagem_menu();
		cin >> escolha;
		if(escolha == "1"){
			coleta_dados_iniciais();
			inicia_jogo();
		}
		else if(escolha == "2")
			mensagem_creditos();
		else if(escolha == "3")
			instrucoes();
		else if(escolha == "4")
			break;
		else cout << "Não existe opção para sua escolha" << endl;
	}

	if (perdeu) {
		mensagem_perdeu();
	} else if (venceu) {
		mensagem_ganhou();
	}

    return 0;
}

/* 
	TODO: agora falta:
		- mudar o método instrucao() para mensagem_instrucao() para seguir o padrão
		- fazer uma forma do usuario poder sair do jogo enquanto está jogando. por exemplo, ao digitar S
		- mudar tudo que ta em inglês pra português
		- tratar quando o usuario colocar mais bombas do que a área do campo. Limitar as bombas para no máximo (linhas*colunas)-1
		- alterar a primeira jogada para revelar vários espaços, caso seja necessário. Basta chamar o método revela dentro de primeira jogada.
		- melhorar a mensagem que aparece a cada jogada para mostrar:
		-- quantas bombas foram encontradas (bomas - bandeiras) (pra isso tem que ter um contador pras bandeiras) poderia colocar no modelo bombasEncontradas / total (ex: 5/16);
		-- quantos quadrados foram revelados
		quanto tempo se passou
		- fazer um shift das coisas que aparecem na tela (é só botar uns espaços em tudo que é printado)


		- Por último, mas não menos importante: TESTAR
*/
