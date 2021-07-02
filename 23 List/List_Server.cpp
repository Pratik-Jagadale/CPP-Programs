#include <iostream>

#include "List.h"
#include "List_Exception.h"

    /*  generic Function  */
book::book(data_t new_data) :p_book_name(new_data),prev(0),next(0)
{

}


void library::generic_insert(book* p_beg_book,book* p_mid_book,book* p_end_book)
{
    p_mid_book->prev = p_beg_book;
    p_mid_book->next = p_end_book;
    p_beg_book->next = p_mid_book;
    p_end_book->prev = p_mid_book;
}

void library::generic_delete(book* p_delete_book)
{
    
    p_delete_book->prev->next = p_delete_book->next;
    p_delete_book->next->prev = p_delete_book->prev;
    delete p_delete_book;
    p_delete_book = 0;
}

book* library::search_book(data_t p_data)
{
    
    for(book* p_run = this->p_head_book->next; p_run != this->p_head_book ; p_run = p_run->next )
        if(p_run->p_book_name == p_data)
            return (p_run);
    return 0;
}


/* create & destroy routine */
library::library()
{
    p_head_book = new book(0);
    p_head_book->next = p_head_book;
    p_head_book->prev = p_head_book;

}

library::~library()
{
    
    for(book *p_run = p_head_book->next , *p_run_next = 0 ; p_run == p_head_book ; p_run = p_run_next)
    {
        p_run_next = p_run->next;
        delete p_run;
    }
    delete p_head_book;
    p_head_book = 0;
}

/* insertion routines : */
ret_t library::insert_first(data_t new_data)
{
    generic_insert(p_head_book, new book(new_data) , p_head_book->next );
    return (SUCCESS);
}

ret_t library::insert_end(data_t p_data){
    generic_insert(this->p_head_book->prev, new book(p_data) , this->p_head_book);
    return (SUCCESS);
}

ret_t library::insert_before(data_t e_data, data_t new_data)
{
    book* p_edata = search_book(e_data);

    if(!p_edata)
        throw std::underflow_error("data_not_found");
        
    generic_insert(p_edata->prev, new book(new_data) , p_edata);
    return (SUCCESS);
}

ret_t library::insert_after(data_t e_data, data_t new_data)
{
    book* p_ebook = search_book(e_data);
    if(!p_ebook)
        throw data_not_found();
    
    generic_insert(p_ebook,new book(e_data) , p_ebook->next );
    return (SUCCESS);
}

/* get & pop routines : */
ret_t library::get_start(data_t* p_get_data)
{
    if(is_empty())
        throw list_is_empty();
    *p_get_data = p_head_book->next->p_book_name ;
    return SUCCESS;
}

ret_t library::get_end(data_t* p_end_data)
{
    if(is_empty())
        throw list_is_empty();
    *p_end_data = p_head_book->prev->p_book_name;
    return SUCCESS;
}

ret_t library::pop_start(data_t* p_pop_data)
{
    if(is_empty())
        throw list_is_empty();
    *p_pop_data = this->p_head_book->next->p_book_name; 
    generic_delete(this->p_head_book->next);
    return SUCCESS;
}

ret_t library::pop_end(data_t* p_pop_data)
{
    if(is_empty())
        throw list_is_empty();

    *p_pop_data = p_head_book->prev->p_book_name;
    generic_delete(p_head_book->prev);
    return (SUCCESS);
}

/* removal data routines */
ret_t library::remove_start()
{
    if(is_empty())
        throw list_is_empty();

    generic_delete(this->p_head_book->next);
    return SUCCESS;
}

ret_t library::remove_end()
{
    if(is_empty())
        throw list_is_empty();

    generic_delete(p_head_book->prev);
    return (SUCCESS);
}

ret_t library::remove_data(data_t p_delete_book)
{
    book* p_run = search_book(p_delete_book);
    if(!p_run)
        throw data_not_found();

    generic_delete(p_run);
    return (SUCCESS);
}

/* Misc routines: */
bool library::find_list_data(data_t p_data)
{
    book* p_run = search_book(p_data);
    if(!p_run)
        return false;
    return true;
}

len_t library::get_len()const
{
    len_t lib_len = 0;
    for(book* p_run = p_head_book->next ; p_run != p_head_book ; p_run = p_run->next,++lib_len);

    return (lib_len); 
}

bool library::is_empty()
{
   return ( (p_head_book == p_head_book->next) && (p_head_book == p_head_book->prev) );
}

std::ostream& operator<<(std::ostream& os, const library& lib_obj)
{
    os <<"[START]<->";
    for(book* p_run = lib_obj.p_head_book->next ; p_run != lib_obj.p_head_book; p_run = p_run->next)
            os << "[" <<p_run->p_book_name <<"]<->";
    os << "END" <<std::endl;
    return os;
}
