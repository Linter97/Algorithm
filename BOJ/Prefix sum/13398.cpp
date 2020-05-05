#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int a[100001], p[2][100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	p[0][0] = a[0];
	int res = a[0];
	for (int i = 1; i < n; i++) {
		p[0][i] = max(p[0][i - 1] + a[i], a[i]);
		p[1][i] = max(p[1][i - 1] + a[i], p[0][i - 1]);
		res = max(res, max(p[0][i], p[1][i]));
	}
	cout << res << "\n";
}
