#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
const int N = 10;
const int mod = 1e9 + 7;
int aa[N][N][61] ;
int kqt[N][N] ;
int kqs[N][N] ;
void in( vector<int> s ){
    cout<<"in s :"<<endl;
    for(int i = 0 ; i < s.size() ; i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
void solve(){
    int n , m ; cin>>m>>n;
    for(int i = 0 ;i < n ; i++){
        for(int j = 0; j< n ;j++){
            cin>>aa[i][j][0] ;
        }
    }
    for(int k = 1 ; k <= 60 ; k++){
        for(int i = 0 ;i <n;i++){
            for(int j =  0; j < n ; j++){
                for(int h = 0 ; h<n;h++){
                    aa[i][j][k] += aa[i][h][k-1] * aa[h][j][k-1] ;
                }
                aa[i][j][k] = aa[i][j][k]%mod;
            }
        }
    }
    int m1 =m ;
    vector<int> v ;
    while( m1 !=0 ){
        v.push_back( m1%2 );
        m1 = m1/2;
    }
    for(int i = 0 ;i < n ; i++){
        kqt[i][i] = 1;
    }
    for(int p = 0 ; p < v.size() ; p++){
        if( v[p]!=0 ){
            for(int i = 0 ;i <n;i++){
                for(int j =  0; j < n ; j++){
                    for(int h = 0 ; h<n;h++){
                        kqs[i][j] += kqt[i][h] * aa[h][j][p] ;
                    }
                    kqs[i][j] = kqs[i][j] % mod;
                }
            }
            for(int i = 0 ;i <n;i++){
                for(int j =  0; j < n ; j++){
                    kqt[i][j] = kqs[i][j];
                    kqs[i][j] = 0;
                }
            }
        }
    }
    for(int i = 0 ;i <n;i++){
        for(int j =  0; j < n ; j++){
            cout<<kqt[i][j]<<" ";
        }
        cout<<endl;
    }
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;t= 1;
    while(t--){
        solve();
    }
}
