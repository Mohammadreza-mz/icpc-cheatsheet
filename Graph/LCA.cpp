void dfsLCA(int u , int p){
    tin[u] = ++timer;
    up[u][0] = p;
    fore(i,1,l){
        up[u][i] = up[up[u][i-1]][i-1];
    }
    for(int v : tree[u]){
        if (v == p)
            continue;
        dfsLCA(v,u);
    }
    tout[u]=++timer;
}
bool isAnsector(int u , int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u , int v){
    if (isAnsector(u , v))
        return u;
    if (isAnsector(v , u))
        return v;
    forn(i , l , 0){
        if (!isAnsector(up[u][i] , v))
            u = up[u][i];
    }
    return up[u][0];
}

void findLca(){
    memset(visited , false ,sizeof visited);
    memset(lev , 0 , sizeof lev);
    dfs(1 , 0);
    memset(tin , 0 , sizeof tin);
    memset(tout , 0 ,sizeof tout);
    timer = 0;
    l = ceil(log2(n));
    memset(up , 0 ,sizeof up);
    dfsLCA(1,1);
}