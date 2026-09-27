#include <iostream>
#include <cmath>
#include <bitset>
#include <queue>
using namespace std;
int n,m,k;
bitset<1000> All[1000];

struct Data{
    int r, c, step;
    Data operator+(const Data &d){
        return {r+d.r,c+d.c,step+d.step};
    }
    bool is_valid(){
        return r >= 0 && r < n && c >= 0 && c < m && All[r][c];
    }
} direction[4] = { {1,0,1} , {0,1,1} , {-1,0,1} , {0,-1,1} };

void solve(){
    cin >> n >> m >> k;
    string S;
    for(int i=0;i<n;i++){
        cin >> S;
        for(int q=0;q<m;q++){
            All[i][q] = S[q] == '.';
        }
    }
    queue<Data> D;
    int x ,y;
    while(k--) {
        cin >> x >> y;
        All[x - 1][y - 1] = 0;
        D.push({x - 1, y - 1, 0});
    }
    Data next ,now;
    long long value = 0;
    while(!D.empty()){
        now = D.front(),D.pop();
        for(Data i : direction){
            next = now + i;
            if(next.is_valid()){
                value += next.step;
                All[next.r][next.c] = 0;
                D.push(next);
            }
        }
    }
    cout << value << endl;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}