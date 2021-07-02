#include<iostream>
#include<cstdlib>
#include<cctype>
#include<string>

void test(void);
void iterator_versions(void);
void insert_option(void);

int main()
{
    std::string s1; //empty string
    std::string s2("String in CPP"); //Initialization of string
    std::string s3 = "My String";
    std::string s4(s2);

    std::cout << std::endl << s1 << std::endl << s2 << std::endl << s3 << std::endl << s4 << std::endl;

    std::cout << std::endl << "======================================================================== " << std::endl;
    std::cout << "indexwise traversal" << std::endl;

    for(std::string::size_type i = 0 ; i != s2.length(); i++)
    	std::cout << "s2[" << i << "] =" << s2[i] << std::endl;

    std::cout << std::endl << "======================================================================== " << std::endl;
    std::cout << "Iterator Traversal" << std::endl;

    for(std::string::iterator iter = s3.begin(); iter != s3.end(); iter++)
    	std::cout << "*iter = " << *iter << std::endl;

    std::cout << std::endl << "======================================================================== " << std::endl;
    std::string::iterator b_iter = s4.begin() + 1;
    std::string::iterator e_iter = s4.end() - 1;

    std::cout << "b_iter = " << *b_iter << std::endl;
    std::cout << "e_iter = " << *e_iter << std::endl;

    std::string s5(b_iter,e_iter); // initialize a string using pointer parameters
    std::cout << std::endl << s5 << std::endl;

    std::cout << std::endl << "======================================================================== " << std::endl;
    test();

    std::cout << std::endl << "======================================================================== " << std::endl;
    iterator_versions();


    std::cout << std::endl << "======================================================================== " << std::endl;
    insert_option();

	return 0;
}


void test(void)
{
	 std::string s("This is C++ string class");


	 std::string::iterator iter_b = s.begin();
	 std::string::iterator iter_e = s.end();

     std::cout << "*iter_b = " << *iter_b << std::endl;
     std::cout << "*iter_e = " << *iter_e << std::endl;

	 std::string s6(iter_b,iter_e - 1);
	 std::string s7(s.begin() , s.end() );

	 std::cout << s6 << std::endl;
	 std::cout << s7 << std::endl;

	 std::cout << *(s.end() - 1) << std::endl;


}

void iterator_versions(void)
{
     std::cout << "Iterator Version" << std::endl;
     std::string s("This is a Sample of String");
 
     std::cout << std::endl << "******************************** " << std::endl;
     std::cout << std::endl << "forword Iterator, Read and Write, for Write change LowerCase Letter to UpperCase" << std::endl;
     std::cout << std::endl << "Original String S :  " << s << std::endl;
     for(std::string::iterator iter = s.begin(); iter != s.end(); ++iter)
     	if(islower(*iter))
     		*iter = *iter - 32;

     std::cout << std::endl << "After Change, S become = " << s << std::endl;

     std::cout << std::endl << "******************************** " << std::endl;
     std::cout << std::endl << "Forword Iterator, Read Only" << std::endl;
     for(std::string::const_iterator iter = s.cbegin(); iter != s.cend(); ++iter)
     {
     	std::cout << "*iter = " << *iter << std::endl;
        //	*iter = *iter + 5;  //NOt Allowed
     }

     std::cout << std::endl << "******************************** " << std::endl;
     std::cout << std::endl << "Reverse Read and Write Iterator" << std::endl;
    
     std::string s1("REVERSE STRING , CHECK UPPERCASE");
     std::cout << "Original String s1: "<< s1 << std::endl;

     for (std::string::reverse_iterator iter = s1.rbegin(); iter != s1.rend(); ++iter)
     {
     	std::cout << "*iter = " << *iter << std::endl;
          if(isupper(*iter))
          	 *iter = *iter + 32;
     }
         
     std::cout << "After Check s1: " << s1 << std::endl;


     std::cout << std::endl << "******************************** " << std::endl;
     std::cout << "Reverse Read Only Iterator " << std::endl;

     for(std::string::const_reverse_iterator iter = s1.crbegin(); iter != s1.crend(); ++iter)
     {
     	std::cout << "*iter = " << *iter << std::endl;
     	// *iter = *iter + 32 // Not allowed;
     }

}


void insert_option(void)
{
	std::cout << "Insertion operations:" << std::endl;
	std::string s1("Hello, C++ World");
	printf("s1 = %s\n",s1.c_str());
	s1.push_back('$');
	printf("s1 = %s\n",s1.c_str());

	std::string s2("HDKYCS");

     std::string::iterator iter = s2.begin();

     printf("s2 = %s\n",s2.c_str());
     iter = s2.insert(iter,'E');
      printf("s2 = %s\n",s2.c_str());
      printf("*iter = %c\n",*iter);


      std::string s3("C++ is Object Oriented Language");
     std::string s4("Java is Pure Object Oriented Language");

     std::string::iterator iter1 = s4.begin() + 4 ; // p
     std::string::iterator iter2 = s4.begin() + 4 + strlen("Pure");

     s3.insert(s3.begin(),iter1,iter2);
     std::cout << "s3:" << s3 <<std::endl;
}



