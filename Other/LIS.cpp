fill(mi,mi+n+1,INF);
mi[0]= -INF;
for(int i=1;i<=n;i++){
    cin>>a[i];
    int p= upper_bound(mi,mi+n+1, a[i])-mi;
    if(mi[p-1]<a[i])  //comment this if to also match equal numbers
        mi[p]= a[i];
}
for(int i=n;i>=0;i--)
    if(mi[i]<INF)
        return cout<<i,0;