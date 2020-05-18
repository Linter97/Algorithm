#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
#define PI 3.141592653589793238462643383279502884e+00
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int x[200001], tree[200001];
int n;
int sum(int k) {
	int s = 0;
	while (k >= 1) {
		s += tree[k];
		k -= k & -k;
	}
	return s;
}
void add(int k, int x) {
	while (k <= n) {
		tree[k] += x;
		k += k & -k;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		add(i, 1);
	}
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		int lo = 0, hi = n;
		while (lo <= hi) {
			int mid = lo - (lo - hi) / 2;
			if (sum(mid) < p)lo = mid + 1;
			else hi = mid - 1;
		}
		cout << x[lo] << " ";
		add(lo, -1);
	}
}
