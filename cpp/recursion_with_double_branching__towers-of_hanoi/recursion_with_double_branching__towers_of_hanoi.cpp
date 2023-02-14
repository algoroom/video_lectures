
#include <iostream>


/// Ֆունկցիան տպում է էկրանին բոլոր այն անհրաժեշտ տեղաշարժերը,
/// որ պետք է անել 'n' հատ սկավառակը 'from' ձողից դեպի 'to' ձողը 
/// տեղափոխելու համար, օգտագորելով 'aux' ձողը որպես օգնական։
void move( int n, int from, int to, int aux )
{
	if ( n == 1 ) {
		// Եկքի ճյուղ
		std::cout << from << " -> " << to << std::endl;
	}
	else {
		// Ընդհանուր դեպք
		move( n-1, from, aux, to );
		std::cout << from << " -> " << to << std::endl;
		move( n-1, aux, to, from );
	}
}


/// Ֆունկցիան տպում է էկրանին բոլոր այն անհրաժեշտ տեղաշարժերը,
/// որ պետք է անել 'n' հատ սկավառակը 'from' ձողից դեպի 'to' ձողը 
/// տեղափոխելու համար, օգտագորելով 2 օգնական ձողեր՝ 'aux1' և 'aux2'։
void move_with_4( int n, int from, int to, int aux1, int aux2 )
{
	// Իրականանցնել ինքնուրույն
	//
	//
}


int main( int argc, char* argv[] )
{
	// Տեղափոխում ենք սկավառակներ
	std::cout << " === Solving Towers of Hanoi === " << std::endl;
	std::cout << " n = 1" << std::endl;
	move( 1, 1, 3, 2 );  // Տեղափոխում ենք 1-ից 3-րդ
	std::cout << std::endl;
	//
	std::cout << " n = 2" << std::endl;
	move( 2, 1, 3, 2 );  // Տեղափոխում ենք 1-ից 3-րդ
	std::cout << std::endl;
	//
	std::cout << " n = 3" << std::endl;
	move( 3, 1, 3, 2 );  // Տեղափոխում ենք 1-ից 3-րդ
	std::cout << std::endl;

	// Տեղափոխում ենք սկավառակներ, 4 ձողերով
	/* std::cout << " === Solving Towers of Hanoi (4 sticks) === " << std::endl;
	std::cout << " n = 3" << std::endl;
	move_with_4( 3, 1, 4, 2, 3 );  // Տեղափոխում ենք 1-ից 4-րդ
	std::cout << std::endl;
	//
	std::cout << " n = 4" << std::endl;
	move_with_4( 4, 1, 4, 2, 3 );  // Տեղափոխում ենք 1-ից 4-րդ
	std::cout << std::endl;
	//
	std::cout << " n = 5" << std::endl;
	move_with_4( 5, 1, 4, 2, 3 );  // Տեղափոխում ենք 1-ից 4-րդ
	std::cout << std::endl; */

	return 0;
}
