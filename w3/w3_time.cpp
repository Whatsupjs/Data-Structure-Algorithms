#include <iostream>

using namespace std;

unsigned int fibonacci (unsigned int n);

int main(){
	unsigned int t = 41;

    cout << "fibonacci(n): " << fibonacci(t) << endl; 
	
	return 0;
}

//define recursive function fibonacci here...
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
