#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
#define PI 3.141592653589793238462643383279502884e+00
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int a[51], b[10001];
int n, m;
int comp(int i, int j) {
	return i > j;
}
int sol(int x) {
	int j = 0;
	for (int i = 0; i < m; i += x, j++) 
		if (j >= n || a[j] < b[i]) return false;
	return true;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; i++) cin >> b[i];
	sort(a, a + n, comp);
	sort(b, b + m, comp);
	if (a[0] < b[0]) cout << "-1\n";
	else {
		int lo = 0, hi = 10000;
		while (lo + 1< hi) {
			int mid = (lo + hi) / 2;
			if (sol(mid)) hi = mid;
			else lo = mid;
		}
		cout << hi << "\n";
	}
}
 
