//Rafabçaster ne paizão
//DIBOAS

/*---------------------------------------------------Árvore de busca binária-----------------------------------------------------

info:  root = raiz da árvore
data = valor do no
node = no*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

typedef struct node {
    int data;//valor do no
    struct node *left;//filho esquerdo
    struct node *right;//filho direito
}no;

/*Função cria no*/
no* createNode(int data) {
    no* newNode = (no*)malloc(sizeof(no));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;//retorna o novo no
}

/*Função inserção de no*/
no* insert(no* node, int data) {
    if (node == NULL) return createNode(data);//se o no for vazio ele usa a recursividade pra criar um nó com o valor solicitado
    if (data <= node->data)//compara o valor do no atual, caso seja menor ou igual vai pra esquerda
        node->left = insert(node->left, data);
    else if (data > node->data)//compara o valor do no atual, caso seja menor ou igual vai pra direita
        node->right = insert(node->right, data);
    return node;//retorna o no incluido
}

/*Função de busca na arvore binaria*/
no* search(no* root, int data){
    if(root == NULL){//verifica se o valor existe
        printf("Nao ha esse valor! (%d)\n\n", data);
        return NULL;
    }else if (data == root->data){//verifica que o valor foi encontrado
            printf("Valor encontrado :  ");
            printf("%d\n\n", data);
            return root;
          }else if(data > root->data){//recursividade que vai andando pela árvore em busca do nó
                    return search(root->right, data);
                }else
                    return search(root->left, data);
}

/*Função de imprimir árvore
Usando recursividade
Calcula o espaço e printa a árvore com rotação para esquerda*/
void printTree(no* root, int level) {
if (root == NULL) {
    return;
}
printTree(root->right, level + 1);
for (int i = 0; i < level; i++) {
    std::cout << "       ";
}
std::cout << root->data << std::endl;
printTree(root->left, level + 1);
}

/*Função remover no e balancear árvore*/
no* removeno(no* root, int data) {
    if (root == NULL) {//verifica se há árvore
        return NULL;
    }
    if (data < root->data) {// verifica se o valor a ser removido é menor ou maior do que o valor armazenado na raiz atual
        root->left = removeno(root->left, data);//se for menor,função é chamada recursivamente para a subárvore esquerda
    } else if (data > root->data) {
        root->right = removeno(root->right, data);//se for maior,função é chamada recursivamente para a subárvore direita.
    } else {
        if (root->left == NULL && root->right == NULL) {//verifica se tem filho, caso seja verdadeiro , remove o no
            free(root);
            return NULL;
        } else if (root->left == NULL) {//Se o nó a ser removido tiver um único filho, ele é substituído pelo seu filho
            no* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {//Se o nó a ser removido tiver um único filho, ele é substituído pelo seu filho
            no* temp = root->left;
            free(root);
            return temp;
        } else {//se tiver 2 filhos, busca na sub árvore direita o menor valor
            no* minno = root->right;
            while (minno->left != NULL) {
                minno = minno->left;
            }
            root->data = minno->data;
            root->right = removeno(root->right, minno->data);
        }
    }
    return root;//retorna a raíz
}



int main() {
    
    int oi = 1;
    no *root = NULL;
    int level = 0;
    int b;

    while(oi == 1){

        printf("\nSeja bem vindo a arvore binaria do RAFABLASTER!\nDigite: \n(1)Inserecao\n(2)Remocao\n(3)Busca\n(4)Imprimir arvore\n(9)Sair\nValor digitado: ");

        int num;
        scanf("%d", &num);
        printf("-------------------------------------------------------------------------------\n");


        switch (num){
            case 1://insere
                printf("\nDigita um valor pra colocar aqui meu jovem:\n");
                scanf("%d", &b);
                root = insert(root, b);
                printf("\nValor adicionado!\n");
                printf("-----------------------\n");
                break;
   
            case 2://remove
                if(root == NULL){
                    printf("arvore vazia!\n");
                }else{ 
                    printf("\nDigita o valor pra tirar da arvore meu comparsa:\n");
                    scanf("%d", &b);
                    removeno(root, b);
                    printf("-----------------------\n");
                }
                break;

            case 3://busca
                if(root == NULL){
                    printf("arvore vazia!\n");
                }else{
                    printf("\nDigita o valor a ser buscado ai meu nobre:\n");
                    scanf("%d", b);
                    search(root, b);
                    printf("-----------------------\n");
                }
                break;

            case 4://print
                if(root == NULL){
                    printf("arvore vazia!\n");
                }else{
                    printTree(root, level);
                    printf("-----------------------\n");
                }
                break;

            case 9:
                if(root == NULL){
                    printf("                  arvore vazia!               \n\n");
                }
                oi = 0;
                printf("--------------  Programa encerrado...  ------------\n\n");
                break;

            default:
                printf("-------------Opcao invalida!!--------------\n");
        }
   
    }
   
   
   
   
   
   
   
   
   
    /*root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    search(root, 20);
    search(root, 70);
    search(root, 34);
    printf("Arvore binaria pronta: \n\n");
    printTree(root, level);

    removeno(root, 30);
    printf("Arvore binaria depois da remocao: \n\n");
    printTree(root, level);*/

    return 0;
}