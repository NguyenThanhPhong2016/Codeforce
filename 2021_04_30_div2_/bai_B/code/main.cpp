#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
const int N = 102;
int ss[N][N];
void in( vector<int> s ){
    cout<<"in s :"<<endl;
    for(int i = 0 ; i < s.size() ; i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
void solve(){
    int n , m , k ; cin>>n>>m>>k;
    if( ss[n][m] == k ){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ss[0][1] = -1;
    for(int i = 1 ; i < N ;i++){
        ss[i][1] = ss[i-1][1] + 1;
        for(int j = 2 ;  j< N ; j++){
            ss[i][j] = ss[i][j -1 ] + i ;
        }
    }
    int t;cin>>t;
    while(t--){
        solve();
    }
}
