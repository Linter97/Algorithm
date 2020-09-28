#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
#define PI 3.141592653589793238462643383279502884e+00
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int ans[3];

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
	ll res = 3e9 + 1;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int l = 0, r = n - 1;
			while (l <= r) {
				int m = l + (r - l) / 2;
				if (j != m && i != m) {
					if (abs((ll)v[m] + v[i] + v[j]) < res) {
						res = abs((ll)v[m] + v[i] + v[j]);
						ans[0] = v[i];
						ans[1] = v[j];
						ans[2] = v[m];
					}
					else if ((ll)v[i] + v[j] + v[m] == 0) {
						res = 0;
						ans[0] = v[i];
						ans[1] = v[j];
						ans[2] = v[m];
						break;
					}
				}
				if (v[m] > -(v[i] + v[j])) r = m - 1;
				else l = m + 1;

			}
		}
	}
	sort(ans, ans + 3);
	cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
}
