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

// Variaveis globais, precisa ser criado 2 para as matrizes de tam indefinido 

bool ehBomba = false;
int tam;
int quantidade_bombas; 
clock_t tInicio, Tfim; 
double tDecorrido;

//prototipo das funções
void tempoInicio();
void tempoFim();


/* Design do Jogo (colocar isso em outra classe) */ 

// Apresentacao inicial
void apresentacao() {
	cout << endl;
	cout << "██████╗ ███████╗███╗   ███╗    ██╗   ██╗██╗███╗   ██╗██████╗  ██████╗ "<< endl;
	cout << "██╔══██╗██╔════╝████╗ ████║    ██║   ██║██║████╗  ██║██╔══██╗██╔═══██╗"<< endl;
	cout << "██████╔╝█████╗  ██╔████╔██║    ██║   ██║██║██╔██╗ ██║██║  ██║██║   ██║"<< endl;
	cout << "██╔══██╗██╔══╝  ██║╚██╔╝██║    ╚██╗ ██╔╝██║██║╚██╗██║██║  ██║██║   ██║"<< endl;
	cout << "██████╔╝███████╗██║ ╚═╝ ██║     ╚████╔╝ ██║██║ ╚████║██████╔╝╚██████╔╝"<< endl;
	cout << "╚═════╝ ╚══════╝╚═╝     ╚═╝      ╚═══╝  ╚═╝╚═╝  ╚═══╝╚═════╝  ╚═════╝ "<< endl;
}

/* Perdeu o jogo
void perdeu(){
    cout << end1;
    cout << "██╗   ██╗ ██████╗  ██████╗███████╗    ██████╗ ███████╗██████╗ ██████╗ ███████╗██╗   ██╗██╗ " << end1;
    cout << "██║   ██║██╔═══██╗██╔════╝██╔════╝    ██╔══██╗██╔════╝██╔══██╗██╔══██╗██╔════╝██║   ██║██║ " << end1; 
    cout << "██║   ██║██║   ██║██║     █████╗      ██████╔╝█████╗  ██████╔╝██║  ██║█████╗  ██║   ██║██║ " << end1;
    cout << "╚██╗ ██╔╝██║   ██║██║     ██╔══╝      ██╔═══╝ ██╔══╝  ██╔══██╗██║  ██║██╔══╝  ██║   ██║╚═╝ " << end1;
    cout << " ╚████╔╝ ╚██████╔╝╚██████╗███████╗    ██║     ███████╗██║  ██║██████╔╝███████╗╚██████╔╝██╗ " << end1;
    cout << "  ╚═══╝   ╚═════╝  ╚═════╝╚══════╝    ╚═╝     ╚══════╝╚═╝  ╚═╝╚═════╝ ╚══════╝ ╚═════╝ ╚═╝ " << end1;
	cout << end1 << end1;
}

// Ganhou o jogo
void ganhou(){
    cout << end1;
    cout << "██╗   ██╗ ██████╗  ██████╗███████╗    ██╗   ██╗███████╗███╗   ██╗ ██████╗███████╗██╗   ██╗██╗██╗██╗██╗██╗██╗██╗██╗" << end1;
    cout << "██║   ██║██╔═══██╗██╔════╝██╔════╝    ██║   ██║██╔════╝████╗  ██║██╔════╝██╔════╝██║   ██║██║██║██║██║██║██║██║██║" << end1;
    cout << "██║   ██║██║   ██║██║     █████╗      ██║   ██║█████╗  ██╔██╗ ██║██║     █████╗  ██║   ██║██║██║██║██║██║██║██║██║" << end1;
    cout << "╚██╗ ██╔╝██║   ██║██║     ██╔══╝      ╚██╗ ██╔╝██╔══╝  ██║╚██╗██║██║     ██╔══╝  ██║   ██║╚═╝╚═╝╚═╝╚═╝╚═╝╚═╝╚═╝╚═╝" << end1;
    cout << " ╚████╔╝ ╚██████╔╝╚██████╗███████╗     ╚████╔╝ ███████╗██║ ╚████║╚██████╗███████╗╚██████╔╝██╗██╗██╗██╗██╗██╗██╗██╗" << end1;
    cout << "  ╚═══╝   ╚═════╝  ╚═════╝╚══════╝      ╚═══╝  ╚══════╝╚═╝  ╚═══╝ ╚═════╝╚══════╝ ╚═════╝ ╚═╝╚═╝╚═╝╚═╝╚═╝╚═╝╚═╝╚═╝" << end1;
	cout << end1 << end1;
} */

// Tela de créditos
void creditos(){
		puts("");
		puts("|-----------------------------------------------------------------------------|");
		puts("|                            PLP 2019.2                                       |");
		puts("|                              Everton                                        |");
		puts("|                                                                             |");
		puts("|                               Grupo                                         |");
		puts("|                            Diego Ribeiro                                    |");
		puts("|                             Iago Tito                                       |");
		puts("|                            Paulo Mateus                                     |");
		puts("|                            Raiany Rufino                                    |");
		puts("|-----------------------------------------------------------------------------|");
}

// Menu do Jogo
void menu(){
		puts("");
		puts("|-----------------------------------------------------------------------------|");
		puts("|                                 Menu                                        |");
		puts("|                           (1) Iniciar Jogo                                  |");
		puts("|                           (2) Créditos                                      |");
		puts("|                           (3) Sair do Jogo                                   |");
		puts("|-----------------------------------------------------------------------------|");
}

int iniciaJogo(){
	int x, y; // coordenadas 
	int tamanho_matriz;
				
	printf("Informe o tamanho N da matriz respeitando o intervalo  9 <= N <= 30.\n");
	scanf("%i", &tamanho_matriz);
	
	tam = tamanho_matriz;
	quantidade_bombas = tam - 1;
	int campo_minado[tam][tam]; // matriz completa do sistema
	int campo_minado_usuario[tam][tam]; // matriz que sera exibida 
	
	//geraBombas();
	
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

		return 0;
	} else {
		puts("Tamanho informado inválido.");
	}
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
	
	menu();
	scanf("%i", &escolha);
	
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
