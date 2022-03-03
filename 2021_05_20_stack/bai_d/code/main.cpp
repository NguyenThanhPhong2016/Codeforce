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
    int n ; cin>>n ;
    stack<int > s;
    for(int i = 0 , x ; i < n ; i++){
        cin>>x;
        s.push( x );
    }
    int dem = 0 ;
    int dem1  =0 ;
    while( s.size() >= 2 && dem1 == 0 ){
        dem1 = 1 ;
        dem++;
        stack<int> a;
        while( s.size() >=2 ){
            int x = s.top() ;
            s.pop();
            if( x >= s.top() ){
                a.push( x );
            }
            else{
                dem1 = 0;
            }
        }
        while( !a.empty() ){
            s.push( a.top() );
            a.pop();
        }
    }
    //cout<<"1 : "<<s.size()<<endl;
    cout<<dem<<endl;
}
signed main(){
        srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;t =1 ;
    while(t--){
        solve();
    }
}
