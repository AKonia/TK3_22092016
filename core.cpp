#include <iostream>
#include "StringArray.hpp"
using namespace std;

// Программа с реализованным классом одномерных массивом строк

int main()
{
	const size_t ARR_SIZE = 10;
	String * arr = new String[ARR_SIZE];
	for(int i = 0; i < ARR_SIZE; i++)
		arr[i] = "Hello World \n";
	for(size_t i = 0; i < ARR_SIZE; i++)
		arr[i][11] = i + '0';
	StringArray sa(ARR_SIZE, arr);
	for(size_t i = 0; i < ARR_SIZE; i++)
		sa[i].printStr();
	return 0;
}
