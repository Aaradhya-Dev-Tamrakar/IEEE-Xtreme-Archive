#include<bits/stdc++.h>
using namespace std;
///20C Dijkstra
///20B D=b*b-4*a*c 
#define left left_stoyan_malinin
#define right right_stoyan_malinin

int AbsDifference(int a,int b)
{
    if (a>=b)
    return a-b;
    return b-a;
}
long long AbsDifference(long long a,long long b)
{
    if (a>=b)
    return a-b;
    return b-a;
}

const int mod=1000000007;
const int mod2=1000000009;
const int inf=1<<30;
const long long infLL=1ll<<62;
const int impossible=-1;

struct stoyan_point
{
    int x,y;
    int id;
};
struct stoyan_pointLL
{
    long long x,y;
    int id;
};
struct stoyan_segment
{
    stoyan_point first,second;
    int lenght;
    bool type;
    int id;
};
struct stoyan_segmentLL
{
    stoyan_pointLL first,second;
    long long lenght;
    bool type;
    int id;
};

/*void make_tree(int k,int left,int right)
{
	if (left==right)
	{
		c[k]=;
	}
	int middle=left+right;middle>>=1;
	make_tree(k+k,left,middle);
	make_tree(k+k+1,middle+1,right);
	c[k]=
}*/

int n;
string s;
vector<int>v;
int cnt_a;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    cin>>s;
    int cnt=0;
    for (int i=0;i<int(s.size());i++)
    {
        if (s[i]=='B')
        cnt++;
        else
        {
            cnt_a++;
            if (cnt)
            v.push_back(cnt);
            cnt=0;
        }
    }
    if (cnt)
    v.push_back(cnt);
    int xor1=0;
    for (int i=0;i<int(v.size());i++)
    xor1^=v[i];
    if (!xor1)
    {
        if (cnt_a&1)
        cout<<"B"<<endl;
        else
        cout<<"-1"<<endl;
    }
    else
    {
        if (cnt_a&1)
        cout<<"A"<<endl;
        else
        cout<<-1<<endl;
    }
	return 0;
}