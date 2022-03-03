#include<bits/stdc++.h>
#define fi  first
#define se  second
#define int long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
#define endl "\n"
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
const int N = 3e5 + 10 ;
pair< ii , char > a[N];
int ans[N];
int n , m  ;
bool cmp( pair< ii , char > a , pair< ii , char > b ){
    return a.fi.fi < b.fi.fi ;
}
int tinh0( int x , int y  ){
    //cout<<x<<" 0 "<<y<<endl;
    return ( x+ y )/2;
}
int tinh1( int x , int y  ){
    //cout<<x<<" 1 "<<y<<endl;
    return ( y - x )/2;
}
void xuli( vector< pair< ii , char > > s ){
    sort( s.begin() , s.end() , cmp );
    stack< pair< ii , char > > sss;
    for(int i = 0 ; i < s.size() ; i++){
        if( sss.size() == 0 ){
            sss.push( s[i] );
            continue;
        }
        auto x = sss.top();
        if( x.se == 'L' ){
            if( s[i].se == 'L' ){
                ans[ x.fi.se    ] = tinh0( x.fi.fi , s[i].fi.fi );
                ans[ s[i].fi.se    ] = tinh0( x.fi.fi , s[i].fi.fi );
                sss.pop();
            }
            else{
                sss.push( s[i] );
            }
        }
        else{
            if( s[i].se == 'L'){
                //cout<<"chay :"<<x.fi.fi<<" "<<a[i].fi.fi<<endl;
                ans[ x.fi.se   ] = tinh1( x.fi.fi , s[i].fi.fi );
                ans[ s[i].fi.se   ] = tinh1( x.fi.fi , s[i].fi.fi );
                sss.pop();
            }
            else{
                sss.push( s[i] );
            }
        }
    }
    while( sss.size() >= 2 ){
        auto x = sss.top();
        sss.pop();
        auto y = sss.top();
        if( y.se == 'R' ){
            ans[ y.fi.se   ] = tinh0( m - x.fi.fi , m - y.fi.fi );
            ans[ x.fi.se   ] = tinh0( m - x.fi.fi , m - y.fi.fi );
            sss.pop();
        }
        else{
            ans[ y.fi.se ] = (y.fi.fi + m - x.fi.fi + m ) /2 ;
            ans[ x.fi.se    ] = ans[y.fi.se];
            sss.pop();
        }
    }
    if( sss.size() ==0 ) return ;
    else{
        ans[sss.top().fi.se ] = -1;
    }
}
void solve(){
    cin>>n>>m;
    vector< pair< ii , char > > a1;
    vector< pair< ii , char > > a2;
    for(int i  = 0 ; i < n ; i++){
        cin>>a[i].fi.fi ;
        a[i].fi.se = i ;
    }
    for(int i  = 0 ; i < n ; i++){
        cin>>a[i].se ;
    }
    for(int i = 0 ; i < n ; i++ ){
        if( a[i].fi.fi % 2 == 0 ){
            a1.pb( a[i] );
        }
        else{
            a2.pb( a[i] );
        }
    }
    xuli(a1);
    xuli(a2);
    for(int i = 0 ; i < n ; i++){
        cout<<ans[i]<<" ";
        ans[i] = -2 ;
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
