#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<map>
#include<string>
using namespace std;
map<int,string>zdy;
long long sum;
int x,y,dt[5][5],fx,cl[5],zsjs,djs,dx;
bool bh=false; 
char d,dj[10]={};
int cx(int i){                    //��ѯ����������������һ�������ֿռ�(���������� 
    if(i==dx)    return 998;
    if(cl[i]!=0)    return i;
    if(cl[i]==0)    return cx(i+1);
}
void sx(){
    for(int i=0;i<=(dx-1);i++){
        if(cx(i+1)!=998){
            if((cl[i]!=0)&&(cl[i]==cl[cx(i+1)])){
                cl[i]*=2;
                sum+=cl[i];
                cl[cx(i+1)]=0;
                bh=true;
            }
        }
    }
    bool bd=false;
    do{
        bd=false;
        for(int ii=(dx-1);ii>=1;ii--)
                if((cl[ii-1]==0)&&(cl[ii]!=0)){
                    cl[ii-1]=cl[ii];
                    cl[ii]=0;
                    bh=true;
                    bd=true;
                }
    }while(bd==true);
}
int main(){
//    freopen("������Ϸ���ֽ��.txt","w",stdout);
    cout<<"������������������2048������"<<endl;
    cout<<"Ŀǰ���ںܶ಻�ܣ����Ҽ���"<<endl;
    cout<<"��Ϸ�����������£�\n        W A S D��8 4 2 6������ �� �� �һ���\n        �������Ϸ��������ͣ����ʹ��p\n        �����Ҫ������Ϸ����ʹ��e"<<endl;
    system("pause");
    system("cls");
    cout<<"����������Ҫ�Զ���ĵȼ�������Ϊ0�����������ְ�(��һ�ȼ�Ϊ�ռ�����0��Ӧ�ȼ�)"<<endl;
    cin>>djs;
    cout<<"����������Ҫ�����̴�С"<<endl;
    cin>>dx;
    zdy[0]='0';    zdy[2]='2';    zdy[4]='4';    zdy[8]='8';    zdy[16]='16';    zdy[32]='32';    zdy[64]='64';    zdy[128]='128';    zdy[256]='256';    zdy[512]='512';
    int oop=0;
    for(int i=1;i<=djs;i++){
        string ppo;
        cin>>ppo;
        zdy[oop]=ppo;
        oop=(oop==0)?2:(oop*2);
    }
    for(int i=0;i<=(dx-1);i++)
        for(int ii=0;ii<=(dx-1);ii++)
            dt[i][ii]=0;
    for(;;){
        for(bool hg=true;hg==true;){
            x=rand()%dx;
            y=rand()%dx;
            if(dt[x][y]==0){
                cout<<"�˴β�����������ǣ�"<<x<<" "<<y<<endl;
                dt[x][y]=2;
                hg=false;
            }
        }
        bool jg=false;
        for(int i=0;i<=(dx-1);i++)
            for(int ii=0;ii<=(dx-1);ii++)
                if(dt[i][ii]==0)
                    jg=true;
        if(jg==false){
            system("cls");
            cout<<"��Ϸ����!��Ŀǰ�Ļ����ǣ�"<<sum<<"��лʹ����������2048"<<endl;
            return 0;
        }
        cout<<"���ڵĻ����ǣ�"<<sum<<endl<<endl<<endl<<endl;
        for(int i=0;i<=(dx-1);i++){
            for(int ii=0;ii<=(dx-1);ii++)
                cout<<zdy[dt[i][ii]]<<"        ";
            cout<<endl<<endl<<endl<<endl;
        }
        do{
            bh=false;
            cout<<"�������ƶ�����2,4,6,8(s a d w)�ֱ�����£����ң���"<<endl;
            cin>>d;
            switch(d){
                case '8':
                case 'w':    
                    for(int i=0;i<=(dx-1);i++){
                        zsjs=0;
                        for(int ii=0;ii<=(dx-1);ii++)
                            cl[zsjs++]=dt[ii][i];
                        sx();
                        zsjs=0;
                        for(int ii=0;ii<=(dx-1);ii++)
                            dt[ii][i]=cl[zsjs++];
                    }
                    break;
                case '4':
                case 'a':
                    for(int ii=0;ii<=(dx-1);ii++){
                        zsjs=0;
                        for(int i=0;i<=(dx-1);i++)
                            cl[zsjs++]=dt[ii][i];
                        sx();
                        zsjs=0;
                        for(int i=0;i<=(dx-1);i++)
                            dt[ii][i]=cl[zsjs++];
                    }
                    break;
                case '6':
                case 'd':
                    for(int ii=0;ii<=(dx-1);ii++){
                        zsjs=0;
                        for(int i=(dx-1);i>=0;i--)
                            cl[zsjs++]=dt[ii][i];
                        sx();
                        zsjs=0;
                        for(int i=(dx-1);i>=0;i--)
                            dt[ii][i]=cl[zsjs++];
                    }
                    break;
                case '2':
                case 's':
                    for(int i=0;i<=(dx-1);i++){
                        zsjs=0;
                        for(int ii=(dx-1);ii>=0;ii--)
                            cl[zsjs++]=dt[ii][i];
                        sx();
                        zsjs=0;
                        for(int ii=(dx-1);ii>=0;ii--)
                            dt[ii][i]=cl[zsjs++];
                    }
                    break;
                case 'p':
                    cout<<"��ͣ"<<endl;
                    system("pause");
                case '5':
                    int o;
                    cout<<"ȷ���˳���ȷ������5��ȡ�������ఴ��"<<endl;
                    cin>>o;
                    if(o==5){
                        system("cls");
                        cout<<"��Ϸ����!��Ŀǰ�Ļ����ǣ�"<<sum<<"��лʹ����������2048"<<endl;
                    }
                    cout<<"ȡ���ɹ�"<<endl;
                    system("pause");
            }
        }while(!bh);
        system("cls");
    } 
    return 0;
}
