#ifndef BST_H_
#define BST_H_

typedef struct rbtnode* rbt;

extern rbt rbt_delete(rbt b, char* str);
extern rbt rbt_free(rbt b);
extern void rbt_inorder(rbt b, void f(char* str));
extern rbt rbt_insert(rbt b, char* str);
extern rbt rbt_new();
extern void rbt_preorder(rbt b, void f(char* str));
extern int rbt_search(rbt b, char* str);

#endif
