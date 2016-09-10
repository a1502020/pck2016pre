
#include <iostream>
#include <string>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, s, n) for (int i = (s); i < (n); ++i)

int dp[1001][1001];

int main() {
	string t, b;
	cin >> t >> b;
	int n = t.length(), m = b.length();
	dp[0][0] = 1;
	FOR(j, 1, m + 1) dp[0][j] = 0;
	FOR(i, 1, n + 1) {
		dp[i][0] = 1;
		FOR(j, 1, m + 1) {
			dp[i][j] = dp[i - 1][j];
			if (t[i - 1] == b[j - 1]) dp[i][j] += dp[i - 1][j - 1];
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}
