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
    int a[n+1];
    for( int i = 1 ; i <= n ; i++ ){
        a[i] = i ;
    }
    if( n == 2  ){
        cout<<"2 1"<<endl;
    }else if( n == 3 ){
        cout<<"3 1 2"<<endl;
    }else{
        if( n%2 ==0 ){
            for(int i = 0 ; i<= n -1 ; i++){
                cout<<(i ^ 1ll)+1 <<" ";
            }
            cout<<endl;
        }
        else{
            for(int i = 0 ; i <= n - 3 ; i++){
                cout<< (i ^ 1ll) + 1 <<" ";
            }
            cout<<n<<" "<<n-2<<endl;
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
