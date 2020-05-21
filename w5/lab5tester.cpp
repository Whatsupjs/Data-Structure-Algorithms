#include <string>
#include <iostream>
#include "stack.h"
/* Tester for Lab 5  */

bool bracketCheck(const std::string& s);

int main(void){

	std::string tests[6]={

		"a(b)c[d]ef{g}",

		"a[(a[bcd(efg{h[i]j}k{[(l)m]}n{}o)p])[q]]rs",

		"a(b)c]d",

		"[[]",

		"aa(bb{cc)dd}ee",
		"ywxzopqr@*"

	};

	

	for(int i=0;i<6;i++){

		if(bracketCheck(tests[i])){

			std::cout << "Test "<< i+1 << " passed" << std::endl;

		}

		else{

			std::cout << "Test "<< i+1 << " error" << std::endl;

		}

	}

	return 0;

}

bool bracketCheck(const std::string& s){
	Stack<char> stack_;

	for(unsigned int i = 0; i < s.length(); i++) {
		if(s.at(i) == '{' || s.at(i) == '(' || s.at(i) == '['){
			stack_.push(s.at(i));
		}
		else if(s.at(i) == '}') {
			if(stack_.top() != '{')
				return false;
			else 
				stack_.pop();
		} 
		else if(s.at(i) == ')'){
			if(stack_.top() != '(')
				return false;
			else
				stack_.pop();
		}
		else if(s.at(i) == ']'){
			if(stack_.top() != '[')
				return false;
			else
				stack_.pop();
		};
	};

	if(stack_.isEmpty()){
		return true;
	};

	return false;
	/*
	if string has any opening bracket, insert into stack, when closing braket shows up, does it match with top of bracket
	if it doesn't match false, if it matches true and pop
	end -> if stack == 0 true, else false.
	*/
   
}