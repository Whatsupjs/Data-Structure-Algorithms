#include "a3.h"
#include <string>
#include <iostream>


SpellCheck::SpellCheck() {
	_root = nullptr;
	for (int i = 0; i < SIZE; i++) {
		_root->next[i] = nullptr;
	}
}

SpellCheck::SpellCheck(string data[],int sz){
	_root = new Node();
	for (int i = 0; i < sz; i++) {
		addWord(data[i]);
	}
}

void SpellCheck::addWord(const string& newWord){
	if (newWord.length() != 0) {
		Node *p = _root;
		for (unsigned int i = 0; i < newWord.length(); i++)
		{
			int index = newWord[i] - 'a';

			if (p->next[index] == nullptr)
			{
				Node *temp = new Node();
				temp->isEnd = false;
				p->next[index] = temp;
				p = p->next[index];
			}
			else
			{
				p = p->next[index];
			}
		}
		p->isEnd = true;
		p->value = newWord;
		
	}
}

bool SpellCheck::lookup(const string& word) const{
	Node *p = _root;
	
	for (unsigned int i = 0; i < word.length(); i++){
		int index = word[i] - 'a';
		if (!p->next[index]){
			return false;
		}
		p = p->next[index];
	}

	return (p != nullptr && p->isEnd);
}

int SpellCheck::suggest(const string& partialWord, string suggestions[]) const{
	Node *p = _root;
	int matches = 0; 

	if(partialWord.length() != 0 ){
		for (unsigned int i = 0; i < partialWord.length(); i++){
			int index = partialWord[i] - 'a';

			if(!p->next[index]){
				return 0;
			}

			p = p->next[index];

		}

		PreOrderTraverse(p, suggestions, matches); 

	} else {
		return 0;
	}

	return matches;
}

void SpellCheck::PreOrderTraverse(Node* node, string suggestions[], int& matches) const{

  if (node != nullptr){
    if (node->isEnd){
      suggestions[matches] = node->value;
      matches++;
    }
    for (int i = 0; i < SIZE; i++)
    {
      PreOrderTraverse(node->next[i], suggestions, matches);
    }
  }
}

SpellCheck::~SpellCheck(){
	if (_root != nullptr){
		delete _root;
		_root = nullptr;
	}
}
