#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
int h[1000001], r[1000001], tree[1000001];
int query(int x) {
	int j = 1;
	while (j < n) {
		int m = j;
		if (x > tree[j]) break;
		if (x <= tree[2 * j]) m = 2 * j;
		else m = 2 * j + 1;
		j = m;
	}
	return j;
}
void add(int k, int x) {
	k += n;
	tree[k] += x;
	for (k /= 2; k >= 1; k /= 2) {
		tree[k] = max(tree[2 * k], tree[2 * k + 1]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> h[i];
	int sz = 1;
	while (sz < n) sz *= 2;
	n = sz;
	for (int i = n; i < 2 * n; i++) add(i - n, h[i - n]);
	for (int i = 0; i < m; i++) {
		cin >> r[i];
		int j = query(r[i]);
		if (j == 1) cout << "0 ";
		else {
			add(j - n, -r[i]);
			cout << j - n + 1 << " ";
		}
	}
}
