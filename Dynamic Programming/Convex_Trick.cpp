
struct Line {
    ll k, b;
 
    Line() {
        k = b = 0ll;
    }
 
    Line(ll k, ll b) : k(k), b(b) {}
 
    ll get(ll x) {
        return k * x + b;
    }
};
 
ld interLine(Line a, Line b) {
    return (ld)(a.b - b.b) / (ld)(b.k - a.k);
}
 
struct CHT {
    vector<Line> V;
 
    CHT() {
        V.clear();
    }
 
    void addLine(Line l) {
        while (V.size() >= 2 && interLine(V[V.size() - 2], l) < interLine(V[V.size() - 2], V.back())) {
            V.pop_back();
        }
 
        V.push_back(l);
    }
 
    ll get(ll x) {
        int l = 0, r = (int)V.size() - 2, idx = (int)V.size() - 1;
 
        while (l <= r) {
            int mid = (l + r) >> 1;
 
            if (interLine(V[mid], V[mid + 1]) <= x) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
                idx = mid;
            }
        }
 
        return V[idx].get(x);
    }
};

struct Hull_Static{
    /**
        all m need to be decreasing order
        if m is in increasing order then negate the m ( like , add_line(-m,c) ),
            remember in query you have to negate the x also
    **/
 
    const ll inf = 1000000000000000000;
    int min_or_max; ///if min then 0 otherwise 1
    int pointer; /// keep track for the best line for previous query, requires all insert first;
    vector < ll > M, C; ///y = m * x + c;
 
    inline void clear(){
        min_or_max = 0; ///initially with minimum trick
        pointer = 0;
        M.clear();
        C.clear();
    }
 
    Hull_Static(){
        clear();
    }
    Hull_Static(int _min_or_max){
        clear();
        this->min_or_max = _min_or_max;
    }
    bool bad_min(int idx1, int idx2, int idx3){
        //return (C[idx3] - C[idx1]) * (M[idx1] - M[idx2]) < (C[idx2] - C[idx1]) * (M[idx1] - M[idx3]);
        return 1.0 * (C[idx3] - C[idx1]) * (M[idx1] - M[idx2]) <= 1.0 *(C[idx2] - C[idx1]) * (M[idx1] - M[idx3]); /// for overflow
    }
 
    bool bad_max(int idx1, int idx2, int idx3){
        //return (C[idx3] - C[idx1]) * (M[idx1] - M[idx2]) > (C[idx2] - C[idx1]) * (M[idx1] - M[idx3]);
        return 1.0 * (C[idx3] - C[idx1]) * (M[idx1] - M[idx2]) >= 1.0 *(C[idx2] - C[idx1]) * (M[idx1] - M[idx3]); /// for overflow
    }
 
    bool bad(int idx1, int idx2, int idx3){ /// for removing line, which isn't necessary
        if(!min_or_max) return bad_min(idx1, idx2, idx3);
        else return bad_max(idx1, idx2, idx3);
    }
 
    void add_line(ll m, ll c){ /// add line where m is given in decreasing order
        //if(M.size() > 0 and M.back() == m) return; /// same gradient, no need to add
        M.push_back(m);
        C.push_back(c);
 
        while(M.size() >= 3 and bad((int)M.size() - 3, (int)M.size() - 2, (int)M.size() - 1)){
            M.erase(M.end() - 2);
            C.erase(C.end() - 2);
        }
    }
    ll getval(ll idx, ll x){ /// get the y coordinate of a specific line
        return M[idx] * x + C[idx];
    }
 
    ll getminval(ll x){ /// if queries are sorted, make sure all insertion first.
        while(pointer <  (int)M.size() - 1 and getval(pointer + 1, x) < getval(pointer, x)) pointer++;
        return M[pointer] * x + C[pointer];
    }
    ll getmaxval(ll x){ /// if queries are sorted, make sure all insertion first.
        while(pointer <  (int)M.size() - 1 and getval(pointer + 1, x) > getval(pointer, x)) pointer++;
        return M[pointer] * x + C[pointer];
    }
    ll getminvalternary(ll x){ ///  minimum value with ternary search
        ll lo = 0;
        ll hi = (ll)M.size() - 1;
        ll ans = inf;
        while(lo <= hi){
            ll mid1 = lo + (hi - lo) / 3;
            ll mid2 = hi - (hi - lo) / 3;
            ll val1 = getval(mid1, x);
            ll val2 = getval(mid2, x);
            if(val1 < val2){
                ans = min(ans, val2);
                hi = mid2 - 1;
            }
            else{
                ans = min(ans, val1);
                lo = mid1 + 1;
            }
        }
        return ans;
    }
 
    ll getmaxvalternary(ll x){ /// maximum value with ternary search
//        cout<<M.size()<<endl;
        ll lo = 0;
        ll hi = (ll)M.size() - 1;
        ll ans = -inf;
        while(lo <= hi){
            ll mid1 = lo + (hi - lo) / 3;
            ll mid2 = hi - (hi - lo) / 3;
            ll val1 = getval(mid1, x);
            ll val2 = getval(mid2, x);
            if(val1 < val2){
                ans = max(ans, val2);
                lo = mid1 + 1;
            }
            else{
                ans = max(ans, val1);
                hi = mid2 - 1;
            }
        }
        return ans;
    }
 
};
 