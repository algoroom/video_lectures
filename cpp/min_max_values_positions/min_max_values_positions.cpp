
#include <iostream>


/// Ֆունկցիան վերադարձնում է 'n' երկարություն ունեցող 'x' շարքում առաջին 
/// մաքսիմալ թվի դիրքը։
int maxIndex( const int x[], int n )
{
	int currentMaxIndex = 0;  // Այստեղ համարակալումը սկսվում է 0-ից
	for ( int i = 1; i < n; ++i )
		if ( x[ i ] > x[ currentMaxIndex ] )
			currentMaxIndex = i;
	return currentMaxIndex;
}


/// Ֆունկցիան վերադարձնում է 'n' երկարություն ունեցող 'x' շարքում վերջին 
/// մաքսիմալ թվի դիրքը։
int lastMaxIndex( const int x[], int n )
{
	int currentMaxIndex = 0;  // Այստեղ համարակալումը սկսվում է 0-ից
	for ( int i = 1; i < n; ++i )
		if ( x[ i ] >= x[ currentMaxIndex ] )
			currentMaxIndex = i;
	return currentMaxIndex;
}


/// Ֆունկցիան հաշվում և վերադարձնում է 'n' երկարություն ունեցող 'x' զանգվածում 
/// մաքսիմալ արժեքների քանակը։
int countOfMaximals( const int x[], int n )
{
	// Իրականացնել ինքնուրույն
	//
	//
	return -1;
}


/// Ֆունկցիան գտնում և վերադարձնում է 'n' երկարությամբ 'x' շարքում այն մաքսիմալ 
/// թվի դիրքը, որը ձախից կարդալիս երրորդն է։
int thirdMaximalIndex( const int x[], int n )
{
	// Իրականացնել ինքնուրույն
	//
	//
	return -1;
}


/// Ֆունկցիան գտնում և վերադարձնում է 'n' երկարությամբ 'x' շարքում այն մաքսիմալ 
/// թվի դիրքը, որը աջից կարդալիս երկրորդն է։
int secondFromEndMaximalIndex( const int x[], int n )
{
	// Իրականացնել ինքնուրույն
	//
	//
	return -1;
}


int main( int argc, char* argv[] )
{
	// Առաջին մաքսիմալ թվի դիրքի որոնում:
	std::cout << "=== Finding position of first maximal ===" << std::endl;
	{
		int x[] = { 5, 3, 6, 8, 9, 7, 3, 6 };                // Զանգվածը
		int n = sizeof(x) / sizeof(int);                     // Զանգվածի երկարությունը
		std::cout << "  case 1: " 
				<< maxIndex( x, n ) << std::endl;         // Պետք է լինի '4'
	}
	{
		int x[] = { 7, 5, 3, 8, 6, 3, 6, 8, 4, 2, 8, 1 };    // Զանգվածը
		int n = sizeof(x) / sizeof(int);                     // Զանգվածի երկարությունը
		std::cout << "  case 2: " 
				<< maxIndex( x, n ) << std::endl;          // Պետք է լինի '3'
	}

	// Վերջին մաքսիմալ թվի դիրքի որոնում:
	std::cout << "=== Finding position of last maximal ===" << std::endl;
	{
		int x[] = { 7, 5, 3, 8, 6, 3, 6, 8, 4, 2, 8, 1 };    // Զանգվածը
		int n = sizeof(x) / sizeof(int);                     // Զանգվածի երկարությունը
		std::cout << "  case 1: " 
				<< lastMaxIndex( x, n ) << std::endl;        // Պետք է լինի '10'
	}
	{
		int x[] = { 5, 3, 7, 5, 3, 5, 7, 3, 5 };             // Զանգվածը
		int n = sizeof(x) / sizeof(int);                     // Զանգվածի երկարությունը
		std::cout << "  case 2: " 
				<< lastMaxIndex( x, n ) << std::endl;        // Պետք է լինի '6'
	}

	// Բացել այս կտորը 'countOfMaximals()' ֆունկցիան իրականացնելուց հետո:
	// 
	/* // Հաշվում ենք մաքսիմալ արժեքների քանակը:
	std::cout << "=== Calculating occurrences of maximal values ===" << std::endl;
	{
		int x[] = { 4, 3, 7, 9, 2, 4 };                         // Զանգվածը
		int n = sizeof(x) / sizeof(int);                        // Զանգվածի երկարությունը
		std::cout << "  case 1: " 
				<< countOfMaximals( x, n ) << std::endl;      // Պետք է լինի '1'
	}
	{
		int x[] = { 5, 3, 7, 5, 3, 5, 7, 3, 5 };               // Զանգվածը
		int n = sizeof(x) / sizeof(int);                       // Զանգվածի երկարությունը
		std::cout << "  case 2: " 
				<< countOfMaximals( x, n ) << std::endl;      // Պետք է լինի '2'
	}*/

	// Բացել այս կտորը 'thirdMaximalIndex()' ֆունկցիան իրականացնելուց հետո:
	// 
	/* // Գտնում ենք ձախից 3-րդ մաքսիմալ արժեքի դիրքը:
	std::cout << "=== Finding third index of maximal value ===" << std::endl;
	{
		int x[] = { 5, 3, 2, 4, 5, 1, 5, 3, 2, 5, 3 };          // Զանգվածը
		int n = sizeof(x) / sizeof(int);                        // Զանգվածի երկարությունը
		std::cout << "  case 1: " 
				<< thirdMaximalIndex( x, n ) << std::endl;      // Պետք է լինի '6'
	}*/

	// Բացել այս կտորը 'secondFromEndMaximalIndex()' ֆունկցիան իրականացնելուց հետո:
	// 
	/* // Գտնում ենք աջից 2-րդ մաքսիմալ արժեքի դիրքը:
	std::cout << "=== Finding second from end index of maximal value ===" << std::endl;
	{
		int x[] = { 3, 9, 2, 5, 9, 1, 4, 9, 3, 6, 9, 1, 2, 3 }; // Զանգվածը
		int n = sizeof(x) / sizeof(int);                        // Զանգվածի երկարությունը
		std::cout << "  case 1: " 
				<< secondFromEndMaximalIndex( x, n ) << std::endl;   // Պետք է լինի '7'
	}*/

	return 0;
}
