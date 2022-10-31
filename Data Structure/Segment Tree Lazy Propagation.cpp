#include <iostream>

#include <vector>

using namespace std;

#define Long long long int

const int N = 200 * 1000;
const Long inf = (Long)1000 * 1000 * 1000 * 1000;
int n;
int ary[N];
Long tree[N << 2];
Long lazy[N << 2];
vector <Long> ans;

void getArray();
void build(int, int, int);
inline int lc(int);
inline int rc(int);
vector <string> split(string, char);
int toInteger(string);
Long minimum(int, int, int, int, int);
void add(int, int, int, int, int, int);
void propagate(int, int, int);
void update(int, int);
void print(); 

int main(){
    getArray();
    build(1, 0, n - 1);
    int q;
    string line;
    cin >> q;
    getline(cin, line);
    for(int i = 0; i < q; i++){
        getline(cin, line);
        vector <string> command = split(line, ' ');
        int lf = toInteger(command[0]);
        int rg = toInteger(command[1]);
        int l1, l2, r1, r2;
        if(lf > rg){
            l1 = lf;
            r1 = n - 1;
            l2 = 0;
            r2 = rg;
        }
        else{
            l1 = lf;
            r1 = rg;
            l2 = -1;
            r2 = -1;
        }
        if(command.size() == 2){
            Long min1 = minimum(1, 0, n - 1, l1, r1);
            Long min2 = minimum(1, 0, n - 1, l2, r2);
            ans.push_back(min(min1, min2));
        }
        else{
            int val = toInteger(command[2]);
            add(1, 0, n - 1, l1, r1, val);
            add(1, 0, n - 1, l2, r2, val);
        }
    }
    print();
    return 0;
}

void getArray(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> ary[i];
}

void build(int node, int l, int r){
    if(l == r)
        tree[node] = ary[l];
    else{
        int mid = (l + r) >> 1;
        build(lc(node), l, mid);
        build(rc(node), mid + 1, r);
        tree[node] = min(tree[lc(node)], tree[rc(node)]);
    }
}

inline int lc(int node){
    return node << 1;
}

inline int rc(int node){
    return node << 1 | 1;
}

vector <string> split(string str, char character){
    vector <string> res;
    string s = "";
    for(int i = 0; i < str.size(); i++){
        char c = str[i];
        if(c == character){
            res.push_back(s);
            s = "";
        }
        else
            s += c;
    }
    res.push_back(s);
    return res;
}

int toInteger(string str){
    int res = 0;
    bool positive = true;
    char zero = '0';
    for(int i = 0; i < str.size(); i++){
        char c = str[i];
        if(c == '-')
            positive = false;
        else{
            int d = int(c) - int(zero);
            res = res * 10 + d;
        }
    }
    if(!positive)
        res *= -1;
    return res;
}

Long minimum(int node, int l, int r, int beg, int end){
    if(l > end || r < beg)
        return inf;
    else if(l >= beg && r <= end)
        return tree[node];
    else{
        propagate(node, l, r);
        int mid = (l + r) >> 1;
        Long min1 = minimum(lc(node), l, mid, beg, end);
        Long min2 = minimum(rc(node), mid + 1, r, beg, end);
        return min(min1, min2);
    }
}

void add(int node, int l, int r, int beg, int end, int val){
    if(l > end || r < beg)
        return;
    else if(l >= beg && r <= end)
        update(node, val);
    else{
        propagate(node, l, r);
        int mid = (l + r) >> 1;
        add(lc(node), l, mid, beg, end, val);
        add(rc(node), mid + 1, r, beg, end, val);
        tree[node] = min(tree[lc(node)], tree[rc(node)]);
    }
}

void propagate(int node, int l, int r){
    if(l < r){
        int mid = (l + r) >> 1;
        update(lc(node), lazy[node]);
        update(rc(node), lazy[node]);
    }
    lazy[node] = 0;
}

void update(int node, int val){
    lazy[node] += val;
    tree[node] += val;
}

void print(){
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
}
