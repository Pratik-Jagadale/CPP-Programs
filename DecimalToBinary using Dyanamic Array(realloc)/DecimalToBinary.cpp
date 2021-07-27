#include <iostream>
#include <cstdlib>
#include <cassert>

int DecimalToBinary(unsigned short DNum); /*declartion*/

/*Driver Code*/
int main(){
	unsigned short DNum;
	nxt:
	std::cout<<"Enter The Decimal Number(0 To 32000) : " <<std::endl;
	std::cin>>DNum;

	if(DNum > 32000 && DNum >= 0){
		std::cout<<"Please Enter the Valid Number..." <<std::endl;
		goto nxt;
	}

	DecimalToBinary(DNum);

	return EXIT_SUCCESS;
}

int DecimalToBinary(unsigned short DNum){
	int* binaryNumber= NULL;
	int arr_size = 0;
	int i = 0;
	while(DNum > 0){
		arr_size += 1; 
        binaryNumber = (int*)realloc(binaryNumber, arr_size * sizeof(int)); 
        assert(binaryNumber); 

		binaryNumber[i] = DNum % 2; /*ramainder*/
		DNum = DNum / 2;
		i++;
		
		/*I have used realloc for dynamic growing array */
	}

	//reversing array
	std::reverse(binaryNumber, binaryNumber + i);

	//printing the array
	std::cout<<"Binary Conversion :" <<std::endl;
	for(int j = 0;j < i ; j++)
		std::cout<<binaryNumber[j];

	return 0;
}
