#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int a[200001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	set<int> s;
	int res = 0;
	for (int i = 0, j = 0; i < n; i++) {
		if (s.count(a[i])) {
			res = max(res, (int)s.size());
			while (s.count(a[i])) {
				s.erase(a[j++]);
			}
			i--;
		}
		else s.insert(a[i]);
	}
	res = max(res, (int)s.size());
	cout << res << "\n";
}
