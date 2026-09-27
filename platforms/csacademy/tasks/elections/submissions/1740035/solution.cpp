#include<iostream>
#include<stdio.h>
#include<string>
#include<stack>
#include<vector>
using namespace std ;

#define MAXN 500007

int n ;
string a ;

int q ;
vector < pair < int , int > > queries[ MAXN ] ;

vector < int > v ;

int ans[ MAXN ] ;

struct node {
    int sm ;
    int minval ;
    node ( ) { sm = minval = 0 ; }
    node ( int _sm , int _minval ) {
        sm = _sm ;
        minval = _minval ;
    }
};

node merge ( node p1 , node p2 ) {
    node ret ;
    ret.sm = p1.sm + p2.sm ;
    ret.minval = min ( p2.minval , p1.minval + p2.sm ) ;
    return ret ;
}

class Tree {
    public :
    node tr[ 5 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            if ( a[ IL - 1 ] == 'C' ) {
                tr[ where ] = node ( 1 , 0 ) ;
            }
            else {
                tr[ where ] = node ( -1 , -1 ) ;
            }
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    void update ( int where , int IL , int IR , int pos , int nwval ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            tr[ where ].sm = nwval ;
            tr[ where ].minval = min ( nwval , 0 ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , nwval ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , nwval ) ;
        }
        tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    node query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( CURR < IL || IR < CURL ) { return node ( 0 , 0 ) ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return merge ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};
Tree w ;

int getl ( int sr ) {
    if ( v.size ( ) == 0 ) { return -1 ; }
    int l , r , mid ;
    l = 0 ;
    r = v.size ( ) - 1 ;
    if ( v[ l ] <= sr ) { return -1 ; }
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( v[ mid ] <= sr ) { r = mid ; }
        else { l = mid ; }
    }
    while ( v[ r ] <= sr ) { r -- ; }
    return r ;
}

void input ( ) {
    cin >> n ;
    cin >> a ;

    cin >> q ;
    int i ;
    for ( i = 1 ; i <= q ; i ++ ) {
        int x , y ;
        cin >> x >> y ;
        queries[ x ].push_back ( make_pair ( y , i ) ) ;
    }
    w.init ( 1 , 1 , n ) ;
}

void solve ( ) {
    int i , j ;
    for ( i = n ; i >= 1 ; i -- ) {
        if ( a[ i - 1 ] == 'C' ) {
            if ( v.size ( ) != 0 ) {
                w.update ( 1 , 1 , n , v.back ( ) , -1 ) ;
                v.pop_back ( ) ;
            }
        }
        else {
            v.push_back ( i ) ;
            w.update ( 1 , 1 , n , i , 0 ) ;
        }
        int sz = queries[ i ].size ( ) ;
        for ( j = 0 ; j < sz ; j ++ ) {
            node ret = w.query ( 1 , 1 , n , i , queries[ i ][ j ].first ) ;
            ans[ queries[ i ][ j ].second ] += v.size ( ) - getl ( queries[ i ][ j ].first ) - 1 ;
            ans[ queries[ i ][ j ].second ] -= ret.minval ;
        }
    }
    for ( i = 1 ; i <= q ; i ++ ) {
        cout << ans[ i ] << "\n" ;
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    ///freopen ( "election.in" , "r" , stdin ) ;
    ///freopen ( "election.out" , "w" , stdout ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
