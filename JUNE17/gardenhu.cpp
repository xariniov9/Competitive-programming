// MONOTONE CHAIN CONVEX HULL!


#include<bits/stdc++.h>

using namespace std;

typedef struct Point{
    int x; int y;
    int idx;
}point;

point P[100000];

int cmp(const void * a, const void * b){
    point * A = (point *)a;
    point * B = (point *)b;
    if(A->y == B->y && A->x == B->x)
        return A->idx - B->idx;
    if(A->y == B->y)
        return A->x - B->x;
    return A->y - B->y;
}

int cross(const pair<int, int> &a, const pair<int, int> & b, const pair<int, int> & c){
        return (a.first - c.first)*(b.second - c.second) -
                (a.second - c.second) * (b.first - c.first);
}
vector<int> res;
vector<pair<int, int> > findHull(int n){
    vector<pair<int, int> > L;
    for(int i=0; i<n; i++){
        pair<int, int> curr = make_pair(P[i].x, P[i].y);
        while(L.size() >=2 && cross(L[L.size()-2], L[L.size()-1], curr) <= 0){
            L.pop_back();
            res.pop_back();
        }
        L.push_back(curr);
        res.push_back(P[i].idx);
    }
    L.pop_back();
    res.pop_back();
    vector<pair<int, int> > U;
    for(int i=n-1; i>=0; i--){
        pair<int, int> curr = make_pair(P[i].x, P[i].y);
        while(U.size() >=2 && cross(U[U.size()-2], U[U.size()-1], curr) <= 0){
            U.pop_back();
            res.pop_back();
        }
        res.push_back(P[i].idx);
        U.push_back(curr);
    }
    U.pop_back();
    res.pop_back();
    for(int i=0; i<U.size(); i++){
        L.push_back(U[i]);
    }
    return L;
}
long double sqr(long double x){
    return x*x;
}
long double Distance(pair<int, int> a, pair<int, int> b){
    return sqrt(sqr(a.first - b.first) +
                sqr(a.second - b.second));
}
int itr;
void Resize(int n){
    int i=0;
    while(i<n){
        P[itr].x = P[i].x;
        P[itr].y = P[i].y;
        P[itr].idx = P[i].idx;
        itr++;
        int j=i+1;
        while(j<n && P[i].x == P[j].x && P[i].y == P[j].y){
            j++;
        }
        i=j;
    }
}

int main(){
    int t=1;
//    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        res.clear();
        itr=0;
        for(int i=0; i<n; i++){
            scanf("%d%d",&P[i].x, &P[i].y);
            P[i].idx = i+1;
        }
        if(n>2)
            qsort(P, n, sizeof(point), cmp);
        Resize(n);
        n=itr;
        vector<pair<int, int> > hull;
        if(n>2){
            hull = findHull(n);

            long double ans = 0.0;
            for(int i=0; i<hull.size()-1; i++){
                ans+=Distance(hull[i], hull[i+1]);
            }

            ans += Distance(hull[hull.size()-1], hull[0]);
            printf("%lld\n",(long long)ans);
        } else{
            if(n==1){
                printf("0\n");
            }else{
                long double ans = 2.0 * Distance(make_pair(P[0].x, P[0].y),
                                                 make_pair(P[1].x, P[1].y));
                printf("%lld\n",(long long)ans);
            }
        }
    }
    return 0;
}
