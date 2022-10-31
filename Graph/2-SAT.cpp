const int N = 1e5 + 100;
int n, m, comp[N << 1];
bool ans[N], mark[N << 1];
vector<int> topo, in[N << 1], out[N << 1];
void dfs(int v, vector<int> *nei, vector<int> *vec) {
	mark[v] = true;
	for (int u: nei[v])
		if (mark[u] == false) {
			comp[u] = comp[v];
			dfs(u, nei, vec);
		}
	vec->push_back(v);
}
bool check() {
	for (int v = 0; v < (n << 1); v++)
		if (mark[v] == false)
			dfs(v, out, &topo);
	memset(mark, false, sizeof mark);
	int COMP = 1;
	while (topo.size()) {
		int u = topo.back();
		topo.pop_back();
		if (mark[u])
			continue;
		comp[u] = COMP++;
		dfs(u, in, &out[(N << 1) - 1]);
	}
	for (int i = 0; i < n; i++)
		if (comp[i << 1] == comp[i << 1 | 1])
			return false;
		else
			ans[i] = (comp[i << 1 | 1] > comp[i << 1]);
	return true;
}
void add_edge(int u, int v) {
	out[u].push_back(v);
	in[v].push_back(u);
}
void add_condition(int u, int v) {
	add_edge(u, v);
	add_edge(v ^ 1, u ^ 1);
}
void input() {
	cin >> n >> m;
	while (m--) {
		// 0 -> 0
		// 0 -> 1
		// 1 -> 0
		// 1 -> 1
		int u, v, x;
		cin >> u >> v >> x;
		u--, v--;
		add_condition((u << 1) | (x >> 1), (v << 1) | (x & 1));
	}
}
int main() {
	input();
	cout << (check()? "YES": "NO") << '\n';
	for (int i = 0; i < n; i++)
		cout << "b[" << i << "] = " << ans[i] << '\n';
}