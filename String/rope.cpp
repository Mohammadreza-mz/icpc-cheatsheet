#include <bits/stdc++.h>
#include <ext/rope> //header with rope
using namespace std;
using namespace __gnu_cxx; //namespace with rope and some additional stuff
int main(){
    rope <int> v; //use as usual STL container
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        v.push_back(i); //initialization
    string p ;
    int idx;
    cin>>p>>idx;
    for(i=1;i<=p.size();i++){
        s.insert(i + idx -1 , p[i-1]);
    }
    int l, r;
    for(int i = 0; i < m; ++i)
    {
        cin >> l >> r;
        --l, --r;
        rope <int> cur = v.substr(l, r - l + 1);
        v.erase(l, r - l + 1);
        v.insert(v.mutable_begin(), cur);

    }
    for(rope <int>::iterator it = v.mutable_begin(); it != v.mutable_end(); ++it)
        cout << *it << " ";
    return 0;
}
