#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1000010],L[1000010],R[1000010],Len[1000010];
bool solve(int n){
	int cnt[2];
	cnt[0]=cnt[1]=0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[i%n+1]){
			cnt[a[i]]++;
		}
	}
	if(cnt[0] && cnt[1]) return 0;
	if(!cnt[0] && !cnt[1]) return 1;
	if(!cnt[0]){
		for(int i=1;i<=n;i++) a[i]^=1;
	}
	int x=0;
	for(int i=1;i<=n;i++){
		if(a[i]){
			x++;
		}
	}
	if(x<=1) return 1;
	int tot=0,mx=0,mn=1e9;
	for(int i=1;i<=n;i++){
		if(a[i]){
			L[++tot]=i%n+1;
			R[tot]=L[tot];
			Len[tot]=1;
			while(!a[R[tot]%n+1]) Len[tot]++,R[tot]=R[tot]%n+1;
			mx=max(mx,Len[tot]);
			mn=min(mn,Len[tot]);
		}
	}
	if(mx-mn>1) return 0;
	if(mx==mn) return 1;
	n=0;
	for(int i=1;i<=tot;i++){
		if(Len[i]==mn) a[++n]=0;
		else a[++n]=1;
	}
	return solve(n);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s; n=s.size();
		for(int i=1;i<=n;i++) a[i]=s[i-1]-'A';
		cout<<solve(n)<<'\n';
	}
	return 0;
}