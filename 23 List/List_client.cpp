#include <iostream>
#include <cassert>
#include <stdexcept>
#include "List.h"

int main(){

    library* p_lib = new library;
    data_t data = 0;

    assert(p_lib->is_empty() == true);
    assert(p_lib->get_len() == 0);

     //
    try
    {
        p_lib->get_start(&data);
    }
    catch (const list_is_empty &e)
    {
        std::cout << e.what() << '\n';
    }
    //
    try
    {
        p_lib->pop_start(&data);
    }
    catch (const list_is_empty &e)
    {
        std::cout << e.what() << '\n';
    }
    //
    try
    {
        p_lib->pop_end(&data);
    }
    catch (const list_is_empty &e)
    {
        std::cout << e.what() << '\n';
    }
    //
    try
    {
        p_lib->remove_start();
    }
    catch (const list_is_empty &e)
    {
        std::cout << e.what() << '\n';
    }
    //
    try
    {
        p_lib->remove_end();
    }
    catch (const list_is_empty &e)
    {
        std::cout << e.what() << '\n';
    }

/////////////////////////////
  for(data = 1 ; data < 5 ; ++data)
            p_lib->insert_first(data);
    std::cout << *p_lib;

    for(data = 5 ; data != 9 ; ++data)
        p_lib->insert_end(data);
    std::cout << *p_lib;

    p_lib->insert_after(5 , 500);
    std::cout << *p_lib;
    p_lib->insert_before(5, 400);
    std::cout << *p_lib;

    try{        
        p_lib->insert_after(550 , 1);
    }catch(data_not_found& e)
    {
        std::cout <<e.what() <<std::endl;
    }

    try{        
        p_lib->insert_before(6 , 4);
    }catch(data_not_found& e)
    {
        std::cout <<e.what() <<std::endl;
    }

    p_lib->get_start(&data); 
    std::cout << "start:" << data << std::endl; 

    p_lib->get_end(&data); 
    std::cout << "end:" << data << std::endl; 

    std::cout << *p_lib; 

    p_lib->pop_start(&data); 
    std::cout << "poped start:" << data << std::endl; 
    std::cout << *p_lib; 

    p_lib->pop_end(&data); 
    std::cout << "poped end:" << data << std::endl; 
    std::cout << *p_lib; 

    p_lib->remove_start(); 
    std::cout <<"After Remove start : " <<*p_lib; 

    p_lib->remove_end(); 
    std::cout <<"After remove end : " <<*p_lib; 

    p_lib->remove_data(400); 
    std::cout <<"After remove data : " <<*p_lib; 

    assert(p_lib->is_empty() == false); 

    if(p_lib->find_list_data(4) == true)
        std::cout << "4 is present in list" << std::endl; 
    
    if(p_lib->find_list_data(500) == false)
        std::cout << "500 is not present in the list" << std::endl; 

    std::cout << "Length:" << p_lib->get_len() << std::endl; 

    delete p_lib; 
    p_lib = 0; 

    return 0;
}
