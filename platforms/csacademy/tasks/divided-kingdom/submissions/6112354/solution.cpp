#include<map>
#include<vector>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N=6e5+5;
struct Ed{int f,l,w;}ed[N];
int n,m,siz[N],vu[N],ansA=1e18,ansB=1e18,ans,fas[N];
vector<pair<int,int> > edges[N];
map<pair<int,int>,int> mo;
bool cmp(Ed a,Ed b){return a.w<b.w;}
int Findfa(int x){
	if(fas[x]!=x) fas[x]=Findfa(fas[x]);
	return fas[x];
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;int f,l,w;
	for(int i=1;i<=m;i++){
		cin>>f>>l>>w;if(f>l) swap(f,l);
		if(!mo[{f,l}]) mo[{f,l}]=w;
		else mo[{f,l}]=min(mo[{f,l}],w);
	}
	m=0;
	for(auto a:mo){
		f=a.first.first,l=a.first.second,w=a.second;
		ed[++m]={f,l,w};
		edges[f].push_back({l,w});
		edges[l].push_back({f,w});
	}
	sort(ed+1,ed+1+m,cmp);
	for(int i=1;i<=2*n;i++) fas[i]=i;
	for(int i=1;i<=m;i++){
		int x=ed[i].f,y=ed[i].l;
		int fx=Findfa(x),fy=Findfa(y);
		int xf=Findfa(x+n),yf=Findfa(y+n);
		if(xf==yf||fx==fy) continue;
		fas[fx]=yf;fas[fy]=xf;
	}
	int aaa=Findfa(1),bbb=Findfa(1+n);
	vector<int> A,B;
	for(int i=1;i<=n;i++){
		for(auto a:edges[i]){
			int x=a.first,w=a.second;
			if(Findfa(x)==Findfa(i)){
				if(Findfa(x)==aaa) ansA=min(ansA,w);
				else ansB=min(ansB,w);
			}
			if(Findfa(x)==aaa) A.push_back(w);
			else B.push_back(w);
		}
		sort(A.begin(),A.end());sort(B.begin(),B.end());
		if(A.size()>1) ansA=min(ansA,A[0]+A[1]);
		if(B.size()>1) ansB=min(ansB,B[0]+B[1]);
		A.clear(),B.clear();
	}
	ans=min(ansA,ansB);
	if(ans==1e18) cout<<-1;
	else cout<<ans;
	return 0;
}