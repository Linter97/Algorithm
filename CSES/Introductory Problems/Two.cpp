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
	int n;
	cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; i++) sum += i;
	if (sum % 2 == 1) cout << "NO\n";
	else {
		vector<int> a, b;
		if (n % 2 == 0) {
			for (int i = 1; i <= n; i++) {
				if (i <= n / 4)a.push_back(i);
				else if (i > n / 4 && i <= n * 3 / 4) b.push_back(i);
				else a.push_back(i);
			}
		}
		else {
			a.push_back(1);
			for (int i = 2, j = 0; i <= n; i++) {
				if (a.size() == b.size()) j = 0;
				else if (a.size() - b.size() == 2) j = 1;
				if (j == 0) a.push_back(i);
				else b.push_back(i);
			}
		}
		cout << "YES\n";
		cout << a.size() << "\n";
		for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
		cout << "\n" << b.size() << "\n";
		for (int i = 0; i < b.size(); i++) cout << b[i] << " ";
	}
}
