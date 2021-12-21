#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool prime[1010101] = { 1, 1, 0 };
vector<ll> pr;
ll n;
vector<ll> GetDiv(ll num) {
	vector<ll> res;
	for (ll i = 2; i * i <= num; ++i) {
		if (num % i == 0) {
			res.push_back(i);
			if (i * i != num)
				res.push_back(num / i);
		}
	}
	sort(res.begin(), res.end());
	return res;
}
ll power(ll num, ll a) {
	ll res = 1;
	for (int i = 0; i < a; ++i) {
		if (res > n)
			return -1;
		res *= num;
	}
	return res;
}
vector<ll> go(ll num) {
	if (num < 7)
		return vector<ll>();
	auto div = GetDiv(num - 1);
	for (auto p : div) {
		ll l = 3, r = 60;
		while (l <= r) {
			ll mid = (l + r) >> 1;
			ll pw = power(p, mid);
			if (pw == -1)
				r = mid - 1;
			else {
				ll sum = (pw - 1) / (p - 1);
				if (sum == num) {
					//ans
					vector<ll> ans = { 1 };
					for (int i = 0; i < mid - 1; ++i) 
						ans.push_back(ans.back() * p);
					return ans;
				}
				else if (sum > num)
					r = mid - 1;
				else
					l = mid + 1;
			}
		}
	}
	div = GetDiv(num);
	for(auto d : div){
		auto res = go(num / d);
		if (res.size() >= 3) {
			for (int i = 0; i < res.size(); ++i)
				res[i] *= d;
			return res;
		}
	}
	return vector<ll>();
}
int main() {
	for (ll i = 2; i < 101010; ++i) {
		if (prime[i]) continue;
		for (ll j = i * i; j < 1010101; j += i)
			prime[j] = 1;
	}
	for (int i = 2; i < 1010101; ++i)
		if (!prime[i]) pr.push_back(i);
	scanf("%lld", &n);
	auto ans = go(n);
	if (ans.empty())
		printf("-1");
	else {
		printf("%d\n", ans.size());
		for (auto i : ans)
			printf("%lld ", i);
	}
}