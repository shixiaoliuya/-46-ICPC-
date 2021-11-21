#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    int sum = 0,k=0;
    for(int i=0;i<s.length();i++){
            k = s.find("edgnb",i);
        if(k != -1){
            sum++;
    i= k;
        }
    }
    cout <<sum << endl;
 return 0;
}
