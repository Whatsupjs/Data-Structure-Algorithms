#include <iostream>

using namespace std;

#define SIZE 10

void merge(int* list, int lowIndex, int highIndex, int midIndex);
void mergeSort(int* list, int lowIndex, int highIndex);
int tmpList[SIZE] = { 0 };
int main()
{
	int theList[SIZE] = { 10,2,7,9,0,16,4,11,6,1 };
	int i;

	cout << "Unsorted list: ";
	for (i = 0; i < SIZE; i++) {
		cout << theList[i] << "\t";
	}
	cout << endl;

	mergeSort(theList, 0, SIZE - 1);

	// Printing the sorted data.
	cout << "  Sorted list: ";
	for (i = 0; i < SIZE; i++) {
		cout << theList[i] << "\t";
	}
	cout << endl;

	return 0;

}

//This function merges two set of data [low ... mid] and [mid+1 ... high] and results a sorted list
void merge(int* list, int lowIndex, int highIndex, int midIndex) {
	
	int start = lowIndex;
	int mid = midIndex;
	int i = lowIndex;

	while (start < midIndex && mid <= highIndex) {
		if (list[start] < list[mid]) {
			tmpList[i++] = list[start++];
		}
		else {
			tmpList[i++] = list[mid++];
		}
	}
	while (start < midIndex) {
		tmpList[i++] = list[start++];
	}
	while (mid <= highIndex) {
		tmpList[i++] = list[mid++];
	}

	for (i = lowIndex; i <= highIndex; i++) {
		list[i] = tmpList[i];
	}
}

//This function sorts the received list of values using the merge sort algorithm 
void mergeSort(int* list, int lowIndex, int highIndex) {
	if (lowIndex < highIndex) {
		int midIndex = (lowIndex + highIndex) / 2;

		mergeSort(list, lowIndex, midIndex);
		mergeSort(list, midIndex + 1, highIndex);
		merge(list, lowIndex, highIndex, midIndex + 1);
	};
}


