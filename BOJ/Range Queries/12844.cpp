#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
#define PI 3.141592653589793238462643383279502884e+00
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m, sz = 1;
ll tree[4000001], lazy[4000001];

void propagate(int node, int s, int e) {
	if (lazy[node]) {
		if (node < sz) {
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		else tree[node] ^= lazy[node];
		lazy[node] = 0;
	}
}
void add(int node, int s, int e, int l, int r, int k) {
	propagate(node, s, e);
	if (r < s || e < l) return;
	if (l <= s && e <= r) {
		lazy[node] ^= k;
		propagate(node, s, e);
		return;
	}
	int mid = (s + e) / 2;
	add(node * 2, s, mid, l, r, k);
	add(node * 2 + 1, mid + 1, e, l, r, k);
	tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}
ll q(int node, int s, int e, int l, int r) {
	propagate(node, s, e);
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return tree[node];
	int mid = (s + e) / 2;
	return q(node * 2, s, mid, l, r) ^ q(node * 2 + 1, mid + 1, e, l, r);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	while (sz < n) sz *= 2;
	for (int i = 0; i < n; i++) cin >> tree[sz + i];
	for (int i = sz - 1; i > 0; i--) tree[i] = tree[i * 2] ^ tree[i * 2 + 1];
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c, d;
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			add(1, 1, sz, b + 1, c + 1, d);
		}
		else {
			cin >> b >> c;
			cout << q(1, 1, sz, b + 1, c + 1) << "\n";
		}
	}
}
