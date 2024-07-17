#include<bits/stdc++.h>
using namespace std;
const int XY=10,V=10;
int main(){
    freopen("data.in","w",stdout);
    srand(time(0));
    printf("%d %d %d %d\n%d %d %d %d\n%d %d %d",rand()%XY+1,rand()%XY+1,rand()%XY+1,rand()%XY+1,rand()%XY+1,rand()%XY+1,rand()%XY+1,rand()%XY+1,rand()%V+1,rand()%V+1,rand()%V+1);
    return 0;
}