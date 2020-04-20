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
	multiset<int> ms;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		auto it = ms.lower_bound(x + 1);
		if (it != ms.end()) {
			ms.erase(it);
			ms.insert(x);
		}
		else ms.insert(x);
	}
	cout << ms.size() << "\n";
}
