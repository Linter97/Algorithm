#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int dp[1000001], dice[6] = { 1, 2, 3, 4, 5, 6 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (auto j : dice) {
			if (i - j >= 0) {
				dp[i] += dp[i - j];
				dp[i] %= MOD;
			}
		}
	}
	cout << dp[n] << "\n";
}
