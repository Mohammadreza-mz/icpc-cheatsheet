// angle bisector
int bcenter( PT p1, PT p2, PT p3, PT& r ){
	if( triarea( p1, p2, p3 ) < EPS ) return -1;
	double s1, s2, s3;
	s1 = dist( p2, p3 );
	s2 = dist( p1, p3 );
	s3 = dist( p1, p2 );
	double rt = s2/(s2+s3);
	PT a1,a2;
	a1 = p2*rt+p3*(1.0-rt);
	rt = s1/(s1+s3);
	a2 = p1*rt+p3*(1.0-rt);
	intersection( a1,p1, a2,p2, r );
	return 0;
}
