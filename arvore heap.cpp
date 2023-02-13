//------------------------------------Árvore Heap-------------------------------------

/* (max heap) */

#include <stdio.h>
#include <stdlib.h>
 
// Função de troca
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
// Função para manter a propriedade de max heap
void maxHeapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
 
    // Verifica se o filho esquerdo é maior que o nó raiz
    if (left < n && arr[left] > arr[largest])
        largest = left;
 
    // Verifica se o filho direito é maior que o nó raiz
    if (right < n && arr[right] > arr[largest])
        largest = right;
 
    // Se o nó raiz não é o maior, troca com o maior filho
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}
 
// Função para construir a max heap
void buildMaxHeap(int arr[], int n)
{
    // Construir a max heap a partir da metade para baixo
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}
 
// Função para extrair o maior elemento (raiz) da max heap
int extractMax(int arr[], int *n)
{
    // Verifica se a heap está vazia
    if (*n <= 0)
        return -1;
 
    // Armazena o valor da raiz
    int max = arr[0];
 
    // Troca a raiz com o último elemento
    arr[0] = arr[*n - 1];
    (*n)--;
 
    // Restaura a propriedade de max heap
    maxHeapify(arr, *n, 0);
 
    return max;
}
 
// Função para inserir um elemento na max heap
void insertMaxHeap(int arr[], int *n, int key)
{
    (*n)++;
    int i = *n - 1;
    arr[i] = key;
 
    // Mantém a propriedade de max heap ao mover para cima
    while (i != 0 && arr[(i - 1) / 2] < arr[i])
    {
        swap(&arr[(i - 1) / 2], &arr[i]);
        i = (i - 1) / 2;
    }
}
 
// Função principal
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    buildMaxHeap(arr, n);
 
    printf("Max heap: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
 
    printf("Extracted max: %d\n", extractMax(arr, &n));
 
    printf("Max heap after extraction: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
 
    insertMaxHeap(arr, &n, 20);
 
    printf("Max heap after insertion: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
 
    return 0;
}
