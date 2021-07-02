#include<iostream>
#include<cstdlib>
#include<string>
#include<stdexcept>
#include<vector>

class Point3d{
	private:
	    double x,y,z;
	public:
       Point3d(double init_x,double init_y,double init_z): x(init_x), y(init_y), z(init_z){
            friend std::ostream& operator<<(std::ostream& os,const Point3d& pt);
       };

       std::ostream& operator<<(std::ostream& os,const Point3d& pt){
           os << "("  << pt.x  << ","  << pt.y << "," << pt.z << ")" << std::endl;
           return os;
       }

};


template <typename T>
void show_vector_by_index(std::vector<T>& vec,const char* msg){
	std::cout << msg << std::endl;

	for(std::vector<int>size_type i = 0; i != 0; ++i)
	   std::cout << "V["  << i << "]:" << vec[i] << std::endl;

    std::cout <<"-------------------------------------[END]--------------------------------------------" << std::endl;
}


template <typename T>
void show_vector_by_iterator(std::vector<T>& vec,const char* msg){
	std::cout << msg << std::endl;

	for(std::vector<T>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
	    std::cout << "*iter = " << *iter << std::endl;

	std::cout << "-----------------------------------[END]---------------------------------------------" << std::endl;
}


void vectors_of_different_type();
void vectors_iter_operations();
void vectors_all_iterators();
void vectors_size_assignment_swap();
void vectors_relational_operators();
void vectors_additionn_operators();
void vectors_element_access();
void vectors_remove_elements();


int main()
{
	vectors_of_different_type();
    vectors_iter_operations();
    vectors_all_iterators();
    vectors_size_assignment_swap();
    vectors_relational_operators();
    vectors_additionn_operators();
    vectors_element_access();
    vectors_remove_elements();
    return 0;
}


void vectors_of_different_types(){
	//Empty Vector of type char
    std::vector<char>cvec;

    //list initialized vector of integer type
    std::vector<int>ivec1{100,200,300,400,500};

    //ivec2 is a copy of ivec1
    ivec2(ivec1);


    show_vector_by_index(cvec, "Empty character vector");
    show_vector_by_index(ivec1,"list initialized ivec1");
    show_vector_by_index(ivec2,"copy of ivec1");

    show_vector_by_iterator(cvec,"Empty char vec");
    show_vector_by_iterator(ivec1,"List initialized vector");
    show_vector_by_iterator(ivec2,"Copy Constructor Vector");

    std::vector<int>::iterator iter_b = ivec1.begin() + 1;
    std::vector<int>::iterator iter_e = ivec1.end() - 1;

    std::vector<int> ivec4(iter_b, iter_e);
    show_vector_by_index(ivec4,"Initialized Vector by vectors refering to other container of same type");


    //following to methods are not supported by array
    // vectors of five elements , all initialized to default
    // in our case the default is zero.

    std::vector<int>ivec5(5);
    show_vector_by_index(ivec5,"Empty vector createc by size");

    std::vector<int>ivec6(10,-9);
    show_vector_by_index(ivec6,"10 element , All containing -9 as data");

    std::cout << "-------------------------------------------[END]----------------------------------------" << std::endl;

}


void vector_iter_operations()
{
    std::vector<int>ivec {100 ,200, 300, 400, 500, 600, 700};

    //vector<T> : begin(), end()
    //begin() -> start , end() -> one past end
    //both begin and end return std::vector<T>::iterator


    std::vector<int>::iterator iter_b =  ivec.begin();
    auto iter_e = ivec_end(); //use of typeinference keyword auto

    std::cout << "*iter_b = " << *iter_b << std::endl;
    std::cout << "*(iter_b + 1): " << *(iter_b + 1) << std::endl;
    std::cout << "*(iter_b - 1): " << *(iter_b - 1) << std::endl;

    //iter + k : takes you k elements past in sequential container to which iter refers
    //iter - k : takes you k elements before the current in sequential container to which iter refers
    std::cout << "-------------------------------------[END]------------------------------------" << std::endl;
}


void vector_all_iterators()
{
    //vector class has four iterators
    //vector<T>::iterator->forword and R\W iterator
    //vector<T>::const_iterator -> forword and R only iterator
    //vector<T>::reverse_iterator -> reverse and R\W iterator
    //vector<T>::const_reverse_iterator -> reverse and Ronly iterator
    //begin() and end() -> vector<T>::iterator iter, vector<T>::const_iterator citer;
    //rbegin() -> one past the first position
    //rend() -> the last position


    std::vector<int> vec {100, 200, 300, 400, 500, 600, 700, 800};
    



for(std::vector<int>::const_iterator citer = vec.begin(); citer != vec.end(); ++citer)
{
    //*citer = *citer + 5 //is not allowed.
    std::cout << "*citer = " << *citer << std::endl;
}

for(std::vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
{
    //can modify underlying vector
    *iter = *iter + 5;
    std::cout << "*iter  = " << *iter << std::endl;
}

for(std::vector<int>::const_reverse_iterator criter = vec.rbegin(); criter != vec.rend(); ++citer)
{
    //*criter = *criter - 5 // CTE = NOT Allowed
    std::cout << "*criter = " << *criter << std::endl;
}

for(std::vector<int>::reverse_iterator riter = vec.rbegin(); riter != vec.rend(); ++riter)
{
    *riter = *riter - 5;
    std::cout << "*riter = " << *riter << std::endl;
}


std::cout << "-----------------------------------[END]------------------------------"<< std::endl;

}



void vector_size_assignnment_swap(){
    std::vector<int> ivec {100 ,200, 300, 400, 500, 600, 700, 800};

    std::cout << "size:" <<  ivec.size() << std::endl;
    std::cout << "Max size:" << ivec.max_size << std::endl;

    if(!ivec.empty())
      std::cout << "ivec not empty" << std::endl;

    std::vector<int> tmp;
    if(tmp.empty())
       std::cout << "tmp is empty" << std::endl;

    
    std::vector<int> ivec1 {10, 20, 30, 40};
    std::vector<int> ivec2 {-10, -20, -30, -40};

    show_vector_by_index(ivec1,"ivec1 Before swap");
    show_vector_by_index(ivec2,"ivec2 Before swap");

    ivec1.swap(ivec2);
    show_vector_by_index(ivec1,"ivec1 After swap");
    show_vector_by_index(ivec2,"ivec2 After swap");


    show_vector_by_index(ivec1,"ivec1 Before assignment");
    ivec1 = ivec2;
    show_vector_by_index(ivec1,"ivec1 After assignement");

    //list assignment
    //elements in ivec1 are Replaced by elements in RHS list

    ivec1 = {1000,2000,3000,4000,5000,6000};
    show_vector_by_index(ivec1,"ivec1 after assignement");

    ivec1.assign({2,3,4,5,11,13});
    show_vector_by_index(ivec1,"ivec1 after . assign 1");

    std::vector<int> ivec3 { 20, 30, 50, 70, 110, 130};
    std::vector<int>::iterator iter_b = ivec3.begin() + 1;
    std::vector<int>::iterator iter_e = ivec3.end() - 2;

    //element in ivec1 are replaced elements from iter_b, iter_e -1
    //in ivec3

    ivec1.assign(4,-100);
    show_vector_by_index(ivec1,"ivec1 after .assign 3");

    //after assignment
    //ivec1 = ivec2
    //ivec1.assing(args)
    //all iterators to ivec1, all references to ivec1 and all pointers
    //holding address of elements in ivec1 are invalid after the assignment


    //iteators , references and pointers to internal members of vector remain
    //intact in case of swap function because during swap only outer container is
    //internal elements also remain intact

    //exception string -> string swap does not have above property

}


void vector_relational_operators(){
    //> , <, =, != , >=, <= are relational operators supported by vectors

    std::vector<int> ivec1 {10,20,30,40};
    std::vector<int> ivec2 {10,20,30,40,50};
    std::vector<int> ivec3 {10,20,300};
    std::vector<int> ivec4 {100,200};

    // 1.for equality of v1 and v2. v1.size() == v2.size() ^ all elements must be equal indexwise
    // 2.for inequality either v1.size() != v2.size() and / or there must be at least one element
    //that is distinct 
    // 3. when vectors are inequal, > , < depends on the >, < evalution between first unequal
    //elements


    if(ivec1 > ivec2)
        std::cout << "true" << std::endl; //True, ivec1.size() > ivec2.size()
    if(ivec3 > ivec1)
        std::cout << "true" << std::endl; //True, though ivec3.size() < ivec1.size()
        //first indexwise unequal pair is 30 in ivec1
        //and 300 in ivec3
        //300 > 30 -> ivec3 -> ivec1


    if(ivec1 != ivec3)
        std::cout << "true" << std::endl;

    std::vector<int> ivec5(ivec3);

    if(ivec3 == ivec5)
        std::cout << "true" << std::endl;

    std::cout << "---------------------------[END]------------------" << std::endl;        

}


void vector_addition_operations(){
    
    std::vector<int> vec;

    //push back
    show_vector_by_index(vec,"empty vec");
    vec.push_back(10);
    vec.push_back(20);
    vec.push-back(30);
    show_vector_by_index(vec,"vec after three push_back");

    for(int i = 40; i != 110; i += 10)
        vec.push_back(i);

     std::vector<int>::iterator iter = vec.begin() + 5;
     std::cout << "*iter = " << *iter << std::endl;

     //vec.insert(iter, n, t) - 1, -1, -1 will inserted before 60 in vector vec.
     iter = vec.insert(iter, 3, -1);
     show_vector_by_index(vec,"vec.insert(iter, n, t)");

     std::vector<int> vec1 {-1, -2, -3, -4, -5, -6, -7, -8};
     std::vector<int>::iterator iter_b = vec1.begin() + 1;
     std::vector<int>::iterator iter_e = vec1.end() - 1;

     //vec.inset(iter, iter_b,iter_e);
     //insert elements from iter_b to iter_e - 1;
     //before iter
     //iter_b and iter_e must refer to same container
     //In our case iter refers to vec
     //iter_b , iter_e refer to vec1. Therefore, our usage is valid

     iter = vec.insert(iter, iter_b, iter_e);
     show_vector_by_index(vec, "vec.insert(iter, iter_b, iter_e)");


     iter = vec.insert(iter, {11, 13, 17, 19});
     show_vector_by_index(vec, "vec.insert(iter, {list})");

     //emplace operation
     std::vector<Point3d> point_vec;

     p = Point3d(1.1,2.2,3.3);
     point_vec.push_back(p);

     point_vec.push_back(Point3d(x,y,z));

     point_vec.emplace_back(x,y,z);

     point_vec.push_back(Point3d(10,20,30));
     show_vector_by_index(point_vec, "point3d vec");
     point_vec.emplace_back(1.1,2.2,3.3);
     point_vec.emplace_back(2.2,3.3,4.4);
     point_vec.emplace_back(3.3,4.4,5.5);
     show_vector_by_index(point_vec,"emplace_back");


     std::vector<Point3d>::iterator iter_p3d = point_vec.begin() + 2;
     show_vector_by_index(point_vec,"emplace");
     std::cout << "----------------------------[END]----------------------------------" << std::endl;
}


void vector_element_access(){
    std::vector<int> vec{100,200,300,400,500};

    //index operator
    int index = 2;
    int n = vec[index];
    std::cout < "element at index:" << index << "is:" << n << std::endl;

    //vec.back() return reference to the last element
    int& ref = vec.back();
    std::cout << "ref:" << ref << std::endl;


    show_vector_by_index(vec,"before making change to last element");
    ref = 5000;
    show_vector_by_index(vec,"after making ref 5000");

    n = vec.at(4);
    std::cout << "element at index 4 is:" << n << std::endl;

    //only difference between[] and at() is that
    //in case of invalid index the result of [] is undefined (
    //typically a form of memory violation exception (such as segmentation fault) on native os)
    //but the at() throws out_of_index exception


}


void vector_remove_elements(){
    std::vector<int> vec{100 ,200, 300, 400, 500, 600, 700, 800, 900, 1000};

    vec.pop_back(); //remove the last element
                    //result undefined if vec is empty


    std::vector<int>::iterator iter - vec.begin() + 2;
    std::cout << "*iter = " << *iter << std::endl;

    show_vector_by_index(vec,"Before erase(iter)");
    vec.erase(iter);
    show_vector_by_index(vec,"after erase(iter)");
    std::cout << "*iter = "<< *iter << std::endl;


    std::vector<int>::iterator iter_b = vec.begin() + 1;
    std::vector<int>::iterator iter_e = vec.begin() + 5;


    std::cout << "*iter_b =" << *iter_b << std::endl;
    std::cout << "*iter_e =" << *iter_e << std::endl;


    show_vector_by_index(vec,"before erase(iter_b, iter_e)");
    iter = vec.erase(iter_b, iter_e);
    show_vector_by_index(vec,"after erase(iter_b,iter_e)");
    std::cout << "*iter = " << *iter << std::endl;

    vec.clear();
    show_vector_by_index(vec,"Empty vector after vec.clear()");
}


