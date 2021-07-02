#include <iostream>
#include <cassert>
#include <stdexcept>
#include "List.h"

using namespace std;

static library* p_lib = nullptr;
typedef int ret_t;

int main(){

     int select = 0;
     while()
     {
        printf("[1]create library :\n
                [1]Add book to first:\n
                [2]Add book to last :\n
                [3]Add book before :\n
                [4]Add book after :\n
                [5]View Book details :\n
                [6]view library :\n
                [7]Remove book :\n
                [8]Delete Library :\n
                [9]count of book available\n
                [10]Exit :\n
                please make valid selection\n");
        if(select > 10 &&select < 1)
        {      
                cout<<"please selecet valid index" <<endl;
                continue;
        }

        scanf("%d",&select);
        
        switch(select)
        {
            case 0:
                

            case 1:
                if(p_lib != nullptr)
                    printf("library already created\n");

                p_lib = new library;
                continue;
            case 2:
                Add_book();
                continue;
            case 3:

            case 4:

            case 5:

            case 6:

            case 7:

            case 8:
                if(p_lib == nullptr)
                    printf("library does not exist\n");

                delete(p_lib);
                p_lib = nullptr;
                printf("library deleted successfully :\n");
                continue;
            case 9:
                break;
            
        }




     }
    
    return 0;
}


void Add_book()
{
    if(p_lib == nullptr){
        printf("First create the library :\n");
        return ;
        }
    std::cout<<"Please Enter book Name :" <<std::cout;

}

void Add_book_to_last()
{

}
void Add_book_to_First()
{

}

void Add_book_at()
{

}
void View_Book_details()
{

}
void view_library()
{

}

void Remove_book()
{

}
void Delete_Library()
{

}
