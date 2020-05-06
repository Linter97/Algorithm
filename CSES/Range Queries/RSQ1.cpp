#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll p[200001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		p[i + 1] = p[i] + x;
	}
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		cout << p[b] - p[a - 1] << "\n";
	}
}
