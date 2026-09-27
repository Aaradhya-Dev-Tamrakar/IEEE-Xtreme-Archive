#include <bits/stdc++.h>
#define dv(i) for (auto f: i) cout<<f<<" "; cout<<"\n"
#define dm(i) for (auto f: i) cout<<f.first<<" "<<f.second<<"\n"
#define all(i) i.begin(),i.end()
#define sz(i) (int)i.size()
using namespace std;

#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)

#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vp;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N; cin>>N; vi A(N); int mx=0,mn=INT_MAX;
    FOR(i,0,N) {
        cin>>A[i];
        mx=max(mx,A[i]); mn=min(mn,A[i]);
    }
    set<int> minloc,maxloc;
    FOR(i,0,N) {
        if (A[i]==mn) minloc.insert(i);
        if (A[i]==mx) maxloc.insert(i);
    }
    int ret=INT_MAX;
    for (auto f: minloc) {
        for (auto z: maxloc) {
            ret=min(ret,abs(f-z));
        }
    }
    cout<<ret+1<<"\n";
    return 0;
}