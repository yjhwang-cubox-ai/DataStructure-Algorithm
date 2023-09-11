#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int val;
    tree* left;
    tree* right;
}tree;

tree* remove(tree* t, int delData){
    tree* temp;
    if (t){
        if (t->val == delData){
            if (t->left == NULL && t->right == NULL){
                free(t);
                return NULL;
            }
            else{
                if (t->left == NULL){

                }
                if (t->right == NULL){

                }
                temp = findMax(t->left);
                t -> val = temp->val;
                t->left = remove(t->left, temp->val);                
            }
        }
        else{
            if (delData < t->val){
                t->left = remove(t->left, delData);
            }
            else if (delData > t->val){
                t->right = remove(t->right, delData);
            }
        }

    }
    return t;
}