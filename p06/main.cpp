
#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)

int N;
int p[5000];

int main() {
	while (true) {
		cin >> N;
		if (N == 0) break;
		REP(i, N) cin >> p[i];
		int res = 0;
		if (p[0] > p[1]) {
			res += p[0] - p[1];
			p[0] = p[1];
		}
		REP(i, N - 1) {
			if (p[i] <= 0) continue;
			res += p[i] * 2;
			p[i + 1] -= p[i];
		}
		if (p[N - 1] > 0) res += p[N - 1];
		cout << res << endl;
	}
	return 0;
}
