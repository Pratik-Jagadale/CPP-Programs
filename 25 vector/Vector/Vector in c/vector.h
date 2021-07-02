#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define SUCCESS 1
#define OUT_OF_RANGE 2
#define EMPTY_VECTOR 3

typedef struct vector_int
{
	int* p_arr;
	size_t size;
}vector_int_t;

/* Interface functions */
vector_int_t* create_int_vector(void);
int push_back(vector_int_t* p_vec_int, int new_element);
int pop_back(vector_int_t* p_vec_int, int* p_poped_back_element);
int get_at(vector_int_t* p_vec_int, int index, int* p_data);
int set_at(vector_int_t* p_vec_int, int index, int new_element);
void show(vector_int_t* p_vec_int);
int destroy_int_vector(vector_int_t* p_vec_int);


