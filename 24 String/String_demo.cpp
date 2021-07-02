#include <iostream>
#include <string>

void iterator_version();

int main(int argc, char const *argv[])
{
	//fore ways to declare string .
	std::string s1;
	std::string s2("Hello");
	std::string s3 = {"Hello World"};
	std::string s4(s2);

	std::cout<< s1 << std::endl << s2 << std::endl << s3 << std::endl <<s4 <<std::endl;

	//index wise traverse
	std::cout << "using Indices" <<std::endl;
	for(std::string::size_type i = 0 ; i != s2.length(); i++)
	{
		std::cout<< "s2" << i << "]" << s2[i] << std::endl;
	}

	std::cout << "using Iterrator" <<std::endl;
	for(std::string::iterator iter = s3.begin() ; iter != s3.end() ; ++iter)
	{
		std::cout << "*iter" << *iter << std::endl; 	
	}

	std::string::iterator b_iter = s2.begin() + 1; // 
	std::string::iterator e_iter = s2.end() - 1; 	//s2.end() implicitely takes the one charcter less from end of string //then it will be -2

	std::cout << "cpy using iterator" <<std::endl;
	std::string s5(b_iter , e_iter);
	std::cout <<"s2 :" <<s2 <<std::endl <<"s5 : " <<s5 <<std::endl; 

	return 0;
}

void iterator_version()
{
	std::string s("India is my Country , And all indian are my bother and sisters ...");

	std::string::iterator b_iter = s.begin();
	std::string::iterator e_iter = s.end();
	std::cout << " iterator : " <<s <<std::endl;
	 for(std::string::iterator::size_type i = 0 ; i < e_iter ; i++)
	 	std::cout << " iter* " <<*iter <<std::endl;

	std::string::const_iterator b_citer = s.cbegin() + 20;
	std::string::const_iterator e_citer = s.cend();
	std::cout << "const iterator : " <<s <<std::endl;

	std::string::reverse_iterator b_riter = s.rend();
	std::string::reverse_iterator r_riter = s.rbegin();
	std::cout << "reverse iterator : " <<s <<std::endl;

	
}
