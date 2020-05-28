#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
#define PI 3.141592653589793238462643383279502884e+00
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int tree[500001];
pii a[500001];

void add(int k, int x) {
	while (k <= n) {
		tree[k] += x;
		k += k & -k;
	}
}
int sum(int k) {
	int res = 0;
	while (k >= 1) {
		res += tree[k];
		k -= k & -k;
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		a[i].first = i + 1;
		swap(a[i].first, a[i].second);
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		cout << a[i].first - sum(a[i].second)<< "\n";
		add(a[i].second, 1);
	}
}
