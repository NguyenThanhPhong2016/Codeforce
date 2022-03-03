#include<bits/stdc++.h>
#define fi  first
#define se  second
#define ll  long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
#define TASK "start"
using namespace std;
void solve(){
    int n ;
    cin>>n;
    int a[n];
    int sum = 0 ;
    for(int i = 0; i < n ; i++){
        cin>>a[i];
    }
    if( a[0]!= a[1] ){
        if( a[0] ==a[2] ){
            cout<<2<<endl;
        }
        else{
            cout<<1<<endl;
        }
    }
    else{
        for(int i = 2 ; i< n;i++){
            if( a[i] != a[0] ){
                cout<<i+1<<endl;
                break;
            }
        }
    }
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}
