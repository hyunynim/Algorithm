#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, m; scanf("%d %d", &n, &m);
	vector<int> seq(n);
	vector<vector<int>> ans(m);
	vector<int> sum(m);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	sort(seq.begin(), seq.end());
	int cur = 0;
	while (seq.size()) {
		cur %= m;
		if (cur == 0) {
			ans[cur].push_back(seq.back());
			sum[cur] += seq.back();
			seq.pop_back();
		}
		else {
			while (seq.size() && sum[0] > sum[cur]) {
				ans[cur].push_back(seq.back());
				sum[cur] += seq.back();
				seq.pop_back();
			}
		}
		++cur;
	}
	printf("%d", sum[0]);
}