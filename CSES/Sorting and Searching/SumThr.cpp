#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

pll a[5001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	sort(a, a + n);
	for (int i = 0; i < n - 2; i++) {
		ll f = a[i].first;
		for (int j = i + 1; j < n; j++) {
			ll s = a[j].first;
			auto it = lower_bound(a + j + 1, a + n, pll{ x - f - s, 0 });
			if (f + s + it->first == x) {
				cout << a[i].second << " " << a[j].second << " " << it->second << "\n";
				return 0;
			}
		}
	}
	cout << "IMPOSSIBLE\n";
}
