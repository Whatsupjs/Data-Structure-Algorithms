#include <iostream>

template <typename T>
class Stack{

	struct Node{

		T data_;

		Node* next_;

		Node(const T& data = T{}, Node* next = nullptr){

			data_=data;

			next_=next;

		}

	};

	Node* top_;

	int count = 0;

public:

	Stack(){
		top_=nullptr;
	}

	void push(const T& data);

	void pop();

	T top() const;

	bool isEmpty() const;

	~Stack();

};

template <typename T>
void Stack<T>::push(const T& data){
	Node* new_node = new Node(data, nullptr);
	if(top_ != nullptr){
        new_node->next_ = top_;
    }
	top_ = new_node;
	count++;
}

template <typename T>
void Stack<T>::pop(){
	Node* rm = top_;

	if(top_ != nullptr){
        top_ = top_-> next_;
    }
    delete rm;
	count--;
}

template <typename T>

Stack<T>::~Stack(){

	Node* curr=top_;

	while(curr){

		Node* rm=curr;

		curr=curr->next_;

		delete rm;

	}

}

template<typename T>
T Stack<T>::top() const{

    T rc;

    if(top_ != nullptr){

        rc=top_->data_;

    }

    return rc;

}

template<typename T>
bool Stack<T>::isEmpty() const{
    if(count == 0 ){
		return true;
	}

	return false;
}