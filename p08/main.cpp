
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <functional>
#include <iomanip>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, s, n) for (int i = (s); i < (n); ++i)

typedef pair<int, int> P;

int V, R;
P xy[100];
pair<P, int> xyi[100];
bool es[100][100];
bool f[100];

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

bool used[100];

typedef pair<double, pair<int, int>> Q;

int main() {
	cin >> V >> R;
	memset(es, 0, sizeof(es));
	REP(i, V) {
		cin >> xyi[i].first.first >> xyi[i].first.second;
		xyi[i].second = i;
		xy[i] = xyi[i].first;
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

	double res = 0.0;
	memset(used, 0, sizeof(used));
	priority_queue<Q, vector<Q>, greater<Q>> q;
	REP(k, hl.size()) {
		used[hl[k].second] = true;
		REP(i, V) if (es[hl[k].second][i]) {
			q.push(make_pair(dist(hl[k].first, xy[i]), make_pair(hl[k].second, i)));
		}
	}
	while (!q.empty()) {
		auto t = q.top(); q.pop();
		int from = t.second.first, to = t.second.second;
		if (used[to]) continue;
		used[to] = true;
		if (!f[from] || !f[to]) res += t.first;
		REP(i, V) if (es[to][i]) q.push(make_pair(dist(xy[to], xy[i]), make_pair(to, i)));
	}

	REP(k, hl.size()) res += dist(hl[k].first, hl[(k + 1) % hl.size()].first);

	cout << fixed << setprecision(5) << res << endl;

	return 0;
}
