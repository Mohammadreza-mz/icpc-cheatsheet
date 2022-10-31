using namespace std;
typedef long long ll;
typedef pair<ll ,int> pii;
vector <pii> v;
//////////// bozorgtarin i b shekli k N!%k^i==0
void fact(ll n) {
	ll x = 2;
	while (x * x <= n)
	{
		ll num = 0;
		while (n % x == 0) {
			num++;
			n /= x;
		}
		if (num) v.push_back(MP(x, num));
		x++;
		if (n == 1ll) break;
	}
	if(n > 1) v.push_back(MP(n, 1));
}

ll getfact(ll n) {
	ll ret = n;
	Rep(i, v.size()) {
		ll k = v[i].first;
		ll cnt = 0;
		ll t = n;
		while (k <= n) {
		cnt += n / k;
		n /= k;
		}
		n = t;
		ret = min(ret, cnt / v[i].second);
	}
	return ret;
}

int main() {
	int tc;
	ll n, k;
	cin >> tc;
	while (tc--) {
		v.clear();
		cin >> n >> k;
		fact(k);
		cout << getfact(n) << endl;
	}
	return 0;
}
