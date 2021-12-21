#include<bits/stdc++.h>
using namespace std;
vector<int> cnt = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
int calc(int num) {
	int res = 0;
	res += cnt[num % 10];
	res += cnt[num / 10];
	return res;
}
int main() {
	int n; scanf("%d", &n);
	n -= 4;
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			if (i + j >= 100) break;
			if (calc(i) + calc(j) + calc(i + j) == n) {
				printf("%02d+%02d=%02d", i, j, i + j);
				return 0;
			}
		}
	}
	printf("impossible");
}