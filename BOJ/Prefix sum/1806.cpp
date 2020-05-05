#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int a[100001], p[100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		p[i + 1] = p[i] + a[i];
	}
	
	int res = 2e9;
	for (int i = 1, j = 0; i <= n; i++) {
		if (p[i] >= s) {
			while (p[i] - p[j] >= s) {
				res = min(res, i - j);
				j++;
			}
		}
	}
	if (res == 2e9) cout << "0\n";
	else cout << res << "\n";
}
