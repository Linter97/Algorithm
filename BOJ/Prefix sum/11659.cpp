#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int a[100001], p[100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		p[i + 1] = a[i] + p[i];
	}
	for (int k = 0; k < m; k++) {
		int i, j;
		cin >> i >> j;
		cout << p[j] - p[i - 1] << "\n";
	}
}
