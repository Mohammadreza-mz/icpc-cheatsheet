bool find_min_dis(P p1, P p2, P c, ld ratio){
    //no intersection: segment inside circle
    if(p1.dis(c) <= ratio*ratio && p2.dis(c)<= ratio*ratio)
        return 0;
 
    P v= p2-p1;
    ld l, r, ax, ay, az, base;
    if(v.x != 0)
        l= p1.x, r= p2.x, ax=1, ay=v.y/v.x, az=v.z/v.x, base=p1.x;
    else if(v.y !=0)
        l= p1.y, r= p2.y, ax= v.x/v.y, ay=1, az=v.z/v.y, base=p1.y;
    else
        l= p1.z, r= p2.z, ax= v.x/v.z, ay=v.y/v.z, az=1, base=p1.z;
    
    ld lastd= p1.dis(c);
    while(abs(r-l)>eps){
        ld m1= (2*l+r)/3,m2=(l+2*r)/3;
        P t1= {p1.x+ax*(m1-base), p1.y+ay*(m1-base), p1.z+az*(m1-base)};
        P t2= {p1.x+ax*(m2-base), p1.y+ay*(m2-base), p1.z+az*(m2-base)};
        ld d1= t1.dis(c), d2= t2.dis(c);
        if(d1 > d2)
            l= m1;
        else
            r= m2;
        lastd= d1;
    }
    if(lastd <= ratio*ratio)
        return 1;
    return 0;
}