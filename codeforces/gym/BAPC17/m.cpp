#include<bits/stdc++.h>
using namespace std;

struct Point{
    int x,y;
    Point(){}
    Point(const int &_x, const int &_y){
        x = _x;
        y = _y;
    }
};
bool cmp1(const Point &a, const Point &b){
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}
bool cmp2(const Point &a, const Point &b){
    if(a.y == b.y)
        return a.x < b.x;
    return a.y < b.y;
}

int n;
Point h,w;
Point arr[100005];
int tree[100005];
map<int,int> mp;

int read(int idx){
    int maxi = INT_MIN;
    while(idx > 0){
        maxi = max(maxi,tree[idx]);
        idx -= (idx&-idx);
    }
    return maxi;
}
void update(int idx, int val){
    while(idx <= n){
        tree[idx] = max(tree[idx],val);
        idx += (idx&-idx);
    }
}

int main(){
    scanf("%d",&n);
    int x,y;
    scanf("%d%d",&x,&y);
    h = Point(x,y);
    scanf("%d%d",&x,&y);
    w = Point(x,y);
    for(int i = 1; i <= n; ++i){
        scanf("%d%d",&x,&y);
        arr[i] = Point(x,y);
    }
    if(h.x > w.x){
        h.x *= -1;
        w.x *= -1;
        for(int i = 1; i <= n; ++i)
            arr[i].x *= -1;
    }
    if(h.y > w.y){
        h.y *= -1;
        w.y *= -1;
        for(int i = 1; i <= n; ++i)
            arr[i].y *= -1;
    }
    sort(arr+1,arr+n+1,cmp2);
    int curr = 1;
    for(int i = 1; i <= n; ++i)
        mp[arr[i].y] = curr++;
    sort(arr+1,arr+n+1,cmp1);
    for(int i = 1; i <= n; ++i){
        if(arr[i].x <= w.x && arr[i].x >= h.x && arr[i].y <= w.y && arr[i].y >= h.y){
            update(mp[arr[i].y],read(mp[arr[i].y])+1);
        }
    }
    int maxi = INT_MIN;
    for(int i = 1; i <= n; ++i)
        maxi = max(maxi,read(mp[arr[i].y]));
    printf("%d\n",maxi);

    return 0;
}