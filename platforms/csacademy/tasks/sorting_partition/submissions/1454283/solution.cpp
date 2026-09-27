#include <bits/stdc++.h>
using namespace std;
stack<int>st;
void solve(int m,int M)
{
    if(!st.empty()&&m<st.top())
    {
        M=max(M,st.top());
        st.pop();
        return solve(m,M);
    }
    st.push(M);
}
int main() {
    int n,nr;
    cin>>n;
    while(n--)
    {
        cin>>nr;
        solve(nr,nr);
    }
    n=0;
    while(!st.empty())
        n++,st.pop();
    cout<<n;
    return 0;
}