#include <stdio.h>
#include <stdlib.h>

#define TAM 500000

int i = 0, j = 0;

int MAIOR_VALOR(int *Vetor_A, int tam){
	int maior = 0;

	for (i =0; i < tam; i++){
		if (Vetor_A[i] > maior) maior = Vetor_A[i];
	}

	return maior;

} // Fim_Função_MAIOR_VALOR

void COUNTING_SORT(int *A, int *B, int tam, int k){

	int C[k]; // Declaração do vetor auxiliar

	for(i = 0; i <= k; i++) C[i] = 0; // preenchendo o vetor C com zero

	for(j = 0; j < tam; j++) C[A[j]]= C[A[j]] + 1; // contagem cada elemento do intervalo

	for(i = 1; i <= k; i++) C[i] = C[i] + C[i-1]; // complemento de casas de cada valor

	for(j = tam -1 ; j >= 0; j--) { // alocação dos valores no vetor ordenado

	int c = C[A[j]]; // recebe o valor do índice do vetor B

	B[c] = A[j]; // recebe o valor que ficará no índice

	C[A[j]] = C[A[j]] - 1; // decrementando o valor do vetor C[A[j]]

    }

} // Fim_função_COUNTING_SORT

int main() {
	int k = 0, tam = 0;
	int A[TAM];
	int j = 0;

	printf("Preenchendo vetor\n\n");

	//Crescente
	for(i = 0; i < TAM; i++){
		A[j] = i;
		j=j+1;
	}
	//

	/*/Decrescente
	for(i = TAM; i >= 0; i--){
		A[j] = i;
		j=j+1;
	}
	/*/

	/*/Aleatório
	for(i = 0; i <= TAM; i++){
		A[j] = (rand()%TAM+1);
		j=j+1;
	}
	/*/


	tam = sizeof(A) / sizeof(int); // cálculo do tamanho do vetor
	k = MAIOR_VALOR(A,tam); // cálculo do intervalo k

	printf("\nVetor A Desordenado:\n");

	for(i = 0; i <= tam; i++);// printf("\n%d, ", A[i]);

	int B[tam]; // vetor ordenado

	COUNTING_SORT(A, B, tam, k); // Chamada da Função

	printf("\n\n\nVetor A Ordenado:\n");

	for(i = 0; i <= tam; i++){
		A[i] = B[i];
		printf("\n%d, ", A[i]);
	}


}
