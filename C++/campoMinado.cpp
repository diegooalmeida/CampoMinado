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
	cout << "       1";
	for (int c = 2; c < colunas+1; c++) {
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
	cout << "       1";
	for (int c = 2; c < colunas+1; c++) {
		if (c < 10)
			cout << "  " <<  c;
		else
			cout << " " << c;
	}

	cout << endl << endl;
}

int x, y;
char m;

void pega_jogada () {
	while (true) {
		cout << "Informe sua jogada" << endl;
		char a;
		cin >> m >> a >> y;

		x = ((int) a) - 65; // x será lido como um char. Vamos converter de char pra um int para trabalhar
							// com indices no array.
		y--; // y será lido do usuario como a posição real no array+1, logo, corrigimos com esse --;

		if (m != 'R' && m != 'F' && m != '?')
			cout << "Jogada invalida." << endl;
		else if (x < 1 || x > linhas) 
			cout << "Linha inválida." << endl;
		else if (y < 1 || y > colunas)
			cout << "Coluna inválida" << endl;
		else 
			break;
	}
}

void gera_bombas (char campo_interno[]) {
	int counter = 0;
	int b;
	while (counter < bombas) {
		b = rand() % (linhas * colunas);
		cout << b << endl;
		if (campo_interno[b] != '0' && campo_interno[b] != 'B') {
			campo_interno[b] = 'B';
			counter++;
			cout << "contador: " << counter << endl;
		}
	}
}

void soma_um (char campo_interno[], int p) {
	if (campo_interno[p] = '0') {
		campo_interno[p] = '1';
	} else if (campo_interno[p] = '1') {
		campo_interno[p] = '2';
	} else if (campo_interno[p] = '2') {
		campo_interno[p] = '3';
	}
	else if (campo_interno[p] = '3') {
		campo_interno[p] = '4';
	}
	else if (campo_interno[p] = '4') {
		campo_interno[p] = '5';
	}
	else if (campo_interno[p] = '5') {
		campo_interno[p] = '6';
	}
	else if (campo_interno[p] = '6') {
		campo_interno[p] = '7';
	}
	else if (campo_interno[p] = '7') {
		campo_interno[p] = '8';
	}

}

void preenche_ao_redor (char campo_interno[], int i, int j) {
	// Quando o quadrado a ser revelado está "no meio" do tabuleiro
	if (i-1 >= 0 && i+1 < linhas && j-1 >= 0 && j+1 < colunas) {
		
		soma_um(campo_interno, (i-1)*linhas + (j-1));
		soma_um(campo_interno, (i-1)*linhas + (j));
		soma_um(campo_interno, (i-1)*linhas + (j+1));
		soma_um(campo_interno, (i)*linhas + (j-1));
		//	
		soma_um(campo_interno, (i)*linhas + (j+1));
		soma_um(campo_interno, (i+1)*linhas + (j-1));
		soma_um(campo_interno, (i+1)*linhas + (j));
		soma_um(campo_interno, (i+1)*linhas + (j+1));

	// Quando o quadrado está no canto superior esquerdo
	} else if (i-1 < 0 && j-1 < 0) {
		//	
		soma_um(campo_interno, (i)*linhas + (j+1));
		soma_um(campo_interno, (i+1)*linhas + (j));
		soma_um(campo_interno, (i+1)*linhas + (j+1));
	
	// Quando o quadrado está "no meio" na parte superior
	} else if (i-1 < 0 && j-1 >= 0 && j+1 < colunas) {
		soma_um(campo_interno, (i)*linhas + (j-1));
		//	
		soma_um(campo_interno, (i)*linhas + (j+1));
		soma_um(campo_interno, (i+1)*linhas + (j-1));
		soma_um(campo_interno, (i+1)*linhas + (j));
		soma_um(campo_interno, (i+1)*linhas + (j+1));

	// O quadrado está no canto superior direito
	} else if (i-1 < 0 && j+1 >= colunas) {
		soma_um(campo_interno, (i)*linhas + (j-1));
		//	
		soma_um(campo_interno, (i+1)*linhas + (j-1));
		soma_um(campo_interno, (i+1)*linhas + (j));

	// O quadrado está "no meio" na lateral esquerda
	} else if (i-1 >= 0 && i+1 < linhas && j-1 < 0) {
		soma_um(campo_interno, (i-1)*linhas + (j));
		soma_um(campo_interno, (i-1)*linhas + (j+1));
		//	
		soma_um(campo_interno, (i)*linhas + (j+1));
		soma_um(campo_interno, (i+1)*linhas + (j));
		soma_um(campo_interno, (i+1)*linhas + (j+1));

	// O quadrado está "no meio" na lateral direita
	} else if (i-1 >= 0 && i+1 < linhas && j+1 >= colunas) {
		soma_um(campo_interno, (i-1)*linhas + (j-1));
		soma_um(campo_interno, (i-1)*linhas + (j));
		soma_um(campo_interno, (i)*linhas + (j-1));
		//	
		soma_um(campo_interno, (i+1)*linhas + (j-1));
		soma_um(campo_interno, (i+1)*linhas + (j));

	// O quadrado está na parte inferior esquerda
	} else if (i+1 >= linhas && j-1 < 0) {
		soma_um(campo_interno, (i-1)*linhas + (j));
		soma_um(campo_interno, (i-1)*linhas + (j+1));
		//	
		soma_um(campo_interno, (i)*linhas + (j+1));

	// O quadrado está "no meio" da parte inferior
	} else if (i+1 >= linhas && j-1 >= 0 && j+1 < colunas) {
		soma_um(campo_interno, (i-1)*linhas + (j-1));
		soma_um(campo_interno, (i-1)*linhas + (j));
		soma_um(campo_interno, (i-1)*linhas + (j+1));
		soma_um(campo_interno, (i)*linhas + (j-1));
		//	
		soma_um(campo_interno, (i)*linhas + (j+1));

	// O quadrado está na parte inferior direita
	} else {
		soma_um(campo_interno, (i-1)*linhas + (j-1));
		soma_um(campo_interno, (i-1)*linhas + (j));
		soma_um(campo_interno, (i)*linhas + (j-1));
		//
	}

}

void preenche_campo_interno(char campo_interno[]) {
	for (int c = 0; c < linhas*colunas; c++) {
		if (campo_interno[c] != 'B')
			campo_interno[c] = '0';
	}
	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++) {
			if (campo_interno[i*linhas + j] == 'B') {
				preenche_ao_redor(campo_interno, i, j);
			}
		}
	}
}

void primeira_jogada (char campo_usuario[], char campo_interno[]) {

	
	campo_usuario[x*linhas + y] = '0';
	campo_interno[x*linhas + y] = '0';
	gera_bombas(campo_interno);
	//preenche_campo_interno(campo_interno);
	cout << "Campo interno:" << endl;
	imprime_campo(campo_interno);
}

int iniciaJogo(){
	
	dados_iniciais(); // pede o tamanho do campo e o número de bombas ao usuario
	
	char campo_usuario[linhas * colunas];
	char campo_interno[linhas * colunas];

	gera_campo_usuario (campo_usuario);
	
	pega_jogada(); // Pega o tipo e a posição da jogada na matriz
	primeira_jogada(campo_usuario, campo_interno); // Realzia a primeira jogada, revelando a posição no campo do usuario
								// e depois dispondo as bombas no campo interno
	imprime_campo(campo_usuario);
	while (true) {
		pega_jogada(); // Pega o tipo e a posição da jogada na matriz
		}
	}



	// imprime_campo(campo_usuario);

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
