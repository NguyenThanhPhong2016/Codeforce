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
    string a ;cin>>a;
    stack<char> s;
    if( a == "" ){
        cout<<0<<endl;
        return ;
    }
    int ans =0 ;
    for(int i = 0 ; i < a.size() ; i++){
        if( a[i] == '(' || a[i] == ')' ) continue;
        if( a[i] == '[' ){
            s.push( a[i] );
        }
        else{
            if( s.size() !=0 ){
                ans++;
                s.pop();
            }
        }
    }
    string kq = "";
    int trai = 0 ;
    int dem = 0 ;
    cout<<ans<<endl;
    int ans1 = ans + ans ;
    for(int i = 0 ; i < a.size() ; i++ ){
        //cout<<"trai : "<<trai<<endl;
        if( kq.size() >= ans1 ) break;
        if( a[i] == '(' || a[i] == ')' ) continue;
        if( a[i] == '[' ){
            if( dem >= ans ) continue;
            dem++;
            trai++;
            kq += a[i];
        }
        else{
            if( trai > 0 ){
                kq += a[i];
                trai--;
            }
        }
    }
    cout<<kq<<endl;
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
