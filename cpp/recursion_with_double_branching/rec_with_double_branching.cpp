
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>


/// Ֆունկցիան տպում է էկրանին ռեկուրսիվ կառուցվածք ունեցող տող, որի n-րդ 
/// մակարդակը կազմվում է 2 հատ 'n-1'-րդ մակարդակների տողերից՝ իրենց միջև 
/// ավելացնելով 'n' թվանշանը։
/// Իսկ 0-րդ մակարդակը դատարկ տողն է։
void printRecursiveString( int n )
{
	// Իրականացնել ինքնուրույն
	//
	//
}


/// Ֆունկցիան միաձուլում է 
/// 'x' զանգվածի [x_a,x_b] միջակայքը
/// 'y' զանգվածի [y_a,y_b] միջակայքի հետ, և գրում է արդյունքը 
/// 'z' զանգվածում, սկսած z_a ինդեքսից։
/// 'z'-ը կարող է համընկնել 'x'-ի կամ 'y'-ի հետ։
void merge( 
		const int x[], int x_a, int x_b, 
		const int y[], int y_a, int y_b, 
		int z[], int z_a )
{
	static std::vector< int > temp;  // Ժամանակավոր տարածք, միաձուլման համար
	temp.resize( (x_b-x_a+1) + (y_b-y_a+1) );  // Միաձուլված շարքի երկարությունը
	std::merge( 
			x+x_a, x+x_b+1,
			y+y_a, y+y_b+1,
			temp.data() );
	std::copy_n( temp.data(), temp.size(), z+z_a );
			// Պատճենահանում ենք միաձուլված շարքը ելքային զանգվածի մեջ։
}


/// Ֆունկցիան Merge-Sort ալգորիթմով սորտավորում է 'x' զանգվածի 
/// [a, b] ինդեքսներով փակ միջակայքը։
void mergeSort( int x[], int a, int b )
{
	if ( a == b ) {
		// Սորտավորվող կտորը ունի միայն 1 արժեք
		return;
	}
	else {
		// Գտնում ենք բաժանման սահմանը
		int mid = (a + b) / 2;
		// Ռեկուրսիվ սորտավորում ենք կեսերը
		mergeSort( x, a, mid );
		mergeSort( x, mid+1, b );
		// Միաձուլում ենք ստացված շարքերը
		merge( x, a, mid, x, mid+1, b, x, a );
	}
}


/// Ֆունկցիան "բաժանում" է 'x' զանգվածի [a,b] ինդեքսներով փակ միջակայքը 
/// այնպես որ նախ գրվում են 'pivot'-ից փոքր արժեքները, իսկ հետո մնացածը։
/// Այն վերադարջնում է ստացված բաժանման սահմանը՝ ինդեքսը։
int partition( int x[], int a, int b, int pivot )
{
	return std::partition(
			x+a, 
			x+b+1, 
			std::bind2nd( std::less<int>(), pivot ) )
		- x;
}


/// Ֆունկցիան Quick-Sort ալգորիթմով սորտավորում է 'x' զանգվածի 
/// [a, b] ինդեքսներով փակ միջակայքը։
void quickSort( int x[], int a, int b )
{
	// Իրականացնել ինքնուրույն, օգտվելով գրված 'partition()' ֆունկցիայից
	//
	//
}


/// Ֆունկցիան տպում է էկրանին 'n' արժեք ունեցող 'x' զանգվածը։
void printArray( const int x[], int n )
{
	std::cout << " [";
	for ( int i = 0; i < n; ++i )
		std::cout << " " << x[i];
	std::cout << " ]" << std::endl;
}


/// Սիմվոլների մատրիցի երկարությունն ու լայնությունը
static const int CHAR_M_SIZE = 75;


/// Ֆունկցիան լրացնում է 'x' սիմվոլների մատրիցը բացակներով, այդպիսով 
/// ստեղծելով իրեն "մաքրելու" տպավորություն։
void clearMatrix( char x[][CHAR_M_SIZE] )
{
	std::fill_n( &(x[0][0]), CHAR_M_SIZE * CHAR_M_SIZE, ' ' );
}


/// Ֆունկցիան 'x' մատրիցի մեջ աստղանիշերով նկարում է 'L' երկարությամբ կողով 
/// քառակուսի, իր վերևի-ձախ աստղանիշը տեղադրելով (i0,j0) վանդակում։
void drawSquare( int i0, int j0, int L, char x[][CHAR_M_SIZE] )
{
	for ( int i = i0; i < i0+L; ++i )
		for ( int j = j0; j < j0+L; ++j )
			x[ i ][ j ] = '*';
}


/// Ֆունկցիան 'x' մատրիցի մեջ աստղանիշերով նկարում է 'L' երկարությամբ կողով 
/// ուղղանկյուն եռանկյուն, իր վերևի-ձախ աստղանիշը (ուղիղ անկյւոնը) տեղադրելով 
/// (i0,j0) վանդակում։
void drawTriangle( int i0, int j0, int L, char x[][CHAR_M_SIZE] )
{
	// Իրականացնել ինքնուրույն
	//
	//
}


/// Ֆունկցիան էկրանին տպում է 'x' սիմվոլների մատրիցի վերևի-ձախ՝ 'printSize' 
/// լայնություն ու երկարություն ունեցող կտորը։
void printMatrix( const char x[][ CHAR_M_SIZE ], int printSize )
{
	for ( int i = 0; i < printSize; ++i ) {
		for ( int j = 0; j < printSize; ++j )
			std::cout.put( x[i][j] );
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


int main( int argc, char* argv[] )
{
	// Բացել այս կտորը 'printRecursiveString()' ֆունկցիան իրականացնելուց հետո
	/* std::cout << " === Printing recursive strings === " << std::endl;
	printRecursiveString( 2 );    // պետք է լինի "121"
	std::cout << std::endl;
	printRecursiveString( 3 );    // պետք է լինի "1213121"
	std::cout << std::endl;
	printRecursiveString( 4 );    // պետք է լինի "121312141213121"
	std::cout << std::endl; */

	// Աշխատեցնում ենք Merge-Sort ալգորիթմը
	std::cout << " === Running Merge-Sort === " << std::endl;
	{
		int x[] = { 5, 3, 1, 24, 69, 35, 8 };
		int x_n = sizeof(x) / sizeof(int);
		mergeSort( x, 0, x_n-1 );
		printArray( x, x_n );
	}
	{
		int x[] = { 22, 31, 19, 64, 96, 29, 38, 10 };
		int x_n = sizeof(x) / sizeof(int);
		mergeSort( x, 0, x_n-1 );
		printArray( x, x_n );
	}
	{
		int x[] = { 6, 5, 4, 3 };
		int x_n = sizeof(x) / sizeof(int);
		mergeSort( x, 0, x_n-1 );
		printArray( x, x_n );
	}

	// Բացել այս կտորը 'quickSort()' ֆունկցիան իրականացնելուց հետո
	/* std::cout << " === Running Quick-Sort === " << std::endl;
	{
		int x[] = { 5, 3, 1, 24, 69, 35, 8 };
		int x_n = sizeof(x) / sizeof(int);
		quickSort( x, 0, x_n-1 );
		printArray( x, x_n );
	}
	{
		int x[] = { 22, 31, 19, 64, 96, 29, 38, 10 };
		int x_n = sizeof(x) / sizeof(int);
		quickSort( x, 0, x_n-1 );
		printArray( x, x_n );
	}
	{
		int x[] = { 6, 5, 4, 3 };
		int x_n = sizeof(x) / sizeof(int);
		quickSort( x, 0, x_n-1 );
		printArray( x, x_n );
	} */

	// Բացել այս կտորը 'drawTriangle()' ֆունկցիան իրականացնելուց հետո։
	/* std::cout << " === Printing triangles === " << std::endl;
	{
		char x[ CHAR_M_SIZE ][ CHAR_M_SIZE ];
		clearMatrix( x );
		drawTriangle( 4, 6, 10, x );
		printMatrix( x, 18 );
	}
	{
		char x[ CHAR_M_SIZE ][ CHAR_M_SIZE ];
		clearMatrix( x );
		drawTriangle( 5, 5, 25, x );
		printMatrix( x, 35 );
	} */

	return 0;
}
