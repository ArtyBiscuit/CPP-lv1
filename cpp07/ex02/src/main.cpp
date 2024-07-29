#include "Array.hpp"

int main(void){

	try{
		std::cout << "\tTest 1." << std::endl;
		Array<int> empty_array;
		std::cout << empty_array[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try{
		std::cout << "\tTest 2." << std::endl;
		Array<int> array(3);
		std::cout << array[0] << std::endl;
		std::cout << array[1] << std::endl;
		std::cout << array[2] << std::endl;
		std::cout << array[3] << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try{
		std::cout << "\tTest 3." << std::endl;
		Array<int> array(3);
		array[0] = 26;
		array[1] = 51;
		array[2] = 42;
		std::cout << array[0] << std::endl;
		std::cout << array[1] << std::endl;
		std::cout << array[2] << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try{
		std::cout << "\tTest 3." << std::endl;
		Array<int> array(3);
		array[0] = 26;
		array[1] = 51;
		array[2] = 42;
        std::cout << "Array 1" << std::endl;
		std::cout << array[0] << std::endl;
		std::cout << array[1] << std::endl;
		std::cout << array[2] << std::endl;

		Array<int> array_tmp;
        std::cout << "Array-2 copy from Array-1" << std::endl;
		array_tmp = array;
        std::cout << "Array 2" << std::endl;
		std::cout << array_tmp[0] << std::endl;
		std::cout << array_tmp[1] << std::endl;
		std::cout << array_tmp[2] << std::endl;
        std::cout << "Set new valus (186) in array-2 on index (1)" << std::endl;
		array_tmp[1] = 186;
        std::cout << "Array 2" << std::endl;
		std::cout << array_tmp[0] << std::endl;
		std::cout << array_tmp[1] << std::endl;
		std::cout << array_tmp[2] << std::endl;
        std::cout << "Array 1" << std::endl;
		std::cout << array[0] << std::endl;
		std::cout << array[1] << std::endl;
		std::cout << array[2] << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	


	return 0;
}