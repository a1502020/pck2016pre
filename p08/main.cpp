
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, s, n) for (int i = (s); i < (n); ++i)

typedef pair<int, int> P;

int V, R;
pair<P, int> xyi[100];
bool es[100][100];
bool f[100];
double d[100][100];

const double INF = 1e9;

int cross(const P &a, const P &b, const P &c, const P &d) {
	const int
		x1 = b.first - a.first,
		y1 = b.second - a.second,
		x2 = d.first - c.first,
		y2 = d.second - c.second;
	return x1 * y2 - x2 * y1;
}

vector<pair<P, int>> hull() {
	sort(xyi, xyi + V);
	vector<pair<P, int>> res(V * 2);
	int k = 0;
	REP(i, V) {
		while (k > 1 && cross(res[k - 2].first, res[k - 1].first, res[k - 1].first, xyi[i].first) <= 0) --k;
		res[k] = xyi[i];
		++k;
	}
	for (int i = V - 2, t = k; i >= 0; --i) {
		while (k > t && cross(res[k - 2].first, res[k - 1].first, res[k - 1].first, xyi[i].first) <= 0) --k;
		res[k] = xyi[i];
		++k;
	}
	res.resize(k - 1);
	return res;
}

double dist(const P &a, const P &b) {
	const int dx = b.first - a.first;
	const int dy = b.second - a.second;
	return sqrt(double(dx * dx + dy * dy));
}

double mc[100];
bool used[100];

int main() {
	cin >> V >> R;
	memset(es, 0, sizeof(es));
	REP(i, V) {
		cin >> xyi[i].first.first >> xyi[i].first.second;
		xyi[i].second = i;
	}
	REP(i, R) {
		int s, t;
		cin >> s >> t;
		--s; --t;
		es[s][t] = es[t][s] = true;
	}

	auto hl = hull();
	memset(f, 0, sizeof(f));
	REP(k, hl.size()) {
		int i = hl[k].second, j = hl[(k + 1) % hl.size()].second;
		es[i][j] = es[j][i] = true;
		f[i] = true;
	}

	REP(k, V) {
		const int i = xyi[k].second;
		d[i][i] = 0.0;
		FOR(l, k + 1, V) {
			const int j = xyi[l].second;
			if (es[i][j]) {
				const int dx = xyi[l].first.first - xyi[k].first.first;
				const int dy = xyi[l].first.second - xyi[k].first.second;
				d[i][j] = sqrt(dx * dx + dy * dy);
			}
			else {
				d[i][j] = INF;
			}
		}
	}
	REP(k, V) REP(i, V) REP(j, V) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	double res = 0.0;
	REP(k, hl.size()) res += dist(hl[k].first, hl[(k + 1) % hl.size()].first);
	REP(i, V) {
		if (f[i]) continue;
		double m = INF;
		REP(k, hl.size()) {
			const int j = hl[k].second;
			m = min(m, d[i][j]);
		}
		res += m;
	}

	return 0;
}
