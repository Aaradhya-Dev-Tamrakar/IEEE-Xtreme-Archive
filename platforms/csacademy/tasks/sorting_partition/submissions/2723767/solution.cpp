#include <bits/stdc++.h>
using namespace std;
stack<int>st;
void solve(int m,int M)
{
    if(!st.empty() && m<st.top())
    {
        M=max(M,st.top());
        st.pop();
        solve(m,M);
    }
    else
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
    cout<<st.size();
    return 0;
}