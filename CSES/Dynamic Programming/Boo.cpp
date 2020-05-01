#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int h[1001], s[1001], dp[1001][100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	cin >> n >> x;
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 1; i <= n; i++) cin >> s[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= x; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - h[i] >= 0) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - h[i]] + s[i]);
		}
	}
	cout << dp[n][x] << "\n";
}
