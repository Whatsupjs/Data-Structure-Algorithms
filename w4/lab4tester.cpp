/************************************************************/

/*  Lab 4 tester                                            */

/*  To compile:                                             */

/*     g++ lab4tester.cpp -std=c++0x                        */

/*  To run:                                                 */

/*     ./a.out                                              */

/************************************************************/



#include "lab4.h"

#include <iostream>



int main(void){

	DList<int> regular;

	Sentinel<int> sentinel;

	std::cout << "testing regular doubly linked list" << std::endl;


	for(int i=0;i<3;i++){

		regular.push_front(i);

		regular.print();

	}


	for(int i=3;i<6;i++){

		regular.push_back(i);

		regular.print();

	}


	for(int i=0;i<7;i++){

		if(i%2){

			regular.pop_front();

		}

		else{

			regular.pop_back();

		}

		regular.print();

	}


	std::cout << "testing sentinel list" << std::endl;

	for(int i=0;i<3;i++){

		sentinel.push_front(i);

		sentinel.print();

	}

	for(int i=3;i<6;i++){

		sentinel.push_back(i);

		sentinel.print();

	}


	for(int i=0;i<7;i++){

		if(i%2){

			sentinel.pop_front();

		}

		else{

			sentinel.pop_back();

		}

		sentinel.print();

	}


	return 0;

}