#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10101];
vector<int> lvl[10101];
int cnt[10101];
int con[10101];
int parent[10101];
int maxD;
int go(int s, int p, int d) {
	++cnt[s];
	parent[s] = p;
	maxD = max(maxD, d);
	lvl[d].push_back(s);
	for (auto nx : adj[s]) {
		if (nx == p) continue;
		cnt[s] += go(nx, s, d + 1);
	}
	return cnt[s];
}
int go2(int s, int p) {
	int res = 1;
	for (auto nx : adj[s]) {
		if (nx == p || con[nx] == 0) continue;
		res += go2(nx, s);
	}
	return res;
}
int main() {
	int n, k; scanf("%d %d", &n, &k);
	for (int i = 0; i < n - 1; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	go(1, -1, 0);
	for (int i = maxD; i > 0; --i) {
		priority_queue<pair<int, int>> q;
		vector<int> noCut;
		if (lvl[i].size() <= k) {
			for (auto x : lvl[i])
				con[x] = 1;
			continue;
		}
		for (auto x : lvl[i])
			q.push({ -cnt[x], x });
		while (q.size() && noCut.size() + q.size() > k) {
			auto cur = q.top();
			q.pop();
			if (con[cur.second]) 
				noCut.push_back(cur.second);
			else 
				cnt[parent[cur.second]] += cur.first;
			while (q.size()) {
				auto cur = q.top(); q.pop();
				con[parent[cur.second]] = con[cur.second] = 1;
			}
			for (auto x : noCut)
				con[parent[x]] = con[x] = 1;
		}
	}
	printf("%d", go2(1, -1));
}