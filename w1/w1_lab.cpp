#include <iostream>

using namespace std;

unsigned int factorial (unsigned int n);
double power (double base, unsigned int n);
unsigned int fibonacci (unsigned int n);

int main(){
	
	cout << "factorial(5): " << factorial(5) << endl;
 	cout << "power(2,4): " << power(2,4) << endl; 
    cout << "fibonacci(9): " << fibonacci(9) << endl; 
	return 0;
}

//define function factorial here...
unsigned int factorial(unsigned int n){
	int f_result = 1;

	for (unsigned int i = 2; i <= n; i++) {
		f_result = f_result * i;
	}

	return f_result;
}


//define function power here...
double power(double base, unsigned int n) {
	int p_result = 1;

	for (unsigned int i = 0; i < n; i++) {
		p_result *= base;
	}

	return p_result;
}


//define function fibonacci here...
unsigned int fibonacci(unsigned int n) {
	int f0 = 0, f1 = 1, fi_result;

	for (unsigned int i = 0; i <= n; i++) {
		if (i <= 1) {
			fi_result = i;
		}
		else {
			fi_result = f0 + f1;
			f0 = f1;
			f1 = fi_result;
		}
	}

	return fi_result;
}