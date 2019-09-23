#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "rbt.h"

#define IS_BLACK(x) ((NULL == (x)) || (BLACK == (x)->colour))
#define IS_RED(x) ((NULL != (x)) && (RED == (x)->colour))

/* Handles memory allocation failures */
void* emalloc(size_t s) {
    void* result = malloc(s);
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

typedef enum { RED, BLACK } rbt_colour;

/* bstnode struct, bst typedef points here */
struct rbtnode {
    rbt lchild;
    rbt rchild;
    char* str;
    rbt_colour colour;
};
/* Allocate, and initialise a new bst */
rbt rbt_new() {
    rbt result = emalloc(sizeof *result);
    result->str = NULL;
    result->lchild = NULL;
    result->rchild = NULL;
    result->colour = RED;
    return result;
}
/* Right rotate tree about root r */
rbt right_rotate(rbt r) {
    rbt oldRoot = r;
    r = r->lchild;

    oldRoot->lchild = r->rchild;
    r->rchild = oldRoot;
    
    return r;
}
/* Left rotate tree about root r */
rbt left_rotate(rbt r) {
    rbt oldRoot = r;
    r = r->rchild;

    oldRoot->rchild = r->lchild;
    r->lchild = oldRoot;

    return r;
}
rbt rbt_fix(rbt r) {
    /* If it's left child exists, and is also red*/
    if (r != NULL) {
        if (r->lchild != NULL) {
            if (r->lchild->colour == RED) {
                if (r->lchild->lchild != NULL) {
                    if (r->lchild->lchild->colour == RED) {
                        if (r->rchild != NULL) {
                            if (r->rchild->colour == RED) {
                                r->colour = RED;
                                r->lchild->colour = BLACK;
                                r->rchild->colour = BLACK;
                            } else {
                                r = right_rotate(r);
                                r->colour = BLACK;
                            r->rchild->colour = RED;
                            }
                        }
                }
                }
                if (r->lchild->rchild != NULL) {
                    if (r->lchild->rchild->colour == RED) {
                        if (r->rchild != NULL) {
                            if (r->rchild->colour == RED) {
                                r->colour = RED;
                                r->lchild->colour = BLACK;
                                r->rchild->colour = BLACK;
                            } else {
                                r->lchild = left_rotate(r->lchild);
                                r = right_rotate(r);
                                r->colour = BLACK;
                                r->rchild->colour = RED;
                            }
                        }
                    }
                }
            }
        }
        if (r->rchild != NULL) {
            if (r->rchild->colour == RED) {
                if (r->rchild->lchild != NULL) {
                    if (r->rchild->lchild->colour == RED) {
                        if (r->lchild != NULL) {
                            if (r->lchild->colour == RED) {
                                r->colour = RED;
                                r->lchild->colour = BLACK;
                                r->rchild->colour = BLACK;
                            } else {
                                r->rchild = right_rotate(r->rchild);
                                r = left_rotate(r);
                                r->colour = BLACK;
                                r->rchild = RED;
                            }
                        }
                    }
                }       
                if (r->rchild->rchild != NULL) {
                    if (r->rchild->rchild->colour == RED) {
                        if (r->lchild != NULL) {
                            if (r->lchild->colour == RED) {
                                r->colour = RED;
                                r->lchild->colour = BLACK;
                                r->rchild->colour = BLACK;
                            } else {
                                r = left_rotate(r);
                                r->colour = BLACK;
                                r->rchild->colour = RED;
                            }
                        }
                        
                    }
                }
            }
        }
        /* Fixup left and right children if they exist */
        if (r->lchild != NULL) {
            r->lchild = rbt_fix(r->lchild);
        }
        if (r->rchild != NULL) {
            r->rchild = rbt_fix(r->rchild);
        }
    }
    return r;
}
/* Insert a node into a rbt */
rbt rbt_insert(rbt b, char* str) {
    rbt result;
    /* If b not null */
    if (b != NULL) {
        /* If str is less that b->str, insert into left child */
        if (0 > strcmp(str, b->str)) {
            b->lchild = rbt_insert(b->lchild, str);
        }
        /* If str is greater than b->str, insert into right child */
        else if (0 < strcmp(str, b->str)) {
            b->rchild = rbt_insert(b->rchild, str);
        }
        b = rbt_fix(b);
        return b;
    }
    /* b is NULL, create new rbt, insert string, return */
    result = rbt_new();
    result->str = emalloc((strlen(str)+1)*sizeof str[0]);
    strcpy(result->str, str);
    return result;    
}
/* Returns 1 if a given string exists in the rbt */
int rbt_search(rbt b, char* str) {
    if (b != NULL) {
        /* If str is less that b->str, search left child */
        if (0 > strcmp(str, b->str)) {
            return rbt_search(b->lchild, str);
        }
        /* If str is greater than b->str, search right child */
        else if (0 < strcmp(str, b->str)) {
            return rbt_search(b->rchild, str);
        } else {
            return 1; /* Return 1 if strings are equal */
        }
    }
    /* Return 0 if a null child is reached */
    return 0;
}
/* Traverse the tree in ascending order, calling f() on every node */
void rbt_inorder(rbt b, void f(char* str)) {
    if (b != NULL) {
        rbt_inorder(b->lchild, f);
        f(b->str);
        rbt_inorder(b->rchild, f);
    }
}
/* Traverse the tree in descending order, calling f() on every node */
void rbt_postorder(rbt b, void f(char* str)) {
    if (b != NULL) {
        rbt_postorder(b->rchild, f);
        f(b->str);
        rbt_postorder(b->lchild, f);
    }
}
void rbt_preorder(rbt b, void f(char*)) {
    if (b != NULL) {
        printf("%s: ", (b->colour == RED ? " RED" : "BLACK"));
        f(b->str);
        rbt_preorder(b->lchild, f);
        rbt_preorder(b->lchild, f);
    }
}
/* Delete a string from the rbt */
rbt rbt_delete(rbt b, char* str) {
    printf("%s\n", str);
    return b;
}
