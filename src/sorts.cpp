#include "sorts.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

void changeIndexValues(int *array, int i, int j) {
  int aux = array[i];
  array[i] = array[j];
  array[j] = aux;
}

void insertSort(int *array, int arrayLength) {
  for (int i = 0; i < arrayLength - 1; i++) {
    int min = i;

    for (int j = i + 1; j < arrayLength; j++) {
      if (array[j] < array[min]) {
        min = j;
      }
    }
    changeIndexValues(array, i, min);
  }
}

void selectionSort(int *array, int arrayLength) {
  for (int j = 1; j < arrayLength; j++) {
    int pivot = array[j];
    int i = j - 1;

    while (i >= 0 && array[i] > pivot) {
      array[i + 1] = array[i];
      i = i - 1;
    }

    array[i + 1] = pivot;
  }
}

// # InsertSort #
//	## Pros: Simplicidade, Duas vezes mais rapido que BubbleSort,
//	normalmente mais rapido que SelectionSort e é estável.
//	## Contras: Considerado lento, em ordem reversa o pior caso é O(n^2).
//	## Indicações: Arrays quase ordenados, e quando pretende adicionar
//	poucos itens a um arquivo ordenado.

// # SelectionSort #
//	## Pros: Custo linear para movimentos de registros.
//	## Contras: Não adianta o arquivo ja estar quase ordenado, sempre terá o
//	custo O(n^2).
//	## Indicações: Arquivos com registros muito grandes, e
//	pequenos arquivos.