
#include <iostream>

using namespace std;

int main() {
	int tbl[4] = { 1867, 1911, 1925, 1988 };
	int E, Y;
	cin >> E >> Y;
	if (E == 0) {
		if (Y <= tbl[1]) cout << "M" << (Y - tbl[0]) << endl;
		else if (Y <= tbl[2]) cout << "T" << (Y - tbl[1]) << endl;
		else if (Y <= tbl[3]) cout << "S" << (Y - tbl[2]) << endl;
		else cout << "H" << (Y - tbl[3]) << endl;
	}
	else {
		cout << (Y + tbl[E - 1]) << endl;
	}
	return 0;
}
