#include <stdio.h>
#include <stdlib.h>

struct Pilha {   // cria��o da esterutura Pilha

	int topo; /* posi��o do elemento topo */
	int capa;
	float *pElem;

};

void criarpilha( struct Pilha *p, int c ){

   p->topo = -1;
   p->capa = c;
   p->pElem = (float*) malloc (c * sizeof(float)); // Alocac��o din�mica de mem�ria 

}
int estavazia ( struct Pilha *p ){ // teste pilha vazia

   if( p-> topo == -1 )

      return 1;   // verdadeiro

   else

      return 0;   // falso

}

int estacheia ( struct Pilha *p ){// teste pilha cheia 


	if (p->topo == p->capa - 1)

		return 1;

	else

		return 0;

}

void empilhar ( struct Pilha *p, float v){

	p->topo++;
	p->pElem [p->topo] = v;

}

float desempilhar ( struct Pilha *p ){

   float aux = p->pElem [p->topo];
   p->topo--;
   return aux;

}

float retornatopo ( struct Pilha *p ){

   return p->pElem [p->topo];

}

int main(){

	struct Pilha minhapilha;
	int capacidade, op;
	float valor;
    printf( "Inserindo numeros reais\n");
	printf( "\ninforme a capacidade da pilha: " );
	scanf( "%d", &capacidade );

	criarpilha (&minhapilha, capacidade);

	while( 1 ){ //loop infinito

		printf("\n1- Empilhar (push)\n");
		printf("2- Desempilhar (POP)\n");
		printf("3- Mostrar o topo \n");
		printf("4- Sair\n");
		printf("\nOpcao? ");
		scanf("%d", &op);

		switch (op){

			case 1: //push

				if( estacheia( &minhapilha ) == 1 )

					printf("\nPILHA CHEIA! \n");

				else {

					printf("\nVALOR? ");
					scanf("%f", &valor);
					empilhar (&minhapilha, valor);

				}
				break;

			case 2: //pop
				if ( estavazia(&minhapilha) == 1 )

					printf( "\nPILHA VAZIA! \n" );

				else{

					valor = desempilhar (&minhapilha);
					printf ( "\n%.1f DESEMPILHADO!\n", valor );

				}
				break;

			case 3: // mostrar o topo da pilha
				if ( estavazia (&minhapilha) == 1 )

					printf( "\nPILHA VAZIA!\n" );

				else {

					valor = retornatopo (&minhapilha);
					printf ( "\nTOPO: %.1f\n", valor );

				}
				break;

			case 4: 
				exit(0);

			default: printf( "\nOPCAO INVALIDA! \n" );
		}
	}
	
}
