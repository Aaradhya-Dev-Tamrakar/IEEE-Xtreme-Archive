#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int t,n,m;
int a[5005];
int minn=1e9,maxx=0,ans;
int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<n;i++) {
	cin >> a[i];
	minn = min(minn,a[i]), maxx = max(maxx,a[i]);
    }
    ans = n;
    int minlastp=-10000,maxlastp=-10000;
    for(int i=0;i<n;i++){
	if(a[i] ==  minn){
	    minlastp = i;
	}
	if(a[i] ==  maxx){
	    maxlastp = i;
	}
	//	cerr << minlastp << "   " << maxlastp << endl;
	ans = min(ans,i+1-min(minlastp,maxlastp));
    }
    cout << ans << endl;
    return 0;
}
