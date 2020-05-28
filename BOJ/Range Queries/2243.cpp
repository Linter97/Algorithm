#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
#define PI 3.141592653589793238462643383279502884e+00
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, sz = 1;
int tree[4000001];
void add(int k, int x) {
	k += sz;
	tree[k] += x;
	for (k /= 2; k >= 1; k /= 2) {
		tree[k] = tree[k * 2] + tree[k * 2 + 1];
	}
}
int q(int n, int k) {
	if (n >= sz) return n - sz;
	if(k <= tree[n * 2]) return q(n * 2, k);
	else return q(n * 2 + 1, k - tree[n * 2]);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	cin >> n;
	while (sz < 1000000) sz *= 2;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a;
		if (a == 1) {
			cin >> b;
			int res = q(1, b);
			cout << res + 1<< "\n";
			add(res, -1);
		}
		else {
			cin >> b >> c;
			b--;
			add(b, c);
		}
	}
}
