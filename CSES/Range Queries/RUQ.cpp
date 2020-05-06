#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
ll x[200001], tree[200001];
int n, q;
ll sum(int k) {
	ll s = 0;
	while (k >= 1) {
		s += tree[k];
		k -= k & -k;
	}
	return s;
}
void add(int k, ll x) {
	while (k <= n) {
		tree[k] += x;
		k += k & -k;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	int prev = 0;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		add(i, x[i] - prev);
		prev = x[i];
	}
	for (int i = 0; i < q; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int a, b, u;
			cin >> a >> b >> u;
			add(a, u);
			add(b + 1, -u);
		}
		else {
			int k;
			cin >> k;
			cout << sum(k) << "\n";
		}
	}
}
