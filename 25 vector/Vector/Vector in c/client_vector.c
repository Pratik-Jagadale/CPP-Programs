#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main()
{
    struct vector_int* p_vec_int = create_int_vector();
    int choice  = TRUE, n;

    while(choice == TRUE)
    {
         printf("Enter an integer:");
         scanf("%d",&n);

         push_back(p_vec_int, n);


         printf("Do you want to continue?[1-YES|0-NO]:");
         scanf("%d",&choice);

         if(choice != TRUE && choice != FALSE)
            choice = FALSE;
    }

    show(p_vec_int);
    destroy_int_vector(p_vec_int);
    p_vec_int = NULL;



	return (EXIT_SUCCESS);
}