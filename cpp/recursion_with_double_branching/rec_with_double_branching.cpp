
#include <iostream>
#include <algorithm>
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


/// Ֆունկցիան Merge-Sort ալգորիթմով սորտավորում է 'x' զանգվածի 
/// [a, b] ինդեքսներով փոկ միջակայքը։
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
		static std::vector< int > temp;   // Ժամանակավոր տարածք, միաձուլման համար
		temp.resize( b-a+1 );             // Միաձուլված շարքի երկարությունը
		std::merge( x+a, x+mid+1, x+mid+1, x+b+1, temp.data() );
		std::copy_n( temp.data(), b-a+1, x+a );
				// Պատճենահանում ենք միաձուլված շարքը ետ՝ 'x'-ի մեջ։
	}
}


/// Ֆունկցիան տպում է էկրանին 'n' արժեք ունեցող 'x' զանգվածը։
void printArray( const int x[], int n )
{
	std::cout << " [";
	for ( int i = 0; i < n; ++i )
		std::cout << " " << x[i];
	std::cout << " ]" << std::endl;
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

	return 0;
}
