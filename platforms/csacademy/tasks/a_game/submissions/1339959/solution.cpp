#include<bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int,int>
#define ll  long long
#define inf 1e9
#define sc1(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b);
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c);

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    int n;
    string a;
    cin>>n;
    cin>>a;
    int cnta=0,cntb=0;
    int ans=0;
    for(int i=0;i<a.length();i++){
        if(a[i]=='B')cntb++;
        else{
            ans^=cntb;
            cntb=0;
            cnta++;
        }
    }
    ans^=cntb;
    if(cnta%2==0)cout<<-1<<endl;
    else {
        if(ans)cout<<"A"<<endl;
        else cout<<"B"<<endl;
    }
    
    return 0;
}
