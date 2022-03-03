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
const int N = 5e5 + 10  ;
int Z[N];
string a ;
void solve(){
    int n , k ;
    cin>>n>>k;
    cin>>a;
    int sz = 0;
    int L = 0, R = 0;
    Z[0] = n;
    for (int i = 1; i < n; i++)
    {
        if (i > R)
        {
            L = R = i;
            while (R < n && a[R] == a[R - L]) R++;
            Z[i] = R - L; R--;
        }
        else
        {
            int k = i - L;
            if (Z[k] < R - i + 1) Z[i] = Z[k];
            else
                {
                    L = i;
                    while (R < n && a[R] == a[R - L]) R++;
                    Z[i] = R - L; R--;
                }
        }
    }
    for(int i = 0 ; i < n ; i++ ){
        //debug(i);cout<<s<<endl;
        if( a[i] < a[0] ){
            sz++;
        }
        else if( a[i] == a[0] ){
            int h = i ;
            int k = Z[i];
            if( i + k == n && i != 0  ){
                i = n ;
            }
            else if( a[i+k] > a[k]){
                i = n;
            }
            if( i!= n) sz++;
        }
        else{
            break;
        }
    }
    for(int i = 0;  i< k ; i++){
        cout<<a[ i%sz ];
    }
    cout<<endl;
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
