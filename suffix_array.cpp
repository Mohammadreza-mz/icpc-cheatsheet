#include <bits/stdc++.h>
using namespace std;
 
#define error(x) cout << #x << " = " << x << endl;
 
typedef long long ll;
typedef pair <int, int> pii;
 
const int N = 4e5 + 5, LOG = 20;
 
int n, r[N][LOG];
string s;
 
void radix_sort(vector <pair <pii, int>> &a) {
	int n = a.size();
	const int c = 5;
	{
		vector <int> cnt(N + 10, 0), pos(N + 10);
		vector <pair <pii, int>> a_new(n);
		for (auto x : a)
			cnt[x.first.second + c]++;
		pos[0] = 0;
		for (int i = 1; i <= N + c; i++)
			pos[i] = pos[i - 1] + cnt[i - 1];
		for (auto x : a) {
			int i = x.first.second + c;
			a_new[pos[i]] = x;
			pos[i]++;
		}
		a = a_new;
	}
	{
		vector <int> cnt(N + 10, 0), pos(N + 10);
		vector <pair <pii, int>> a_new(n);
		for (auto x : a)
			cnt[x.first.first + c]++;
		pos[0] = 0;
		for (int i = 1; i <= N + c; i++)
			pos[i] = pos[i - 1] + cnt[i - 1];
		for (auto x : a) {
			int i = x.first.first + c;
			a_new[pos[i]] = x;
			pos[i]++;
		}
		a = a_new;
	}
}

int lcp(int x, int y) {
	int ans = 0;
	for (int i = LOG - 1; ~i; i--) {
		if(y + (1 << i) > n)
			continue;
		if(r[x][i] == r[y][i])
			x += (1 << i), y += (1 << i), ans += (1 << i);
	}
	return ans;
}
 
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);	
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; i++)
		r[i][0] = (int)s[i];
	for (int j = 0; j < LOG - 1; j++) {
		vector <pair <pii, int>> a(n);
		for (int i = 0; i < n; i++) {
			if(i + (1 << j) < n)
				a[i] = {{r[i][j], r[i + (1 << j)][j]}, i};
			else
				a[i] = {{r[i][j], -1}, i};
		}
		radix_sort(a);
		r[a[0].second][j + 1] = 0;
		for (int i = 1; i < n; i++) {
			if(a[i].first == a[i - 1].first)
				r[a[i].second][j + 1] = r[a[i - 1].second][j + 1];
			else
				r[a[i].second][j + 1] = i;
		}
	}
	vector <pii> vec;
	for (int i = 0; i <= n; i++)
		vec.push_back({r[i][LOG - 1], -i});
	sort(vec.begin(), vec.end());
	for (auto x : vec)
		cout << x.second * -1 << " ";
	cout << "\n";
}