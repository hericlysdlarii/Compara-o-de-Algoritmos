#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define TAM 100000

int main(){
	float tempo=0;
	time_t t_inic, t_fim;
	
	int vetor[TAM],i=0, j = 0, aux = 0;
	
	t_inic = time(NULL);
	
	/*/PREECHE VETOR CRESCENTE
	for( i = 0; i < TAM; i++ ){
		vetor[i] = i;
	}
	/*/
	
	//PREENCHE VETOR DECRESCENTE
	for( i = TAM; i >= 0; i--){
		vetor[j] = i; 
		j=j+1;
	}
	//
	
	/*/PREENCHE VETOR ALEATÓRIO
	for( i = 0; i < TAM; i++ ){
		vetor[i] = (rand()%TAM+1);
	}
	/*/
	
	//ordena
	for( i = 0; i < TAM; i++ )
	{
		for( j = i + 1; j < TAM; j++ ){
			if ( vetor[i] > vetor[j] ){
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
		}
	}
 
	
	// exibe elementos ordenados
	/*
	printf("Elementos ordenados (Insercao Crescente):");
	for( i = 0; i < TAM; i++ ){
		printf("\nn vetor[%d] = %d", i, vetor[i]); // exibe o vetor ordenado
	}
	*/
	
	t_fim = time(NULL);
	tempo = difftime(t_fim, t_inic);
	printf("\nTempo de execucao (Insercao Crescente): %f", tempo);

}
