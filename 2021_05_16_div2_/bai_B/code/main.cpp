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
    int n ;
    cin>>n;
    int a[n+1];
    int dem = 0 ;
    for(int i = 1 ; i < n+1 ; i++){
        cin>>a[i];
        if( a[i] != i  ) dem++;
    }
    if(dem == 0 ){
        cout<<0<<endl;
        return;
    }
    if( a[1] == 1 || a[n] == n ){
        cout<<1<<endl;
    }
    else if( a[1] == n && a[n] == 1) {
        cout<<3<<endl;
    }
    else{
        cout<<2<<endl;
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
