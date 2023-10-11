#include <stdlib.h>

/*Step 5 : */

/*Return 0 if ds1 and ds2 are clones,
 * else return -1*/
int
diff (void *root1,    /*pointer to Data structure 1*/
      void *root2,    /*pointer to data structure 2*/
      void *(*iterator(void *)), /*Iterator function callback*/
      int comparator(void *, void *),
      void *(*get_app_data(void *))){  /*Comparison function callback*/

      /*Write your code here*/ 
      void *node1 = root1;
      void *node2 = root2;

      while((node1 != NULL) && (node2 != NULL)){
          void *data1 = get_app_data(node1);
          void *data2 = get_app_data(node2);
       
          if(comparator(data1, data2) != 0){
              return -1; /*Nodes have different data, not clones*/
 	  }
          
	  node1 = iterator(node1);
	  node2 = iterator(node2);
      }
      return 0; /*Lists are clones*/
}
