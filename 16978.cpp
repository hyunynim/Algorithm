#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Segment {
	vector<ll> tree;
	vector<ll> seq;
	Segment(int n) {
		seq.resize(n + 1);
		int log = ceil(log2(n));
		int t = (1 << (log + 1));
		tree.resize(t);
	}

	void init(int node, int s, int e) {
		if (s == e) {
			tree[node] = seq[s];
		}
		else {
			init(node * 2, s, (s + e) / 2);
			init(node * 2 + 1, (s + e) / 2 + 1, e);
			tree[node] = tree[node * 2] + tree[node * 2 + 1];
		}
	}

	ll query(int node, int s, int e, int i, int j) {
		if (e < i || s > j) return 0;
		if (i <= s && e <= j) return tree[node];
		return query(node * 2, s, (s + e) / 2, i, j) + query(node * 2 + 1, (s + e) / 2 + 1, e, i, j);
	}

	void update(int node, int s, int e, int i, ll u) {
		if (i < s || i > e) return;
		tree[node] += u;
		if (s != e) {
			update(node * 2, s, (s + e) / 2, i, u);
			update(node * 2 + 1, (s + e) / 2 + 1, e, i, u);
		}
	}
};
struct QUERY {
	int a, b, c;
};
int main() {
	int n;
	scanf("%d", &n);
	Segment s(n);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &s.seq[i]);

	s.init(1, 1, n);

	int m; scanf("%d", &m);
	vector<QUERY> q1;
	vector<pair<QUERY, int>> q2;

	for (int i = 0; i < m; ++i) {
		int a; scanf("%d", &a);
		if (a == 1) {
			int b, c; scanf("%d %d", &b, &c);
			q1.push_back({ b, c });
		}
		else {
			int b, c, d; scanf("%d %d %d", &b, &c, &d);
			q2.push_back({ { b, c, d }, i });
		}
	}
	sort(q2.begin(), q2.end(), [](pair<QUERY, int> & _q1, pair<QUERY, int> & _q2) {
		return _q1.first.a < _q2.first.a;
	});
	int cur = 0;
	vector<pair<int, ll>> ans;
	for (auto q : q2) {
		while (cur < q1.size() && cur < q.first.a) {
			ll tmp = q1[cur].b - s.seq[q1[cur].a];
			s.seq[q1[cur].a] = q1[cur].b;
			s.update(1, 1, n, q1[cur].a, tmp);
			++cur;
		}
		ans.push_back({ q.second, s.query(1, 1, n, q.first.b, q.first.c) });
	}
	sort(ans.begin(), ans.end());
	for (auto i : ans)
		printf("%lld\n", i.second);
}