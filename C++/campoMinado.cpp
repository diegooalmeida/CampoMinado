#include <iostream>
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
// Menu do jogo
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
// Tela de créditos
// TODO: Pegar o sobrenome de Everton
void creditos(){
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
// -=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- Variaveis globais -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
int linhas, colunas, bombas; // quantidade de cada uma dessas coisas no jogo
int x, y; // posicao da jogada do jogador
char m; // tipo de jogada do jogador: R - revelar, F - bandeira, ? - interrogacao
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //

void coleta_dados_iniciais () {
    while (true) {
		cout << "Informe o tamanho M N da matriz e o numero X de bombas com:" << endl;
		cout << "9 <= M <= 16  ,  9 <= N <= 30  e  10 <= x <= 99" << endl;
		cout << "Sugerimos: 16 16 40" << endl;
		cout << endl;

		cout << "Sua opcao: ";
		cin >> linhas >> colunas >> bombas;

		cout << endl << endl;

		if (linhas < 9 || linhas > 16 || colunas < 9 || colunas > 30 || bombas < 10 || bombas > 99)
			cout << "Valores inválidos, tente novamente." << endl;
		else
			break;
	}
}

void preenche_campo(char campo[]) {
	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++) {
			campo[i*linhas + j] = '+';
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
		if (campo_interno[b] == '+') {
			campo_interno[b] = 'B';
			counter++;
		}
	}
}

void preenche_campo_com_zeros (char campo_interno[]) {
    for (int c = 0; c < linhas*colunas; c++) {
        if (campo_interno[c] == '+')
            campo_interno[c] = '0';
    }
}

void soma_um (char campo_interno[], int p) {
	if (campo_interno[p] == '0') {
		campo_interno[p] = '1';
	} else if (campo_interno[p] == '1') {
		campo_interno[p] = '2';
	} else if (campo_interno[p] == '2') {
		campo_interno[p] = '3';
	} else if (campo_interno[p] == '3') {
		campo_interno[p] = '4';
	} else if (campo_interno[p] == '4') {
		campo_interno[p] = '5';
	} else if (campo_interno[p] == '5') {
		campo_interno[p] = '6';
	} else if (campo_interno[p] == '6') {
		campo_interno[p] = '7';
	} else if (campo_interno[p] == '7') {
		campo_interno[p] = '8';
	}

}

void calcula_arredores (char campo_interno[], int i, int j) {
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

void primeira_jogada (char campo_interno[], char campo_usuario[]) {

	campo_interno[x*linhas + y] = '0';

    gera_bombas(campo_interno);
    
    preenche_campo_com_zeros (campo_interno);

    // calcula o valor de cada quadrado baseado em quantas bombas existem ao seu redor
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (campo_interno[i*linhas + j] == 'B')
                calcula_arredores (campo_interno, i, j);
        }
    }

    // poe o valor do quadrado do campo interno no campo do usuario (caso a primeira jogada tenha alguma bomba ao redor)
    campo_usuario[x*linhas + y] = campo_interno[x*linhas + y];

}

// TODO: metodo para revelar quadrados adjacentes

void jogo () {
    coleta_dados_iniciais();

    char campo_interno[linhas * colunas];
    char campo_usuario[linhas * colunas];

    preenche_campo (campo_interno);
    preenche_campo (campo_usuario);

    imprime_campo (campo_usuario);

    pega_jogada ();
    primeira_jogada (campo_interno, campo_usuario);

    // TODO: while true para o jogo pedir novas jogadas ate o jogador perder ou vencer
}

int main() {
	apresentacao();

    int escolha; // escolha do menu informada pelo usuario
	 	
	// Menu do jogo
	
	while (true) {
		menu();
		cin >> escolha;
		
		switch(escolha){
			case 1:
				jogo();
			break;
			
			case 2:
				creditos();
			break;
			
			case 3:
				exit(0);
			break;
			
			default:
				cout << "Não existe opção para sua escolha" << endl;
			break;
		}
	}

    return 0;
}
