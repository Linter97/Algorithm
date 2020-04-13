#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int a[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (1) {
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		stack<int> st;
		memset(a, 0, sizeof(a));
		int res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int x;
				cin >> x;
				if (x == 1) a[j]++;
				else a[j] = 0;
				while (!st.empty() && a[st.top()] > a[j]) {
					int h = a[st.top()];
					st.pop();
					int w = j;
					if (!st.empty()) w = j - st.top() - 1;
					res = max(res, h * w);
				}
				st.push(j);
			}
			while (!st.empty()) {
				int h = a[st.top()];
				st.pop();
				int w = m;
				if (!st.empty()) w = m - st.top() - 1;
				res = max(res, h * w);
			}
		}
		cout << res << "\n";
	}
}
