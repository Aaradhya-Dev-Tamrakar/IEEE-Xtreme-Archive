//#define NDEBUG
#include <bits/stdc++.h>

using namespace std ;

//----------------------------------------------------------------------------------------------------------------------------------------------

typedef long long int LLI ;
typedef long double LD ;
typedef pair < int , int > PII ;
typedef pair < LLI , LLI > PLLILLI ;

typedef vector < int > VI ;
typedef vector < LLI > VLLI ;
typedef vector < bool > VB ;
typedef vector < string > VS ;
typedef vector < float > VF ;
typedef vector < double > VD ;
typedef vector < LD > VLD ;
typedef vector < PII > VPII ;
typedef vector < PLLILLI > VPLLILLI ;

typedef vector < VI > VVI ;
typedef vector < VVI > VVVI ;
typedef vector < VVVI > VVVVI ;
typedef vector < VLLI > VVLLI ;
typedef vector < VVLLI > VVVLLI ;
typedef vector < VVVLLI > VVVVLLI ;
typedef vector < VB > VVB ;
typedef vector < VS > VVS ;
typedef vector < VF > VVF ;
typedef vector < VD > VVD ;
typedef vector < VLD > VVLD ;
typedef vector < VPII > VVPII ;
typedef vector < VPLLILLI > VVPLLILLI ;

typedef set < int > SI ;
typedef set < LLI > SLLI ;
typedef set < PII > SPII ;
typedef set < PLLILLI > SPLLILLI ;
typedef set < string > SS ;

typedef unordered_set < int > USI ;
typedef unordered_set < LLI > USLLI ;
typedef unordered_set < PII > USPII ;
typedef unordered_set < PLLILLI > USPLLILLI ;
typedef unordered_set < string > USS ;

typedef map < int , int > MII ;
typedef map < LLI , LLI > MLLILLI ;
typedef map < int , PII > MIPII ;
typedef map < PII , PII > MPIIPII ;
typedef map < PII , int > MPIII ;
typedef map < int , string > MIS ;
typedef map < string , int > MSI ;
typedef map < string , string > MSS ;

typedef unordered_map < int , int > UMII ;
typedef unordered_map < LLI , LLI > UMLLILLI ;
typedef unordered_map < int , PII > UMIPII ;
typedef unordered_map < PII , PII > UMPIIPII ;
typedef unordered_map < PII , int > UMPIII ;
typedef unordered_map < int , string > UMIS ;
typedef unordered_map < string , int > UMSI ;
typedef unordered_map < string , string > UMSS ;

#define DASH "<---------------------------------------------------------------->"
#define FIE(i,start,stop) for ( int i = start , _stop = stop ; i < _stop ; i ++ )
#define FII(i,start,stop) for ( int i = start , _stop = stop ; i <= _stop ; i ++ )
#define FDEI(i,start,stop) for ( int i = start - 1 , _stop = stop ; i >= _stop ; i -- )
#define FDII(i,start,stop) for ( int i = start , _stop = stop ; i >= _stop ; i -- )
#define TR(it,container) for ( __typeof ( container.begin () ) it = container.begin () ; it != container.end () ; it ++ )
#define PRINT(s,x) cout << "--> " << s << " " << #x << ":" << x << endl
#define PRINT1(x) cout << "--> " << #x << ":" << x << endl
#define PRINT2(x1,x2) cout << "--> " << #x1 << ":" << x1 << ", " << #x2 << ":" << x2 << endl
#define PRINT3(x1,x2,x3) cout << "--> " << #x1 << ":" << x1 << ", " << #x2 << ":" << x2 << ", " << #x3 << ":" << x3 << endl
#define PRINT4(x1,x2,x3,x4) cout << "--> " << #x1 << ":" << x1 << ", " << #x2 << ":" << x2 << ", " << #x3 << ":" << x3 << ", " << #x4 << ":" << x4 << endl
#define ALL(x) x.begin () , x.end ()
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define LB lower_bound
#define UB upper_bound
#define endl '\n'

void WAIT ()
{
    #ifndef ONLINE_JUDGE
        fflush ( stdin ) ; fflush ( stdout ) ; cout.flush () ; cin.clear () ; 
    #endif  
    #ifdef SHELL
        cout << endl << DASH << endl ;
        cout << "ENTER 0 TO EXIT" << endl ;
        fflush ( stdin ) ; fflush ( stdout ) ; cout.flush () ; cin.clear () ; 
        char ch ; do { cin >> ch ; } while ( ch != '0' ) ;
    #endif
}

void FAST ()
{
    ios::sync_with_stdio ( false ) ; cin.tie ( NULL ) ;
}

template < class T > void print_2darray ( const char * s , T arr , int n , int m )
{
    cout << "--> " << s << endl ;
    cout << "[" << endl ;
    FIE ( i , 0 , n )
    {
        cout << "{" ;
        FIE ( j , 0 , m )
        {
            cout << arr [ i ] [ j ] << ( j == m - 1 ? "" : "," ) ;
        }
        cout << "}" << endl ;
    }
    cout << "]" << endl ;
}

template < class T > void print_2darray ( const char * s , T arr , int n )
{
    cout << "--> " << s << endl ;
    cout << "[" << endl ;
    FIE ( i , 0 , n )
    {
        cout << i << " - {" ;
        FIE ( j , 0 , ( int ) arr [ i ].size () )
        {
            cout << arr [ i ] [ j ] << ( j == ( int ) arr [ i ].size () - 1 ? "" : "," ) ;
        }
        cout << "}" << endl ;
    }
    cout << "]" << endl ;
}

template < class T > void print_1darray ( const char * s , T arr , int n )
{
    cout << "--> " << s << endl ;
    cout << "[" << endl ;
    FIE ( i , 0 , n )
    {
        cout << arr [ i ] << ( i == n - 1 ? "" : "," ) ;
    }
    cout << endl << "]" << endl ;
}

template < class T > void print_1darray ( const char * s , T arr )
{
    cout << "--> " << s << endl ;
    cout << "[" << endl ;
    FIE ( i , 0 , arr.size () )
    {
        cout << arr [ i ] << ( i == ( int ) arr.size () - 1 ? "" : "," ) ;
    }
    cout << endl << "]" << endl ;
}

template < class T > void print_set ( const char * s , set < T > & myset )
{
    cout << "--> " << s << endl ;
    cout << "[" << endl ;
    TR ( it , myset )
    {
        cout << * it << " " ;
    }
    cout << endl << "]" << endl ;
}

template < class T > void print_uset ( const char * s , unordered_set < T > & myset )
{
    cout << "--> " << s << endl ;
    cout << "[" << endl ;
    TR ( it , myset )
    {
        cout << * it << " " ;
    }
    cout << endl << "]" << endl ;
}

template < class T1 , class T2 > void print_map ( const char * s , map < T1 , T2 > & mymap )
{
    cout << "--> " << s << endl ;
    cout << "[" << endl ;
    TR ( it , mymap )
    {
        cout << "{" << it->F << "->" << it->S << "}" << endl ;
    }
    cout << "]" << endl ;
}

template < class T1 , class T2 > void print_umap ( const char * s , unordered_map < T1 , T2 > & mymap )
{
    cout << "--> " << s << endl ;
    cout << "[" << endl ;
    TR ( it , mymap )
    {
        cout << "{" << it->F << "->" << it->S << "}" << endl ;
    }
    cout << "]" << endl ;
}

#define INF 1000000000
#define LINF 1000000000000000000LL
#define ERROR 0.00000001
#ifndef ONLINE_JUDGE
    #define DBG 1
#endif

//----------------------------------------------------------------------------------------------------------------------------------------------

const int N = 1e9 , M = 100000 ;
int n , m , x ;

int solve ( int x , int n )
{
    if ( n == 1 )
    {
        return 1 ;
    }
    if ( x % 2 )
    {
        return n / 2 + solve ( ( x + 1 ) / 2 , ( n + 1 ) / 2 ) ;
    }
    else
    {
        return solve ( x / 2 , n / 2 ) ;
    }
    return - INF ;
}

int main ()
{
    FAST () ;
    
    cin >> n >> m ;
    int prev = -1 ;
    FIE ( i , 0 , m )
    {
        cin >> x ;
        x = solve ( x , n ) ;
        if ( prev != -1 && x != prev + 1 )
        {
            cout << 0 ;
            return 0 ;
        } 
        prev = x ;
    }
    cout << 1 ;

    #ifdef DBG
        brute ( 0 , n - 1 ) ;
        print_1darray ( "val" , val , n ) ;       
    #endif

    WAIT () ;
    return 0 ;
}