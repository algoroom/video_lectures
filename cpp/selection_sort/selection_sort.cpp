
#include <iostream>
#include <algorithm>


/// Ֆունկցիան կատարում է ընտրությամբ սորտավորում 'n' երկարություն ունեցող 
/// 'x' զանգվածի վրա։
void selection_sort( int x[], int n )
{
	for ( int k = 0; k < n-1; ++k ) {  // k-րդ իտերացիա
		int minIndex = k;  // [k,n) միջակայքում որոնվող 
		                   // նվազագույն արժեքի ինդեքսը
		for ( int i = k+1; i < n; ++i )
			if ( x[i] < x[minIndex] )
				minIndex = i;
		// Այժմ 'minIndex'-ի արժեքը հաշվարկված է,
		// տեղափոխում ենք x[k]-ն և x[minIndex]-ը
		if ( k != minIndex ) {
			int temp = x[k];
			x[k] = x[minIndex];
			x[minIndex] = temp;
		}
	}
}


/// Այս ֆունկցիան նույն տրամաբանությամբ կատարում է ընտրությամբ սորտավորում, 
/// 'n' երկարություն ունեցող 'x' զանգվածի վրա։
/// Տարբերությունը նրանում է որ այն նաև օգտվում է STL գրադարանի ֆունկցիաներից։
/// Ժամանակային բարդությունը նույնն է, միայն գրելաձևն է տարբեր։
void selection_sort_cpp_style( int x[], int n )
{
	for ( int k = 0; k < n-1; ++k ) {  // k-րդ իտերացիա
		int minIndex = std::min_element( &(x[k]), &(x[n]) ) - &(x[0]);
				// [k,n) միջակայքում որոնվող նվազագույն արժեքի ինդեքսը
		if ( k != minIndex )
			std::swap( x[k], x[minIndex] );
	}
}


/// Ֆունկցիան կատարում է ընտրությամբ սորտավորում 'n' երկարություն ունեցող 
/// 'x' զանգվածի վրա, դասակարգելով թվերը ըստ նվազման։
void selection_sort_decreasing( int x[], int n )
{
	// Իրականացնել ինքնուրույն
	//
	//
}


/// Ֆունկցիան կատարում է ընտրությամբ սորտավորում 'n' երկարություն ունեցող 
/// 'x' զանգվածի վրա, բայց աշխատելով աջից-ձախ։
void selection_sort_right_to_left( int x[], int n )
{
	// Իրականացնել ինքնուրույն
	//
}


/// Ֆունկցիան տպում է էկրանին 'n' երկարություն ունեցող 'x' զանգվածը։
void print_array( const int x[], int n )
{
	std::cout << "  {";
	for ( int i = 0; i < n; ++i )
		std::cout << " " << x[ i ];
	std::cout << " }" << std::endl;
}


int main( int argc, char* argv[] )
{
	// Ընտրությամբ սորտավորում
	std::cout << " === Selection sort === " << std::endl;
	{
		int x[] = { 5, 8, 1, 2, 10, 6, 3 };
		const int n = sizeof(x) / sizeof(int);
		selection_sort( x, n );
		print_array( x, n );
	}
	{
		int x[] = { 20, 30, 40, 6, 5, 4, 3 };
		const int n = sizeof(x) / sizeof(int);
		selection_sort( x, n );
		print_array( x, n );
	}
	{
		int x[] = { 5, 3, 8, 6, 10, 9 };
		const int n = sizeof(x) / sizeof(int);
		selection_sort( x, n );
		print_array( x, n );
	}

	std::cout << " === Selection sort (cpp style) === " << std::endl;
	{
		int x[] = { 5, 8, 1, 2, 10, 6, 3 };
		const int n = sizeof(x) / sizeof(int);
		selection_sort_cpp_style( x, n );
		print_array( x, n );
	}
	{
		int x[] = { 20, 30, 40, 6, 5, 4, 3 };
		const int n = sizeof(x) / sizeof(int);
		selection_sort_cpp_style( x, n );
		print_array( x, n );
	}
	{
		int x[] = { 5, 3, 8, 6, 10, 9 };
		const int n = sizeof(x) / sizeof(int);
		selection_sort_cpp_style( x, n );
		print_array( x, n );
	}

	// Բացել այս կտորը 'selection_sort_decreasing()' ֆունկցիան իրականացնելուց հետո
	/* std::cout << " === Selection sort (decreasing) === " << std::endl;
	{
		int x[] = { 5, 8, 1, 2, 10, 6, 3 };
		const int n = sizeof(x) / sizeof(int);
		selection_sort_decreasing( x, n );
		print_array( x, n );
	}
	{
		int x[] = { 20, 30, 40, 6, 5, 4, 3 };
		const int n = sizeof(x) / sizeof(int);
		selection_sort_decreasing( x, n );
		print_array( x, n );
	}
	{
		int x[] = { 5, 3, 8, 6, 10, 9 };
		const int n = sizeof(x) / sizeof(int);
		selection_sort_decreasing( x, n );
		print_array( x, n );
	} */

	// Բացել այս կտորը 'selection_sort_right_to_left()' ֆունկցիան իրականացնելուց հետո
	/* std::cout << " === Selection sort (right to left) === " << std::endl;
	{
		int x[] = { 5, 8, 1, 2, 10, 6, 3 };
		const int n = sizeof(x) / sizeof(int);
		selection_sort_right_to_left( x, n );
		print_array( x, n );
	}
	{
		int x[] = { 20, 30, 40, 6, 5, 4, 3 };
		const int n = sizeof(x) / sizeof(int);
		selection_sort_right_to_left( x, n );
		print_array( x, n );
	}
	{
		int x[] = { 5, 3, 8, 6, 10, 9 };
		const int n = sizeof(x) / sizeof(int);
		selection_sort_right_to_left( x, n );
		print_array( x, n );
	} */

	return 0;
}
