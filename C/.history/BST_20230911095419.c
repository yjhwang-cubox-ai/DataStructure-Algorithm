#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int val;
    tree* left;
    tree* right;
}tree;

tree* addNode(tree*t , int data){
    if(!t){
        t = (tree*)malloc(sizeof(tree));
        t->val = data;
        t->left = NULL;
        t->right = NULL;
    }
    else{
        if (data < t->val){
            t->left = addNode(t->left, data);
        }
        if(data > t->val){
            t->right = addNode(t->right, data);
        }
    }
    return t;
}

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
                    temp = t->right;
                    free(t);
                    return temp;
                }
                if (t->right == NULL){
                    temp = t->left;
                    free(t);
                    return temp;
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