#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int dp[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		dp[i] = INF;
		int t = i;
		while (t) {
			int digit = t % 10;
			if (i - digit >= 0) dp[i] = min(dp[i], dp[i - digit] + 1);
			else dp[i] = 1;
			t /= 10;
		}
	}
	cout << dp[n] << "\n";
}
