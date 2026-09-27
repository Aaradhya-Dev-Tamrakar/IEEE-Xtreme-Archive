#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>
#include <random>

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

const int M=100*1000;
int v[M];
bool done[M];
void exec()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	int prec=v[n-2];
	int dc=v[n-1]-v[n-2];
	for(int i=n-3;i>=0;i--){
		if(v[i]==prec-dc){
			prec=v[i];
		}
		else{
			break;
		}
	}
	int prea,preb,da,db,ca,cb,k;
	auto f=[&]{
		for(;k<n;k++){
			bool incb=false;
			if(ca>=2&&v[k]>=prec&&
			   dc&&((v[n-1]-v[k])%dc==0)&&
			   (db==-1||v[k]-preb==db)){
				incb=true;
			}
			else if(k==n-1&&(cb==1||(v[k]-preb==db&&ca>=2))){
				incb=true;
			}
			else if(k==n-1&&ca==1){

			}
			else if(ca==1&&v[k]-prea==dc&&(dc&&(v[n-1]-v[k])%dc==0))
			{

			}
			else if(da>=0&&v[k]-prea==da){
			}
			else if(db==-1||v[k]-preb==db){
				incb=true;
			}
			else if(da==-1){
			}
			else{
				//cerr << k << ", " << v[k] << endl;
				return false;
			}
			if(incb){
				if(preb!=-1){
					db=v[k]-preb;
				}
				preb=v[k];
				cb++;
			}
			else{
				da=v[k]-prea;
				prea=v[k];
				ca++;
			}
		}
		if(ca>=2&&cb>=2&&da>0&&db>0){
			cout << v[0] << " " << da << " " << ca << endl;
			return true;
		}
		return false;
	};
	prea=v[1];
	preb=-1;
	da=v[1]-v[0];
	db=-1;
	ca=2;
	cb=0;
	k=2;
	if (f()){
		return;
	}
	prea=v[2];
	preb=v[1];
	da=v[2]-v[0];
	db=-1;
	ca=2;
	cb=1;
	k=3;
	if (f()){
		return;
	}
	prea=v[0];
	preb=v[2];
	da=-1;
	db=v[2]-v[1];
	ca=1;
	cb=2;
	k=3;
	if(f()){
		return;
	}
	cout << -1 << endl;
}
int main() {
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		exec();
	}

	return 0;
}

