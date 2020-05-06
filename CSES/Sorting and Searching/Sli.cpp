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
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	multiset<int> ms, ms2;
	for (int i = 0; i < n; i++) {
		if (i - k >= 0) {
			if (ms.count(a[i - k])) {
				auto it = ms.find(a[i - k]);
				ms.erase(it);
			}
			else {
				auto it = ms2.find(a[i - k]);
				ms2.erase(it);
			}
		}
		if (ms.size() <= ms2.size()) {
			if (ms2.empty() || a[i] <= *ms2.begin()) ms.insert(a[i]);
			else {
				ms.insert(*ms2.begin());
				ms2.erase(ms2.begin());
				ms2.insert(a[i]);
			}
		}
		else {
			if (a[i] >= *ms.rbegin()) ms2.insert(a[i]);
			else {
				ms2.insert(*ms.rbegin());
				ms.erase(--ms.end());
				ms.insert(a[i]);
			}
		}
		if (i - k + 1 >= 0) {
			cout << *ms.rbegin() << " ";
		}
	}
}
