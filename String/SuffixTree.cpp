#define pci pair< char, int >
#define NV N[v]
string s;
struct node {
    int p, b, e, link;
    /*map< char, int > children;*/
    vector< pci > children;
    node( int _p, int _b, int _e ) { p = _p, b = _b, e = _e, link = -1; }
    void addChild( pci a ) { 
        children.push_back( a );
    }
    void changeChild( pci a ) {
 //children[a.first] = a.second;
        for( int i = 0; i < children.size(); i++ ) {
            if( children[i].first == a.first ) {
                children[i].second = a.second;
                return;
            }
        }
    } 
    int length() { return e - b + 1; } 
    bool gotoNext( char c, int &nv, int &nd) {
        if( nd < e - b ) {
            if( s[b + nd + 1] == c ) {
                nd++;
                return true;
            }
        } else {
            for( int i = 0; i < children.size(); i++ ) {
                if( children[i].first == c ) {
                    nv = children[i].second, nd = 0;
                    return true;
                }
            }
        }
        return false;
    }
};
vector< node > N;
void add2Tree( ) {
    N.clear();
    N.push_back( node( -1, -1, -1 ) );
    N[0].link = 0;
    int j = 0, pp = -1, v = 0, d = 0;
    for( int i = 0; i < s.length(); i++ ) {
        pp = -1;
        for( ; j <= i; j++ ) {
            if( NV.gotoNext( s[i], v, d ) ) {
                if( pp != -1 ) N[pp].link = NV.p;
                break;
            } else {
               int id = N.size();
                if( d < NV.e - NV.b ) {
                    if( pp != -1 ) N[pp].link = id;
                    N.push_back( node( NV.p, NV.b, NV.b + d ) );
                    N[NV.p].changeChild( pci( s[NV.b], id ) );
                    NV.b += d + 1;
                    NV.p = pp = id;
                    N[id].addChild( pci( s[NV.b], v ) );
                    int len = N[id].p ? d + 1 : d;
                    v = N[N[id].p].link;
                    d = NV.length() - 1;
                    while( len ) {
                        int temp = v;
                        N[temp].gotoNext( s[i - len] , v, d );
                        int l = NV.length();
                        if( len <= l ) {
                            d = len - 1;
                            break;
                        }
                        d = l - 1;
                        len -= l;
                    }
                    id++;
                } else {
                    if( pp != -1 ) N[pp].link = v;
                    pp = v;
                    v = NV.link;
                    d = NV.length() - 1;
                }
                N[pp].addChild( pci( s[i], id ) );
                N.push_back( node( pp, i, s.length() - 1 ) );
            }
        }
    }
}