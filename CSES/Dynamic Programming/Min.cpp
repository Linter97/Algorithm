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
	for (int i = 0; i < n; i++) cin >> c[i];
	for (int i = 1; i <= x; i++) {
		dp[i] = INF;
		for (int j = 0; j < n; j++) {
			if (i - c[j] >= 0) dp[i] = min(dp[i], dp[i - c[j]] + 1);
		}
	}
	cout << (dp[x] != INF ? dp[x] : -1) << "\n";
}
