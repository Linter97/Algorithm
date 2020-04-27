#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

pii a[200001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	sort(a, a + n);
	ll res = 0, f = 0;
	for (int i = 0; i < n; i++) {
		f += a[i].first;
		res += a[i].second - f;
	}
	cout << res << "\n";
}
