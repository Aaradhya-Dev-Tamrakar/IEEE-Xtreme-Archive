#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstring>
#include <cmath>
#include <cassert>
#include <climits>
#include <set>
#include <stack>
using namespace std;

#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define REPE(i,n) FORE(i,0,n)
#define FORSZ(i,a,v) FOR(i,a,SZ(v))
#define REPSZ(i,v) REP(i,SZ(v))
typedef long long ll;

const int MAXN=100000;
const int MOD=1000000007;
const int MAXIDX=(1<<30)-1;
struct Range { int l,r,kind; Range() {} Range(int l,int r,int kind):l(l),r(r),kind(kind) {} };
bool operator<(const Range &a,const Range &b) { return a.l<b.l; }
typedef int Mat[3][3];
struct S { int lazy; int l,r; Mat val; };

void mmult(Mat &A,const Mat &B) {
    static Mat tmp;
    REP(i,3) REP(j,3) { ll cur=0; REP(k,3) cur+=(ll)A[i][k]*B[k][j]; tmp[i][j]=cur%MOD; }
    REP(i,3) REP(j,3) A[i][j]=tmp[i][j];
}
void mpow(Mat &A,int n) {
    static Mat x; REP(i,3) REP(j,3) x[i][j]=A[i][j],A[i][j]=i==j?1:0;
    while(true) { if(n&1) mmult(A,x); if((n>>=1)==0) break; mmult(x,x); }
}

Mat yes;
Mat no;

int sroot;
vector<S> s;
int smake() { int ret=SZ(s); s.PB(S()); s[ret].lazy=s[ret].l=s[ret].r=-1; memset(s[ret].val,0,sizeof(s[ret].val)); return ret; }

void sapply(int x,int val,int len) {
    s[x].lazy=val;
    REP(i,3) REP(j,3) s[x].val[i][j]=i==j?1:0;
    if(val==0||val==1) {
        mmult(s[x].val,val==0?no:yes);
        mpow(s[x].val,len);
    } else {
        mmult(s[x].val,val==2?no:yes);
        mmult(s[x].val,val==2?yes:no);
        mpow(s[x].val,len/2);
        if(len%2) mmult(s[x].val,val==2?no:yes);
    }
    //printf("%d times %d:",len,val); REP(i,3) REP(j,3) printf(" %d",s[x].val[i][j]); puts("");
}
void spush(int x,int l,int m,int r) {
    if(s[x].l==-1) { int tmp=smake(); s[x].l=tmp; }
    if(s[x].r==-1) { int tmp=smake(); s[x].r=tmp; }
    if(s[x].lazy!=-1) {
        sapply(s[x].l,s[x].lazy,m-l+1);
        sapply(s[x].r,s[x].lazy^(s[x].lazy>=2&&(m-l+1)%2==1?1:0),r-m);
        s[x].lazy=-1;
    }
}
void spull(int x) {
    REP(i,3) REP(j,3) s[x].val[i][j]=s[s[x].l].val[i][j];
    mmult(s[x].val,s[s[x].r].val);
    //printf("pulled %d:",x); REP(i,3) REP(j,3) printf(" %d",s[x].val[i][j]); puts("");
}

void sset(int x,int l,int r,int L,int R,int VAL) {
    //if(x==sroot) printf("sset(%d,%d..%d,%d..%d,%d) [%d,%d]\n",x,l,r,L,R,VAL,s[x].l,s[x].r),fflush(stdout);
    if(L<=l&&r<=R) {
        sapply(x,VAL^(VAL>=2&&(l-L)%2!=0?1:0),r-l+1);
    } else {
        int m=l+(r-l)/2;
        spush(x,l,m,r);
        if(L<=m) sset(s[x].l,l,m,L,R,VAL);
        if(m+1<=R) sset(s[x].r,m+1,r,L,R,VAL);
        spull(x);
    }
}

set<Range> ranges;

void split(int x) {
    auto at=prev(ranges.upper_bound(Range(x,x,0)));
    if(x==at->l) return;
    auto cat=*at;
    ranges.erase(at);
    ranges.insert(Range(cat.l,x-1,cat.kind));
    if(cat.kind==1&&(x-cat.l)%2==1) {
        ranges.insert(Range(x,x,0));
        if(x!=cat.r) ranges.insert(Range(x+1,cat.r,1));
    } else {
        ranges.insert(Range(x,cat.r,cat.kind));
    }
}

void normalize(int x) {
    auto at=prev(ranges.upper_bound(Range(x,x,0)));
    assert(at->l==x&&at->kind==1);
    if(at!=ranges.begin()) {
        auto prv=prev(at);
        if(prv->kind==1&&(prv->r-prv->l+1)%2==1) at=prv;
    }
    while((at->r-at->l+1)%2==1) {
        //printf("\trangesmid (at=%d..%d):",at->l,at->r); for(auto it=ranges.begin();it!=ranges.end();++it) printf("[%d..%d=%d]",it->l,it->r,it->kind); puts("");
        int ones=0;
        while(true) {
            auto nxt=next(at);
            if(nxt->kind==0) {
                auto cnxt=*nxt;
                ranges.erase(nxt);
                if(cnxt.l+1<=cnxt.r) ranges.insert(Range(cnxt.l+1,cnxt.r,0));
                break;
            }
            if(nxt->r-nxt->l+1>=2) {
                ++ones;
                auto cnxt=*nxt;
                ranges.erase(nxt);
                if(cnxt.l+2<=cnxt.r) ranges.insert(Range(cnxt.l+2,cnxt.r,1));
                break;
            }
            ++ones;
            ranges.erase(nxt);
        }
        if(ones==0) {
            ranges.insert(Range(at->r+1,at->r+1,0));
            break;
        }
        //printf("\trangesmid (ones=%d):",ones); for(auto it=ranges.begin();it!=ranges.end();++it) printf("[%d..%d=%d]",it->l,it->r,it->kind); puts("");
        auto cat=*at;
        ranges.erase(at);
        if(ones%2==0) { // 1010101|1111110 -> 1010101|0010101
            ranges.insert(Range(cat.l,cat.r,1));
            ranges.insert(Range(cat.r+1,cat.r+2,0));
            at=ranges.insert(Range(cat.r+3,cat.r+ones+1,1)).first;
            sset(sroot,0,MAXIDX,cat.l,cat.r+1,3);
            sset(sroot,0,MAXIDX,cat.r+2,cat.r+ones+1,2);
        } else if(cat.l==cat.r) { // 1|11111110 -> 0|01010101
            ranges.insert(Range(cat.l,cat.r+1,0));
            at=ranges.insert(Range(cat.r+2,cat.r+ones+1,1)).first;
            sset(sroot,0,MAXIDX,cat.l,cat.l,0);
            sset(sroot,0,MAXIDX,cat.l+1,cat.r+ones+1,2);
        } else { // 1010101|11111110 -> 1010100|01010101
            ranges.insert(Range(cat.l,cat.r-2,1));
            ranges.insert(Range(cat.r-1,cat.r+1,0));
            at=ranges.insert(Range(cat.r+2,cat.r+ones+1,1)).first;
            sset(sroot,0,MAXIDX,cat.l,cat.r-1,3);
            sset(sroot,0,MAXIDX,cat.r,cat.r,0);
            sset(sroot,0,MAXIDX,cat.r+1,cat.r+ones+1,2);
        }
    }
    //printf("\trangesaft:"); for(auto it=ranges.begin();it!=ranges.end();++it) printf("[%d..%d=%d]",it->l,it->r,it->kind); puts("");
}

void insert(int x) {
    split(x); split(x+1);
    auto at=prev(ranges.upper_bound(Range(x,x,0)));
    assert(at->l==x&&at->r==x);
    if(at->kind==0) {
        ranges.erase(at);
        ranges.insert(Range(x,x,1));
        sset(sroot,0,MAXIDX,x,x,1);
        normalize(x);
        return;
    }
    {
        split(x+2);
        auto nxt=next(at);
        assert(nxt->l==x+1&&nxt->r==x+1&&nxt->kind==0);
        ranges.erase(at);
        ranges.erase(nxt);
        at=ranges.insert(Range(x,x+1,1)).first;
    }
    while(true) {
        if(at->l==0) { // $1010101010+0 -> $010101010101
            auto cat=*at;
            ranges.erase(at);
            ranges.insert(Range(0,0,0));
            ranges.insert(Range(1,cat.r,1));
            sset(sroot,0,MAXIDX,0,cat.r,2);
            normalize(1);
            return;
        }
        auto prv=prev(at); assert(prv->r==at->l-1);
        if(at->l==1) { // $0|10101010+0 -> $10101010101
            assert(prv->l==0&&prv->r==0&&prv->kind==0);
            auto cat=*at;
            ranges.erase(prv);
            ranges.erase(at);
            ranges.insert(Range(0,cat.r,1));
            sset(sroot,0,MAXIDX,0,cat.r,3);
            normalize(0);
            return;
        }
        if(prv->kind==1) {
            assert((prv->r-prv->l+1)%2==0);
            auto cprv=*prv;
            auto cat=*at;
            ranges.erase(prv);
            ranges.erase(at);
            at=ranges.insert(Range(cprv.l,cat.r,1)).first;
            continue;
        }
        if(prv->r-prv->l+1>=2) { // 00|10101010+0 ->10|0101010101
            auto cprv=*prv;
            auto cat=*at;
            ranges.erase(prv);
            ranges.erase(at);
            if(cprv.l<=cprv.r-2) ranges.insert(Range(cprv.l,cprv.r-2,0));
            ranges.insert(Range(cat.l-2,cat.l-1,1));
            ranges.insert(Range(cat.l,cat.l,0));
            ranges.insert(Range(cat.l+1,cat.r,1));
            sset(sroot,0,MAXIDX,cat.l-2,cat.l-1,3);
            sset(sroot,0,MAXIDX,cat.l,cat.r,2);
            normalize(cat.l-2);
            normalize(cat.l+1);
            return;
        }
        auto prvprv=prev(prv); assert(prvprv->r==prv->l-1);
        if(prvprv->kind==0) {
            auto cprvprv=*prvprv;
            auto cprv=*prv;
            ranges.erase(prvprv);
            ranges.erase(prv);
            ranges.insert(Range(cprvprv.l,cprv.r,0));
        } else if((prvprv->r-prvprv->l+1)%2==0) {
            auto cprvprv=*prvprv;
            auto cprv=*prv;
            ranges.erase(prvprv);
            ranges.erase(prv);
            ranges.insert(Range(cprvprv.l,cprvprv.r-1,1));
            ranges.insert(Range(cprvprv.r,cprv.r,0));
        } else {
            auto cprvprv=*prvprv;
            auto cprv=*prv;
            ranges.erase(prvprv);
            ranges.erase(prv);
            ranges.insert(Range(cprvprv.l,cprv.r,1));
        }
    }
}

int n;
int a[MAXN];


void run() {
    scanf("%d",&n); REP(i,n) scanf("%d",&a[i]),--a[i];
    ranges.clear(); ranges.insert(Range(0,MAXIDX,0));
    s.clear(); sroot=smake(); sapply(sroot,0,MAXIDX+1);
    REP(i,n) {
        insert(a[i]);
        printf("%d\n",s[sroot].val[0][0]); fflush(stdout);
    }
}

void precalc() {
    memset(yes,0,sizeof(yes)); yes[0][0]=yes[2][0]=yes[2][1]=1;
    memset(no,0,sizeof(no)); no[0][0]=no[0][1]=no[2][1]=no[1][2]=1;
}

ll bfsum;
set<int> bf;

void bfnormalize(int a) {
    while(true) {
        assert(bf.count(a));
        int len=1; while(bf.count(a+len)) ++len;
        if(len==1) break;
        if(len%2==1) ++a,--len;
        bf.erase(a);
        for(int i=1;i<len;i+=2) bf.erase(a+i);
        bf.insert(a+len);
        a+=len;
    }
}

void bfinsert(int a) {
    { int x=1,y=2; REP(i,a) { int z=x+y; x=y,y=z; } bfsum+=x; }
    if(bf.count(a)) {
        while(true) {
            if(a==0) {
                bf.erase(a);
                bf.insert(a+1);
                bfnormalize(a+1);
                break;
            } else if(a==1) {
                bf.erase(a);
                bf.insert(a-1);
                bf.insert(a+1);
                bfnormalize(a+1);
                break;
            } else if(!bf.count(a-2)) {
                bf.insert(a-2);
                bf.insert(a-1);
                if(bf.count(a-3)) bfnormalize(a-3); else bfnormalize(a-2);
                break;
            } else {
                bf.erase(a);
                bf.insert(a+1);
                bfnormalize(a+1);
                a-=2;
            }
        }
    } else {
        bf.insert(a);
        if(bf.count(a-1)) bfnormalize(a-1); else bfnormalize(a);
    }
}

void bfverify() {
    auto bfit=bf.begin();
    int lst=-2;
    for(auto it=ranges.begin();it!=ranges.end();++it) {
        if(it->kind==0) continue;
        for(int i=it->l;i<=it->r;i+=2) {
            assert(i-lst>=2); lst=i;
            assert(bfit!=bf.end()&&*bfit==i);
            ++bfit;
        }
    }
    assert(bfit==bf.end());
    int at=0,x=1,y=2; ll chk=0;
    for(auto it=bf.begin();it!=bf.end();++it) {
        while(at<*it) { int z=x+y; x=y,y=z,++at; }
        chk+=x;
    }
    assert((SZ(bf)>0&&*prev(bf.end())>40)||chk==bfsum);
    stack<pair<int,pair<int,int>>> stck; stck.push(MP(sroot,MP(0,MAXIDX)));
    set<int> have;
    while(SZ(stck)>0) {
        int x=stck.top().first,l=stck.top().second.first,r=stck.top().second.second; stck.pop();
        if(s[x].lazy==-1) {
            int m=l+(r-l)/2;
            stck.push(MP(s[x].r,MP(m+1,r)));
            stck.push(MP(s[x].l,MP(l,m)));
        } else {
            //printf("(%d..%d)=%d\n",l,r,s[x].lazy);
            if(s[x].lazy==1) FORE(i,l,r) have.insert(i);
            if(s[x].lazy==2) for(int i=l+1;i<=r;i+=2) have.insert(i);
            if(s[x].lazy==3) for(int i=l;i<=r;i+=2) have.insert(i);
        }
    }
    //printf("bf:"); for(auto it=bf.begin();it!=bf.end();++it) printf(" %d",*it); puts("");
    //printf("s:"); for(auto it=have.begin();it!=have.end();++it) printf(" %d",*it); puts("");
    //fflush(stdout);
    assert(have==bf);
}

void stress() {
    REP(rep,1000) {
        ranges.clear(); ranges.insert(Range(0,MAXIDX,0));
        s.clear(); sroot=smake(); sapply(sroot,0,MAXIDX+1);
        bfsum=0; bf.clear();
        REP(i,100) {
            int a=rep==0?i:rep==1?100-i:rep==2?2*i:rep==3?2*i+1:rand()%10;
            //printf("i=%d -> %d\n",i,a);
            insert(a);
            bfinsert(a);
            //printf("ranges:"); for(auto it=ranges.begin();it!=ranges.end();++it) printf("[%d..%d=%d]",it->l,it->r,it->kind); puts("");
            //fflush(stdout);
            bfverify();
        }
        printf("."); if(rep%40==39) puts(""); fflush(stdout);
    }
}

int main() {
    precalc();
    run();
    //stress();
    return 0;
}