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

void solve(){
    int n ;cin>>n;
    int a[n];
    int minbt = 101 ;
    for(int i = 0; i < n ; i++){
        cin>>a[i];
        minbt = min( minbt , a[i] );
    }
    int dem = 0 ;
    for(int i = 0 ; i < n ; i++){
        if( a[i] == minbt ) dem++;
    }
    cout<<n - dem << endl;
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
