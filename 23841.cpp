#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, m; cin >> n >> m;
	vector<string> seq(n);
	for (int i = 0; i < n; ++i) {
		cin >> seq[i];
		string str = seq[i];
		reverse(str.begin(), str.end());
		string ans = "";
		for (int j = 0; j < m; ++j) {
			if (seq[i][j] == '.' && str[j] == '.')
				ans.push_back('.');
			else if (str[j] == '.')
				ans.push_back(seq[i][j]);
			else
				ans.push_back(str[j]);
		}
		cout << ans << '\n';
	}

}