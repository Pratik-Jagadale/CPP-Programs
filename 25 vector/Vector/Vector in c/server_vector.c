#include "vector.h"

vector_int_t* create_int_vector(void)
{
	vector_int_t* p_vec = (vector_int_t*)malloc(sizeof(struct vector_int));
	assert(p_vec);
	p_vec->p_arr = NULL;
	p_vec->size  = 0;
	return(p_vec);
}


int push_back(vector_int_t* p_vec_int , int new_element)
{
	p_vec_int->size += 1;
	p_vec_int->p_arr = (int*)realloc(p_vec_int->p_arr, p_vec_int->size * sizeof(int));
	p_vec_int->p_arr[p_vec_int->size - 1] = new_element;
	return (SUCCESS);
}


int pop_back(vector_int_t* p_vec_int, int* p_poped_back_element)
{
	if(p_vec_int->size == 0)
	   return (EMPTY_VECTOR);
	*p_poped_back_element = p_vec_int->p_arr[p_vec_int->size - 1];
	p_vec_int->size -= 1;
	p_vec_int->p_arr = (int*)realloc(p_vec_int->p_arr, p_vec_int->size * sizeof(int));
	return (SUCCESS);
}


int get_at(vector_int_t* p_vec_int, int index, int* p_data)
{
	if(index < 0 || index >= p_vec_int->size)
	   return (OUT_OF_RANGE);
	*p_data = p_vec_int->p_arr[index];
	return (SUCCESS);
}


int set_at(vector_int_t* p_vec_int, int index, int new_element)
{
	if(index < 0 || index >= p_vec_int->size)
	    return (OUT_OF_RANGE);
	 p_vec_int->p_arr[index] = new_element;
	 return (SUCCESS);
}


void show(vector_int_t* p_vec_int)
{
	int i;
	printf("[START]");
	for(i = 0; i < p_vec_int->size; ++i)
	    printf("[%d]",p_vec_int->p_arr[i]);
	puts("[END]");
}



int destroy_int_vector(vector_int_t* p_vec_int)
{
	free(p_vec_int->p_arr);
	free(p_vec_int);
	return (SUCCESS);
}



