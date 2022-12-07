
#include <iostream>


/// Ֆունկցիան կատարում է տեղադրումներով սորտավորում 'n' արժեք ունեցող 
/// 'x' զանգվածի վրա։
void insertion_sort( int x[], int n )
{
	for ( int k = 1; k < n; ++k ) {  // տեղադրվող արժեքի ինդեքսը
		int value = x[k];
		int i = k - 1;               // տեղափոխվող արժեքի ինդեքսը
		while ( i >= 0 && x[i] > value ) {
			x[i+1] = x[i];
			--i;
		}
		x[i+1] = value;              // տեղադրում
	}
}


/// Ֆունկցիան կատարում է տեղադրումներով սորտավորում 'n' արժեք ունեցող 
/// 'x' զանգվածի վրա, բայց տեղաշարժելով արժեքներին աջից ձախ։
void insertion_sort_right_to_left( int x[], int n )
{
	// իրականացնել ինքնուրույն
	//
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
	// Տեղադրումներով սորտավորում
	std::cout << " === Insertion sort ===" << std::endl;
	{
		int x[] = { 5, 8, 1, 2, 10, 6, 3 };
		const int n = sizeof(x) / sizeof(int);
		insertion_sort( x, n );
		print_array( x, n );
	}
	{
		int x[] = { 20, 30, 40, 6, 5, 4, 3 };
		const int n = sizeof(x) / sizeof(int);
		insertion_sort( x, n );
		print_array( x, n );
	}
	{
		int x[] = { 5, 3, 8, 6, 10, 9 };
		const int n = sizeof(x) / sizeof(int);
		insertion_sort( x, n );
		print_array( x, n );
	}

	// Հանել մեկնաբանությունից 'insertion_sort_right_to_left()' ֆունկցիան 
	//   իրականացնելուց հետո։
	/* std::cout << " === Insertion sort (right to left) ===" << std::endl;
	{
		int x[] = { 5, 8, 1, 2, 10, 6, 3 };
		const int n = sizeof(x) / sizeof(int);
		insertion_sort_right_to_left( x, n );
		print_array( x, n );
	}
	{
		int x[] = { 20, 30, 40, 6, 5, 4, 3 };
		const int n = sizeof(x) / sizeof(int);
		insertion_sort_right_to_left( x, n );
		print_array( x, n );
	}
	{
		int x[] = { 5, 3, 8, 6, 10, 9 };
		const int n = sizeof(x) / sizeof(int);
		insertion_sort_right_to_left( x, n );
		print_array( x, n );
	} */

	return 0;
}
