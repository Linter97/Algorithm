#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int sum = 0, res = -2e9;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (sum < 0) sum = 0;
			sum += x;
			res = max(res, sum);
		}
		cout << res << "\n";
	}
}
