
#include <iostream>


/// Ֆունկցիան հաշվում և վերադարձնում է a^n աստիճանը, ռեկուրսիվ, 
/// ամեն քայլին աստիճանը 1 միավորով նվազեցնելով։
double power( double a, int n )
{
	if ( n == 1 ) {
		// a^1 միշտ հավասար է a-ի
		return a;
	}
	else {
		// Կատարում ենք նվազեցված խնդիրը
		int nReduced = n - 1;
		double resultReduced = power( a, nReduced );
		// Ավելացնում ենք ստացված արդյունքին մեր մասը
		double result = resultReduced * a;
		return result;
	}
}


/// Ֆունկցիան հաշվում և վերադարձնում է a^n աստիճանը, ռեկուրսիվ, 
/// ամեն քայլին նվազեցնելով աստիճանը 2 անգամ։
double power_optimal( double a, int n )
{
	if ( n == 1 )
		return a;
	else {
		if ( n % 2 == 0 ) {   // n-ը զույգ է
			double resultReduced = power_optimal( a, n/2 );
			return resultReduced * resultReduced;
		}
		else {                // n-ը կենտ է
			double resultReduced = power_optimal( a, (n-1)/2 );
			return resultReduced * resultReduced * a;
		}
	}
}


/// Ֆունկիցան ռեկուրսիվ հաշվում է a*b արտադրյալը, բայց որպես 'b' հատ 
/// 'a'-երի գումքր։
/// Ռեկուրսիվ ամեն քայլին գումարը նվազեցվում է 1 'a'-ով։
int product( int a, int b )
{
	// Իրականացնել ինքնուրույն
	//
	//
	return -1;
}


/// Ֆունկիցան ռեկուրսիվ հաշվում է a*b արտադրյալը, բայց որպես 'b' հատ 
/// 'a'-երի գումքր։
/// Ռեկուրսիվ ամեն քայլին գումարը նվազեցվում է 2 անգամ։
int product_logrithmic( int a, int b )
{
	// Իրականացնել ինքնուրույն
	//
	//
	return -1;
}


/// Ֆունկցիան ռեկուրսիվ հաշվում և վերադարձնում է 'n' թվի ֆակտորիալը։
long long factorial( int n )
{
	// Իրականացնել ինքնուրույն
	//
	//
	return -1;
}


/// Ֆունկցիան տպում է փոխանցված 'z' ամբողջ թիվը, բայց թվանշան-առ-թվանշան։
void print_by_digits( int z )
{
	if ( z <= 9 )
		std::cout.put( '0'+z );     // տպում ենք 'z' թվանշանը
	else {
		int last = z % 10;
		int remaining = z / 10;
		print_by_digits( remaining );
		std::cout.put( '0'+last );  // տպում ենք 'last' թվանշանը
	}
}


/// Ֆունկցիան տպում է փոխանցված 'z' ամբողջ թիվը, բայց թվանշան-առ-թվանշան, 
/// ու հակառակ հաջորդականությամբ։
void print_by_digits_reverse( int z )
{
	if ( z <= 9 )
		std::cout.put( '0'+z );     // տպում ենք 'z' թվանշանը
	else {
		int last = z % 10;
		int remaining = z / 10;
		std::cout.put( '0'+last );  // տպում ենք 'last' թվանշանը
		print_by_digits_reverse( remaining );
	}
}


/// Ֆունկցիան ռեկուրսիվ հաշվում և վերադարձնում է փոխանցված 'z' ամբողջ թվի 
/// թվանշանների քանակը։
int digits_count( int z )
{
	// Իրականացնել ինքնուրույն
	//
	//
	return -1;
}


/// Ֆունկցիան շրջում է տրված թվի թվանշանների հաջորդականությունը, և վերադարձնում է 
/// ստացված թիվը։
int reverse_digits( int z )
{
	// Իրականացնել ինքնուրույն
	//
	//
	return -1;
}


/// Ֆունկցիան Էվկլիդեսի ալգորիթմով, ռեկուրսիվ հաշվում է տրված 2 թվերի ամենամեծ 
/// ընդհանուր բաժանարարը (Greatest Common Divisor):
int gcd( int a, int b )
{
	// Իրականացնել ինքնուրույն
	//
	//
	return -1;
}


int main( int argc, char* argv[] )
{
	// a^n աստիճանի հաշվարկ
	std::cout << " === Calculating a^n === " << std::endl;
	std::cout << power( 5.0, 2 ) << std::endl;  // պետք է լինի 25.0
	std::cout << power( 2, 8 ) << std::endl;    // պետք է լինի 256
	std::cout << power( 1.5, 17 ) << std::endl; // պետք է լինի 985.261

	// a^n աստիճանի օպտիմալ հաշվարկ
	std::cout << " === Calculating a^n optimally === " << std::endl;
	std::cout << power_optimal( 5.0, 2 ) << std::endl;  // պետք է լինի 25.0
	std::cout << power_optimal( 2, 8 ) << std::endl;    // պետք է լինի 256
	std::cout << power_optimal( 1.5, 17 ) << std::endl; // պետք է լինի 985.261

	// Բացել այս կտորը 'product()' ֆունկցիան իրականացնելուց հետո։
	/* std::cout << " === Calculating product === " << std::endl;
	std::cout << product( 3, 4 ) << std::endl;       // պետք է լինի 12
	std::cout << product( 20, 30 ) << std::endl;     // պետք է լինի 600
	std::cout << product( 1, 5 ) << std::endl; */       // պետք է լինի 5

	// Բացել այս կտորը 'product_logarithmic()' ֆունկցիան իրականացնելուց հետո։
	/* std::cout << " === Calculating product in logarithmic manner === " << std::endl;
	std::cout << product_logrithmic( 3, 4 ) << std::endl;       // պետք է լինի 12
	std::cout << product_logrithmic( 20, 30 ) << std::endl;     // պետք է լինի 600
	std::cout << product_logrithmic( 1, 5 ) << std::endl; */       // պետք է լինի 5

	// Բացել այս կտորը 'factorial()' ֆունկցիան իրականացնելուց հետո։
	/* std::cout << " === Calculating factorials === " << std::endl;
	std::cout << factorial( 3 ) << std::endl;     // պետք է լինի 6
	std::cout << factorial( 5 ) << std::endl;     // պետք է լինի 120
	std::cout << factorial( 12 ) << std::endl; */    // պետք է լինի 479001600

	// Թվի, ըստ թվանշանների արտածում
	std::cout << " === Printing numbers by digits === " << std::endl;
	print_by_digits( 456 );
	std::cout << std::endl;
	print_by_digits( 9823 );
	std::cout << std::endl;
	print_by_digits( 17 );
	std::cout << std::endl;

	// Թվի, ըստ թվանշանների հակառակ արտածում
	std::cout << " === Printing numbers by digits in reverse === " << std::endl;
	print_by_digits_reverse( 735 );
	std::cout << std::endl;
	print_by_digits_reverse( 6540 );
	std::cout << std::endl;
	print_by_digits_reverse( 19 );
	std::cout << std::endl;

	// Բացել այս կտորը 'digits_count()' ֆունկցիան իրականացնելուց հետո։
	/* std::cout << " === Returning number of digits === " << std::endl;
	std::cout << digits_count( 34 ) << std::endl;
	std::cout << digits_count( 1024 ) << std::endl;
	std::cout << digits_count( 65930 ) << std::endl; */

	// Բացել այս կտորը 'reverse_digits()' ֆունկցիան իրականացնելուց հետո։
	/* std::cout << " === Reversing digits === " << std::endl;
	std::cout << reverse_digits( 34 ) << std::endl;
	std::cout << reverse_digits( 1024 ) << std::endl;
	std::cout << reverse_digits( 65930 ) << std::endl; */

	// Բացել այս կտորը 'gcd()' ֆունկցիան իրականացնելուց հետո։
	/* std::cout << " === Greatest Common Divisor (GCD) === " << std::endl;
	std::cout << gcd( 15, 25 ) << std::endl;      // պետք է ստացվի 5
	std::cout << gcd( 256, 12 ) << std::endl;     // պետք է ստացվի 4
	std::cout << gcd( 17, 37 ) << std::endl; */      // պետք է ստացվի 1

	return 0;
}
