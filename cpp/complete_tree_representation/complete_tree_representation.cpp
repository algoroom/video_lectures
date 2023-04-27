
#include <iostream>
#include <vector>


/// Այս դասի օբյեկտը իրենից ներկայացնում է Երկուական Ծառի մեկ հանգույց։
class Node
{
public:
	/// Հանգույցում պահվող արժեքը
	int value;

	/// Ցուցիչ ձախ երեխա-հանգույցի վրա (կամ null, եթե այն չկա)
	Node* left = nullptr;

	/// Ցուցիչ աջ երեխա-հանգույցի վրա (կամ null, եթե այն չկա)
	Node* right = nullptr;

public:
	/// Հանգույցի կոնստրուկտոր
	/// Օգտագործվում է ծառը լակոնիկ կառուցելու համար
	/// 'value__'-ն նոր հանգույցի արժեքն է, 'left__'-ը իր արդեն պատրաստված ձախ 
	/// երեխա-հանգույցը, իսկ 'right__'-ը՝ աջ երեխա-հանգույցը։
	/// 'left__'-ը և 'right__'-ը կարող են լինել 'null', ինչը նշանակում է այդ 
	/// երեխա-հանգույցի բացակայություն։
	Node( int value__, Node* left__ = nullptr, Node* right__ = nullptr )
		: value( value__ ), 
		  left( left__ ), 
		  right( right__ )
	{}

	/// Ֆունկցիան տպում է էկրանին այս (this) հանգույցով սկսվող ենթածառը, 
	/// պտտած 90 աստիճանով ձախ, ու էկրանի ձախ եզրից 'indent' հեռավորությամբ։
	void print( int indent = 0 ) const
	{
		// Տպում ենք աջ ենթածառը
		if ( right != nullptr )
			right->print( indent + 3 );
		// Տպում ենք այս (this) հանգույցի արժեքը
		for ( int i = 0; i < indent; ++i )
			std::cout.put( ' ' );
		std::cout << value << std::endl;
		// Տպում ենք ձախ ենթածառը
		if ( left != nullptr )
			left->print( indent + 3 );
	}

	/// Ֆունկցիան փոխակերպում է այս (this) հանգույցով սկսվող ավարտուն ծառը
	/// դեպի զանգվածով ներկայացում։
	std::vector< int > convertToArray() const
	{
		// Իրականացնել ինքնուրույն
		//
		//
		return std::vector< int >();
	}

};


/// Այս գլոբալ ֆունկցիան փոխակերպում է 'a' զանգվածով փոխանցված ավարտուն ծառը, 
/// դեպի հանգույցներով և ցուցիչներով ներկայացում։
/// Վերադարձնում է կառուցված ծառի արմատի վրա ցուցիչը։
Node* convertToNodes( const std::vector< int >& a )
{
	const int n = (int)a.size();
	// Ստեղծում ենք հանգույցների զանգվածը
	std::vector< Node* > b( n );
	for ( int i = 0; i <= n-1; ++i )
		b[ i ] = new Node( a[ i ] );
	// Տեղադրում ենք 'left' և 'right' կապերը
	for ( int k = 1; k <= n-1; ++k ) {
		// Հաշվում ենք 'k'-ի ծնող ինդեքսը
		int kPar = (k-1) / 2;
		// Որոշում ենք, 'k'-ն ձախ թե աջ երեխան է
		if ( k % 2 == 1 )
			b[ kPar ]->left = b[ k ];
		else
			b[ kPar ]->right = b[ k ];
	}
	// Վերադարձնում ենք արմատը, որը 0 ինդեքսում է
	return b[ 0 ];
}


int main( int argc, char* argv[] )
{
	{
		// Կառուցում ենք մի ավարտուն (complete) ծառ
		//
		//                  53
		//          82             45
		//     44       12     76      3
		//   56  43   13
		//
		Node* completeTreeRoot = new Node( 53, 
				new Node( 82, 
						new Node( 44, 
								new Node( 56 ), 
								new Node( 43 ) ), 
						new Node( 12, 
								new Node( 13 ) ) ), 
				new Node( 45, 
						new Node( 76 ), 
						new Node( 3 ) ) );

		// Բացել այս կտորը 'convertToArray()' ֆունկցիան իրականացնելուց հետո
		//
		/* std::cout << "Converting tree to array ... " << std::endl;
		// Փոխակերպում ենք ավարտուն ծառը զանգվածի
		std::vector< int > a = completeTreeRoot->convertToArray();
		const int n = (int)a.size();
		// Տպում ենք ստացված զանգվածը
		std::cout << " [";
		for ( int i = 0; i < n; ++i )
			std::cout << " " << a[ i ];
		std::cout << " ]" << std::endl; */
	}

	{
		std::cout << "Converting array to tree (case 1) ... " << std::endl;
		std::vector< int > a = { 5, 3, 2, 19, 34, 21, 67, 24, 78, 6 };
		Node* root = convertToNodes( a );
		root->print();
	}

	{
		std::cout << "Converting array to tree (case 2) ... " << std::endl;
		std::vector< int > a = { 20, 34, 9, 56, 87, 4 };
		Node* root = convertToNodes( a );
		root->print();
	}

	return 0;
}
