//------------------------Tabela Hash----------------------------------

/*estrutura de dados, com calculo de conflito, utilizando lista ligada*/



#include <stdio.h>
#include <stdlib.h>

//struct com lista ligada 
typedef struct node {
    int valor;
    int chave;
    struct node *prox;
}oi;

oi no[10];

//inicia tabela 
void inicializa() {
    int i;
    for (i = 0; i < 10; i++) {
        no[i].chave = -1;
        no[i].valor = -1;
        no[i].prox = NULL;
    }
}

/*
Tipo "unsigned para garantir que retornará valor positivo
Faz calculo para achar posição na tabela
*/
unsigned int hash(int chave){
    return chave % 10;
}

/*
Função que calcula a posição para inserir
*/
void insere(int chave, int valor) {
    int b = hash(chave);
    if (no[b].chave == -1) {
        no[b].chave = chave;
        no[b].valor = valor;
    } else {
        oi *novo = (oi*) malloc(sizeof(struct node));
        novo->chave = chave;
        novo->valor = valor;
        novo->prox = no[b].prox;
        no[b].prox = novo;
    }
}


//Print
/*void exibe() {
    int i;
    oi *temp;
    for (i = 0; i < 10; i++) {
        printf("Indice %d: ", i);
        if (no[i].chave != -1) {
            printf("(%d, %d)", no[i].chave, no[i].valor);
            temp = no[i].prox;
            while (temp != NULL) {
                printf(" -> (%d, %d)", temp->chave, temp->valor);
                temp = temp->prox;
            }
        }
        printf("\n");
    }
}
*/

//Busca elemento
int busca(int chave, int valor){
    int b = hash(chave);
    int index = b;

    while (no[index].chave != -1) {
        if (no[index].valor == valor) {
            return index;
        }
        if (no[index].prox != NULL) {
            oi *temp = no[index].prox;
            while (temp != NULL) {
                if (temp->valor == valor) {
                    return index;
                }
                temp = temp->prox;
            }
        }
        index = (index + 1) % 10;
    }

    printf("Nao encontrado!\n");
    return -1;
}


//imprime na tela 
void imprime() {
    int i;
    for (i = 0; i < 10; i++) {
        printf("Indice %d: Chave %d Valor %d\n", i, no[i].chave, no[i].valor);
    }
}

int main(){
    inicializa();
    insere(1, 10);
    insere(2, 20);
    insere(3, 30);
    insere(4, 40);
    imprime();
    int resultado = busca(3, 30);
    if (resultado != -1) {
        printf("Elemento encontrado na posicao %d\n", resultado);
    }
    return 0;
}
