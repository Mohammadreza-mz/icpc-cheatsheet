f[0]=f[1]=0; //f[length] s is text and t is pattern
int cur= 0,ans=0;
for(int i=1;i<t.size();i++){
    while (cur && t[cur] != t[i])
        cur = f[cur];
    cur += (t[i]==t[cur]);
    f[i+1]=cur;
}
cur=0;
for(int i=0;i<s.size();i++){
    if(cur == t.size())
        cur= f[cur];
    while(cur && s[i]!=t[cur])
        cur= f[cur];
    cur += (s[i]==t[cur]);
    ans += (cur == t.size());
}