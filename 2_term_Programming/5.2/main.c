#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int x;
    struct Node *left, *right;
} node;

void add(node **tree, int x) {
    if (*tree == NULL) {
        *tree = (node *) malloc(sizeof(node));
        (*tree)->x = x;
        (*tree)->left = (*tree)->right = NULL;
        return;
    }
    if (x > (*tree)->x) {
        add(&((*tree)->right), x);
    } else {
        add(&((*tree)->left), x);
    }
}

void simmetricPrint(node *tree) {
    if (tree) {
        simmetricPrint(tree->left);
        printf("%d ", tree->x);
        simmetricPrint(tree->right);
    }
}

void deleteTree(node *tree) {
    if (tree) {
        deleteTree(tree->right);
        deleteTree(tree->left);
        free(tree);
    }
}

void copy(node *tree, node **newTree) {
    if (tree) {
        *newTree = (node *) malloc(sizeof(node));
        (*newTree)->x = tree->x;
        copy(tree->left, &(*newTree)->left);
        copy(tree->right, &(*newTree)->right);
    } else {
        *newTree = NULL;
    }
}

void getPrint(node *tree, char str[100]) {
    if (tree) {
        getPrint(tree->left, str);
        sprintf(str + strlen(str), "%d", tree->x);
        //printf("%d ", tree->x);
        //strcat(str,(char*)tree->x);
        getPrint(tree->right, str);
    }
}

void compareTrees(node *firstTree, node *secondTree) {
    char str1[100] = "", str2[100] = "";
    getPrint(firstTree, str1);
    getPrint(secondTree, str2);
    if (strcmp(str1, str2)) {
        printf("not equal\n");
    } else {
        printf("equal\n");
    }
}

int main() {
    FILE *fp = fopen("input.txt", "r");
    node *tree = NULL;
    int n;
    fscanf(fp, "%d", &n);
    int i;
    for (i = 0; i < n; i++) {
        int tmp;
        fscanf(fp, "%d", &tmp);
        add(&tree, tmp);
    }
    simmetricPrint(tree);
    puts("\n");

    node *newTree = NULL;
    copy(tree, &newTree);
    simmetricPrint(newTree);
    puts("\n");

    compareTrees(tree, newTree);

    add(&newTree, 1);
    simmetricPrint(newTree);
    puts("\n");

    compareTrees(tree, newTree);
    deleteTree(tree);
    deleteTree(newTree);
    fclose(fp);
    return 0;
}
