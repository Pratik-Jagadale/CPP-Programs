#include<iostream>
#include<stdexcept>
#include<cstdlib>
#include<cstring>

typedef size_t ret_size;
typedef char ret_char;

class String
{
	private:
	   ret_char* p_str;
	   ret_size size;
	public:

	    String(ret_char* p_init);	    
	    String(const String& other);   
	    String();	    
	    ret_size length();
	    

	   class iterator
	   {
	      private:
	        ret_char* p_iter;
	        int num;
	      public:
	         iterator(ret_char* p_init_iter);  
	         iterator(int val);    
	         iterator operator++();
	         iterator operator++(int);
	         iterator operator--();
	         iterator operator--(int);  
             bool operator==(const iterator& ref_obj);
             bool operator!=(const iterator& ref_obj);               
             ret_char operator*();
            
             //friend void operator=(const String::iterator& ref_obj,const String::iterator& k);
             iterator operator-=(const int& k);         
	   };

	   iterator begin();
	   iterator end();

       //====================================================================================================

	   class const_iterator
	   {
	   	  private:
	        const char* p_const_iter;
	      public:
	         const_iterator(ret_char* p_init_iter);         
	         const_iterator operator++();
	         const_iterator operator++(int);
	         const_iterator operator--();
	         const_iterator operator--(int); 
	         //const_iterator operator+(int& k);          
             bool operator==(const const_iterator& ref_obj);
             bool operator!=(const const_iterator& ref_obj);           
             ret_char operator*();
	   };

       const_iterator cbegin();
       const_iterator cend();

       //======================================================================================================*/


       class reverse_iterator
       {
       	  private:
       	  	ret_char* p_rev_str;
       	  public:
       	  	reverse_iterator(ret_char* p_init_str);
       	  	reverse_iterator operator++();
       	  	reverse_iterator operator--();
       	  	bool operator==(const reverse_iterator& ref_obj);
       	  	bool operator!=(const reverse_iterator& ref_obj);
       	  	ret_char operator*();

       };

       reverse_iterator rbegin();
       reverse_iterator rend();

       //====================================================================================
	   
	   ret_char operator[](int index);
	   ret_char* c_str();
	   ~String();
	   
	   friend std::ostream& operator<<(std::ostream& ,const String& other);
};


