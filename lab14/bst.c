#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bst.h"

/* Handles memory allocation failures */
void* emalloc(size_t s) {
    void* result = malloc(s);
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return result;
}
/* bstnode struct, bst typedef points here */
struct bstnode {
    bst lchild;
    bst rchild;
    char* str;
};
/* Allocate, and initialise a new bst */
bst bst_new() {
    bst result = emalloc(sizeof result);
    result->lchild = NULL;
    result->rchild = NULL;
    result->str = NULL;
    return result;
}
/* Insert a node into a bst */
bst bst_insert(bst b, char* str) {
    bst result;
    /* If b not null */
    if (b != NULL) {
        /* If str is less that b->str, insert into left child */
        if (0 > strcmp(str, b->str)) {
            b->lchild = bst_insert(b->lchild, str);
        }
        /* If str is greater than b->str, insert into right child */
        else if (0 < strcmp(str, b->str)) {
            b->rchild = bst_insert(b->rchild, str);
        }
        return b;
    }
    /* b is NULL, create new bst, insert string, return */
    result = bst_new();
    result->str = emalloc((strlen(str)+1)*sizeof str[0]);
    strcpy(result->str, str);
    return result;    
}
/* Returns 1 if a given string exists in the bst */
int bst_search(bst b, char* str) {
    if (b != NULL) {
        /* If str is less that b->str, search left child */
        if (0 > strcmp(str, b->str)) {
            bst_insert(b->lchild, str);
        }
        /* If str is greater than b->str, search right child */
        else if (0 < strcmp(str, b->str)) {
            bst_search(b->rchild, str);
        } else {
            return 1; /* Return 1 if strings are equal */
        }
    }
    /* Return 0 if a null child is reached */
    return 0;
}
/* Traverse the tree in ascending order, calling f() on every node */
void bst_inorder(bst b, void f(char* str)) {
    if (b != NULL) {
        bst_inorder(b->lchild, f);
        f(b->str);
        bst_inorder(b->rchild, f);
    }
}
/* Traverse the tree in descending order, calling f() on every node */
void bst_postorder(bst b, void f(char* str)) {
    if (b != NULL) {
        bst_postorder(b->rchild, f);
        f(b->str);
        bst_postorder(b->lchild, f);
    }
}
/* Delete a string from the bst */
bst bst_delete(bst b, char* str) {
    bst currNode;
    char* temp;

    /* If string is less than b->str, delete from left child */
    if (0 > strcmp(str, b->str)) {
        b->lchild = bst_delete(b->lchild, str);
        return b;
    }
    /* If str is greater than b->str, delete from right child */
    else if (0 < strcmp(str, b->str)) {
        b->rchild = bst_delete(b->rchild, str);
        return b;
    }


    if (b->lchild == NULL && b->rchild == NULL) {
        free(b->str);
        free(b);
        return NULL;
    }
    if (b->lchild == NULL || b->rchild == NULL) {
        free(b->str);
        free(b);
        return (b->lchild != NULL ? b->lchild : b->rchild);
    }
    if (b->lchild != NULL || b->rchild != NULL) {
        currNode = b->rchild;
        while (currNode->lchild != NULL) {
            currNode = currNode->lchild;
        }
        temp = b->str;
        b->str = currNode->str;
        currNode->str = temp;
    }
    return b;
}
