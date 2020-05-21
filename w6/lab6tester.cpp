#include <stdio.h>
#include "htable.h"
#include <iostream>

int main(void){
    //construct table;
    Bucket table;
	Chain table2;

    //Test bucket table;
	std::cout << "Test Bucket Table" << std::endl;
    std::cout << "\n Testing Insert" << std::endl;
    std::cout << "Inserting (2,13), (2,14), (1,1), (1,2), (3,1), (3,2), (3,3), (3,4)" << std::endl;
    table.insert(2, 13);
    table.insert(2, 14);
    table.insert(1, 1);
    table.insert(1, 2);
	table.insert(3, 1);
	table.insert(3, 2);
	table.insert(3, 3);
	table.insert(3, 4);
    table.display();

    std::cout << "\n Testing delete" << std:: endl;
    std::cout << "Deleting (2,13), (1,2)" << std::endl;
    table.deleted(2,13);
    table.deleted(1,2);
    table.display();

    std::cout << "\n Testing find" << std::endl;
    std::cout << "True 1 , False 0" << std::endl;
    std::cout << "Finding (2,13) " << table.find(2,13) << std::endl;
    std::cout << "Finding (2,14) " << table.find(2,14) << std::endl;

	std::cout << "\n Testing isFull and isEmpty" << std::endl;
	std::cout << "True 1 , False 0" << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << "Key " << i << " is full " << table.isFull(i) << " is empty " << table.isEmpty(i) << std::endl;
	}

	std::cout << "Test Chain Table" << std::endl;
	std::cout << "\n Testing Insert" << std::endl;
	std::cout << "Inserting (2,13), (2,14), (1,1), (1,2), (3,1), (3,2), (3,3), (3,4)" << std::endl;
	table2.insert(2, 13);
	table2.insert(2, 14);
	table2.insert(1, 1);
	table2.insert(1, 2);
	table2.insert(3, 1);
	table2.insert(3, 2);
	table2.insert(3, 3);
	table2.insert(3, 4);
	table2.display();

	std::cout << "\n Testing delete" << std::endl;
	std::cout << "Deleting (3,3)" << std::endl;
	table2.deleted(3, 3);
	table2.display();

	std::cout << "\n Testing find" << std::endl;
	std::cout << "True 1 , False 0" << std::endl;
	std::cout << "Finding (2,13) " << table2.find(2, 13) << std::endl;
	std::cout << "Finding (2,14) " << table2.find(2, 14) << std::endl;
	std::cout << "Finding (3,5) " << table2.find(3, 5) << std::endl;
	std::cout << std::endl;

	table2.display();

	std::cout << "\n Testing isEmpty" << std::endl;
	std::cout << "True 1 , False 0" << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << "Key " << i << " is empty " << table.isEmpty(i) << std::endl;
	}
    return 0;
}