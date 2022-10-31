//From "You Know Izad?" team cheat sheet
/* 
a[i] = b[i] (for i <= k) 
a[i] = c[1]*a[i-1] + c[2]a[i-2] + ... + c[k]a[i-k] (for i > k) 
Given: 
b[1], b[2], ..., b[k] 
c[1], c[2], ..., c[k] 
a[N]=? 
*/  
typedef vector<vector<ll> > matrix;  
int K;  
matrix mul(matrix A, matrix B){  
    matrix C(K+1, vector<ll>(K+1));  
    REP(i, K) REP(j, K) REP(k, K)  
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % INF32;  
    return C;  
}  
matrix pow(matrix A, ll p){  
    if (p == 1) return A;  
    if (p % 2) return mul(A, pow(A, p-1));  
    matrix X = pow(A, p/2);  
    return mul(X, X);  
}  
ll solve() {  
    // base (initial) values  
    vector<ll> F1(K+1);  
    REP (i, K)  
        cin >> F1[i];  
    matrix T(K+1, vector<ll>(K+1));  
    REP(i, K) {  
        REP(j, K) {  
            if(j == i + 1) T[i][j] = 1;  
            else if(i == K) cin >> T[i][K - j + 1]; // multipliers  
            else T[i][j] = 0;  
        }  
    }  
    ll N;  
    cin >> N;  
    if (N == 1) return 1;  
    T = pow(T, N-1);  
    ll res = 0;  
    REP(i, K)  
        res = (res + T[1][i] * F1[i]) % INF32; // Mod Value  
    return res;  
}  
int main() {  
    cin >> K;  
    cout << solve() << endl;  
}  
