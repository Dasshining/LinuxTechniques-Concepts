#include "tree.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern int
diff (void *root1,    /*pointer to first node of data struture 1*/
        void *root2,    /*pointer to first node of data struture 2*/
        void *(*iterator)(void *), /*Iterator function callback*/
        int (*comparator)(void *, void *),
        void *(*get_app_data)(void *)); /*Comparison function callback*/


/*Application specific data structures*/
typedef struct student_{
    char name[32];
    unsigned int year_of_birth;
    unsigned int height;
    unsigned int weight;
    unsigned int total_marks;
} student_t;


/*Step 2 : Implement list iterator function here*/
void* tree_iterator (void *tree_node){
    /*write your code here*/
    return((tree_node_t *)tree_node)->right;
}

/*Step 3 : implement student comparator function here*/

int student_comparator (void *_studentobj1, void *_studentobj2){
    /*Write your code here*/
    student_t *student1 = (student_t *) _studentobj1;
    student_t *student2 = (student_t *) _studentobj2;
    if(strcmp(student1->name, student2->name) == 0 &&
       student1->year_of_birth == student2->year_of_birth &&
       student1->height	       == student2->height &&
       student1->weight        == student2->weight &&
       student1->total_marks   == student2->total_marks){
       printf("Data is the same\n");
       return 0; 
    }
    printf("data is not the same\n");
    return -1;
} 

/*Step 4 : implement get_app_data_from_list_node function*/
void*
get_app_data_from_tree_node(void *tree_node){
    /*Write your code here*/
    return ((tree_node_t *)tree_node)->data;
}


int
main(int argc, char **argv){

    /*Student database list 1*/
    student_t *student1 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student1->name, "Abhishek", strlen("Abhishek"));
    student1->year_of_birth = 2000;
    student1->height = 167;
    student1->weight = 80;
    student1->total_marks = 90;

    student_t *student2 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student2->name, "Sagar", strlen("Sagar"));
    student2->year_of_birth = 2001;
    student2->height = 170;
    student2->weight = 82;
    student2->total_marks = 80;

    student_t *student3 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student3->name, "Vineet", strlen("Vineet"));
    student3->year_of_birth = 2002;
    student3->height = 161;
    student3->weight = 62;
    student3->total_marks = 72;

    student_t *student4 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student4->name, "Neeraj", strlen("Neeraj"));
    student4->year_of_birth = 1998;
    student4->height = 167;
    student4->weight = 76;
    student4->total_marks = 67;


    tree_t *student_tree1 = get_new_tree();
    tree_node_t *student_node_1 = createNode(student_tree1, student1);
    tree_node_t *student_node_2 = createNode(student_tree1, student2);
    tree_node_t *student_node_3 = createNode(student_tree1, student3);
    tree_node_t *student_node_4 = createNode(student_tree1, student4);
    student_node_1->right = student_node_2;
    student_node_1->left  = student_node_3;
    student_node_2->right = student_node_4;
    student_node_2->parent = student_node_1;
    student_node_3->parent = student_node_1;
    student_node_4->parent = student_node_4;
    


    /*Student database list 2*/
    student_t *student5 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student5->name, "Abhishek", strlen("Abhishek"));
    student5->year_of_birth = 2000;
    student5->height = 167;
    student5->weight = 80;
    student5->total_marks = 90;

    student_t *student6 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student6->name, "Sagar", strlen("Sagar"));
    student6->year_of_birth = 2001;
    student6->height = 170;
    student6->weight = 82;
    student6->total_marks = 80;

    student_t *student7 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student7->name, "Vineet", strlen("Vineet"));
    student7->year_of_birth = 2002;
    student7->height = 161;
    student7->weight = 62;
    student7->total_marks = 72;

    student_t *student8 = (student_t *)calloc(1, sizeof(student_t));
    strncpy(student8->name, "Neeraj", strlen("Neeraj"));
    student8->year_of_birth = 1998;
    student8->height = 167;
    student8->weight = 76;
    student8->total_marks = 67;

    tree_t *student_tree2 = get_new_tree();
    tree_node_t *student_node_5 = createNode(student_tree2,student5);
    tree_node_t *student_node_6 = createNode(student_tree2,student6);
    tree_node_t *student_node_7 = createNode(student_tree2,student7);
    tree_node_t *student_node_8 = createNode(student_tree2,student8);
    student_node_5->right = student_node_6;
    student_node_5->left  = student_node_7;
    student_node_6->right = student_node_8;
    student_node_6->parent = student_node_5;
    student_node_7->parent = student_node_5;
    student_node_6->parent = student_node_8;

    /*Step 6*/

    if(diff((void *)student_tree1->root, (void *)student_tree2->root, tree_iterator, student_comparator, get_app_data_from_tree_node) == 0)
        printf("Data sructures are equal\n");
    else
        printf("Data sructures are not equal\n");
    return 0;
}
