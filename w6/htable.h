#include <stdio.h>
#include <iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
const int TABLE_SIZE = 5;
const int BUCKET_SIZE = 4;

//Bucket
class Bucket{
private:
    int bucket[TABLE_SIZE][BUCKET_SIZE];

public:

    Bucket();
    void insert(int key, int data);
    void deleted(int key, int data);
    bool find(int key , int data);
    bool isFull(int key);
    bool isEmpty(int key);
    void display();
};

Bucket::Bucket(void){
    std::cout << "Object initialized to 0" << std::endl;   
    for( int i = 0; i < TABLE_SIZE; i++ ){
        for( int j = 0; j < BUCKET_SIZE; j++){
            bucket[i][j] = 0; 
        };
    };
};

void Bucket::insert(int key, int data){
    if(!isFull(key)){
        for( int i = 0; i < BUCKET_SIZE; i++){
            if(bucket[key][i] == 0){
                bucket[key][i] = data;
                break;  
            };
        };
    } else {
        std::cout << key << " Bucket is full" << std::endl;
    };
};

void Bucket::deleted(int key, int data){
    if(!isEmpty(key) && find(key, data)){
        for( int i = 0; i < BUCKET_SIZE; i++){
            if(bucket[key][i] == data) {
                bucket[key][i] = 0;
                break;
            };
        };
	}
	else {
		std::cout << key << " Bucket is empty" << std::endl;
	};
};

bool Bucket::find(int key, int data){
    bool result = false;
    for( int i = 0; i < BUCKET_SIZE; i++){
        if(bucket[key][i] == data) {
            result = true;
            break;
        };
    };
    return result;
};

bool Bucket::isFull(int key){
    bool result = true;
    for( int i = 0; i < BUCKET_SIZE; i++){
        if(bucket[key][i] == 0){
            result = false;
            break;
        };
    };
    return result;
};

bool Bucket::isEmpty(int key){
    bool result = true;
    for( int i = 0; i < BUCKET_SIZE; i++){
        if(bucket[key][i] != 0){
            result = false;
            break;
        };
    };
    return result;
};

void Bucket::display(){
    for( int i = 0; i < TABLE_SIZE; i++){
        std::cout << i << " : ";
        for( int j = 0; j < BUCKET_SIZE; j++){
            std::cout << bucket[i][j] << " ";
        }
        std::cout << std::endl;
    };
};

//
//
//Chain Link
class Chain {
private:
	struct Node {
		int key;
		int value;
		Node* next;

		Node(int key, int value) {
			this->key = key;
			this->value = value;
			this->next = nullptr;
		}
	};

	Node** table;

public:
	Chain();
	void insert(int key, int value);
	void deleted(int key, int value);
	bool find(int key, int value);
	bool isEmpty(int key);
	void display();
	int HashFunc(int key);
};

Chain::Chain() {
	table = new Node*[TABLE_SIZE];
	for (int i = 0; i < TABLE_SIZE; i++) {
		table[i] = nullptr;
	};
};

int Chain::HashFunc(int key)
{
	return key % TABLE_SIZE;
};

void Chain::insert(int key, int value) {
	int hash_key = HashFunc(key);
	Node* prev = nullptr;
	Node* ins = table[hash_key];

	while (ins != nullptr) {
		prev = ins;
		ins = ins->next;
	}
	if (ins == nullptr) {
		ins = new Node(key, value);

		if (prev == nullptr) {
			table[hash_key] = ins;
		}
		else {
			prev->next = ins;
		}
	}
	else {
		ins->value = value;
	}
}

void Chain::deleted(int key, int value) {
	int hash_key = HashFunc(key);
	Node* ins = table[hash_key];
	Node* prev = nullptr;

	if (ins == nullptr || ins->key != key) {
		std::cout << "Table is empty" << std::endl;
		return;
	}
	while (ins->next != nullptr){
		
		if (ins->value == value) {
			if (prev != nullptr) {
				prev->next = ins->next;
			}

			delete ins;
			break;
		}
		else {
			prev = ins;
			ins = ins->next;
		}
		
	}
}

bool Chain::find(int key, int value) {
	bool result = false; 
	int hash_key = HashFunc(key);
	Node* ins = table[hash_key];
	
	while (ins != nullptr) {
		if (ins->key == key && ins->value == value) {
			result = true;
		}
		ins = ins->next;
	}

	return result;
}

bool Chain::isEmpty(int key) {
	bool result = false;
	int hash_key = HashFunc(key);
	Node* ins = table[hash_key];

	if (ins == nullptr) {
		result = true;
	}

	return result;
}

void Chain::display() {
	for (int i = 0; i < TABLE_SIZE; i++) {
		int hash_key = HashFunc(i);
		Node* data = table[hash_key];

		std::cout << i << " : ";
		
		while (data != nullptr) {
			std::cout << data->value;
			std::cout << " ";
			data = data->next;
		} 

		std::cout << std::endl;
	}
}