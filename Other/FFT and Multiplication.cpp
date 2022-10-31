#define base complex<double>  
void fft (vector<base> & a, bool invert){  
    if (L(a) == 1) return;  
    int n = L(a);  
    vector <base> a0(n / 2), a1(n / 2);  
    for (int i = 0, j = 0; i < n; i += 2, ++j){  
        a0[j] = a[i];  
        a1[j] = a[i + 1];  
    }  
    fft (a0, invert);  
    fft (a1, invert);  
    double ang = 2 * PI / n * (invert ? -1 : 1);  
    base w(1), wn(cos(ang), sin(ang));  
    fore(i, 0, n / 2) {  
        a[i] = a0[i] + w * a1[i];  
        3  
        a[i + n / 2] = a0[i] - w * a1[i];  
        if (invert)  
            a[i] /= 2, a[i + n / 2] /= 2;  
        w *= wn;  
    }  
}  
void multiply (const vector<int> &a, const vector<int> & b, vector<int> &res){  
    vector <base> fa(all(a)), fb(all(b));  
    size_t n = 1;  
    while (n < max(L(a), (L(b)))) n <<= 1;  
    n <<= 1;  
    fa.resize(n), fb.resize(n);  
    fft(fa, false), fft(fb, false);  
    fore(i, 0, n)  
    fa[i] *= fb[i];  
    fft (fa, true);  
    res.resize (n);  
    fore(i, 0, n)  
    res[i] = int (fa[i].real() + 0.5);  
}  