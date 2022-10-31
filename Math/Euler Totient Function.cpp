/* Returns the number of positive integers that are
 * relatively prime to n. As efficient as factor().
 * REQUIRES: factor()
 * REQUIRES: sqrt() must work on Int.
 * REQUIRES: the constructor Int::Int( double ).
 **/
int phi( int n ) {
	vector< int > p;
	factor( n, p );
	for( int i = 0; i < ( int )p.size(); i++ ) {
		if( i && p[i] == p[i - 1] ) continue;
		n /= p[i];
		n *= p[i] - 1;
	}
	return n;
}