/**********************************************************/
/*                                                        */
/*  Summer 2019											  */
/*                                                        */
/**********************************************************/
#define  _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <cstring>
#include <cstdio>
#include <string>
#include <iostream>
#include <string>

using namespace std;
#include "a3.h"

const char insertWords[39][45] = {
	"apple", "carrot", "app","cart",
	"dramat","appear","city","world",
	"yard","adver","event","apps","apply","appel","appal","appear","appeal",
	"applet","append","ten","tea","team","term","cat","catch","caters","catted","catlin",
	"teaching","terminal","terrible","fry","from","free","front","fresh","friend","french","frozen" };

const char search[14][45] = {
	"apple", "carrot", "sublime","free",
	"dramat","appel","city","world",
	"teaching","adver","fresh","test","pass","act"
};

const char moreWords[14][45] = {
	"yellow", "orange", "see","banana",
	"sea","country","sky","blue",
	"main","maintain","mean","meant","mask","more"
};

const char suggesstions[5][45] = {
	"app", "ca", "sub","te",
	"fry"
};

int main(int argc, char* argv[]) {

	int numberOfWords = 39;
	string* wordList;
	wordList = new string[39];

	for (int i = 0; i < numberOfWords; i++) {
		wordList[i].append(insertWords[i]);
	}
	
	SpellCheck checker(wordList, numberOfWords);

	cout << numberOfWords << " words added to the spellchecker" << endl;

	cout << "--------------------------------------------------" << endl;
	cout << "Add more words: " << endl;
	cout << "--------------------------------------------------" << endl;
	int moreWordsNum = 14;
	//more words added
	for (int i = 0; i < moreWordsNum; i++) {
		checker.addWord(moreWords[i]);

	}

	cout << moreWordsNum << " more words added to the spellchecker" << endl;

	cout << "--------------------------------------------------" << endl;
	cout << "Validate Words: " << endl;
	cout << "--------------------------------------------------" << endl;
	int searchedWords = 14;
	for (int i = 0; i < searchedWords; i++) {
		if (checker.lookup(search[i])) {
			cout << "-----> " << search[i] << "\tdoes exist." << endl;
		}
		else {
			cout << "-----> " << search[i] << "\tdoes not exist." << endl;
		}
	}

	int suggWords = 5;
	
	for (int i = 0; i < suggWords; i++) {

		string* suggestList;

		suggestList = new string[5000];

		int nWords = checker.suggest(suggesstions[i], suggestList);
		cout << "--------------------------------------------------" << endl;
		cout << "Partial Word: " << endl;
		cout << "-----> " << suggesstions[i] << endl;
		if (nWords > 0) {
			
			cout << "Suggessted Words: " << endl;
			for (int i = 0; i < nWords; i++)
				cout << "-----> " << suggestList[i] << endl;;
			
		}
		else {
			cout << "There is no matching word for this partial word!" << endl;
		}

	}
	cout << "--------------------------------------------------" << endl;

	return 0;

}




