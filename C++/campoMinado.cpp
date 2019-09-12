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
		cout << "|                           (3) Sair do Jogo                                  |" << endl;
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
		else if(escolha == "2")mensagem_creditos();
		else if(escolha == "3")exit(0);
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
		- fazer o método para adicionar bandeiras e interrogações,
		  lembrando de não permitir revelar quadrados com bandeiras
		- Fazer o display que mostra quantos quadrados faltam ser revelados e quantas bombas faltam ser descobertas
		- Fazer a funcão de tempo e mostrar no final

		- Por último, mas não menos importante: TESTAR
*/