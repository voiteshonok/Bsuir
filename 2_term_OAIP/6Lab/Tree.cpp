//---------------------------------------------------------------------------

#pragma hdrstop

#include "Tree.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void node::add(node **tree, int key, AnsiString str) {
    if (*tree == NULL) {
        *tree = new node;
        (*tree)->key = key;
        (*tree)->name = str;
        (*tree)->left = (*tree)->right = NULL;
        return;
    }
    if (key > (*tree)->key) {
        add(&((*tree)->right), key, str);
    } else {
        add(&((*tree)->left), key, str);
    }
}

void node::deleteTree(node *tree) {
    if (tree) {
        deleteTree(tree->right);
        deleteTree(tree->left);
        free(tree);
    }
}

void node::simmetricPrint(node *tree, TMemo *mem) {
    if (tree) {
        simmetricPrint(tree->left, mem);
        mem->Lines->Add(IntToStr(tree->key) + " ");
        simmetricPrint(tree->right, mem);
    }
}

void node::preOrderPrint(node *tree, TMemo *mem) {
    if (tree) {
        mem->Lines->Add(IntToStr(tree->key) + " ");
        preOrderPrint(tree->left, mem);
        preOrderPrint(tree->right, mem);
    }
}

void node::postOrderPrint(node *tree, TMemo *mem) {
    if (tree) {
        postOrderPrint(tree->left, mem);
        postOrderPrint(tree->right, mem);
        mem->Lines->Add(IntToStr(tree->key) + " ");
    }
}


int node::max(int a, int b) {
    return (a > b ? a : b);
}

int node::getDeep(node *tree) {
    return (tree ? 1 + max(getDeep(tree->left), getDeep(tree->right)) : 0);
}

void node::deleteNode(node **tree, int data) {
    if (*tree) {
        if ((*tree)->key == data) {
            node *ptr = *tree;
            if ((*tree)->left == NULL && (*tree)->right == NULL)(*tree) = NULL;
            else if ((*tree)->left == NULL)(*tree) = ptr->right;
            else if ((*tree)->right == NULL)(*tree) = ptr->left;
            else {
                *tree = ptr->right;
                node **ptr1 = tree;
                while (*ptr1) {
                    ptr1 = &((*ptr1)->left);
                }
                *ptr1 = ptr->left;
            }
            free(ptr);
        } else {
            if ((*tree)->key > data) {
                deleteNode(&((*tree)->left), data);
            } else {
                deleteNode(&((*tree)->right), data);
            }
        }
    }
}

void node::balance(node **tree) {
    if (*tree == NULL) {
        return;
    }
    while (abs(getDeep((*tree)->left) - getDeep((*tree)->right)) > 1) {
        if (getDeep((*tree)->left) > getDeep((*tree)->right) + 1) {
            node *left = (*tree)->left->right, *right = *tree;
            *tree = (*tree)->left;
            right->left = left;
            (*tree)->right = right;
        } else if (1 + getDeep((*tree)->left) < getDeep((*tree)->right)) {
            node *left = *tree, *right = (*tree)->right->left;
            *tree = (*tree)->right;
            left->right = right;
            (*tree)->left = left;
        }
    }
}

void node::findNode(node *tree, TEdit *edit) {
    int data = StrToInt(edit->Text);
    if (tree) {
        if (tree->key == data) {
            edit->Text = IntToStr(data) + " " + tree->name;
        } else {
            if (tree->key > data) {
                findNode(tree->left, edit);
            } else {
                findNode(tree->right, edit);
            }
        }
    }
}
