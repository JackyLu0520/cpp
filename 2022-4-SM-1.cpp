#include<bits/stdc++.h>
using namespace std;
int n,c[200010],a[200010],b[200010]={0},pos,Min,ans,col=1;
int main(){
	//freopen("sample.in","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",c+i);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<=n;i++)
        if(!b[i]){
            pos=i;
            while(b[pos]==0){
                b[pos]=col;
                pos=a[pos];
            }
            if(b[pos]==col){
	            Min=c[pos];
	            int k=pos;
	            pos=a[pos];
	            while(k!=pos){
	                Min=min(Min,c[pos]);
	                pos=a[pos];
	            }
	            //cout<<Min<<' '<<col<<endl;
	            ans+=Min;
	        }
	        col++;
        }
    printf("%d",ans);
    return 0;
}
