
/*
TUTORIAL :

https://www.topcoder.com/community/data-science/data-science-tutorials/geometry-concepts-basic-concepts/


*/
#include<bits/stdc++.h>

using namespace std;

pair<double, double> getVector(pair<double, double> a, pair<double, double> b){
    pair<double, double> vec = make_pair(a.first - b.first,
                                   a.second - b.second);
    return vec;
}

double dotProduct(pair<double, double> a, pair<double, double> b){
    double dot = a.first * b.first +
                    a.second * b.second;
    return dot;
}

double magnitude(pair<double, double> a){
    return sqrt(a.second * a.second + a.first * a.first);
}

double getAngle(pair<int, int> a, pair<int, int> b){
    double angle = acos(dotProduct(a, b)/(magnitude(a) * magnitude(b)));
    return angle;
}

double crossProduct(pair<double, double> a, pair<double, double> b){
    return a.first * b.second - a.second * b.first;
}

double linePointDist(pair<double, double> a, pair<double, double> b, pair<double, double>c, bool isSegment){
    double dist = crossProduct(getVector(a, b), getVector(b, c));
    //isSegment denotes if to consider it as segment or a line..
    if(!isSegment)
        return abs(dist);
    int dot1 = dotProduct(getVector(a, b), getVector(b, c));
    if(dot1 > 0)
        return magnitude(getVector(b, c));
    int dot2 = dotProduct(getVector(b, a), getVector(a, c));
    if(dot2 > 0)
        return magnitude(getVector(a, c));
    return abs(dist);
}

double polygonArea(vector<pair<double, double> > P){
    double ans = 0;
    if(P.size() <=2)
        return 0;
    for(int i=1; i<P.size()-1; i++){
        ans += crossProduct(getVector(P[0], P[i]), getVector(P[0],P[i+1]));
    }
    return abs(ans/2.0);
}

int main(){


}
