vector <int> adj[maxn], Adj[maxn];

int ord[maxn], f[maxn], fi[maxn], se[maxn], ans[maxn];

bool get(int v,int u) {
	int idx = lower_bound(adj[v].begin(), adj[v].end(), u) - adj[v].begin();
	if (idx != adj[v].size() && adj[v][idx] == u)
		return true;
	return false;
}

bool cmp(int v,int u) {
	if (adj[v].size() < adj[u].size())
		return true;
	if (adj[v].size() > adj[u].size())
		return false;
	return (v < u);
}

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++) {
		cin >> fi[i] >> se[i];
		fi[i]--, se[i]--;
		adj[fi[i]].push_back(se[i]);
		adj[se[i]].push_back(fi[i]);
		Adj[fi[i]].push_back(se[i]);
		Adj[se[i]].push_back(fi[i]);
	}
	for (int i = 0; i < n; i++)
		sort(adj[i].begin(), adj[i].end()),
		sort(Adj[i].begin(), Adj[i].end(), cmp);
	for (int i = 0; i < n; i++)
		ord[i] = i;
	sort (ord, ord + n, cmp);	
	for (int i = 0; i < n; i++)
		f[ord[i]] = i;
	for (int v = 0; v < n; v++) {
		int idx = -1;
		for (int j = 0; j < adj[v].size(); j++) {
			int u = Adj[v][j];
			if (f[u] > f[v])
				break;
			idx = j;
		}
		for (int i = 0; i <= idx; i++)
			for (int j = 0; j < i; j++) {
				int u = Adj[v][i];
				int w = Adj[v][j];
				if (get(u,w))
					ans[v]++, ans[u]++, ans[w]++;
			}
	}
	for (int i = 0; i < q; i++) {
		int v;
		cin >> v;
		v--;
		cout << ans[v] << '\n';
	}
	return 0;
}
