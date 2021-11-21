#include<bits/stdc++.h>
using namespace std;
int n[4],temp[4];
int Min;
void dfs(int start,int ans){
    cout<<"start:"<<start<<" "<<ans<<endl;
    for(int i=0;i<4;i++)
            cout<<n[i]<<" ";
    cout<<endl;
    if(start>=4){
        Min=min(Min,ans);
    }
    if(n[start]==0){
        dfs(start+1,ans);
        return;
    }
    for(int i=start;i<4;i++)
        temp[i]=n[i];
    int a=n[start];
    ans+=abs(a);
    for(int i=start;i<4;i++){
        n[i]-=a;
        dfs(start+1,ans);
    }
    for(int i=start;i<4;i++)
        n[i]=temp[i];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        Min=1<<30;
        int a,b;
        cin>>a>>b;
        n[0]=a/1000-b/1000;
        a=a%1000;
        b=b%1000;
        n[1]=a/100-b/100;
        a=a%100;
        b=b%100;
        n[2]=a/10-b/10;
        a=a%10;
        b=b%10;
        n[3]=a-b;
        for(int i=0;i<4;i++)
            cout<<n[i]<<" ";
        cout<<endl;
        dfs(0,0);
        cout<<Min<<endl;
    }
 return 0;
}
