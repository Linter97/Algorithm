#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int a[101], dp[101][100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - a[i - 1] >= 0 && dp[i - 1][j - a[i - 1]]) dp[i][j] = 1;
		}
	}
	vector<int> res;
	for (int i = 1; i <= sum; i++) if (dp[n][i]) res.push_back(i);
	cout << res.size() << "\n";
	for (auto i : res)cout << i << " ";
}
