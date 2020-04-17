#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int a[200001], b[2000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	sort(a, a + n);
	sort(b, b + m);
	int p = 0, res = 0;
	for (int i = 0; i < n && p < m; i++) {
		if (b[p] < a[i] - k) {
			p++;
			i--;
		}
		else if (a[i] + k < b[p]) continue;
		else {
			p++;
			res++;
		}
	}
	cout << res << "\n";
}
