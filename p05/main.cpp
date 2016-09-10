
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, s, n) for (int i = (s); i < (n); ++i)

int N;
int p[1000][3];

bool removed[1000];

int main() {
	cin >> N;
	REP(i, N) {
		REP(j, 3) cin >> p[i][j];
		sort(p[i], p[i] + 3);
	}
	memset(removed, 0, sizeof(removed));
	int res = 0;
	REP(i, N) FOR(j, i + 1, N) {
		if (!removed[j] && p[i][0] == p[j][0] && p[i][1] == p[j][1] && p[i][2] == p[j][2]) {
			removed[j] = true;
			++res;
		}
	}
	cout << res << endl;
	return 0;
}
