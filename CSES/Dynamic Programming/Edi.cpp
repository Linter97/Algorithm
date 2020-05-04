#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int dp[5001][5001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string a, b;
	cin >> a >> b;
	for (int i = 0; i <= a.length(); i++) {
		for (int j = 0; j <= b.length(); j++) {
			if (i == 0) dp[i][j] = j;
			else if (j == 0) dp[i][j] = i;
			else if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }) + 1;
		}
	}
	cout << dp[a.length()][b.length()] << "\n";
}
