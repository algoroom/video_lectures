
#include <iostream>


/// Ֆունկցիան կատարում է պղպջակային սորտավորում 'n' երկարություն ունեցող 
/// 'x' զանգվածի վրա։
/// Որևէ օպտիմիզացիաներ ներառված չեն։
void bubble_sort( int x[], int n )
{
	for ( int k = 1; k < n; ++k ) {  // k-րդ իտերացիա
		for ( int i = 0; i < n-1; ++i ) {
			if ( x[i] > x[i+1] ) {
				// տեղափոխում ենք 'x[i]'-ն և 'x[i+1]'-ը
				int t = x[i];
				x[i] = x[i+1];
				x[i+1] = t;
			}
		}
	}
}


/// Ֆունկցիան կատարում է պղպջակային սորտավորում 'n' երկարություն ունեցող 
/// 'x' զանգվածի վրա։
/// Ներառված է առաջին օպտիմիզացիան։
void bubble_sort_opt_1( int x[], int n )
{
	for ( int k = 1; k < n; ++k ) {  // k-րդ իտերացիա
		for ( int i = 0; i < n-k; ++i ) {
			if ( x[i] > x[i+1] ) {
				// տեղափոխում ենք 'x[i]'-ն և 'x[i+1]'-ը
				int t = x[i];
				x[i] = x[i+1];
				x[i+1] = t;
			}
		}
	}
}


/// Ֆունկցիան կատարում է պղպջակային սորտավորում 'n' երկարություն ունեցող 
/// 'x' զանգվածի վրա։
/// Ներառված են առաջին և երկրորդ օպտիմիզացիաները։
void bubble_sort_opt_1_and_2( int x[], int n )
{
	for ( int k = 1; k < n; ++k ) {  // k-րդ իտերացիա
		bool chg = false;   // արդյո՞ք այս իտերացիային կատարել ենք 
		                    // որևէ տեղափոխություն
		for ( int i = 0; i < n-k; ++i ) {
			if ( x[i] > x[i+1] ) {
				// տեղափոխում ենք 'x[i]'-ն և 'x[i+1]'-ը
				int t = x[i];
				x[i] = x[i+1];
				x[i+1] = t;
				chg = true;  // հիշում ենք որ կատարել ենք տեղափոխություն
			}
		}
		if ( ! chg )  // եթե իտերացիայի ընթացքում տեղափոխություն չի կատարվել, 
			return;   // ուրեմն շարքը սորտավորված է, կարող ենք ավարտել։
	}
}


/// Ֆունկցիան կատարում է պղպջակային սորտավորում 'n' երկարություն ունեցող 
/// 'x' զանգվածի վրա, բայց ամեն իտերացիան սկանավորում է շարքը աջից ձախ։
void bubble_sort_right_to_left( int x[], int n )
{
	// Իրականացնել ինքնուրույն
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
	// Պղպջակային սորտավորում (առանց օպտիմիզացիաների)
	std::cout << " === Bubble Sort (without optimizations) === " << std::endl;
	{
		int z[] = { 5, 19, 3, 25, 3, 7, 18, 4 };
		int n = sizeof(z) / sizeof(z[0]);
		bubble_sort( z, n );
		print_array( z, n );
	}
	{
		int z[] = { 20, 16, 13, 10, 8, 5 };
		int n = sizeof(z) / sizeof(z[0]);
		bubble_sort( z, n );
		print_array( z, n );
	}
	{
		int z[] = { 94, 39, 43, 12, 5, 6, 18, 23, 48 };
		int n = sizeof(z) / sizeof(z[0]);
		bubble_sort( z, n );
		print_array( z, n );
	}

	// Պղպջակային սորտավորում (միայն առաջին օպտիմիզացիայով)
	std::cout << " === Bubble Sort (with 1'st optimization) === " << std::endl;
	{
		int z[] = { 5, 19, 3, 25, 3, 7, 18, 4 };
		int n = sizeof(z) / sizeof(z[0]);
		bubble_sort_opt_1( z, n );
		print_array( z, n );
	}
	{
		int z[] = { 20, 16, 13, 10, 8, 5 };
		int n = sizeof(z) / sizeof(z[0]);
		bubble_sort_opt_1( z, n );
		print_array( z, n );
	}
	{
		int z[] = { 94, 39, 43, 12, 5, 6, 18, 23, 48 };
		int n = sizeof(z) / sizeof(z[0]);
		bubble_sort_opt_1( z, n );
		print_array( z, n );
	}

	// Պղպջակային սորտավորում (երկու օպտիմիզացիաներով)
	std::cout << " === Bubble Sort (with 1'st and 2'nd optimizations) === " << std::endl;
	{
		int z[] = { 5, 19, 3, 25, 3, 7, 18, 4 };
		int n = sizeof(z) / sizeof(z[0]);
		bubble_sort_opt_1_and_2( z, n );
		print_array( z, n );
	}
	{
		int z[] = { 20, 16, 13, 10, 8, 5 };
		int n = sizeof(z) / sizeof(z[0]);
		bubble_sort_opt_1_and_2( z, n );
		print_array( z, n );
	}
	{
		int z[] = { 94, 39, 43, 12, 5, 6, 18, 23, 48 };
		int n = sizeof(z) / sizeof(z[0]);
		bubble_sort_opt_1_and_2( z, n );
		print_array( z, n );
	}

	// Բացել այս կտորը 'bubble_sort_right_to_left()' ֆունկցիան 
	// իրականացնելուց հետո
	/* std::cout << " === Bubble Sort [right to left] === " << std::endl;
	{
		int z[] = { 5, 19, 3, 25, 3, 7, 18, 4 };
		int n = sizeof(z) / sizeof(z[0]);
		bubble_sort_right_to_left( z, n );
		print_array( z, n );
	}
	{
		int z[] = { 20, 16, 13, 10, 8, 5 };
		int n = sizeof(z) / sizeof(z[0]);
		bubble_sort_right_to_left( z, n );
		print_array( z, n );
	}
	{
		int z[] = { 94, 39, 43, 12, 5, 6, 18, 23, 48 };
		int n = sizeof(z) / sizeof(z[0]);
		bubble_sort_right_to_left( z, n );
		print_array( z, n );
	} */

	return 0;
}
