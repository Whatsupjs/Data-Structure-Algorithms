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

//define recursive function factorial here...
unsigned int factorial(unsigned int n){
	int f_result = 1;

	if(n > 1)
		f_result = n * factorial(n-1);

	return f_result;
}



//define recursive function power here...
double power(double base, unsigned int n) {
	int p_result = 1;

	if(n > 0)
		p_result = base * power(base, n-1);

	return p_result;
}



//define recursive function fibonacci here...
unsigned int fibonacci(unsigned int n) {
	int fi_result;

	if (n < 2)
	    fi_result = n;
	else
		fi_result = fibonacci(n-1) + fibonacci(n-2);

	return fi_result;
}