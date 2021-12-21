#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll w, h, l; scanf("%lld %lld %lld", &w, &h, &l);
	ll ans = l;
	for (int i = 1; i <= l; ++i) {
		ll y = floor(sqrt(l * l - i * i));
		ans += (y * 2) + 1;
	}
	for (int i = 1; i < l; ++i) {
		ll y = floor(sqrt(l * l - i * i));
		ans += y;
	}
	vector<ll> bottom(101010), right(101010), top(101010);
	printf("%lld", ans);
}