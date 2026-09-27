#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int) 5e5;

struct Query {
    int l, r;
    int pos;
    bool operator <(const Query &other) const {
        return l > other.l;
    }
}qry[MAXN + 1];

struct Aint {
    int suf;
    int sum;
}aint[4 * MAXN + 1];

void update(int nod, int left, int right, int pos, int val) {
    if(left == right) {
        aint[nod].suf += val;
        aint[nod].sum += val;
    }
    else {
        int mid = (left + right) / 2;
        if(pos <= mid)
            update(2 * nod, left, mid, pos, val);
        else
            update(2 * nod + 1, mid + 1, right, pos, val);
        aint[nod].sum = aint[2 * nod].sum + aint[2 * nod + 1].sum;
        aint[nod].suf = min(aint[2 * nod + 1].suf, aint[2 * nod + 1].sum + aint[2 * nod].suf);
    }
}

int sum, mn;

void query(int nod, int left, int right, int l, int r) {
    if(l <= left && right <= r) {
        mn = min(mn, aint[nod].suf + sum);
        sum += aint[nod].sum;
    }
    else {
        int mid = (left + right) / 2;
        if(mid < r)
            query(2 * nod + 1, mid + 1, right, l, r);
        if(l <= mid)
            query(2 * nod, left, mid, l, r);
    }
}

int sp[MAXN + 1], stk[MAXN + 1];
int sol[MAXN + 1];
char str[MAXN + 1];

int main() {
    FILE *fi, *fout;
    int i, n, q;
    //fi = fopen("election.in" ,"r");
    //fout = fopen("election.out" ,"w");
    fi = stdin;
    fout = stdout;
    fscanf(fi,"%d %s %d " ,&n,str + 1,&q);
    for(i = 1; i <= q; i++) {
        fscanf(fi,"%d %d " ,&qry[i].l,&qry[i].r);
        qry[i].pos = i;
    }
    sort(qry + 1, qry + q + 1);
    for(i = 1; i <= n; i++) {
        sp[i] = sp[i - 1];
        if(str[i] == 'C') {
            sp[i]++;
        }
        else {
            sp[i]--;
        }
        update(1, 1, n, i, sp[i] - sp[i - 1]);
    }
    int pos = n, sz = 0;
    for(int p = 1; p <= q; p++) {
        while(pos >= qry[p].l) {
            if(str[pos] == 'T') {
                stk[++sz] = pos;
                update(1, 1, n, pos, 1);
            }
            else {
                while(sz > 0 && sp[stk[sz]] >= sp[pos - 1]) {
                    update(1, 1, n, stk[sz], -1);
                    sz--;
                }
            }
            pos--;
        }
        mn = n + 1;
        sum = 0;
        query(1, 1, n, qry[p].l, qry[p].r);
        int res = -1;
        for(int step = 1 << 18; step; step >>= 1) {
            if(res + step < sz && stk[sz - (res + step)] <= qry[p].r) {
                res += step;
            }
        }
        if(mn > 0) {
            mn = 0;
        }
        sol[qry[p].pos] = -mn + res + 1;
    }
    for(i = 1; i <= q; i++) {
        fprintf(fout,"%d\n" ,sol[i]);
    }
    //fclose(fi);
    //fclose(fout);
    return 0;
}
