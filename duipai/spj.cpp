#include<bits/stdc++.h>
using namespace std;
const double eps=1e-4;
int main(){
    FILE *bf=fopen("bf.out","r");
    FILE *sol=fopen("sol.out","r");
    FILE *res=fopen("res.out","w");
    double a,b;
    for(int i=1;(fscanf(bf,"%lf",&a))!=EOF;i++){
        fscanf(sol,"%lf",&b);
        if(fabs(a-b)>eps){fprintf(res,"Error on line %d!bf:%lf,sol:%lf",i,a,b);return 0;}
    }
    fprintf(res,"Accepted!");
    return 0;
}