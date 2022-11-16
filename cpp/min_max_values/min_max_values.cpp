
#include <iostream>


/// Ֆունկցիան վերադարձնում է տրված 2 թվերից մեծագույնին
int max2( int a, int b )
{
	if ( a > b )
		return a;
	else
		return b;
}


/// Ֆունկցիան վերադարձնում է տրված 4 թվերից մեծագույնին
int max4( int a, int b, int c, int d )
{
	int m1 = max2( a, b );
	int m2 = max2( c, d );
	int m = max2( m1, m2 );
	return m;
}


/// Ֆունկցիան հաշվում և վերադարձնում է 'x' զանգվածի միջից [from - to] 
/// ինդեքսների միջև (ներառյալ) ընկած թվերից մեծագույնին
int max_k( const int x[], int from, int to )
{
	if ( from == to )
		return x[ from ];  // Տրված միջակայքը 1 երկարությամբ է
	// Կիսում ենք միջակայքը
	int mid = (from + to) / 2;
	// Ռեկուրսիվ հաշվում ենք կեսերի մաքսիմալներին
	int m1 = max_k( x, from, mid );
	int m2 = max_k( x, mid+1, to );
	// Ընտրում ենք ստացված 2-ից մեծագույնին
	if ( m1 > m2 )
		return m1;
	else
		return m2;
}


/// Ֆունկցիան հաշվում և վերադարձնում է 'n' երկարություն ունեցող 'x'
/// զանգվածից մեծագույն արժեքը՝ դինամիկ մաքսիմումի սկզբունքով։
int max( const int x[], int n )
{
	// Նախ համարում ենք որ ընթացիք մաքսիմումը առաջին արժեքն է
	int currentMax = x[0];
	// Հետո ստուգում ենք մնացած արժեքներին
	for ( int i = 1; i < n; ++i )
		if ( x[i] > currentMax )
			currentMax = x[i];
	return currentMax;
}


/// Ֆունկցիան հաշվում և վերադարձնում է 'n' երկարություն ունեցող 'x'
/// զանգվածից փոքրագույն արժեքը՝ դինամիկ մինիմումի սկզբունքով։
int min( const int x[], int n )
{
	// Իրականացնել ինքնուրույն
	//
	//
	return -1;
}


int main( int argc, char* argv[] )
{
	// Երկու թվերից մեծագույնի ընտրում
	std::cout << " === Maximal from 2 nubmers === " << std::endl;
	std::cout << max2( 5, 7 ) << std::endl;   // 7
	std::cout << max2( 12, 4 ) << std::endl;  // 12
	std::cout << max2( 8, 8 ) << std::endl;   // 8

	// Չորս թվերից մեծագույնի ընտրում
	std::cout << " === Maximal from 4 nubmers === " << std::endl;
	std::cout << max4( 5, 3, 1, 8 ) << std::endl;   // 8
	std::cout << max4( 6, 4, 9, 1 ) << std::endl;   // 9
	std::cout << max4( 9, 12, 4, 3 ) << std::endl;  // 12
	
	// Մաքսիմալը զանգվածների միջից (ռեկուրսիվ մոտեցում)
	std::cout << " === Maximal from arrays (recursive approach) === " << std::endl;
	{
		int x[] = { 5, 8, 12, 4, 9, 23, 5, 8, 10 };   // Զանգվածը
		int n = sizeof(x) / sizeof(int);              // Զանգվածի երկարությունը
		std::cout << max_k( x, 0, n-1 ) << std::endl;
	}
	{
		int x[] = { 24, 33, 19, 62, 4, 5, 24, 9 };    // Զանգվածը
		int n = sizeof(x) / sizeof(int);              // Զանգվածի երկարությունը
		std::cout << max_k( x, 0, n-1 ) << std::endl;
	}
	
	// Մաքսիմալը զանգվածների միջից (դինամիկ մոտեցում)
	std::cout << " === Maximal from arrays (dynamic approach) === " << std::endl;
	{
		int x[] = { 5, 8, 12, 4, 9, 23, 5, 8, 10 };   // Զանգվածը
		int n = sizeof(x) / sizeof(int);              // Զանգվածի երկարությունը
		std::cout << max( x, n ) << std::endl;
	}
	{
		int x[] = { 24, 33, 19, 62, 4, 5, 24, 9 };    // Զանգվածը
		int n = sizeof(x) / sizeof(int);              // Զանգվածի երկարությունը
		std::cout << max( x, n ) << std::endl;
	}

	// Հանել մեկնաբանությունից, 'min()' ֆունկցիան իրականացնելուց հետո
	/* std::cout << " === Minimal from arrays (dynamic approach) === " << std::endl;
	{
		int x[] = { 10, 15, 2, 3, 4, 62, 9 };      // Զանգվածը
		int n = sizeof(x) / sizeof(int);           // Զանգվածի երկարությունը
		std::cout << min( x, n ) << std::endl;     // Պետք է լինի '2'
	}
	{
		int x[] = { 22, 33, 19, 64, 20, 1, 6 };    // Զանգվածը
		int n = sizeof(x) / sizeof(int);           // Զանգվածի երկարությունը
		std::cout << min( x, n ) << std::endl;     // Պետք է լինի '1'
	} */

	return 0;
}
