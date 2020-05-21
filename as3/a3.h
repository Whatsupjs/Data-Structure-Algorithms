#include <string>
using namespace std;

//global variable of alphabet size
const int SIZE = 26;

class SpellCheck{
	
	struct Node {
		Node *next[SIZE];
		bool isEnd;
		string value;
	};

	Node *_root;
	

public:
	SpellCheck();
	SpellCheck(string data[],int sz);
	void PreOrderTraverse(Node* node, string suggestions[], int& matches) const;
	void addWord(const string& newWord);
	bool lookup(const string& word) const;
	int suggest(const string& partialWord, string suggestions[]) const;
	~SpellCheck();	
};