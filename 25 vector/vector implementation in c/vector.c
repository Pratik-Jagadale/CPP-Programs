#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
//#include <vector.h>

#define TRUE 1
#define FALSE 0

#define SUCCES 1
#define OUT_OF_RANGE 2
#define EMPTY_VECTOR 3

 //server : declarations
struct vector_int{
    int* p_arr;
    size_t size;
};
typedef struct vector_int vector_int_t;

vector_int_t* create_vector(void);
int push_back(vector_int_t* p_vec_int ,int new_element);
int pop_back(vector_int_t* p_vec_int ,int* pop_backed_element);
int get_at(vector_int_t* p_vec_int, int index ,int* p_data);
int set_at(vector_int_t* p_vec_int ,int index, int new_element);
void show(vector_int_t* p_vec_int);
int destroy_int_vector(vector_int_t* p_vec_int);
  
//client
int main(void)
{
    struct vector_int* p_vec_int = create_vector(); 
    int choice = TRUE, n; 

    while(choice == TRUE)
    {
        printf("Enter an integer:"); 
        scanf("%d", &n); 

        push_back(p_vec_int, n); 

        printf("Do you want to continue?[1-YES|0-NO]:"); 
        scanf("%d", &choice); 

        if(choice != TRUE && choice != FALSE)
            choice = FALSE; 
    }

    show(p_vec_int); 
    destroy_int_vector(p_vec_int); 
    p_vec_int = NULL; 

    return (EXIT_SUCCESS); 
}

//server definations

vector_int_t* create_vector(void)
{
    vector_int_t* p_vec = (vector_int_t*)malloc(sizeof(struct vector_int) * sizeof(int) );
    assert(p_vec);
    p_vec->p_arr = NULL;
    p_vec->size = 0;
    return (p_vec);
}

int push_back(vector_int_t* p_vec_int ,int new_element)
{
    p_vec_int->size += 1;
    p_vec_int->p_arr = (int*)realloc(p_vec_int->p_arr , p_vec_int->size * sizeof(int) );
    p_vec_int->p_arr[p_vec_int->size - 1] = new_element;
    return SUCCES;
}

int pop_back(vector_int_t* p_vec_int ,int* pop_backed_element)
{
    if(p_vec_int->size == 0)
        return (EMPTY_VECTOR);
    p_vec_int->size -= 1;
    *pop_backed_element = p_vec_int->p_arr[p_vec_int->size - 1];
    p_vec_int->p_arr = (int*)realloc(p_vec_int->p_arr ,p_vec_int->size * sizeof(int) );
    return (SUCCES);
}

int get_at(vector_int_t* p_vec_int, int index, int* p_data)
{
    if(index < 0 || p_vec_int->size < 0 || index > p_vec_int->size)
        return (OUT_OF_RANGE);
    *p_data = p_vec_int->p_arr[index];
    return (SUCCES);
}

int set_at(vector_int_t* p_vec_int ,int index, int new_element)
{
    if(index < 0 || p_vec_int->size < 0 || index > p_vec_int->size)
        return (OUT_OF_RANGE);
    p_vec_int->p_arr[index] = new_element;
    return (SUCCES);
}

void show(vector_int_t* p_vec_int)
{
    int i;
    for(i =0 ; i < p_vec_int->size ; ++i)
        printf(" %d : [ %d ] \n",i,p_vec_int->p_arr[i]);
}

int destroy_int_vector(vector_int_t* p_vec_int)
{
    free(p_vec_int->p_arr);
    free(p_vec_int);
}
  