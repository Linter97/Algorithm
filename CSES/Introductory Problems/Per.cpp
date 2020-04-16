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
	if (n == 2 || n == 3) cout << "NO SOLUTION\n";
	else {
		for (int i = 1; i <= n; i++) {
			if (i % 2 == 0) cout << i << " ";
		}
		for (int i = 1; i <= n; i++) {
			if (i % 2 == 1) cout << i << " ";
		}
	}
}
