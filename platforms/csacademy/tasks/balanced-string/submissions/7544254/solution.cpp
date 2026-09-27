#include<bits/stdc++.h>
using std::pair;
using std::make_pair;
typedef long long ll;
typedef __int128 lll;
typedef long double ld;
const int maxn=1e9+7;
ll T;
std::string s;
bool check(std::string a){
    for(int i=1;i<(int)a.size();i++){
        if((a[i-1]=='B'&&a[i]=='B')||(a[0]=='B'&&a.back()=='B')){
            for(int j=0;j<(int)a.size();j++){
                if(a[j]=='A')a[j]='B';
                else a[j]='A';
            }
            break;
        }
    }
    bool aa=0,bb=0;
    for(int i=1;i<(int)a.size();i++){
        if(a[i-1]=='A'&&a[i]=='A'){
            aa=1;
        }
        if(a[i-1]=='B'&&a[i]=='B'){
            bb=1;
        }
    }
    if(a[0]=='A'&&a.back()=='A')aa=1;
    if(a[0]=='B'&&a.back()=='B')bb=1;
    if(aa&bb)return 0;
    if(!aa&&!bb)return 1;
    std::vector<ll> vec;
    ll t=0;
    for(int i=0;i<(int)a.size();i++){
        if(a[i]=='B'){
            for(int j=i,k=0;k<=(int)a.size();j=(j+1)%(int)a.size(),k++){
                if(a[j]=='B'){
                    if(t!=0){
                        vec.push_back(t);
                    }
                    t=0;
                }else{
                    t++;
                }
            }
            break;
        }
    }
    ll mx=0,mn=maxn;
    for(ll i:vec){
        mx=std::max(mx,i);
        mn=std::min(mn,i);
    }
    if(mx-mn>1)return 0;
    std::string nxt;
    for(ll i:vec){
        if(i==mn)nxt.push_back('A');
        else nxt.push_back('B');
    }
    return check(nxt);
}
void SOLVE(){
    std::cin>>s;
    std::cout<<check(s)<<"\n";
}
int main()
{
     std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin>>T;while(T--)SOLVE();
    return 0;
}