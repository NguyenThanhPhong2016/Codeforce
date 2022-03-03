#include <bits/stdc++.h>

using namespace std;
const int inf=1e7+6;
int s[inf][3];
int main()
{
    int n ;cin>>n;
    int y[n];
    for(int i= 0 ; i < n ; i++){
        cin>>y[i];
    }
    for(int i = 0 ;i < n;i++){
        for(int j = i+1;j<n;j++){
            int t = y[i]+y[j];
            if( s[t][0] != 0 && s[t][1] != i && s[t][2]!=j && i!=s[t][2]  ){
                cout<<"YES"<<endl;
                cout<<i+1<<" "<<j+1<<" "<<s[t][1]+1<<" "<<s[t][2]+1;
                exit(0);
            }
            if(s[t][0] == 0){
                s[t][0]++;
                s[t][1]=i;
                s[t][2]=j;
            }
        }
    }
    cout<<"NO";
    return 0;
}
