#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, q;
int a[1001][1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char c;
			cin >> c;
			a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + (c == '*' ? 1 : 0);
		}
	}
	for (int i = 0; i < q; i++) {
		int x1, y1, x2, y2;
		int res = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		res = a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] + a[x1 - 1][y1 - 1];
		cout << res << "\n";
	}
}
