#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
//kkkk
const int INF = 0x3f3f3f3f;
const int MAX_N = 100000;
const int MAX_M = 100000;
const int MAX_COORD = 100000000;

int N , M;
pair< pair < int , int > , int  > plt[ MAX_N ];
int ball[ MAX_M ];

bool custome_compare( const pair< pair< int , int > , int >&p1 , const pair< pair< int , int > , int >&p2 )
{ 
    return ( p1.first.second < p2.first.second );    
}

void mirror() {
    for( int i = 0; i < N; i++ ) {
        int aux = plt[ i ].first.first;
        plt[ i ].first.first = -plt[ i ].first.second;
        plt[ i ].first.second = - aux;
    }
    for( int j = 0; j < M; j++ ){
        ball[ j ] = -ball[ j ];
    }
}

void sweepLine() {
    sort( ball , ball + M );
    sort( plt , plt + N , custome_compare );
    vector< pair< int , int >> gapStack;
    gapStack.push_back( { INF , ball[ 0 ] } );
    int p = 1;
    for( int i = 0; i < N; i++ ) {
        while( ( p < M ) && ( ball[ p ] <= plt[ i ].first.second ) ) {
            int current_length = ball[ p ] - ball[ p - 1 ];
            while( gapStack.back().first <= current_length ) {
                gapStack.pop_back();
            }
            gapStack.push_back( { current_length , ball[ p ] });
            p++;
        }
        
        if( ( plt[ i ].first.second <= ball[ 0 ] ) || ( plt[ i ].first.first >= ball[ M - 1 ] ) ) {
            plt[ i ].second = 0;
            continue;
        }
        
        if( ( p < M ) && ( plt[ i ].first.first >= ball[ p - 1] ) && ( plt[ i ].first.second <= ball[ p ] ) ) {
            plt[ i ].second = 0;
            continue;
        }
    
        int left = 0 , right = ( ( int )gapStack.size() ) - 1 , mid;
        while( left != right ) {
            mid = ( left + right + 1 )/2;
            if( gapStack[ mid ].first >= ( plt[ i ].first.second - plt[ i ].first.first ) ) {
                left = mid;
            }
            else {
                right = mid - 1;
            }
        }

        if( plt[ i ].second > ( plt[ i ].first.second - gapStack[ left ].second ) ) {
            plt[ i ].second = plt[ i ].first.second - gapStack[ left ].second;
        }
        
    }
}

int main() {
    
    scanf( "%d" , &N ) , scanf( "%d" , &M );
    for( int i = 0; i < N; i++ ) { 
        scanf( "%d" , &plt[ i ].first.first ) , scanf( "%d" , &plt[ i ].first.second );
        plt[ i ].second = INF; 
    }
    
    for( int j = 0; j < M; j++ ) {
        scanf( "%d" , &ball[ j ] );
    }
    sweepLine() , mirror() , sweepLine();
    
    long long min_cost = 0;
    for( int i = 0; i < N; i++ ) {
        min_cost +=  plt[ i ].second;
    }
    
    printf( "%lld\n" , min_cost );
}