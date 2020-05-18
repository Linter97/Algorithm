#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
#define PI 3.141592653589793238462643383279502884e+00
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, q;
int tree[2 << 19];
void add(int k, int x) {
	k += n;
	tree[k] = x;
	for (k /= 2; k >= 1; k /= 2) {
		tree[k] = min(tree[k * 2], tree[k * 2 + 1]);
	}
}
int query(int a, int b) {
	a += n;
	b += n;
	int res = 2e9;
	while (a <= b) {
		if (a % 2 == 1) res = min(res, tree[a++]);
		if (b % 2 == 0) res = min(res, tree[b--]);
		a /= 2, b /= 2;
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	fill(tree, tree + (2 << 19), 2e9);
	int sz = 1;
	while (sz < n) sz *= 2;
	for (int i = n; i < 2 * n; i++) {
		int x;
		cin >> x;
		add(i - n, x);
	}
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		cout << query(a, b) << "\n";
	}
}
