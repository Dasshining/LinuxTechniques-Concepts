/*Header file for Tree Data Structure*/

typedef struct tree_node_{

    void *data;
    struct tree_node_ *left;
    struct tree_node_ *right;
    struct tree_node_ *parent;
} tree_node_t;

typedef struct tree_{
    tree_node_t *root;
} tree_t;


/* Public Function declaration to create and return
 * a new empty doubly linked list*/
tree_t *get_new_tree();

/*  Public Function declaration to add the appication
 *  data to DLL*/
tree_node_t *createNode(tree_t *tree, void *appn_data);
