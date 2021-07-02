#include<iostream>
#include<cstdlib>
#include<string>
#include<stdexcept>

void string_creation_ops();
void string_assignment_swap_and_relational_ops();
void string_insert_ops();
void string_access_ops();
void string_erase_ops();
void show_string_by_index(std::string& s);
void show_string_by_iterator(std::string& s);
void string_misc_ops();



void    string_concat_op();
void	string_additional_creation_ops();
void	string_additional_insert_erase_ops();
void	string_substring_op();
void	string_find_op();
void    string_replace_op();
void    string_cmp_ops();
void    string_fmt_ops();



int main()
{
	string_creation_ops();
	string_assignment_swap_and_relational_ops();
	string_insert_ops();
	string_access_ops();
	string_erase_ops();


	show_string_by_index(std::string("String class in STL"));
	show_string_by_iterator(std::string("ABCD"));

	string_misc_ops();
	return 0;
}

void string_creation_ops()
{
	 std::string s1;                     //create empty string
	 std::string s2 = "Initialized String";           //Initialized string.
	 std::string s3("My String");
	 std::string s4(s3 +" " + "Copy Constructed string");           //copy constructed string.


	 std::cout << "s1:" << s1 << std::endl;
	 std::cout << "s2:" << s2 << std::endl;
	 std::cout << "s3:" << s3 << std::endl;
	 std::cout << "s4:" << s4 << std::endl;


	 std::string s5({'C' , '+' , '+' , ' ' , 'R', 'u' , 'l' , 'e' , 's'});

	 std::cout << "s5:" << s5 << std::endl;

	 std::string::iterator b_iter = s5.begin() + 1;
	 std::string::iterator e_iter = s5.end() - 1;

	 std::string s6(b_iter, e_iter);
	 std::cout << "s6:" << s6 << std::endl;

	 std::string s7(5, 'V');
	 std::cout << "s7:" << s7 << std::endl;

	 std::cout << "----------------------------------[END]--------------------------------" << std::endl; 
}


void string_assignment_swap_and_relational_ops()
{
	std::string s1 = "Hello";
	std::string s2 = "World";

	std::cout << "s1:" << s1 << std::endl;
	std::cout << "s2:" << s2 << std::endl;

	std::cout << "Before assignment:s1:" << s1 << std::endl;
	s1 = s2;
	std::cout << "After assignemtn (s1 = s2) s1:" << s1 << std::endl;
    s1 = {'n','e','w',' ','w','a','y','!'};
    std::cout << "After assignment s1 = {c1, c2..} :" << s1 << std::endl;
    std::cout << "s1:" << s1 << std::endl;


    std::cout << "===========assign()================" << std::endl;
    std::string::iterator b_iter = s1.begin() + 1;
    std::string::iterator e_iter = s1.end() - 1;
    s2.assign(b_iter, e_iter);
    std::cout << "s2 after s2.assign(iter1, iter2):" << s2 << std::endl;
    s2.assign({'t','e','s','t'});
    std::cout << "s2 after s2.assign({list}) :" << s2 << std::endl;
    s2.assign(5,'Z');
    std::cout << "s2 after s2.assign(n, t): " << s2 << std::endl;
    
    std::cout << "Before swap:s1: " << s1 << "s2:" << s2 << std::endl;
    s1.swap(s2);
    std::cout << "After swap s1: " << s1 << "s2:" << s2 << std::endl;

    std::string s3("Vishal");
    std::string s4("Intel");

    if(s4 < s3)
    	std::cout << s4 << " < " << s3 << "is true" << std::endl;

    if(s3 > s4)
    	std::cout << s3 << " > " << s4 << std::endl;

    std::string s5(s4);

    if(s3 != s5)
    	std::cout << s3 << " != " << s5 << "is true" << std::endl;

    if(s4 == s5)
    	std::cout << s4 << " == " << s5 << "is true" << std::endl;

    std::string s6("abcde");
    std::string s7("abcdE");

    if(s6 > s5)
    	std::cout << s6 << " > " << s7 << std::endl;

    std::cout << "s6.size():" << s6.size() << std::endl;
    std::cout << "s6.max_size():" << s6.max_size() << std::endl;

    if(!s6.empty())
    	std::cout << "s6 is not empty" << std::endl;

    std::string s8;
    if(s8.empty())
    	std::cout << "s8 is empty" << std::endl;

    std::cout << "-------------------------------[END]---------------------" << std::endl;

}


void string_insert_ops()
{
	std::string s1("CDE");
	std::cout << "s1:" << s1 << std::endl;
	s1.push_back('F');
	std::cout << "s1.push_back(e):" << s1 << std::endl;

	std::string::iterator iter = s1.begin();
	std::string s2("AB");
	for(std::string::size_type i = 0; i != s2.size(); ++i)
		iter = s1.insert(iter, s2[i]);
	std::cout << "after s1.insert(p,iter):s1:" << s1 << std::endl;

	std::string::iterator b_iter  = s1.begin() + 2;
	std::string::iterator e_iter  = s2.end() - 1;

	std::string s3("Hello World");
	iter = s3.begin() + 6;
	std::cout << *iter << std::endl;
	iter = s3.insert(iter, b_iter, e_iter);
	std::cout << "after s3.insert(iter, b_iter, e_iter):" << s3 << std::endl;


	std::string s4("55");
	std::cout << "s4:" << s4 << std::endl;
	iter = s4.begin() + 1;
	iter = s4.insert(iter, 4, '0');
	std::cout << "aftere s4.insert(iter, n, t): s4:" << s4 << std::endl;

	iter = s4.begin();
	s4.insert(iter, {'a','b','c'});
	std::cout << "after s4.insert(iter, {c1, c2, ...}):s4:" << s4 << std::endl;
    std::cout << "-------------------------[END]---------------------" << std::endl;


}


void string_access_ops()
{
	std::string s("Hello");

	char& c_first = s.front();
	char& c_last  = s.back();

	std::cout << "First character in a string: " << c_first << std::endl;
	std::cout << "Second character in a string: " << c_last << std::endl;


	int i = 6;
	//std::cout << "s[" << i << "]:" << s[i] << std::endl;
	try
	{
		 std::cout << "s.at(" << i << "):" << s.at(i) << std::endl;

	}catch(std::out_of_range& e)
	{

         std::cout << e.what() << std::endl;
	}
	
	//at will throw out_of_range exception if i < 0 || i >= s.size()
	//the result of subscript when i < 0 or i >= s.size() is undefined
	std::cout << "--------------------------------------[END]-------------------------" << std::endl;

}


void string_erase_ops()
{
	std::string s("Hello");
	std::size_t size = s.size();

	std::cout << "s.pop_back():" << std::endl;
	for(std::string::size_type i = 0; i < size; ++i)
	{
		s.pop_back();
		std::cout << "s:" << s << std::endl;
	}

	s = "Hello, World!";
	std::string::iterator iter = s.begin() + 3;
	std::cout << "s:" << s <<  std::endl;
	s.erase(iter);
	std::cout << "after s.erase(iter):s:" << s << std::endl;
	s.clear();
	std::cout << "s:" << s << std::endl;

	std::cout << "---------------------------------------------[END]------------------------------------" << std::endl;
}


void show_string_by_index(std::string& s)
{
	for(std::string::size_type i = 0; i != s.size(); ++i)
		std::cout << "s[" << i << "]:" << s[i] << std::endl;
	std::cout << "-------------------------------------[END]---------------------------------" << std::endl;
}

void show_string_by_iterator(std::string& s)
{
	std::cout << "r/w forward" << std::endl;
	for(std::string::iterator iter = s.begin(); iter != s.end(); ++iter)
	{
		*iter = *iter + 32;
		std::cout << "*iter = " << *iter << std::endl;
	}

	std::cout << "ro forward" << std::endl;
	for(std::string::const_iterator iter = s.cbegin(); iter != s.end(); ++iter)
	{
		//*iter = *iter + 32; //CTE
		std::cout << "*citer  = " << *iter << std::endl;
	}


	std::cout << "reverse rw" << std::endl;
	for(std::string::reverse_iterator iter = s.rbegin(); iter != s.rend(); ++iter)
	{
		*iter = *iter - 32;
		std::cout << "*iter = " << *iter << std::endl;
	}


	std::cout << "reverse ro" << std::endl;
	for(std::string::const_reverse_iterator iter = s.crbegin(); iter != s.crend(); ++iter)
		std::cout << "*iter = " << *iter << std::endl;


	std::cout << "----------------------------------------------[END]--------------------------------" << std::endl;

}



void string_misc_ops()
{
	string_concat_op();
	string_additional_creation_ops();
	string_additional_insert_erase_ops();
	string_substring_op();
	string_find_op();
	string_replace_op();
	string_cmp_ops();
	string_fmt_ops();
}

void string_concat_op()
{
	std::string s1("Hello");
	std::string s2("World");
	std::cout << "s1 + s2" << s1 + s2 << std::endl;
	std::string msg = s1 + "," + s2 + "!"; // n number of strings can be added
	std::cout << "msg:" << msg << std::endl;
}


void string_additional_creation_ops()
{
	std::cout << "Additional creation operations:" << std::endl;
	//string s(cp, n);
	std::string s = "Hello, World!";
	char* p = &s[6];
	std::string s1(p, 5);
	std::cout << "s1:" << s1 << std::endl;


	//string s(s2, pos2)
	std::string s2(s, 6);
	std::cout << "s2:" << s2 << std::endl;


	//string s(s2, pos2, len2)
	std::string s3(s, 4, 6);
	std::cout << "s3:" << s3 << std::endl;
	std::cout << "--------------------------------------------------[END]-----------------------------------" << std::endl;
}


void string_additional_insert_erase_ops()
{
	//s.insert(pos, n, t);
	//s.erase(pos, n);
	std::cout << "Additional insert and erase operations" << std::endl;
	std::string s("Hello");
	std::cout << "Before: s:" << s << std::endl;
	s.insert(s.size() , 4, '!');
	std::cout << "After:s:" << s << std::endl;

	s.erase(s.size() - 2, 4);
	std::cout << "s:" << s << std::endl;
	std::cout << "----------------------------------[END]----------------------------" << std::endl;
}

void string_substring_op()
{
	//s.substr(pos, n); where pos should be valid index (0 <= pos < s.size())
	// n is length of chars
    // also the string s should have n chars from pos.

    std::cout << "substring operations" << std::endl;
    std::string s("The C++ Programming Language");
    std::string sub_str1 = s.substr(0, 3); //i to j - 1
    std::cout << "sub_str1:" << sub_str1 << std::endl;
    std::string sub_str2 = s.substr(5); //i to s.size() - 1
    std::cout << "sub_str2:" << sub_str2 << std::endl;

    try
    {
    	std::string substr3 = s.substr(s.size() + 3);

    }catch(std::out_of_range& e){
    	std::cout << e.what() << std::endl;
    }

    std::cout << "-------------------------------------[END]----------------------------" << std::endl;
}


void string_find_op()
{
	std::string s("AAbbAbbbbbAAccAAbbAA");
	std::string f_str("AA");
	char* cf_str = "AA";
	char f_char = 'A' ;
	std::size_t found_pos;

	found_pos = s.find(f_char, 0);
	std::cout << "s.find(f_char, 0):" << found_pos << std::endl;

	found_pos = s.find(f_char, 1);
	std::cout << "s.find(f_char, 1):" << found_pos << std::endl;

	found_pos = s.find(f_char, 7);
	std::cout << "s.find(f_char, 7):" << found_pos << std::endl;

	found_pos = s.find(f_str, 0);
	std::cout << "s.find(f_str, 0):" << found_pos << std::endl;

	found_pos = s.find(f_str, found_pos + 1);
	std::cout << "s.find(f_str, 1):" << found_pos << std::endl;

	found_pos = s.find(cf_str, 0);
	std::cout << "s.find(cf_str, 0):" << found_pos << std::endl;

	found_pos = s.find(cf_str, found_pos + 1);
	std::cout << "s.find(cf_str, found_pos + 1):" << found_pos << std::endl;

	s.assign("The C Programming Language. The C++ Programming Language");
	char name[] = "The C Programming Language";


	found_pos = s.find(&name[6], 0 ,11);
	std::cout << "s.find(&name[6], 0, 11):" << found_pos << std::endl;

	std::cout << "---------------------------------------------[END]--------------------------------------" << std::endl;


	s.assign("AAbbAbbbbbAAccAAbbAA");

	/* s.rfind(args) */
	found_pos = s.rfind(f_char);
	std::cout << "s.rfind(f_char):" << found_pos << std::endl;

	found_pos = s.rfind(f_char, found_pos - 1);
	std::cout << "s.rfind(f_char, found_pos-1):" << found_pos << std::endl;


	found_pos = s.rfind(f_char, found_pos - 1);
	std::cout << "s.rfind(f_char, found_pos-1):" << found_pos << std::endl;


	s.assign("The C++ Language. DS in C++. Algorithms in C++. Templates in C++!!");
	f_char = 'C';
	f_str.assign("c++");


	found_pos = s.find_first_of(f_char, 0);
	std::cout << "s.find_first_of(f_char,0):" << found_pos << std::endl;


	found_pos = s.find_first_of(f_char, found_pos + 1);
	std::cout << "s.find_last_of(f_char):" << found_pos << std::endl;


	found_pos = s.find_last_of(f_char, found_pos - 1);
	std::cout << "s.find_last_of(f_char, found_pos - 1):" << found_pos << std::endl;

}


void string_replace_op(){
	/* s.replace(range, arg) */
	std::string s("The C++ Programming Language");
	std::string r_str1("The Haskell World");
	std::string r_str2("A magical evening");
	char msg[] = "Functional Programming";
	char artical[] = "The C programming language";
	char word[] = "magical";

	std::cout << "s:" << s << std::endl;
	s.replace(4, 3, std::string("Python"));
	std::cout << "s:" << s << std::endl;


	std::string::iterator b_range_iter = s.begin() + 4;
	std::string::iterator e_range_iter = s.begin() + 10;
	s.replace(b_range_iter, e_range_iter, std::string("C++"));

	s.replace(0, 3, r_str2, 2, 7);
	std::cout << "s:" << s << std::endl;

	s.replace(0, 7, &artical[0], 3);
	std::cout << "s:" << s << std::endl;

	s.replace(0, 7, 3, '!');
	std::cout << "s:" << s << std::endl;

	b_range_iter = s.begin();
	e_range_iter = s.begin() + 3;


	s.replace(b_range_iter, e_range_iter, {'T', 'h', 'e'});
	std::cout << "s:" << s << std::endl;
	s.replace(b_range_iter, e_range_iter, r_str2.begin() + 2, r_str2.begin() + 9);
	std::cout << "s:" << s << std::endl;
	std::cout << "---------------------------------------------[END]--------------------------------------" << std::endl;
}


void string_cmp_ops()
{
	std::string s1("Hello");
	std::string s2(s1);
	std::string s3("Hellish");
	std::string s4("ll");
	char* cp1 = "Hellish";
	char* cp2 = "ll";


	std::cout << "s1.compare(s2):" << s1.compare(s2) << std::endl;
	std::cout << "s1.compare(2,2,s4):" << s1.compare(2,2,s4) << std::endl;
	std::cout << "s1.compare(2,2,s3,2,2):" << s1.compare(2,2,s3,2,2) << std::endl;
	std::cout << "s1.compare(cp1):" << s1.compare(cp1) << std::endl;
	std::cout << "s1.compare(2,2,cp2):" << s1.compare(2,2,cp2) << std::endl;
	std::cout << "s1.compare(2,2,cp1,2):" << s1.compare(2,2,cp1+2,2) << std::endl;
	std::cout << "----------------------------------------[END]-------------------------" << std::endl;
}


void string_fmt_ops(){
	int n = -1345435; 
	long int lng_i = -35433463535; 
	long long int lng_lng_i = -3453625252525; 
	unsigned int un = 235425235;
	unsigned long int u_lng_i = 3454356436; 
	unsigned long long int u_lng_lng_i = 365343643646; 
	float f = 343536.345345; 
	float d = -3635.34563; 
	std::cout << "std::to_string(n):" << std::to_string(n) << std::endl; 

	/* 
		
	int 
	long int 
	long long int 				std::to_string()
	unsigned int  				--------------->  string 
	unsigned long int 			<---------------
	unsigned long long int 
	float 
	double 

	string -> int -> stoi()
	string -> long -> stol()
	string-> long long -> stoll() 

	string -> unsinged int -> stoul() 
	string -> unsigned long long int -> stoull() 
	
	string -> float -> stof() 
	string -> double -> stod() 
	string -> long double -> stold() 

*/ 
}