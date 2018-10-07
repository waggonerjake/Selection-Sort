#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <exception>

void SelectionSort(int A[], int n);

int main()
{
	int n;
	//Making sure n is a postive nonzero number	
	while(true)
	{
		std::cout << "How many numbers do you want to sort? ";
		std::cin >> n;
		if(n <=0)
		{
			std::cout << "Please enter a positive non-zero number."<<std::endl;
		}
		else
		{
			break;
		}
	}
	int A[n];
	
	srand (time(NULL));

	std::cout << "Here is the pre sorted array:" << std::endl;	

	//Sets each index to a random integer between 0 and 200
	for(int i=0;i<n;i++)
	{	
		int RNG = rand()%201;
		A[i] = RNG;
		if(i < n-1)
		{
			std::cout << A[i] << ", ";
		}
		else
		{
			std::cout << A[i];
		}	

	}
	std::cout << "\n";
	SelectionSort(A, n);
	return 0;
}

void SelectionSort(int A[], int n)
{	
	//Will eventually set every value, except the last value, to the "smallest" 
	//value so we can make comparisons
	for(int j =0; j<n-1; j++)
	{
		int smallest = A[j];
		int swapper = j;

		//Checking if there is any smaller value than what we currently have
		for(int i=j+1;i<n;i++)
		{
			if(A[i] < smallest)
			{
				smallest = A[i];
				swapper = i;
			}
		}
		//Will swap everytime, so if it doesnt actually have a value to swap 
		//with, make it swap with itself
		std::swap(A[j],A[swapper]);
	}
	
	std::cout << "Here is the sorted array:" << std::endl;	

	for(int i =0; i<n; i++)
	{
		if(i < n-1)
		{
			std::cout << A[i] << ", ";
		}
		else
		{
			std::cout << A[i];
		}
	}
	std::cout << "\n";
}
