#include "tree.h"
#include <memory.h>
#include <stdlib.h>

tree_t *get_new_tree(){

    tree_t *tree = calloc(1, sizeof(tree_t));
    tree->root = NULL;
    return tree;
}

tree_node_t *createNode(tree_t *tree,void *app_data){
    
    tree_node_t *tree_new_branch = calloc(1, sizeof(tree_node_t));
    tree_new_branch->left = NULL;
    tree_new_branch->right = NULL;
    tree_new_branch->data = app_data;
    
    if(!tree->root){
        tree_new_branch->parent = NULL;
        tree->root = tree_new_branch;
    }
    
    return tree_new_branch;
}
