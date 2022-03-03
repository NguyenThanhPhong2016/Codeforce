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
//
void in( vector<int> s ){
    cout<<"in s :"<<endl;
    for(int i = 0 ; i < s.size() ; i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
set< ii > s;
void solve(){
    int dem = -1;
    int n ;
    cin>>n;
    int a[n];
    for(int i = 0 ; i< n ;i++){
        cin>>a[i];
    }
    int ans = 0 ;
    int sum = 0 ;
    for(int i = 0 ; i < n ; i++){
        //debug(i);
        if( a[i] >=0 ){
            sum += a[i];
            ans++;
        }
        else{
            if( sum + a[i] >= 0 ){
                ans++;
                sum += a[i];
                s.insert( { a[i] , dem++ } );
            }
            else{
                if( s.size() == 0 ) continue;
                auto x = *s.begin();
                if( x.fi < a[i] ){
                    sum = sum - x.fi + a[i];
                    s.erase( x );
                    s.insert( {a[i] , dem++ } );
                }
            }
        }
        //debug(sum);
        //debug(ans);
    }
    cout<<ans<<endl;
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;t= 1 ;
    while(t--){
        solve();
    }
}
