#include <iostream>
#include <cassert>
#include <stdexcept>
#include <string>
#include "Lib.h"

int main(){

    library* p_lib = new library;

    assert(p_lib->is_empty() == true);
    assert(p_lib->get_len() == 0);

    p_lib->insert_first("PQR" ,"Jagadale" , "data structure" , 1);
     p_lib->insert_first("xyz" ,"Pratik" , "algorithm," , 1);
   // p_lib->show();
   // std::cout << *p_lib ;

    std::string p_data = "PQR" , author_name , subject;
    int book_id;
    p_lib->find_list_data(p_data,&author_name, &subject , &book_id);

    std::cout<<"Book Name :"<< p_data <<" Author Name: " <<author_name <<" Subject:" <<subject <<" book id:" <<book_id <<std::endl;

    delete p_lib; 
    p_lib = 0; 

    return 0;
}
