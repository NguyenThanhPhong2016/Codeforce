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
const int mod[] = {(int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9+ 9277};
const int N = 2e5 + 10 ;
void solve1(int n){
    vector< string > a(n);
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    int ans = 0 ;
    int sz = a[0].size();
    for(int i = 0 ; i < n ; i++){
        for(int j =  i+1 ; j  < n ; j++){
            int l = -1;
            int si[27];
            int sj[27];
            for(int k = 0 ; k< 27 ; k++){
                si[k]= sj[k] = 0 ;
            }
            for( int k = 0 ; k < sz ; k++ ){
                si[ a[i][k] - 'a' ]++;
                sj[ a[j][k] - 'a' ]++;
            }
            for(int k = 0 ; k< 27 ; k++){
                if( si[k] != sj[k] ){
                    //cout<<k<<" "<<si[k]<<" "<<sj[k]<<endl;
                    ans += 1337;break;
                }
                if( k == 26 ){
                    int l = 0 ;
                    int r = 0 ;
                    for(int h = 0; h < sz ; h++){
                        if( a[i][h] != a[j][h] ){
                            l = h ; break;
                        }
                    }
                    for(int h = sz - 1; h >= 0 ; h--){
                        if( a[i][h] != a[j][h] ){
                            r = h ; break;
                        }
                    }
                    if( l + 1 == r ) ans += 1 ;
                    else{
                        int xd = 0;
                        for(int h = l + 1 ; h <= r ; h++){
                            if( a[i][h] > a[i][h-1] ){
                                break;
                            }
                            if( h==r ){
                                ans += 1 ;xd = 1 ;
                            }
                        }
                        if( xd == 0){
                            for(int h = l + 1 ; h <= r ; h++){
                                if( a[j][h] > a[j][h-1] ){
                                    break;
                                }
                                if( h==r ){
                                    ans += 1 ;xd =1 ;
                                }
                            }
                            if( xd == 0 ) ans += 2 ;
                        }
                    }
                }
            }
            debug(i);debug(j);debug(ans);
        }
    }
    cout<<ans<<endl;
}
void solve(){
    int n ;cin>>n ;
    if( n <= 2e3 ){
        solve1(n);return;
    }
    vector< string > a(n);
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
        a[i] = " " +  a[i];
    }
    int sz = a[0].size()  - 1 ;
    int o = rand()%4 ;
    int modbt = mod[o];
    int s[n][sz+1];
    for(int i = 0 ; i< n ; i++){
        s[i][0] = 0 ;
    }
    for(int i = 0; i < n ; i++){
        for(int j =  1;  j <= sz ; j++){
            s[i][j] = ( s[i][j-1]*29 + ( a[i][j] - 'a' )  ) % modbt ;
        }
    }
    map<int , int > ss[sz+1][sz+1][2];
    for(int i = 0 ; i <= sz ; i++ ){
        for(int j = i + 2 ; j <= sz ; j++){
            for(int k = 0 ; k < n  ;k++){
                int h = s[k][i]*101 + s[k][j]*99 + s[k][sz];
                if( i+2 == j ){
                    s[i][j][1][h]++;continue;
                }
                for(int l = i + 2 ;  l <= j ; l++){
                    if( a[k][l] < a[k][l-1]  ){
                        s[i][j][0][h]++;break;
                    }
                    if( l == j ){
                        s[i][j][1][h]++;
                    }
                }

            }
        }
    }

    cout<<ans<<endl;

}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;t = 1;
    while(t--){
        solve();
    }
}
