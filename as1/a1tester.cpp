/*********************************************************/
/*                                                       */
/*   This program uses a text file with a list of        */
/*   words and creates the tables using the words as     */
/*   keys.                                               */
/*   You will need the file: dictionary_2.txt            */
/*                                                       */
/*********************************************************/

#include "table.h"
#include <string>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>


using namespace std;
const int MAX=35;

const char* filename="dictionary_2.txt";

int main(int argc, char* argv[]){

    FILE* fp=fopen(filename,"r");

    int testnumber=0;
    if(!fp){
        cout << "could not open file " << filename << ".  Make sure it is in the" << endl;
        cout << "same directory as this program and try again" << endl;
        return 0;
    }
    char curr[50];          //used to read in words from text file
    string* wordlist;        //list of test cases. 

    bool oprc;              //return value from an operation

    int numremoved=0;		//number of words removed from the table;
	int numinserted = 0;	//number of words inserted into the table

    int currValue = 0;

    wordlist= new string[MAX];
    for(int i=0;i<MAX;i++){
       fscanf(fp,"%s\n",curr);                 //read in a word from data file
       wordlist[i]=curr;                       //record it
    }/*end for:  populate table*/

    cout << "* * * * * * * * * * * * Testing HashTable Table* * * * * * * * * * * * * * * *"<< endl;
    cout << "Test 1: initialization and update" << endl;
    int hashtableCapacity=20;
    double lambda = 0.65;
    int hashtableMax = (int) (hashtableCapacity*lambda);
    LPTable<int> hashtable(hashtableCapacity,lambda);
     
	cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Test 1: Add " << hashtableMax << " records, as many as table can hold" << endl;
	cout << "Duplicate keys will not be inserted. Their value will be updated in the table by adding the new value to the old one." << endl;
	cout << "If a record is updated, the size of the table will not change." << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < hashtableMax; i++) {

		int currValue = 1;
		oprc = hashtable.update(wordlist[i], currValue);

		if (oprc) {
			cout << "Key-value (" << wordlist[i] << " , " << currValue << ")\tis inserted/updated" << endl;
			numinserted++;
		}
		else {
			cout << "Key-value (" << wordlist[i] << " , " << currValue << ")\tis not inserted/updated" << endl;
		}
	}

	cout << "------------------------" << endl;
	cout << numinserted << " records are inserted/updated." << endl;
	cout << "Hash Table after Test 1:" << endl;
	cout << "------------------------" << endl;
	hashtable.printTable();

    testnumber++;
	
	cout << "--------------------------------------------------------------------------------------------------------" << endl;
    cout << "Test 2: Add some more records (more than table can hold)" << endl;
	cout << "Since the table is full as a result of data insertion in the previous part, no new record will be added." << endl;
	cout << "Only the value of duplicate keys will be updated." << endl;
	cout << "--------------------------------------------------------------------------------------------------------" << endl;

    for(int i=0;i<MAX - hashtableMax;i++){

		int currValue = 1;
        oprc=hashtable.update(wordlist[hashtableMax+i], currValue);

		
		if (oprc) {
			cout << "Key-value (" << wordlist[hashtableMax + i] << "," << currValue << ")\tis inserted/updated" << endl;
		}
		else {
			cout << "Key-value (" << wordlist[hashtableMax + i] << "," << currValue << ")\tis not inserted/updated" << endl;
		}
    }/*end*/

    testnumber++;

	cout << "------------------------" << endl;
	cout << "Hash Table after Test 2:" << endl;
	cout << "------------------------" << endl;
	hashtable.printTable();

	cout << "----------------------------------------------------------------------------------" << endl;
    cout << "Test 3: Checking hashtableTable::find() and that records were properly recorded..." << endl;
	cout << "----------------------------------------------------------------------------------" << endl;

    for(int i=0;i<hashtableMax;i++){
		int currValue = 1;
 
		oprc=hashtable.find(wordlist[i],currValue);                

        if(oprc){                                          

			cout << "Key-value (" << wordlist[i] << "," << currValue << ")\tdoes exist it the table" << endl;
		}
		else {
			cout << "Key-value (" << wordlist[i] << "," << currValue << ")\tdoes not exist it the table" << endl;
		}
            
    }

    testnumber++;

	cout << "------------------------------------------------------------------------" << endl;
    cout << "Test 4: Change some records in hashtable table and see if it still works" << endl;
	cout << "------------------------------------------------------------------------" << endl;

    for(int i=0;i<hashtableMax;i++){

		int currValue = 1;
    
		oprc=hashtable.update(wordlist[i], currValue);
           
		if (oprc) {
			cout << "Key-value (" << wordlist[i] << "," << currValue << ")\tis updated" << endl;
		}
		else {
			cout << "Key-value (" << wordlist[i] << "," << currValue << ")\tis not updated" << endl;
		}
    }

	cout << "------------------------" << endl;
	cout << "Hash Table after Test 4:" << endl;
	cout << "------------------------" << endl;

	hashtable.printTable();

    testnumber++;

	cout << "-----------------------------------------------------------------------" << endl;
    cout << "Test 5: Remove some records that exist from hashtable table..." << endl;
	cout << "If a key exists in the table, the record with that key will be removed." << endl;
	cout << "-----------------------------------------------------------------------" << endl;

    numremoved=0;

	for(int i=0;i<hashtableMax;i++){

		oprc=hashtable.remove(wordlist[i]);                         
        
        if(!oprc){
			cout << "Key (" << wordlist[i] << ")\t\tdoes not exists" << endl;
		}
		else {
			numremoved++;
			cout << "Key (" << wordlist[i] << ")\t\tis removed" << endl;
		}

    }
	
	cout << "------------------------" << endl;
	cout << "Hash Table after Test 5:" << endl;
	cout << "------------------------" << endl;
		
	hashtable.printTable();
 
	testnumber++;

	cout << "-----------------------------------------------------------------------" << endl;
    cout << "Test 6: Attempt to remove some records that do not exist from the table" << endl;
	cout << "-----------------------------------------------------------------------" << endl;

	numremoved = 0;
	for(int i=0;i<hashtableMax;i++){

		oprc = hashtable.remove(wordlist[i]);

		numremoved++;

		if (!oprc) {
			cout << "Key (" << wordlist[i] << ")\t\tdoes not exists" << endl;
		}
		else {
			cout << "Key (" << wordlist[i] << ")\t\tis removed" << endl;
		}
    }

	cout << "----------------------------------" << endl;
	cout << numremoved << " records are removed." << endl;
	cout << "Hash Table after Test 6:" << endl;
	cout << "----------------------------------" << endl;
	hashtable.printTable();

    testnumber++;
	
	cout << "-----------------------------" << endl;
	cout << "Test 7: Add some more records" << endl;
	cout << "-----------------------------" << endl;


	for (int i = 0; i < MAX - hashtableMax; i++) {

		oprc = hashtable.update(wordlist[hashtableMax + i], 1);
			
		if (oprc) {
			cout << "Key-value (" << wordlist[hashtableMax + i] << "," << currValue << ")\t\tis inserted/updated" << endl;
		}
		else {
			cout << "Key-value (" << wordlist[hashtableMax + i] << "," << currValue << ")\t\tis not inserted/updated" << endl;
		}
	}/*end*/

	cout << "------------------------" << endl;
	cout << "Hash Table after Test 7:" << endl;
	cout << "------------------------" << endl;
	hashtable.printTable();


		
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "Tests Completed." << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << endl;

    fclose(fp);
    
}


