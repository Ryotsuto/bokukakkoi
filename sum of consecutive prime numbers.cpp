#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    bool pri[10001];
    int i=0,j=0,k=0,n,prime[5000]={0},cnt=0,ans=0,total=1229;
    for(i=1;i<10001;i++)
    {
        if((i%2==0)&&(i!=2))
            pri[i]=false;
        else
            pri[i]=true;
    }
    for(i=3;i<=sqrt(10001);i+=2)
    {
        if(pri[i])
            for(j=i+i;j<=10001;j+=i)
                pri[j]=false;
    }
    for(i=1;i<=10001;i++)
        if(pri[i])
        {
            prime[k]=i;
            k++;
        }
    //����1-10000��������������prime������
    prime[0]=0;
    /*for(i=1;i<=10001;i++)
        cout<<prime[i]<<endl;*/

    while(cin>>n)
    {
        if(n!=0)
        {
            for(i=1;prime[i]<=n;i++)    //prime����洢1-10000��Χ������������prime[1...total]
            {
                for(j=i;j<=total&&cnt<n;j++) //cntΪ����������
                    cnt+=prime[j];
                if(cnt==n)
                    ans++;  //ansΪ���в�ͬ���������
                cnt=0;
            }
            cout<<ans<<endl;
            ans=0;
        }
        else
            break;
    }
    return 0;
}
