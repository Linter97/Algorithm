#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

char grid[1001][1001];
int dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}
	dp[0][1] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] != '*') {
				dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j];
				dp[i + 1][j + 1] %= MOD;
			}
		}
	}
	cout << dp[n][n] << "\n";
}
