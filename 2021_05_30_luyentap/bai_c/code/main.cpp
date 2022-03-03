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
    int n ,k  ; cin>>n>>k;
    string s ;
    cin>>s;
    s =  " " + s ;
    for(int i = 1 ; i < n ; i++ ){
        if( k<=0 ) break;
        if( s[i] == '4' && s[i+1] == '7' ){
            if( i%2 == 0  ){
                if( s[i-1] == '4' ){
                    if( k%2 == 1 ){
                        s[i] = '7';
                    }
                    else s[i] = '4';
                    break;
                }
                else{
                    s[i] = '7';i++;k--;
                }
            }
            else{
                if( i < n -1 ){
                    if( s[i+2] == '7' ){
                        if( k %2 == 1 ){
                            s[i+1] = '4';
                        }
                        else{
                            s[i+1] = '7';
                        }
                        break;
                    }
                    else{
                        s[i+1] = '4';
                        k--;
                    }
                }
                else{
                    s[i+1] = '4';i++;k--;
                }
            }
        }
    }
    for(int i = 1 ; i<= n ; i++){
        cout<<s[i];
    }
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
