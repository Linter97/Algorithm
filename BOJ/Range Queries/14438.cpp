#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
#define PI 3.141592653589793238462643383279502884e+00
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m, sz = 1;
int tree[400001];
void add(int k, int x) {
	k += sz;
	tree[k] = x;
	for (k /= 2; k >= 1; k /= 2) {
		tree[k] = min(tree[k * 2], tree[k * 2 + 1]);
	}
}
int q(int x, int y) {
	x += sz, y += sz;
	int res = 2e9;
	while (x <= y) {
		if (x % 2 == 1) res = min(res, tree[x++]);
		if (y % 2 == 0) res = min(res, tree[y--]);
		x /= 2, y /= 2;
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	cin >> n;
	fill(tree, tree + 400000, 2e9);
	while (sz < n) sz *= 2;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		add(i, a);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		if (x == 1) add(y - 1, z);
		else cout << q(y - 1, z - 1) << "\n";
	}
}
