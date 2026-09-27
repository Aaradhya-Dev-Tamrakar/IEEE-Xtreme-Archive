#include <cstdio>
#include <algorithm>
#include <deque>

using namespace std;
#define NMAX 5007

int n, v[NMAX], minim, maxim, cntMax, cntMin, sol;
deque <int> dq;

int main()
{
    scanf("%d", &n);
    for(int i = 1; i<= n; ++i)
    {
        scanf("%d", &v[i]);
        if(i == 1)
        {
            minim = v[i];
            maxim = v[i];
            continue;
        }
        minim = min(minim, v[i]);
        maxim = max(maxim, v[i]);
    }
    //printf("%d %d\n", minim, maxim);
    sol = n;
    for(int i = 1; i<= n; ++i)
    {
        //printf("%d : \n", i);
        dq.push_back(v[i]);
        if(v[i] == minim) cntMin ++;
        if(v[i] == maxim) cntMax ++;
        for( ; ; )
        {
            if(dq.empty()) break;
            int tmp = dq.front();
            if(tmp == minim && cntMin <= 1) break;
            if(tmp == maxim && cntMax <= 1) break;
            dq.pop_front();
            if(tmp == minim) cntMin --;
            if(tmp == maxim) cntMax --;
        }
        if(cntMin >= 1 && cntMax >= 1) sol = min(sol, (int)(dq.size()));
        //printf("sol = %d cntMin = %d cntMax = %d dq.front = %d dq.back = %d\n", sol, cntMin, cntMax, dq.front(), dq.back());
    }
    printf("%d\n", sol);
}