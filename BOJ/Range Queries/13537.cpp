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
int q(int x, int y ,int k) {
	x += sz, y += sz;
	int ret = 0;
	while (x <= y) {
		if (x % 2 == 1) {
			ret += mt[x].end() - upper_bound(mt[x].begin(), mt[x].end(), k);
			x++;
		}
		if (y % 2 == 0) {
			ret += mt[y].end() - upper_bound(mt[y].begin(), mt[y].end(), k);
			y--;
		}
		x /= 2, y /= 2;
	}
	return ret;
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
		int res = q(a - 1, b - 1, c);
		cout << res << "\n";
	}
}
