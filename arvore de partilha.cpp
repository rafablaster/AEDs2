//----------------------------------arvore de partilha--------------------------------------------

//Este código cria uma árvore de partição que armazena intervalos de valores, onde cada nó representa um intervalo

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int low;
  int high;
  struct node *left;
  struct node *right;
} node;

node *createNode(int low, int high) {
  node *newNode = (node *) malloc(sizeof(node));
  newNode->low = low;
  newNode->high = high;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

/*
 insere um novo intervalo na árvore, garantindo que não haja intersecção entre os intervalos
*/
node *insert(node *root, int low, int high) {
  if (root == NULL) {
    return createNode(low, high);
  }
  if (root->low > high) {
    root->left = insert(root->left, low, high);
  } else if (root->high < low) {
    root->right = insert(root->right, low, high);
  }
  return root;
}

//print
void display(node *root) {
  if (root != NULL) {
    display(root->left);
    printf("[%d, %d] ", root->low, root->high);
    display(root->right);
  }
}

int main() {
  
  node *root = NULL;
  root = insert(root, 17, 19);
  insert(root, 5, 8);
  insert(root, 21, 24);
  insert(root, 4, 8);
  insert(root, 15, 18);
  insert(root, 7, 10);

  printf("Arvore de Particao: ");
  display(root);
  printf("\n");
  return 0;
}

