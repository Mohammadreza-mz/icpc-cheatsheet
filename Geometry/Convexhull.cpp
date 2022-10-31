ll cross(Point a , Point b){
    return a.x * b.y - a.y *b.x;
}

void convex(){
	sort(points.begin(), points.end());
	int m = 0;
	fore(i,0,points.size()-1){
        while (m > 1 && cross(CH[m-1] - CH[m-2] , points[i] - CH[m-2]) <= 0){
            CH.pop_back();
            m--;
        }
        CH.push_back(points[i]);
        m++;
    }
 
    int k = m;
    forn(i,points.size()-2 , 0){
        while (m > k && cross(CH[m-1] - CH[m-2] , points[i] - CH[m-2]) <= 0){
            CH.pop_back();
            m--;
        }
        CH.push_back(points[i]);
        m++;
    }
}

ld area() {
    ld sum = 0;
    int i;
    fore(i,0,CH.size()-2){
        sum += (CH[i].x*CH[i+1].y - CH[i].y*CH[i+1].x); 
    }
    return fabs(sum/2);
}