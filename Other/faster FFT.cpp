const double PI = acos(-1);
#define base complex<double>  
int lg_n;
int rev [maxn * 20];
vector<base> polies[maxn];
int reverse(int num ,int lll) {
    return rev[num];
}
 
void fft(vector<base> & a, bool invert) {
    int n = a.size();
   
 
    for (int i = 0; i < n; i++) {
        if (i < reverse(i, lg_n))
            swap(a[i], a[reverse(i, lg_n)]);
    }
 
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        base wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            base w(1);
            for (int j = 0; j < len / 2; j++) {
                base u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
 
    if (invert) {
        for (base & x : a)
            x /= n;
    }
}
 

void multiply (int u , int v){  
	int n = 1;
    while (n < max(L(a) , L(b))) {
    	n <<= 1;  
    }
    n <<= 1;
    lg_n = 0;
    while ((1 << lg_n) < n)
        lg_n++;
 
    for (int i=0; i<n; ++i) {
		rev[i] = 0;
		for (int j=0; j<lg_n; ++j)
			if (i & (1<<j))
				rev[i] |= 1<<(lg_n-1-j);
	}
	a.resize(n);
	b.resize(n);
    fft(a, false), fft(b, false);  
    for(int i=0; i<n; i++){
    	a[i] *= b[i];  
    }
    fft (a, true);  
    res.resize (n);  

    for(i=0; i<n; i++) {
    	res[i] = round(a[i].real());
    } 
}