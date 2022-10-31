//From "You Know Izad?" team cheat sheet
//fill the v array  
//e.g. to push (p v !q) use the following code:  
//  v[VAR(p)].push_back( NOT( VAR(q) ) )  
//  v[NOT( VAR(q) )].push_back( VAR(p) )  
//the result will be in color array  
#define VAR(X) (X << 1)  
#define NOT(X) (X ^ 1)  
#define CVAR(X,Y) (VAR(X) | (Y))z  
#define COL(X) (X & 1)  
#define NVAR 400  
int n;  
vector<int> v[2 * NVAR];  
int color[2 * NVAR];  
int bc[2 * NVAR];  
bool dfs( int a, int col ) {  
    color[a] = col;  
    int num = CVAR( a, col );  
    for( int i = 0; i < v[num].size(); i++ ) {  
        int adj = v[num][i] >> 1;  
        int ncol = NOT( COL( v[num][i] ) );  
        if( ( color[adj] == -1 && !dfs( adj, ncol ) ) ||   
            ( color[adj] != -1 && color[adj] != ncol ) ) {  
            color[a] = -1;  
            return false;  
        }  
    }  
    return true;  
}  
bool twosat() {  
    memset( color, -1, sizeof color );  
    for( int i = 0; i < n; i++ ){  
        if( color[i] == -1 ){  
            memcpy(bc, color, sizeof color);  
            if( !dfs( i, 0 )){  
                memcpy(color, bc, sizeof color);  
                if(!dfs( i, 1 ))  
                    return false;  
            }  
        }  
    }  
    return true;  
}  