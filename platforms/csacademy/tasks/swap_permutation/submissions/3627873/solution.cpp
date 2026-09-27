#include <iostream>
using namespace std;
int state[100001];
int swaps[100001];
void swap(int a, int b ,int i){
    int temp = state[a];
    state[a] = state[b];
    state[b] = temp;
    if (state[a]!= 1 && state[b]!= 1 && state[0] == 0){
        state[0] = i;
    }
        else if (state[a] == 1 && swaps[state[b]] == 0){
            swaps[state[b]] = i;
        }
        else if (state[b] == 1 && swaps[state[a]] == 0){
            swaps[state[a]] = i;
        }
}
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    for (int i = 0;i <= a;i++){
        state[i] = i;
        swaps[i] = 0;
    }
    for (int i = 1; i <= b ;i++){
        int d,e;
        cin >> d >> e;
        swap(d,e,i);
    }
    if (state[c] == 1){
        cout << state[0] << endl;
    }
        else {
            cout << swaps[state[c]] << endl;
        }


    return 0;
}