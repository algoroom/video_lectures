
#include <iostream>


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

	/// Ցուցիչ ծնող-հանգույցի վրա (կամ null, եթե այս հանգույցը արմատն է)
	Node* parent = nullptr;

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
	{
		// Թարմացնում ենք ձախ երեխա-հանգույցի 'parent' դաշտը
		if ( left != nullptr )
			left->parent = this;
		// Թարմացնում ենք աջ երեխա-հանգույցի 'parent' դաշտը
		if ( right != nullptr )
			right->parent = this;
	}

	/// Ֆունկցիան ստուգում է արդյո՞ք այս (this) հանգույցով սկսվող ենթածառը 
	/// ամբողջ (full) ծառ է։
	bool isFull() const
	{
		// Իրականացնել ինքնուրույն
		//
		//
	}
};


int main( int argc, char* argv[] )
{
	// Կառուցում ենք մի ամբողջ (full) ծառ
	//
	//                 4
	//        16                 20
	//                      8          3
	//                    4   19
	//
	Node* fullTreeRoot = new Node( 4, 
			new Node( 16 ), 
			new Node( 20, 
					new Node( 8, 
							new Node( 4 ), 
							new Node( 19 ) ), 
					new Node( 3 ) ) );

	// Կառուցում ենք մի կատարյալ (perfect) ծառ
	//
	//               4
	//      16               20
	//   2      9        8        3
	//
	Node* perfectTreeRoot = new Node( 4, 
			new Node( 16, 
					new Node( 2 ), 
					new Node( 9 ) ), 
			new Node( 20, 
					new Node( 8 ), 
					new Node( 3 ) ) );

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


	return 0;
}
