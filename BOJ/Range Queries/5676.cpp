#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
#define PI 3.141592653589793238462643383279502884e+00
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, k;
int tree[400001], x[100001];

void add(int x, int k) {
	k += n;
	tree[k] = x;
	for (k /= 2; k >= 1; k /= 2) {
		tree[k] = tree[2 * k] * tree[2 * k + 1];
	}
}
int q(int a, int b) {
	a += n, b += n;
	int res = 1;
	while (a <= b) {
		if (a % 2 == 1) res *= tree[a++];
		if (b % 2 == 0) res *= tree[b--];
		a /= 2, b /= 2;
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (1) {
		cin >> n >> k;
		fill(tree, tree + 400000, 1);
		fill(x, x + 100000, 1);
		if (cin.eof() == true) break;
		for (int i = 0; i < n; i++) cin >> x[i];
		int sz = 1;
		while (sz < n) sz *= 2;
		n = sz;
		for (int i = 0; i < n; i++) {
			if (x[i] > 0) add(1, i);
			else if (x[i] == 0) add(0, i);
			else add(-1, i);
		}
		for (int i = 0; i < k; i++) {
			char c;
			int a, b;
			cin >> c >> a >> b;
			if (c == 'C') {
				if (b > 0) add(1, a - 1);
				else if (b == 0) add(0, a - 1);
				else add(-1, a - 1);
			}
			else {
				int res = q(a - 1, b - 1);
				if (res > 0) cout << "+";
				else if (res == 0) cout << "0";
				else cout << "-";
			}
		}
		cout << "\n";
	}
}
