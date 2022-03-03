#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
#define endl "\n"
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
using namespace std;
//  sort(v.begin(), v.end(), greater<int>());
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}

void solve(){
    int n ; cin>>n;
    string a ;cin>>a;
    int s[26];
    int ss[26][26];
    int sss[26][26][26];
    for(int i= 0 ; i < 26 ;  i++){
        s[i] = 0 ;
        for(int j = 0 ; j < 26 ; j++){
            ss[i][j] = 0 ;
            for(int k = 0 ; k < 26 ; k++){
                sss[i][j][k] = 0 ;
            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        s[ a[i] - 'a' ]++;
    }
    for(int i = 0 ; i< 26 ; i++){
        if( s[i] == 0 ){
            cout<<( char )( i + 'a' )<<endl;
            return;
        }
    }
    for(int i= 0 ; i +1 < n ;  i++){
        ss[ a[i] - 'a' ][ a[i+1] - 'a' ]++;
    }
    for(int i= 0 ; i < 26 ;  i++){
        for(int j = 0 ; j < 26 ; j++){
            if( ss[i][j] == 0 ){
                cout<<( char )( i + 'a' )<<(char)( j + 'a' )<<endl;
                return;
            }
        }
    }
    for(int i= 0 ; i +2 < n ;  i++){
        sss[ a[i] - 'a' ][ a[i+1] - 'a' ][ a[ i + 2 ] - 'a' ]++;
    }
    for(int i= 0 ; i < 26 ;  i++){
        for(int j = 0 ; j < 26 ; j++){
            for(int k = 0;  k < 26 ;k++){
                if( sss[i][j][k] == 0 ){
                    cout<<( char )( i + 'a' )<<(char)( j + 'a' )<<(char)( k + 'a' )<<endl;
                    return;
                }
            }
        }
    }
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
