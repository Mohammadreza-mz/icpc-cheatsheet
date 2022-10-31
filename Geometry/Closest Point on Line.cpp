//From In 1010101 We Trust cheatsheet:
//the closest point on the line p1->p2 to p3
void closestpt( PT p1, PT p2, PT p3, PT &r ){
	if(fabs(triarea(p1, p2, p3)) < EPS){ r = p3; return; }
	PT v = p2-p1; v.normalize();
	double pr; // inner product
	pr = (p3.y-p1.y)*v.y + (p3.x-p1.x)*v.x;
	r = p1+v*pr;
}
