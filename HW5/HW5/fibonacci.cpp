#include <iostream>
using namespace std;
int fib(int n) {
	if (n == 1) return 1;
	if (n == 0) return 0;
	else return (fib(n - 1) + fib(n - 2));
}
int main() {
	int n = 21;
	cout << "fib(" << n << ") = " << fib(n) << endl;
}