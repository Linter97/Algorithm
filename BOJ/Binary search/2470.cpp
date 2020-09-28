#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
#define PI 3.141592653589793238462643383279502884e+00
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int res = 2e9 + 1;
	int n1 = 0, n2 = 0;
	for (int i = 0; i < n; i++) {
		int l = 0, r = n - 1;
		while (l <= r) {
			int m = l + (r - l) / 2;
			if (abs(v[m] + v[i]) < res && i != m) {
				res = abs(v[m] + v[i]);
				n1 = min(v[i], v[m]);
				n2 = max(v[i], v[m]);
			}
			else if (v[i] + v[m] == 0) {
				res = 0;
				n1 = min(v[i], v[m]);
				n2 = max(v[i], v[m]);
				break;
			}
			else if (v[m] > -v[i]) r = m - 1;
			else l = m + 1;

		}
	}
	cout << n1 << " " << n2 << "\n";
}
