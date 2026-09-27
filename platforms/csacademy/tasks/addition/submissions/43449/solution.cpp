#include<iostream>
#include<stdio.h>
using namespace std ;

int a , b ;

void input ( ) {
	scanf ( "%d%d" , &a , &b ) ;
}

void solve ( ) {
	printf ( "%d\n" , a + b ) ;
}

int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}
