const int B= 62;
ll a[B+1];
void add(ll x){
    for(int i=B;i>=0;i--){
        ll v= (1ll << i);
        if(v & x){
            if(a[i])
                x^= a[i];
            else{
                a[i] = x;
                break;
            }
        }
    }
}
ll find_ans(){
    ll ans = 0;
    for(int i=B;i>=0;i--){
        ll v= (1ll << i);
        if(a[i] && (v & ans)==0)
            ans ^= a[i];
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    while(n--){
        ll x;
        cin>>x;
        add(x);
    }
    cout<<find_ans();
}