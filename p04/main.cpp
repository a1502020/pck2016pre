
#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if (a < b) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	int W, H, C;
	cin >> W >> H >> C;
	int g = gcd(W, H);
	cout << (C * (W / g) * (H / g)) << endl;
	return 0;
}
