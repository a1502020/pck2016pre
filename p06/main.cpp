
#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, s, n) for (int i = (s); i < (n); ++i)
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int N;
int p[5000];

int main() {
	while (true) {
		cin >> N;
		if (N == 0) break;
		REP(i, N) cin >> p[i];
		int res = 100000;
		REP(k, 4) {
			int cnt = k, t = min(k, p[0]);
			REP(i, N - 1) {
				cnt += (p[i] - t) * 2;
				t = min(p[i + 1], p[i] - t);
			}
			cnt += max(0, p[N - 1] - t);
			res = min(res, cnt);
		}
		cout << res << endl;
	}
	return 0;
}
