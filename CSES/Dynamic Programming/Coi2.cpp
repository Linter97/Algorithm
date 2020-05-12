#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int c[101], dp[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= x; j++) {
			if (j - c[i] >= 0) {
				dp[j] += dp[j - c[i]];
				dp[j] %= MOD;
			}
		}
	}
	cout << dp[x] << "\n";
}
