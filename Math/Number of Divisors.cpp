/* Returns the number of positive divisors of n.
 * Complexity: about O(sqrt(n)).
 * REQUIRES: factor()
 * REQUIRES: sqrt() must work on Int.
 * REQUIRES: the constructor Int::Int( double ).
 **/
template< class Int >
Int divisors( Int n ) {
	vector< Int > f;
	factor( n, f );
	int k = f.size();
	vector< Int > table( k + 1, Int( 0 ) );
	table[k] = Int( 1 );

	for( int i = k - 1; i >= 0; i-- ) {
		table[i] = table[i + 1];
		for( int j = i + 1; ; j++ )
			if( j == k || f[j] != f[i] )
			{ table[i] += table[j]; break; }
	}

	return table[0];
}
