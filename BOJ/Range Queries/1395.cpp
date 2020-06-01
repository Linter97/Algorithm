#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
#define PI 3.141592653589793238462643383279502884e+00
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m, sz = 1;
int tree[400001], lazy[400001];
void propagate(int node, int s, int e) {
	if (lazy[node]) {
		if (node < sz) {
			lazy[node * 2] ^= 1;
			lazy[node * 2 + 1] ^= 1;
			int t = 0;
			t += (lazy[node * 2] ? (e - s + 1) / 2 - tree[node * 2] : tree[node * 2]);
			t += (lazy[node * 2 + 1] ? (e - s + 1) / 2 - tree[node * 2 + 1] : tree[node * 2 + 1]);
			tree[node] = t;
		}
		else tree[node] ^= 1;
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
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int q(int node, int s, int e, int l, int r) {
	propagate(node, s, e);
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return tree[node];
	int mid = (s + e) / 2;
	return q(node * 2, s, mid, l, r) + q(node * 2 + 1, mid + 1, e, l, r);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	while (sz < n) sz *= 2;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a;
		if (a == 0) {
			cin >> b >> c;
			add(1, 1, sz, b, c, 1);
		}
		else {
			cin >> b >> c;
			cout << q(1, 1, sz, b, c) << "\n";
		}
	}
}
