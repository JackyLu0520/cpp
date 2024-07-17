#include<bits/stdc++.h>
using namespace std;
const double eps=1e-7;
double ax,ay,bx,by,cx,cy,dx,dy;
double p,q,r;
double f(double x1,double x2){
    double ex=bx*x1+ax*(1-x1),ey=by*x1+ay*(1-x1);
    double fx=dx*x2+cx*(1-x2),fy=dy*x2+cy*(1-x2);
    double tae=sqrt((ex-ax)*(ex-ax)+(ey-ay)*(ey-ay))/p;
    double tdf=sqrt((fx-dx)*(fx-dx)+(fy-dy)*(fy-dy))/q;
    double tef=sqrt((fx-ex)*(fx-ex)+(fy-ey)*(fy-ey))/r;
    return tae+tdf+tef;
}
int main(){
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy,&p,&q,&r);
    double lab=0,rab=1,lres,rres;
    while(fabs(rab-lab)>eps){
        double labmid=(2*lab+rab)/3,rabmid=(lab+2*rab)/3;
        double lcd=0,rcd=1;
        while(fabs(rcd-lcd)>eps){
            double lcdmid=(2*lcd+rcd)/3,rcdmid=(lcd+2*rcd)/3;
            if(f(labmid,lcdmid)>f(labmid,rcdmid))
                lcd=lcdmid;
            else
                rcd=rcdmid;
        }
        lres=lcd;
        lcd=0,rcd=1;
        while(fabs(rcd-lcd)>eps){
            double lcdmid=(2*lcd+rcd)/3,rcdmid=(lcd+2*rcd)/3;
            if(f(rabmid,lcdmid)>f(rabmid,rcdmid))
                lcd=lcdmid;
            else
                rcd=rcdmid;
        }
        rres=lcd;
        if(f(labmid,lres)>f(rabmid,rres))
            lab=labmid;
        else
            rab=rabmid;
    }
    printf("%.2lf",f(lab,lres));
    return 0;
}