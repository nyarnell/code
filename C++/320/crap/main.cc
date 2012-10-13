#include <iostream>
using namespace std;

// void swap(int &a, int &b) {
	// int temp;
	// temp = a;
	// a = b;
	// b = temp;
// }
// int main() {
	// int value = 2, list[5] = {1, 3, 5, 7, 9};
	// int tmp1 = value;
	// int tmp2 = list[0];
	// swap(tmp1, tmp2);
	// value = tmp1;
	// list[0] = tmp2;
	// tmp1 = list[0];
	// tmp2 = list[1];
	// swap(tmp1, tmp2);
	// list[0] = tmp1;
	// list[1] = tmp2;
	// tmp1 = value;
	// tmp2 = list[value];
	// swap(tmp1, tmp2);
	// list[value] = tmp2;
	// value = tmp1;
	// cout << value << endl;
	// for ( int i = 0; i < 5 ; i++ ){
		// cout << list[i] << " ";
	// }
	// cout << endl;
// }

void fun(int &first, int &second) {
	first += first;
	second += second;
}
int main() {
	int list[2] = {1, 3};
	int tmp1 = list[0];
	int tmp2 = list[1];
	fun(tmp1, tmp2);
	list[0] = tmp1;
	list[1] = tmp2;
	cout << list[0] << " " << list[1] << endl;
}