#include<bits/stdc++.h>
using namespace std;
const int M=50010;
int tst,a[M],k;string str;
bool ck(string x)
{
	int fa=0,fb=0,n=x.size();
	for(int i=0;i<n;++i)
		if(x[i]=='A'&&x[(i+1)%n]=='A')fa=1;
		else if(x[i]=='B'&&x[(i+1)%n]=='B')fb=1;
	if(fa&&fb)return 0;
	if(fb)for(int i=0;i<n;++i)x[i]=(x[i]=='A'?'B':'A');
	k=0;
	for(int i=0;i<n;++i)if(x[i]=='B')a[++k]=i;
	if(k<2)return 1;
	a[0]=a[k]-n;
	for(int i=k;i;--i)a[i]-=a[i-1];
//	cout<<x<<'\n';
//	for(int i=1;i<=k;++i)cout<<a[i]<<' ';cout<<'\n';
	int mn=n,mx=0;
	for(int i=1;i<=k;++i)mn=min(mn,a[i]),mx=max(mx,a[i]);
	if(mn==mx)return 1;
	else if(mx-mn>1)return 0;
	else
	{
		x="";
		for(int i=1;i<=k;++i)x+=(a[i]==mn?'A':'B');
		return ck(x);
	}
}
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0); 
	cin>>tst;
	while(tst--)
	{
		cin>>str;
		cout<<ck(str)<<'\n';
	}
	return 0;
}