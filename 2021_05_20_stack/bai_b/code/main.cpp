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
    string a;
    cin>>a;
    stack<char> s;
    for(int i = 0 ; i < a.size() ; i++){
        if( s.size() == 0 ){
            s.push( a[i] );
            continue;
        }
        if( s.top() == a[i] ){
            s.pop();
        }
        else{
            s.push( a[i] );
        }
    }
    if( s.size() ==0 ) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;t=1;
    while(t--){
        solve();
    }
}
