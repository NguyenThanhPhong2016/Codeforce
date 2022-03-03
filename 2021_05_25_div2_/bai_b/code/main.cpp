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
vector<int> s;
int check(int value ){
    sort( s.begin() , s.end()  );
    for(int i = 1 ; i < s.size() ; i++){
        if( s[i] - s[i-1] < value ) return 0 ;
    }
    return 1 ;
}
void solve(){
    s.clear();
    int n ;cin>>n;
    int a[n];
    int dem = 0 ;
    int minbt = 1e9+10;
    for(int i = 0; i < n ; i++){
        cin>>a[i];
        if( a[i] > 0  ){
            dem++;
            minbt = min( minbt , a[i] );
        }
    }
    if( dem==0  ) cout<<n<<endl;
    else{
        for(int i = 0;  i < n ; i++){
            if(a[i] <= 0 ){
                s.pb( a[i] );
            }
        }
        s.pb( minbt );
        int u = check( minbt );
        cout<<s.size() - (1 - u)<<endl;
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
