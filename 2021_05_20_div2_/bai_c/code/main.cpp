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
    int n ; cin>>n;
    map<int ,int > a;
    vector< vector<int > > s;
    int dem = -1 ;
    for(int i = 0 , x ; i < n ; i++ ){
        cin>>x;
        if( a.find(  x  ) == a.end() ){
            dem++;
            a[x] = dem ;
            vector<int > a1 ;
            a1.push_back( i );
            s.pb(a1);
        }
        else{
            auto it = a.find(x);
            auto it1 = it->second;
            s[it1].push_back( i );
        }
    }
    /*
    for(int i = 0 ; i< s.size() ; i++ ){
        for(int j = 0 ; j < s[i].size() ; j++){
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    int ans = 0 ;
    for(int i = 0 ; i< s.size() ; i++ ){
        sort(  s[i].begin() , s[i].end()  );
        if( s[i].size() <= 1 ) continue;
        int k = s[i].size();
        int sum[k+1];
        sum[0]= s[i][0];
        for(int j = 1 ; j < k ; j++){
            sum[j] = sum[j-1] + s[i][j];
        }
        int ans1  = 0;
        for(int j = 1 ; j < k ; j++){
            ans1 += ( n - s[i][j]  )*( sum[ j -1 ] + j  );
        }
        ans+= ans1 ;
    }
    cout<<ans<<endl;
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
