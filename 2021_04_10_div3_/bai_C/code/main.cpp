#include    <bits/stdc++.h>
#define fi  first
#define se  second
#define ll  long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define pb push_back
using namespace std;
void solve(){
    int a ,b ;cin>>a>>b;
    int n = a+ b;
    string s;
    cin>>s;
    if( a%2 ==1 && b%2 ==1 ){
        cout<<-1<<endl;
        return;
    }
    for(int i = 0 ; i< n ; i++){
        if( s[i]!='?' ){
            if( s[ n -1 - i] == '?' ){
                s[ n-1 -i ] = s[i];
            }
            else{
                if( s[n-1-i] == s[i] ) continue;
                else{
                    cout<<-1<<endl;
                    return;
                }
            }
        }
    }
    int x =0 , y=0 ;
    for(int i = 0 ; i<n;i++){
        if( s[i]!='?' ){
            if( s[i] == '0' ) x++;
            else y++;
        }
    }
    if( n%2 ==1 ){
        int k = (n-1)/2;
        if( s[k] == '?' ){
            if( a%2 ==1 ){
                x++;
                s[k] = '0';
            }
            else{
                y++;
                s[k] = '1';
            }
        }
        else{
            if( a%2 ==1 ){
                if( s[k] == '0' ){
                }
                else{
                    cout<<-1<<endl;
                }
            }
            else{
                if( s[k] == '1' ){
                }
                else{
                    cout<<-1<<endl;
                }
            }
        }
    }
    x = a- x;
    y = b - y ;
    x=x/2;
    y=y/2;
    cout<<x<<y<<endl;
    for(int i = 0; i<n;i++){
        if( s[i]=='?' ){
            if( x>0 ){
                s[i] = '0';
                s[n-1-i] = '0';
                x--;
            }
            else if(y>0){
                s[i] = '1';
                s[n-1-i] = '1';
                y--;
            }
            else{
                break;
            }
        }
    }
    cout<<s<<endl;
}

int main(){
	int t;cin>>t;
	while(t--){
        solve();
	}
}
