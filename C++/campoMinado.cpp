#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>

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

// Variaveis globais

int linhas, colunas;
int bombas; 

clock_t tInicio, Tfim; 
double tDecorrido;

//prototipo das funções
void tempoInicio();
void tempoFim();


/* Design do Jogo (colocar isso em outra classe) */ 

// Apresentacao inicial
void apresentacao() {
	cout << endl;
	cout << "██████╗ ███████╗███╗   ███╗    ██╗   ██╗██╗███╗   ██╗██████╗  ██████╗ " << endl;
	cout << "██╔══██╗██╔════╝████╗ ████║    ██║   ██║██║████╗  ██║██╔══██╗██╔═══██╗" << endl;
	cout << "██████╔╝█████╗  ██╔████╔██║    ██║   ██║██║██╔██╗ ██║██║  ██║██║   ██║" << endl;
	cout << "██╔══██╗██╔══╝  ██║╚██╔╝██║    ╚██╗ ██╔╝██║██║╚██╗██║██║  ██║██║   ██║" << endl;
	cout << "██████╔╝███████╗██║ ╚═╝ ██║     ╚████╔╝ ██║██║ ╚████║██████╔╝╚██████╔╝" << endl;
	cout << "╚═════╝ ╚══════╝╚═╝     ╚═╝      ╚═══╝  ╚═╝╚═╝  ╚═══╝╚═════╝  ╚═════╝ " << endl;
}

// Perdeu o jogo
void perdeu(){
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
void ganhou(){
    cout << endl;
    cout << "██╗   ██╗ ██████╗  ██████╗███████╗    ██╗   ██╗███████╗███╗   ██╗ ██████╗███████╗██╗   ██╗██╗██╗██╗██╗██╗██╗██╗██╗" << endl;
    cout << "██║   ██║██╔═══██╗██╔════╝██╔════╝    ██║   ██║██╔════╝████╗  ██║██╔════╝██╔════╝██║   ██║██║██║██║██║██║██║██║██║" << endl;
    cout << "██║   ██║██║   ██║██║     █████╗      ██║   ██║█████╗  ██╔██╗ ██║██║     █████╗  ██║   ██║██║██║██║██║██║██║██║██║" << endl;
    cout << "╚██╗ ██╔╝██║   ██║██║     ██╔══╝      ╚██╗ ██╔╝██╔══╝  ██║╚██╗██║██║     ██╔══╝  ██║   ██║╚═╝╚═╝╚═╝╚═╝╚═╝╚═╝╚═╝╚═╝" << endl;
    cout << " ╚████╔╝ ╚██████╔╝╚██████╗███████╗     ╚████╔╝ ███████╗██║ ╚████║╚██████╗███████╗╚██████╔╝██╗██╗██╗██╗██╗██╗██╗██╗" << endl;
    cout << "  ╚═══╝   ╚═════╝  ╚═════╝╚══════╝      ╚═══╝  ╚══════╝╚═╝  ╚═══╝ ╚═════╝╚══════╝ ╚═════╝ ╚═╝╚═╝╚═╝╚═╝╚═╝╚═╝╚═╝╚═╝" << endl;
	cout << endl << endl;
}

// Tela de créditos
void creditos(){
		cout << "" << endl;
		cout << "|-----------------------------------------------------------------------------|" << endl;
		cout << "|                            PLP 2019.2                                       |" << endl;
		cout << "|                              Everton                                        |" << endl;
		cout << "|                                                                             |" << endl;
		cout << "|                               Grupo                                         |" << endl;
		cout << "|                            Diego Ribeiro                                    |" << endl;
		cout << "|                             Iago Tito                                       |" << endl;
		cout << "|                            Paulo Mateus                                     |" << endl;
		cout << "|                            Raiany Rufino                                    |" << endl;
		cout << "|-----------------------------------------------------------------------------|" << endl;
}

// Menu do Jogo
void menu(){
		cout << "" << endl;
		cout << "|-----------------------------------------------------------------------------|" << endl;
		cout << "|                                 Menu                                        |" << endl;
		cout << "|                           (1) Iniciar Jogo                                  |" << endl;
		cout << "|                           (2) Créditos                                      |" << endl;
		cout << "|                           (3) Sair do Jogo                                  |" << endl;
		cout << "|-----------------------------------------------------------------------------|" << endl;
		cout << endl << endl;
}


// Pede o tamanho do campo e o número de bombas ao usuario
void dados_iniciais () {
	while (true) {
		printf("Informe o tamanho M N da matriz e o numero X de bombas com:\n");
		printf("9 <= M <= 16  ,  9 <= N <= 30  e  10 <= x <= 99\n");
		printf("Sugerimos: 16 16 40\n");
		cout << endl;

		cout << "Sua opcao: ";
		scanf("%i %i %i", &linhas, &colunas, &bombas);

		printf("\n\n");

		if (linhas < 9 || linhas > 16 || colunas < 9 || colunas > 30 || bombas < 10 || bombas > 99)
			printf("Valores inválidos, tente novamente.");
		else
			break;
	}
}

void gera_campo_usuario (char campo_usuario[]) {
	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++) {
			campo_usuario[i*linhas + j] = '+';
		}
	}
}
void imprime_campo (char campo[]) {

	cout << endl << endl;
	// Imprime a legenda de numeros superior
	cout << "       0";
	for (int c = 1; c < colunas; c++) {
		if (c < 10)
			cout << "  " <<  c;
		else
			cout << " " << c;
	}
	cout << endl;

	// Imprime a linha superior
	cout << "       -";
	for (int c = 0; c < colunas-1; c++) {
		cout << "  -";
	}
	cout << endl;

	// Imprime a matriz
	for (int i = 0; i < linhas; i++) {
		cout << "  " << (char)(i+65) << " | "; // Imprime as letras da linha e uma linha separadora no lado esquerdo
		for (int j = 0; j < colunas; j++) {
			cout << " " << campo[i*linhas + j] << " ";
		}
		cout <<" | " << (char)(i+65); // Imprime as letras da linha e uma linha separadora no lado direito
		cout << endl;
	}

	// Imprime a linha inferior
	cout << "       -";
	for (int c = 0; c < colunas-1; c++) {
		cout << "  -";
	}
	cout << endl;

	// Imprime a legenda de numeros inferior
	cout << "       0";
	for (int c = 1; c < colunas; c++) {
		if (c < 10)
			cout << "  " <<  c;
		else
			cout << " " << c;
	}

	cout << endl << endl;
}

int iniciaJogo(){
	
	dados_iniciais(); // pede o tamanho do campo e o número de bombas ao usuario
	
	char campo_usuario[linhas * colunas];
	char campo_interno[linhas * colunas];

	gera_campo_usuario (campo_usuario);
	imprime_campo(campo_usuario);

	// TODO:
	/*
		Agora precisamos pegar a primeira jogada do usuario e depois gerar o campo interno, para que a primeira jogada
		não tenha uma bomba
	*/


	// TODO: ajustar pra tamanho mxn
	/*
	if(tam >= 9 && tam <= 30) {
		tempoInicio();
		while(!ehBomba){ // While nao achou bomba e não ganhou, falta fazer o metodo para ganhou()
			
			// Trocar para digitar a coordenada em apenas uma linha, exemplo: 2A
			printf("Digite o eixo x: ");
			scanf("%d", &x);
			printf("Digite o eixo y: ");
			scanf("%d", &y);
			if(x > 0 && x <= tam && y > 0 && y <= tam){
				campo_minado_usuario[x-1][y-1] = campo_minado[x-1][y-1]; 
				if(campo_minado_usuario[x-1][y-1] == 'B'){
					ehBomba = true;
				}
				//imprimir o campo minado
			   tempoFim();
			   puts("Você ganhou");
			}
			else{
				puts("Coordenadas informadas inválidas. Digite novamente.");
			}
		}
		
		if (ehBomba == true){
			tempoFim();
			puts("Você perdeu");
		}else{  // troca por  else if ganhou, mas falta fazer o metodo para ganhou 
			tempoFim();
			puts("Você ganhou");
		}
		// imprimir o campo minado do sistema para depois exibir os creditos
		creditos();
		*/

		return 0;
}


/*void geraBombas(){
    int i;
    int j;
    srand(time(NULL)); // responsavel por alimentar a rand
    for(int k=0; k<=quantidade_bombas; k++){
        i = rand() % tam;
        j = rand() % tam;
        campo_minado[i][j] = 'B';
    }
}*/

void tempoInicio(){
	//iniciando a contagem do tempo
    tInicio=clock();
}

void tempoFim(){
    //terminando a contagem do tempo
    Tfim=clock();
    
    //calculando o tempo decorrido
    tDecorrido=((double)(tInicio-Tfim)/CLOCKS_PER_SEC);

    printf("Tempo gasto: %lf s\n", tDecorrido);
}

int main(){
    
    setlocale (LC_ALL, "Portuguese");
	apresentacao();

    int escolha; // escolha do menu informada pelo usuario
	 	
	// Menu do jogo
	
	while (true) {
		menu();
		cin >> escolha;
		
		switch(escolha){
			case 1:
				iniciaJogo();
			break;
			
			case 2:
				creditos();
			break;
			
			case 3:
				exit(0);
			break;
			
			default:
				printf("Não existe opção para sua escolha");
			break;
		}
	}
}
