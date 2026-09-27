#include <iostream>
#include <cmath>
#include <bitset>
#include <queue>
using namespace std;
int n,m,k;
bitset<1000> Matrix[1000];

struct Node{
    int row,col,step;
    Node operator+(const Node &op){
        return {row+op.row,col+op.col,step+op.step };
    }
    bool is_valid(){
        return row>=0 && col>=0 && row<n && col<m && Matrix[row][col];
    }
    
};

Node dir[4] = {{0,1,1},{0,-1,1},{1,0,1},{-1,0,1}};



void solve(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        string S;
        cin>>S;
        for(int j = 0; j<m;j++){
            Matrix[i][j] = S[j]=='.';
        }
    }
    queue<Node> D;
    int x,y;
    while(k--){
        cin>>x>>y;
        Matrix[x-1][y-1] = 0;
        D.push({x-1,y-1,0});
    }
    Node nextNode,nowNode;
    long long sum = 0;
    while(!D.empty()){
        nowNode =D.front(),D.pop();
        for(int a = 0; a<4;a++){
            nextNode = nowNode + dir[a];
            if(nextNode.is_valid()){
                sum+= nextNode.step;
                Matrix[nextNode.row][nextNode.col] = 0;
                D.push(nextNode);
            }
        }
    }
    cout<<sum<<endl;
}
int main(){
    // cin.sync_with_stdio(0);
    // cin.tie(0);
    solve();
    return 0;
}