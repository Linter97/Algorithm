#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
#define PI 3.141592653589793238462643383279502884e+00
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m, sz = 1;
vector<int> mt[400001];
void add(int k, int x) {
	k += sz;
	mt[k].push_back(x);
	for (k /= 2; k >= 1; k /= 2) {
		mt[k].push_back(x);
	}
}
int q(int node, int s, int e, int x, int y, int k) {
	if (x > e || y < s) return 0;
	if (x <= s && e <= y) return mt[node].end() - upper_bound(mt[node].begin(), mt[node].end(), k);
	int mid = (s + e) / 2;
	return q(node * 2, s, mid, x, y, k) + q(node * 2 + 1, mid + 1, e, x, y, k);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	cin >> n;
	while (sz < n) sz *= 2;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		add(i, a);
	}
	for (int i = 1; i < sz * 2; i++) sort(mt[i].begin(), mt[i].end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		int res = q(1, 1, sz, a, b, c);
		cout << res << "\n";
	}
}
