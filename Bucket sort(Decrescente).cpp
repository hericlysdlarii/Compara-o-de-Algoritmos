#include <stdio.h>
#include <stdlib.h>
#include<time.h>


struct bucket 
{
    int count;
    int* values;
};

int compareIntegers(const void* first, const void* second)
{
    int a = *((int*)first), b =  *((int*)second);
    if (a == b)
    {
        return 0;
    }
    else if (a < b)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

void bucketSort(int array[],int n)
{
    struct bucket buckets[3];
    int i, j, k;
    for (i = 0; i < 3; i++)
    {
        buckets[i].count = 0;
        buckets[i].values = (int*)malloc(sizeof(int) * n);
    }
    // Divide the unsorted elements among 3 buckets
    // < 0    : first
    // 0 - 10 : second
    // > 10   : third
    for (i = 0; i < n; i++)
    {
        if (array[i] < 0)
        {
            buckets[0].values[buckets[0].count++] = array[i];
        }
        else if (array[i] > 10)
        {
            buckets[2].values[buckets[2].count++] = array[i];
        }
        else
        {
            buckets[1].values[buckets[1].count++] = array[i];
        }
    }
    for (k = 0, i = 0; i < 3; i++)
    {
        // Use Quicksort to sort each bucket individually
        qsort(buckets[i].values, buckets[i].count, sizeof(int), &compareIntegers);
        for (j = 0; j < buckets[i].count; j++)
        {
            array[k + j] = buckets[i].values[j];
        }
        k += buckets[i].count;
        free(buckets[i].values);
    }
}

int main(int brArg,char *arg[]) {

	float tempo=0;
	time_t t_inic, t_fim;
	
    int array[500000];
    int i=500000,j=0,k,n;
	
	
	/*/preeche o vetor crescente
	for( j = 0; j < TAM; j++ ){
		array[j] = j;
	}
 	/*/   
	
	/*/PREENCHE VETOR ALEATÓRIO
	for( j = 0; j < TAM; j++ ){
		array[j] = (rand()%TAM+1);
	}
	/*/
	
	//PREENCHE VETOR DECRESCENTE
	for(k=500000; k>=0; k--){
		array[j] = k;
		j=j+1;
	}
	//
    n=500000;
    /*
    for (j = 0; j<TAM; j++)
    {
        printf("Broj: %d\n", array[j]);
    }
*/
	
	t_inic = clock();
	
    bucketSort(array, n);
    
   	t_fim = clock();
/* 
    for (k = 0; k<TAM; k++){
        printf("%d \n", array[k]);   
	}
	*/

	tempo = difftime(t_fim, t_inic)/CLOCKS_PER_SEC;
	printf("\nTempo de execucao (Insercao Crescente): %f", tempo);
    return 0;
}
