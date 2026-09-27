#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Gap{
    int l,r,len;
};

struct Platform{
    int l,r,len;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), std::cout.tie(nullptr);
    
    int N,M;
    ll xs=0 , xe=0;
    cin >> N >> M;
    
    vector<Platform> platforms(N);
    
    for(int i=0 ; i<N ;i++ ){
        cin >> xs >> xe ;
        platforms[i] = {xs , xe , xe - xs};
        //cout << platforms[i].l << " " << platforms[i].r << " " << platforms[i].len << endl;
    }
    
    vector<int> balls(M);
    
    for(int i = 0 ; i<M ;i++){
        cin >> balls[i];
        //cout << balls[i] << endl;
    }
    
    sort(balls.begin(), balls.end());
    
    vector<Gap> gaps;
    gaps.push_back({-200000000, balls[0] , (int)(balls[0] + 200000000)});
    for(int i=1 ; i<M ; i++){
        int l = balls[i-1];
        int r = balls[i];
        gaps.push_back({l, r, r - l});
    }
    
    gaps.push_back({balls.back(),200000000, (int)(200000000 - balls.back())});
    
    sort(gaps.begin(), gaps.end(), [](const Gap &a, const Gap &b) {return a.len > b.len;});
    
    // for(auto& pf : gaps){
    //     cout << pf.l << " " << pf.r << " " << pf.len << endl;
    // }
    
    ll totalCost = 0;
    
    for(auto& pf: platforms){
        int j=0;
        int min_df = 200000000 ,min_rm;
        while(pf.len <= gaps[j].len){
            min_rm = abs(min( gaps[j].r - pf.r, pf.l - gaps[j].l));
            min_df = min(min_df, min_rm);
            
            //cout << min_df << " " << pf.l << " " << pf.r << " " << gaps[j].l << " " << gaps[j].r << endl;
            j++;
        }
        //cout << endl;
        totalCost += min_df;
    }
    cout << totalCost << endl;
    
    return 0;
}