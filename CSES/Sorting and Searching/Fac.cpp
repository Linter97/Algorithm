#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int k[200001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, t;
	cin >> n >> t;
	for (int i = 0; i < n; i++) cin >> k[i];
	ll lo = 0, hi = 1e18, res = 1e18;
	while (lo <= hi) {
		ll  mid = (lo + hi) >> 1;
		ll  sum = 0;
		for (int i = 0; i < n; i++) {
			sum += mid / k[i];
			if (sum >= t) break;
		}
		if (sum >= t) {
			hi = mid - 1;
			res = min(res, mid);
		}
		else lo = mid + 1;
	}
	cout << res << "\n";
}
