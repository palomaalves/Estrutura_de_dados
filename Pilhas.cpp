#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#define MAXTAM 100
using namespace std;

typedef struct {
	int Item[MAXTAM];
	int Topo;
} TPilha;

void TPilha_Inicia (TPilha *p){
	p->Topo = -1;
}

int TPilha_Vazia (TPilha *p){
	if (p->Topo == -1){
		return 1;
	} else {
		return 0;
	}
}

int TPilha_Cheia (TPilha *p){
	if(p->Topo == MAXTAM-1){
		return 1;
	} else {
		return 0;
	}
}

void Tpilha_Insere (TPilha *p, int x){
	if (TPilha_Cheia(p) == 1){
		printf("ERRO: Pilha cheia");
	} else {
		p->Topo++;
		p->Item[p->Topo] = x;
	}
}

int TPilha_Retira (TPilha *p){
	int aux;
	if (TPilha_Vazia(p) ==1){
		printf("ERRO: Pilha vazia");
	} else {
		aux = p->Item[p->Topo];
		p->Topo--;
		return aux;
	}
}

int main ()
{
	TPilha *p = (TPilha*)malloc(sizeof(TPilha));
	TPilha_Inicia(p);
	
	Tpilha_Insere(p, 1);
	Tpilha_Insere(p, 2);
	Tpilha_Insere(p, 3);
	
	
	int aux;
	
	aux = TPilha_Retira(p);
	printf("\n SAIU: %d", aux);
	printf("\n");
	aux = TPilha_Retira(p);
	printf("\n SAIU: %d", aux);
	printf("\n");


system ("pause");
return 0 ;

}
