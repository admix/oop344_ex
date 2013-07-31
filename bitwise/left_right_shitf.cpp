#include <iostream>
using namespace std;
int main() {
	unsigned u = 27u; //0....00011011

	cout << "Left Shift: "<< u << " << " << 3 << " = " << (u << 3) << endl;
	cout << "Right Shift: "<< u << " >> " << 2 << " = " << (u >> 2) << endl;
	return 0;
}