#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
//  sort(v.begin(), v.end(), greater<int>());
//

void in( vector<int> s ){
    cout<<"in s :"<<endl;
    for(int i = 0 ; i < s.size() ; i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}

void solve(){
    int n ,x  ; cin>>n>>x;
    int a[n];
    int maxbt = 0;
    int sum = 0;
    for(int i = 0 ; i<n;i++){
        cin>>a[i];
        sum+= a[i];
        maxbt = max( maxbt , a[i] );
    }
    if( sum == x ){
        cout<<"NO"<<endl;
        return;
    }
    int sum1= 0 ;
    for(int i = 0 ; i<n;i++){
        sum1 += a[i];
        if( sum1 ==x ){
            int p = a[i];
            a[i] = a[i+1];
            a[i+1] = p;
            break;
        }
    }
    cout<<"YES"<<endl;
    for(int i = 0 ; i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;


}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
