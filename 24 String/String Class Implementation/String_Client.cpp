#include<iostream>
#include<stdexcept>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include"String.h"




int main()
{
	 String s1;
	 String s2("Implementation of string class");
	 String s3(s2);

	 std::cout << s1 << std::endl;
	 std::cout << s2 << std::endl;
	 std::cout << s3 << std::endl;

	 //Indexwise Traversal
	 std::cout << std::endl << "===================================================================================" << std::endl;
	 std::cout << "IndexWise Traversal" << std::endl;
	 for(ret_size i = 0; i < s2.length(); i++)
	 	std::cout << "s2[" << i << "] = " << s2[i] << std::endl;
      
    
     //Iterator Traversal
     std::cout << std::endl << "===================================================================================" << std::endl;
	 std::cout << "Iterator Traversal" << std::endl;
	 for(String::iterator iter = s2.begin(); iter != s2.end(); ++iter)
	 {
	 	std::cout << "*iter = " << *iter << std::endl;
	     if(islower(*iter))
	     	*iter -= 32;
	 }
	 	


     //Forword Read only
     std::cout << std::endl << "===================================================================================" << std::endl;
	 std::cout << "Read Only Iterator, Constant" << std::endl;
	 for(String::const_iterator citer = s2.cbegin(); citer != s2.cend(); ++citer)
	 {
	 	 std::cout << "*citer = " << *citer << std::endl;
	 	 //*citer = *citer + 5; //Not Allowed
	 }


	 //Reverse Iterator
	 std::cout << std::endl << "===================================================================================" << std::endl;
	 std::cout << "Reverse Iterator" <<std::endl;
	 for(String::reverse_iterator riter = s2.rbegin(); riter != s2.rend(); ++riter)
	     std::cout << "*riter = " << *riter << std::endl;



  return 0;
}
