#include<iostream>
#include<stdexcept>
#include<cstdlib>
#include<cstring>
#include"String.h"


String::String(ret_char* p_init)
{
	         size = strlen(p_init);
	         p_str = new ret_char[size + 1];
	         strncpy(p_str,p_init,size);
	         p_str[size] = '\0';
}

String::String(const String& other):p_str(new ret_char[other.size + 1]),size(other.size)
{
             strncpy(this->p_str,other.p_str,this->size);
}


String::String():p_str(NULL),size(0)
{

}

ret_size String::length()
{
	        return size;
}


String::iterator::iterator(ret_char* p_init_iter):p_iter(p_init_iter)
{

}


String::iterator String::iterator::operator++()
{
	              p_iter = p_iter + 1;
	              return p_iter;
}


String::iterator String::iterator::operator++(int)
{
                  iterator tmp(p_iter);
                  p_iter = p_iter + 1;
                  return tmp;
}


String::iterator String::iterator::operator--()
{
	              p_iter = p_iter - 1;
	              return p_iter;
}


String::iterator String::iterator::operator--(int)
{
	              iterator tmp(p_iter);
	              p_iter = p_iter - 1;
	              return tmp;
}

             /*iterator& operator=(const iterator& ref_obj)
             {
             	  this->p_str = ref_obj.p_str;
             	  return *this;
             }*/
String::iterator::iterator(int val)
{
	this->num = val;
}


String::iterator String::iterator::operator-=(const int& k)
{
	return *p_iter -= k;
	//return p_iter;
}

/*void operator=(const String::iterator& ref_obj,const String::iterator& k)
{
	 ref_obj.p_iter = k.p_iter;
}*/

bool String::iterator::operator==(const iterator& ref_obj)
{
             	return this->p_iter == ref_obj.p_iter;
}

             
bool String::iterator::operator!=(const iterator& ref_obj)
{
             	 return this->p_iter != ref_obj.p_iter;
}


ret_char String::iterator::operator*()
{
             	 return *p_iter;
}


String::iterator String::begin()
{
	       return iterator(p_str);
}

String::iterator String::end()
{
	       return iterator(p_str + size);
}

ret_char String::operator[](int index)
{
	       if(index < 0 || index > size)
	         throw std::out_of_range("Index out of range");
	       return *(p_str+index);
}

ret_char* String::c_str()
{
	        ret_char* p_copy = new ret_char[size + 1];
	        strncpy(p_copy,p_str,size);
	        return p_copy;
}

String::~String()
{
	      if(p_str)
	         delete [] p_str;
}


std::ostream& operator<<(std::ostream& os, const String& other)
{
	if(other.p_str)
	   os << other.p_str << std::endl;
	return os;
}

//==============================================================================================================


String::const_iterator::const_iterator(ret_char* p_init_iter):p_const_iter(p_init_iter)
{

}

/*iterator& operator=(const iterator& ref_obj)
             {
             	  this->p_str = ref_obj.p_str;
             	  return *this;
             }*/


String::const_iterator String::const_iterator::operator++()
{
	              p_const_iter = p_const_iter + 1;
	              return *this;
}


/*String::const_iterator String::const_iterator::operator++(int)
{
                  const const_iterator tmp(p_const_iter);
                  p_const_iter = p_const_iter + 1;
                  return tmp;
}*/


String::const_iterator String::const_iterator::operator--()
{
	              p_const_iter = p_const_iter - 1;
	              return *this;
}

/*String::const_iterator String::const_iterator::operator+(const int& k)
{
          return const_iterator(*p_const_iter + k);
}


/*String::const_iterator String::const_iterator::operator--(int)
{
	              const_iterator tmp(p_const_iter);
	              p_const_iter = p_const_iter - 1;
	              return tmp;
}*/


bool String::const_iterator::operator==(const const_iterator& ref_obj)
{
             	return this->p_const_iter == ref_obj.p_const_iter;
}

             
bool String::const_iterator::operator!=(const const_iterator& ref_obj)
{
             	 return this->p_const_iter != ref_obj.p_const_iter;
}


ret_char String::const_iterator::operator*()
{
             	 return *p_const_iter;
}


String::const_iterator String::cbegin()
{
	       return const_iterator(p_str);
}

String::const_iterator String::cend()
{
	       return const_iterator(p_str + size);
}


//==========================================================================================================

//Reverse Iterator
String::reverse_iterator::reverse_iterator(ret_char* p_init_str):p_rev_str(p_init_str)
{

}


String::reverse_iterator String::reverse_iterator::operator++()
{
	  p_rev_str = p_rev_str - 1;
	  return p_rev_str;
}

String::reverse_iterator String::reverse_iterator::operator--()
{
	p_rev_str = p_rev_str + 1;
	return p_rev_str;
}

bool String::reverse_iterator::operator==(const reverse_iterator& ref_obj)
{
       return (p_rev_str == ref_obj.p_rev_str);
}

bool String::reverse_iterator::operator!=(const reverse_iterator& ref_obj)
{
	return (p_rev_str != ref_obj.p_rev_str);
}

ret_char String::reverse_iterator::operator*()
{
	return *p_rev_str;
}


String::reverse_iterator String::rbegin()
{
	return reverse_iterator(p_str + size - 1);
}

String::reverse_iterator String::rend()
{
	return reverse_iterator(p_str - 1);
}


//======================================================================================================

