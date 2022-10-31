/* Given a, b and n, solves the equation ax = b (mod n)
 * for x. Returns the vector of solutions, all smaller
 * than n and sorted in increasing order. The vector is
 * empty if there are no solutions.
 * REQUIRES: struct Triple, egcd
 **/
template< class Int >
vector< Int > msolve( Int a, Int b, Int n ) {
	if( n < 0 ) n = -n;
	Triple< Int > t = egcd( a, n );
	vector< Int > r;
	if( b % t.d ) return r;
	Int x = ( b / t.d * t.x ) % n;
	if( x < Int( 0 ) ) x += n;
	for( Int i = 0; i < t.d; i++ )
	r.push_back( ( x + i * n / t.d ) % n );
	return r;
}
