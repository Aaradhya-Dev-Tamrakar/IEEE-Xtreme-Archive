#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
long long int inline f(int x){return (long long)(1ll<<x)-1;}
char inp[510]={};
long long int lightsout(int r){
	if(r==-1)return 0;
	while(inp[r]=='0'&&r>=1)r--;
	if(r==0){
		return inp[0]=='1';
	}
	long long int t=f(r+1);
	for(int i=r-1;i>=0;i--){
		if(inp[i]=='1'){
			t-=f(i+1);
			t+=lightsout(i-1);
			break;
		}

	}
	return t;
}
int main(){
	int n;
	scanf("%s",inp);
	n=strlen(inp);
	for(int i=0;i<n/2;i++){
		swap(inp[i],inp[n-i-1]);
	}
	printf("%lld",lightsout(n-1));
}
