#ifndef _LIST_H_
#define _LIST_H_
 
#include <cstdio>
#include <iostream>
#include <string>

#include "List_Exception.h"

#define SUCCESS         1

typedef int ret_t;
typedef int data_t;
typedef int len_t;

class book{
    friend class library;
    friend std::ostream& operator<<(std::ostream& os, const library& lib_obj);    
private:
    int p_book_name;
    book* prev;
    book* next;
    book(data_t new_book);
};

class library{
private:
    book* p_head_book;

    /*generic Function*/
    void generic_insert(book* p_beg_book,book* _mid_book,book* p_end_book);
    void generic_delete(book* p_book);
    book* search_book(data_t data);

public:

    /* create & destroy routine */
    library();
    ~library();

    /* insertion routines : */
    ret_t insert_first(data_t p_data);
    ret_t insert_end(data_t p_data);
    ret_t insert_before(data_t p_e_data, data_t p_new_data);
    ret_t insert_after(data_t p_e_data, data_t p_new_data);

    /* get & pop routines : */
    ret_t get_start(data_t* p_get_data);
    ret_t get_end(data_t* p_end_data);
    ret_t pop_start(data_t* p_pop_data);
    ret_t pop_end(data_t* p_pop_data);

    /* removal data routines */
    ret_t remove_start();
    ret_t remove_end();
    ret_t remove_data(data_t p_delete_book);

    /* Misc routines: */
    bool find_list_data(data_t p_data);
    len_t get_len()const;
    bool is_empty();

    friend std::ostream& operator<<(std::ostream& os, const library& lib_obj);

};

#endif /* _LIST_H_ */