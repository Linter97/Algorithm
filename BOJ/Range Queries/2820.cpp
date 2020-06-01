#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
#define PI 3.141592653589793238462643383279502884e+00
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m, sz = 1, cnt;
int tree[2000001], lazy[2000001], p[500001];
vector<int> adj[500001];
int lo[500001], hi[500001];
void propagate(int node, int s, int e) {
	if (lazy[node]) {
		tree[node] += (e - s + 1) * lazy[node];
		if (node < sz) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
void add(int node, int s, int e, int l, int r, int k) {
	propagate(node, s, e);
	if (r < s || e < l) return;
	if (l <= s && e <= r) {
		lazy[node] += k;
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
void dfs(int here) {
	lo[here] = ++cnt;
	for (auto there : adj[here]) {
		if (!lo[there]) dfs(there);
	}
	hi[here] = cnt;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	while (sz < n) sz *= 2;
	int x, y;
	cin >> x;
	p[1] = x;
	for (int i = 2; i <= n; i++) {
		cin >> x >> y;
		p[i] = x;
		adj[y].push_back(i);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) add(1, 1, sz, lo[i], lo[i], p[i]);
	for (int i = 0; i < m; i++) {
		char c;
		int a, x;
		cin >> c;
		if (c == 'p') {
			cin >> a >> x;
			if (lo[a] == hi[a]) continue;
			add(1, 1, sz, lo[a] + 1, hi[a], x);
		}
		else {
			cin >> a;
			cout << q(1, 1, sz, lo[a], lo[a]) << "\n";
		}
	}
}
