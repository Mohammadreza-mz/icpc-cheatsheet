#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 10;
int nxt[maxn], cmp, n;
vector <int> adj[maxn], ver[maxn];

bool con(int v,int u) {
    int idx = lower_bound(adj[v].begin(), adj[v].end(), u) - adj[v].begin();
    return (idx != adj[v].size() && adj[v][idx] == u);
}

int get(int v) {
    if (nxt[v] == v)
        return v;
    return (nxt[v] = get(nxt[v]));
}

void dfs(int v) {
    nxt[v] = get(v + 1);
    ver[cmp].push_back(v);
    for (int u = get(0); u < n; u = get(u + 1)) {
        if (!con(u, v))
            dfs(u);
    }
}

int main() {
    int m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int v, u;
        scanf("%d%d", &v, &u);
        v--, u--;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    for (int i = 0; i <= n; i++)
        sort (adj[i].begin(), adj[i].end());
    for (int i = 0; i < maxn; i++)
        nxt[i] = i;

    for (int i = 0; i < n; i++)
        if (get(i) == i)
            dfs(i), cmp++;
    printf("%d\n", cmp);
    for (int i = 0; i < cmp; i++) {
        printf("%d ", (int)ver[i].size());
        for (int j = 0; j < ver[i].size(); j++)
            printf("%d ", ver[i][j] + 1);
        printf("\n");
    }
    return 0;
}