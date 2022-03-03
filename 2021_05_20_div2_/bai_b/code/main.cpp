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
    string a;
    cin>>a;
    int dem = 0 ;
    for(int i = 0 ; i< n ; i++){
        if( a[i] == '0' ) dem++;
    }
    if( dem % 4 == 0 ){
        cout<<"DRAW"<<endl;
    }
    else if( dem%4 == 1 ){
        cout<<"BOB"<<endl;
    }
    else if( dem%4 == 3 ){
        cout<<"ALICE"<<endl;
    }
    else{
        cout<<"BOB"<<endl;
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
