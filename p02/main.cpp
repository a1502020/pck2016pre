
#include <iostream>

using namespace std;

int main() {
	int H, R;
	cin >> H >> R;
	if (H == -R) cout << 0 << endl;
	else if (H > -R) cout << 1 << endl;
	else cout << -1 << endl;
	return 0;
}
