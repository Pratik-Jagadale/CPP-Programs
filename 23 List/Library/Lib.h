#ifndef _LIB_H_
#define _LIB_H_
 
#include <cstdio>
#include <iostream>
#include <string>

#include "lib_Exception.h"

#define SUCCESS         1

typedef int ret_t;
typedef std::string data_t;
typedef int len_t;

class book{
    friend class library;
    friend std::ostream& operator<<(std::ostream& os, const library& lib_obj);    
private:
    std::string p_book_name;
    std::string author_name;
    std::string subject;
    int book_id;
    book* prev;
    book* next;
    book(data_t p_book_name ,data_t author_name ,data_t subject ,int book_id );
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
    ret_t insert_first(data_t p_book_name ,data_t author_name ,data_t subject ,int book_id );
    ret_t insert_end(data_t p_book_name ,data_t author_name,data_t subject ,int book_id);
    ret_t insert_before(data_t p_e_data, data_t p_book_name ,data_t author_name, data_t subject ,int book_id);
    ret_t insert_after(data_t p_e_data, data_t p_book_name ,data_t author_name,data_t subject ,int book_id);

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
    bool find_list_data(data_t p_data , data_t* author_name, data_t* subject ,int* book_id);
    len_t get_len()const;
    bool is_empty();

    void show();
    friend std::ostream& operator<<(std::ostream& os, const library& lib_obj);

};

#endif /* _LIB_H_ */