#include<bits/stdc++.h>
using namespace std;
bool work(const vector<int>& s,int c){
	vector<int> nex; 
	int mn=1e9,mx=0;
	for(int i=0;i<s.size();++i)if(s[i]==c){
		int now=i;
		while(i+1<s.size()&&s[i+1]!=c)++i;
		if(i+1==s.size())break;
		nex.push_back(i-now);
		mn=min(mn,i-now);
		mx=max(mx,i-now);
	}
	return mn==1e9||mx==mn||mx-mn==1&&(mn==0||work(nex,mn)&&work(nex,mx));
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		vector<int> v;
		for(char c:s)v.push_back(c);
		for(char c:s)v.push_back(c);
		cout<<(work(v,'A')&&work(v,'B'))<<'\n';
	}
}
