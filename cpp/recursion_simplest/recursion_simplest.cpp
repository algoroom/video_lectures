
#include <iostream>


/// Ֆունկցիան ռեկուրսիվ կերպով տպում է [1..n] թվերը։
void output_1_to( int n )
{
	if ( n == 1 ) {
		// Անում ենք առաջադրանքը, առանց այլոց դիմելու
		std::cout << " " << 1;
	}
	else {
		// Կատարում ենք նվազեցված խնդիրը
		int nSmall = n - 1;
		output_1_to( nSmall );
		// Ավելացնում ենք մեր մասը
		std::cout << " " << n;
	}
}


/// Ֆունկցիան ռեկուրսիվ կերպով տպում է [1..n] թվերը, բայց հակառակ 
/// հերթականությամբ։
void output_reverse_1_to( int n )
{
	if ( n == 1 ) {
		// Անում ենք առաջադրանքը, առանց այլոց դիմելու
		std::cout << " " << 1;
	}
	else {
		// Նախ կատարում ենք մեր մասը
		std::cout << " " << n;
		// Իսկ հետո կատարում ենք նվազեցված խնդիրը
		int nSmall = n - 1;
		output_reverse_1_to( nSmall );
	}
}


/// Ֆունկցիան տպում է 'n' հատ աստղանիշ, բայց ռեկուրսիվ կերպով՝ առանց ցիկլեր 
/// օգտագործելու։
void output_stars( int n )
{
	// Իրականացնել ինքնուրույն
	//
	//
}


/// Ֆունկցիան ռեկուրսիվ կերպով տպում է 'n' հատ աստղանիշ, բայց ամեն քայլին 
/// "նվազեցնելով" խնդիրը միանգամից 2 աստղանիշով։
void output_stars_step_2( int n )
{
	if ( n == 1 )
		std::cout << "*";
	else if ( n == 2 )
		std::cout << "**";
	else {
		// Անում ենք առաջադրանքի մեր մասը
		std::cout << "**";
		// Կատարում ենք նվազեցված խնդիրը
		int nSmall = n - 2;
		output_stars_step_2( nSmall );
	}
}


/// Ֆունկցիան ռեկուրսիվ կերպով տպում է n-ից մինչև 1 թվերը, այնուհետև ետ 
/// մինչև n:
void output_n_to_1_to_n( int n )
{
	// Իրականացնել ինքնուրույն
	//
	//
}


/// Ֆունկցիան ռեկուրսիվ կերպով տպում է 'from'-ից մինչև 'to' թվերը, այնուհետև 
/// ետ մինչև 'from':
void output_incr_decr( int from, int to )
{
	if ( from == to ) {
		// Տպում ենք ամենամեծ թիվը՝ 1 անգամ
		std::cout << " " << to;
	}
	else {
		// Նախ տպում ենք առջևի ամենափոքր թիվը
		std::cout << " " << from;
		// Ռեկուրսիվ կանչ, բոլոր մեջտեղի թվերի համար
		int nextFrom = from + 1;
		output_incr_decr( nextFrom, to );
		// Վերջում տպում ենք ետևի ամենափոքր թիվը
		std::cout << " " << from;
	}
}


/// Ֆունկցիան ասղանիշերով տպում է ուղղանկյուն եռանկյուն, 'n' երկարությամբ կողով, 
/// ուղիղ անկյունը ներքևի-ձախ կողմում։
void print_triangle_1( int n )
{
	// Իրականացնել ինքնուրույն
	//
	//
}


/// Ֆունկցիան ասղանիշերով տպում է ուղղանկյուն եռանկյուն, 'n' երկարությամբ կողով, 
/// ուղիղ անկյունը վերևի-ձախ կողմում։
void print_triangle_2( int n )
{
	// Իրականացնել ինքնուրույն
	//
	//
}


int main( int argc, char* argv[] )
{
	// [1..n] թվերի արտածում
	std::cout << " === Printing numbers [1..n] === " << std::endl;
	output_1_to( 5 );
	std::cout << std::endl;
	//
	output_1_to( 12 );
	std::cout << std::endl;
	//
	output_1_to( 2 );
	std::cout << std::endl;

	// [1..n] թվերի արտածում, հակառակ հերթականությամբ
	std::cout << " === Printing numbers [1..n] in reverse === " << std::endl;
	output_reverse_1_to( 6 );
	std::cout << std::endl;
	//
	output_reverse_1_to( 4 );
	std::cout << std::endl;
	//
	output_reverse_1_to( 12 );
	std::cout << std::endl;

	// Բացել այս կտորը 'output_stars()' ֆունկցիան իրականացնելուց հետո։
	/* std::cout << " === Printing stars === " << std::endl;
	output_stars( 5 );
	std::cout << std::endl;
	//
	output_stars( 8 );
	std::cout << std::endl; */

	// Աստղանիշերի տպում (ամեն քայլին նվազեցնելով 2 միավորով)
	std::cout << " === Printing stars (with step 2) === " << std::endl;
	output_stars_step_2( 5 );
	std::cout << std::endl;
	//
	output_stars_step_2( 8 );
	std::cout << std::endl;

	// Բացել այս կտորը 'output_n_to_1_to_n()' ֆունկցիան իրականացնելուց հետո
	/* std::cout << " === Printing from 'n' to 1, then to 'n' === " << std::endl;
	output_n_to_1_to_n( 3 );
	std::cout << std::endl;
	//
	output_n_to_1_to_n( 5 );
	std::cout << std::endl; */

	// Արտածում 1-ից մինչև n, այնուհետև ետ մինչև 1
	std::cout << " === Printing from 1 to 'n', then to 1 === " << std::endl;
	output_incr_decr( 1, 4 );
	std::cout << std::endl;
	//
	output_incr_decr( 1, 6 );
	std::cout << std::endl;

	// Բացել այս կտորը 'print_triangle_1()' ֆունկցիան իրականացնելուց հետո։
	/* std::cout << " === Triangle 1 === " << std::endl;
	print_triangle_1( 4 );
	std::cout << std::endl;
	//
	print_triangle_1( 6 );
	std::cout << std::endl; */

	// Բացել այս կտորը 'print_triangle_2()' ֆունկցիան իրականացնելուց հետո։
	/* std::cout << " === Triangle 2 === " << std::endl;
	print_triangle_2( 5 );
	std::cout << std::endl;
	//
	print_triangle_2( 3 );
	std::cout << std::endl; */

	return 0;
}
