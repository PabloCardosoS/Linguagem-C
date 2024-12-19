#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	printf("****************************************\n");
	printf("Bem vindo ao nosso jogo de adivinhação\n");
	printf("****************************************\n");

	srand(time(0));
	int numerosecreto = rand() % 100;

	int chute;
	int tentativas = 1;
	double pontos = 1000;

	int acertou = 0;

	int nivel;
	printf("Qual o nível de dificuldade?\n");
	printf("(1) Fácil - (2) Médio - (3) Difícil\n\n");
	printf("Escolha: ");
	scanf("%d", &nivel);

	int numerodetentativas;
	
	/*if(nivel == 1) {
		numerodetentativas = 10;
	} else if (nivel == 2) {
		numerodetentativas = 8;
	} else {
		numerodetentativas = 5;
	}*/

	// Usando Switch-Case
	switch(nivel) {
		case 1:
			numerodetentativas = 10;
			break;
		case 2:
			numerodetentativas = 8;
			break;
		default:
			numerodetentativas = 5;
			break;
	}

	for(int i = 1; i <= numerodetentativas; i++) {
		printf("Qual é o seu %dº chute? ", tentativas);
		scanf("%d", &chute);

		if(chute < 0) {
			printf("Você não pode chutar números negativos!\n");
			continue;
		}

		acertou = (chute == numerosecreto);
		int maior = (chute > numerosecreto);

		if(acertou) {
			break;
		} else if(maior) {
			printf("O número deve ser menor.\n");
		} else { 
			printf("O número deve ser maior.\n");
		}
		tentativas++;

		double pontosperdidos = (double) abs(chute - numerosecreto) / 2;
		pontos -= pontosperdidos;
	}
	printf("Fim de jogo!\n");

	if(acertou) {
		printf("Você ganhou!\n");
		printf("Você acertou em %d tentativas!\n", tentativas);
		printf("Você fez %.1f pontos.\n\n", pontos);
	} else {
		printf("Você perdeu! Tente novamente!\n\n");
	}

}

