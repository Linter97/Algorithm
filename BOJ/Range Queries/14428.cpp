#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
#define PI 3.141592653589793238462643383279502884e+00
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m, sz = 1;
pii tree[400001];
void add(int k, int x) {
	k += sz;
	tree[k].first = x;
	for (k /= 2; k >= 1; k /= 2) {
		if (tree[k * 2].first <= tree[k * 2 + 1].first) {
			tree[k].first = tree[k * 2].first;
			tree[k].second = tree[k * 2].second;
		}
		else {
			tree[k].first = tree[k * 2 + 1].first;
			tree[k].second = tree[k * 2 + 1].second;
		}
	}
}
pii q(int x, int y) {
	x += sz, y += sz;
	pii res = { 2e9,0 };
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
	for (int i = 0; i <= 400000; i++) {
		tree[i].first = 2e9;
		tree[i].second = i;
	}
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
		else cout << q(y - 1, z - 1).second - sz + 1<< "\n";
	}
}
