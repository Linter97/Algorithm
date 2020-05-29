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
int q(int x, int y, int k) {
	x += sz, y += sz;
	int ret = 0;
	while (x <= y) {
		if (x % 2 == 1) {
			ret += upper_bound(mt[x].begin(), mt[x].end(), k) - mt[x].begin();
			x++;
		}
		if (y % 2 == 0) {
			ret += upper_bound(mt[y].begin(), mt[y].end(), k) - mt[y].begin();
			y--;
		}
		x /= 2, y /= 2;
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	while (sz < n) sz *= 2;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		add(i, a);
	}
	for (int i = 1; i < sz * 2; i++) sort(mt[i].begin(), mt[i].end());
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		int lo = -1e9, hi = 1e9;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (q(x - 1, y - 1, mid) < z) lo = mid + 1;
			else hi = mid - 1;
		}
		cout << lo << "\n";
	}
}
