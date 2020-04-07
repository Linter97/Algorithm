#include <bits/stdc++.h>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int a[1000001], NGE[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	stack<int> st;
	for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() && st.top() <= a[i]) st.pop();
		if (st.empty()) NGE[i] = -1;
		else NGE[i] = st.top();
		st.push(a[i]);
	}
	for (int i = 0; i < n; i++)cout << NGE[i] << " ";
	cout << "\n";
}
