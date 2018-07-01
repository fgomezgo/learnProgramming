#include<bits/stdc++.h>
#define fst first
#define snd second
using namespace std;

pair<int,int> sqr1[4];
pair<int,int> sqr2[4];
pair<int,int> rect[4];

int main(){
    int maxX = INT_MIN, maxY = INT_MIN, minX = INT_MAX, minY = INT_MAX;
    for(int i = 0; i < 4; ++i){
        scanf("%d%d",&sqr1[i].fst,&sqr1[i].snd);
        maxX = max(maxX,sqr1[i].fst);
        minX = min(minX,sqr1[i].fst);
        maxY = max(maxY,sqr1[i].snd);
        minY = min(minY,sqr1[i].snd);
    }
    for(int i = 0; i < 4; ++i){
        scanf("%d%d",&sqr2[i].fst,&sqr2[i].snd);
    }
    int maxBplus = INT_MIN, maxBminus = INT_MIN, minBplus = INT_MAX, minBminus = INT_MAX;
    for(int i = 0; i < 4; ++i){
        int sig = (i+1)%4;
        rect[i].fst = (sqr2[sig].snd-sqr2[i].snd)/(sqr2[sig].fst-sqr2[i].fst);
        if(rect[i].fst == 1){
            rect[i].snd = sqr2[sig].snd-sqr2[sig].fst;
            maxBplus = max(maxBplus,rect[i].snd);
            minBplus = min(minBplus,rect[i].snd);
        } else{
            rect[i].snd = sqr2[sig].snd+sqr2[sig].fst;
            maxBminus = max(maxBminus,rect[i].snd);
            minBminus = min(minBminus,rect[i].snd);
        }
    }


    for(int x = -100; x <= 100; ++x){
        for(int y = -100; y <= 100; ++y){
            bool f1 = (x <= maxX && x >= minX && y <= maxY && y >= minY);
            bool f2 = true;
            for(int i = 0; i < 4; ++i){
                if(rect[i].fst == 1){
                    int tmp = x+rect[i].snd;
                    if(rect[i].snd == maxBplus && y > tmp){
                        f2 = false;
                        break;
                    }
                    if(rect[i].snd == minBplus && y < tmp){
                        f2 = false;
                        break;
                    }
                } else{
                    int tmp = -x+rect[i].snd;
                    if(rect[i].snd == maxBminus && y > tmp){
                        f2 = false;
                        break;
                    }
                    if(rect[i].snd == minBminus && y < tmp){
                        f2 = false;
                        break;
                    }
                }
            }
            if(f1 && f2){
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}