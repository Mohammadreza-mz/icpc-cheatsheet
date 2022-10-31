Line(Point p1 , Point p2){
	a = p2.y - p1.y;
	b = p1.x - p2.x;
	c = a * p1.x + b * p1.y;
	c = -c;

}

Point intersection(Line l1 , Line l2){
	ld a1 = l1.a;
	ld b1 = l1.b;
	ld c1 = -l1.c;
	ld a2 = l2.a;
	ld b2 = l2.b;
	ld c2 = -l2.c;
	ld determinant = a1*b2 - a2*b1; 
	ld x = (b2*c1 - b1*c2)/determinant; 
	ld y = (a1*c2 - a2*c1)/determinant; 
	return Point(x, y); 
}

Point mirrorImage(Point p , Line l) 
{ 
	ld a = l.a;
	ld b = l.b;
	ld c = l.c;
	ld x1 = p.x;
	ld y1 = p.y;
	ld temp = -2 * (a * x1 + b * y1 + c) / 
	(a * a + b * b); 
	ld x = temp * a + x1; 
	ld y = temp * b + y1; 
	return Point(x, y); 
}

ld pointToLine(Point p0, Point p1, Point p2){
	//p0 to (p1 , p2)
	ll x0 = p0.x;
	ll y0 = p0.y;
	ll x1 = p1.x;
	ll y1 = p1.y;
	ll x2 = p2.x;
	ll y2 = p2.y;
	ld a = ((y2 - y1)*x0 - (x2 - x1)*y0 + x2 * y1 - y2 * x1);
	ld b = (y2 - y1)*(y2 - y1) + (x2 - x1)*(x2 - x1);
	return a * a / b;
}

inline p3d rotate(const p3d& p /*pt*/, const p3d& u /*axis*/, const ld& angle) {
//p center u
ld c = cos(angle), s = sin(angle), t = 1 - cos(angle);  return {
	p.x*(t*u.x*u.x + c) + p.y*(t*u.x*u.y - s*u.z) + p.z*(t*u.x*u.z + s*u.y),
	p.x*(t*u.x*u.y + s*u.z) + p.y*(t*u.y*u.y + c) + p.z*(t*u.y*u.z - s*u.x),
	p.x*(t*u.x*u.z - s*u.y) + p.y*(t*u.y*u.z + s*u.x) + p.z*(t*u.z*u.z + c) }; 
}


int cmp(ld x){
	if (fabs(x) < eps)
		return 0;
	return ((x < 0 ) ? -1 : 1);
}

ld Dot( const Vec2& a, const Vec2& b )
{
    return a.x * b.x + a.y * b.y;
}

int orientation(Point p, Point q, Point r) 
{ 
	ld val = (q.y - p.y) * (r.x - q.x) - 
	(q.x - p.x) * (r.y - q.y); 

	if (cmp(val) == 0) return 0;  
	return (cmp(val) > 0)? 1: 2;  
}

bool onSegment(Point p, Point q, Point r) 
{ 
	// (p , r) point q
    if (cmp(q.x - max(p.x, r.x)) >= 0 && cmp(q.x - min(p.x, r.x)) <= 0 && 
            cmp(q.y - max(p.y, r.y)) >= 0 && cmp(q.y - min(p.y, r.y)) <= 0 )
        return true; 
    return false; 
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) 
{ 
	// (p1 , q1) intersect (p2 , q2)
	int o1 = orientation(p1, q1, p2); 
	int o2 = orientation(p1, q1, q2); 
	int o3 = orientation(p2, q2, p1); 
	int o4 = orientation(p2, q2, q1); 
	if (o1 != o2 && o3 != o4) 
		return true; 
	if (o1 == 0 && onSegment(p1, p2, q1)) return true; 
	if (o2 == 0 && onSegment(p1, q2, q1)) return true; 
	if (o3 == 0 && onSegment(p2, p1, q2)) return true; 
	if (o4 == 0 && onSegment(p2, q1, q2)) return true; 
    return false; // Doesn't fall in any of the above cases 
} 

bool isInside(Point p) 
{ 
	if (n < 3)  return false; 
	Point extreme = {1e18, p.y}; 
	int count = 0, i = 0; 
	do
	{ 
		int next = (i+1)%n; 
		if (doIntersect(polygon[i], polygon[next], p, extreme)) 
		{ 
			if (orientation(polygon[i], p, polygon[next]) == 0) 
				return onSegment(polygon[i], p, polygon[next]); 

			count++; 
		} 
		i = next; 
	} while (i != 0); 
	return count&1;
}
ld cross(Vec2 a , Vec2 b){
	return a.x * b.y - a.y * b.x;
}
ld len(Vec2 a){
	return hypotl(a.x , a.y);
}
ld SqDistancePtSegment( Vec2 a, Vec2 b, Vec2 p )
{
	Vec2 v1 = b - a;
	Vec2 v2 = p - a;
	Vec2 v3 = p - b;
	if (cmp(Dot(v1 , v2)) < 0)return len(v2);
	if (cmp(Dot(v1 , v3)) > 0) return len(v3);
	return fabs(cross(v1 , v2)) /len(v1);
}
Point F( int  i  ,int j , int k){
	Vec2 a , b , c;
	a.x = polygon[i].x;
	a.y = polygon[i].y;
	b.x = polygon[j].x;
	b.y = polygon[j].y;
	c.x = polygon[k].x;
	c.y = polygon[k].y;
	Vec2 v1 = b - a;
	Vec2 v2 = c - a;
	Vec2 nimsaz =  (v2 * len(v1)) + (v1 * len(v2)) ;
	ld sz = len(nimsaz);
	nimsaz.x /= sz;
	nimsaz.y /= sz;
	ld costeta = Dot(nimsaz  , v2) / (len(nimsaz) * len(v2));
	ld sinteta = sqrt(1.0 - costeta * costeta);
	ld d = R / sinteta;
	Vec2 point = (nimsaz * d) + a;
	return {point.x , point.y};

}

Point rotate(Point c , Point p , ld angle)
{
    ld sn = sin(angle);
    ld cs = cos(angle);
    Point q(cs*(p.x-c.x) - sn *(p.y-c.y) + c.x , sn *(p.x-c.x) + cs * (p.y-c.y) + c.y);
    return q;
}