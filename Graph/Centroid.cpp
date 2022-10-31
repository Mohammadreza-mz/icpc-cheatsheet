int n, sz[N], ans[N], g[N];
bool mark[N];
vector<int> adj[N]; 
void dfs(int v, int p = -1) {
	sz[v] = 1;
	g[v] = -1;
	for (auto u : adj[v]) {
		if(u == p || mark[u])
			continue;
		dfs(u, v);
		sz[v] += sz[u];
		if(g[v] == -1 || sz[g[v]] < sz[u])
			g[v] = u;
	}
	return;
}
void Centroid(int v, int par, int cur) {
	dfs(v, par);
	int total = sz[v];
	if(sz[v] == 1)
		ans[v] = cur, mark[v] = true;
	if(sz[v] > 1) {
		while(sz[g[v]] * 2 > total && !mark[g[v]])
			v = g[v];
		ans[v] = cur;
		mark[v] = true;
		for (auto u : adj[v])
			if(!mark[u] && !ans[u])
				Centroid(u, v, cur + 1);
	}
}
int main() {Centroid(0, -1, 1);}