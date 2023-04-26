
#include <iostream>
#include <algorithm>


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

	/// Ֆունկցիան հաշվում և վերադարձնում է այս (this) հանգույցով սկսվող ենթածառում
	/// հանգույցների քանակը։
	int treeSize() const
	{
		// Ստուգում ենք, արդյո՞ք խորանալիս դուրս չենք եկել ծառի տիրույթից
		if ( this == nullptr )
			return 0;
		// Այլապես վստահ ենք, որ 'this'-ը ցույց է տալիս ինչ-որ հանգույցի վրա
		return left->treeSize() + 1 + right->treeSize();
	}

	/// Ֆունկցիան հաշվում և վերադարձնում է այս (this) հանգույցով սկսվող ենթածառի
	/// բարձրությունը։
	int treeHeight() const
	{
		// Ստուգում ենք, արդյո՞ք խորանալիս դուրս չենք եկել ծառի տիրույթից
		if ( this == nullptr )
			return -1;  // Այնպիսի թիվ, որին 1 գումարելով ստանանք 
			            // տերևի բարձրություն՝ այսինքն 0:
		// Այլապես վստահ ենք, որ 'this'-ը ցույց է տալիս ինչ-որ հանգույցի վրա
		return 1 + std::max( left->treeHeight(), right->treeHeight() );
	}

	/// Ֆունկցիան ստուգում է արդյո՞ք այս (this) հանգույցով սկսվող ենթածառը 
	/// ամբողջ (full) ծառ է։
	bool isFull() const
	{
		// Իրականացնել ինքնուրույն
		//
		//
	}

	/// Ֆունկցիան ստուգում է արդյո՞ք այս (this) հանգույցով սկսվող ենթածառը 
	/// կատարյալ (perfect) ծառ է։
	bool isPerfectByMethod1() const
	{
		int h = treeHeight();
		int n = treeSize();
		if ( n == (1 << (h+1)) - 1 )
			return true;
		else
			return false;
	}

	/// Ֆունկցիան ստուգում է արդյո՞ք այս (this) հանգույցով սկսվող ենթածառը 
	/// կատարյալ (perfect) ծառ է։
	/// 
	/// Ուշադրություն, սա O(N^2) վատագույն բարդությամբ աշխատող իրականացում է։
	///   Օպտիմիզացումը թողնված է որպես վարժություն։
	bool isPerfectByMethod2() const
	{
		if ( left == nullptr && right == nullptr )
			return true;  // Սա տերև է
		if ( left == nullptr || right == nullptr )
			return false;  // Ծառը ունի միայն մեկ ենթածառ
		// Այստեղից վստահ ենք որ կա 2 ենթածառ
		if ( left->isPerfectByMethod2() ) {
			if ( right->isPerfectByMethod2() ) {
				int leftH = left->treeHeight();
				int rightH = right->treeHeight();
				int h = treeHeight();
				if ( leftH == h-1 && rightH == h-1 )
					return true;
			}
		}
		return false;
	}

	/// Ֆունկցիան ստուգում է արդյո՞ք այս (this) հանգույցով սկսվող ենթածառը 
	/// ավարտուն (complete) ծառ է։
	bool isComplete() const
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

	// Կառուցում ենք մեկ այլ՝ պատահական ծառ
	//
	//                  12
	//          24             40
	//              63             9
	//            29  35
	//
	Node* randomTreeRoot = new Node( 12, 
			new Node( 24, 
					nullptr, 
					new Node( 63, 
							new Node( 29 ), 
							new Node( 35 ) ) ), 
			new Node( 40, 
					nullptr, 
					new Node( 9 ) ) );

	// Բացել այս կտորը 'isFull()' ֆունկցիան իրականացնելուց հետո։
	/* // Ստուգում ենք տարբեր ծառերի ամբողջականությունը (full tree)
	std::cout << "Checking fullness of trees: " << std::endl;
	std::cout << "   full tree - "     << fullTreeRoot->isFull() << std::endl;
	std::cout << "   perfect tree - "  << perfectTreeRoot->isFull() << std::endl;
	std::cout << "   complete tree - " << completeTreeRoot->isFull() << std::endl;
	std::cout << "   random tree - "   << randomTreeRoot->isFull() << std::endl; */

	// Ստուգում ենք տարբեր ծառերի կատարելությունը (perfect tree)
	std::cout << "Checking perfectness of trees  (method 1) : " << std::endl;
	std::cout << "   full tree - "     << fullTreeRoot->isPerfectByMethod1() << std::endl;
	std::cout << "   perfect tree - "  << perfectTreeRoot->isPerfectByMethod1() << std::endl;
	std::cout << "   complete tree - " << completeTreeRoot->isPerfectByMethod1() << std::endl;
	std::cout << "   random tree - "   << randomTreeRoot->isPerfectByMethod1() << std::endl;

	std::cout << "Checking perfectness of trees  (method 2) : " << std::endl;
	std::cout << "   full tree - "     << fullTreeRoot->isPerfectByMethod2() << std::endl;
	std::cout << "   perfect tree - "  << perfectTreeRoot->isPerfectByMethod2() << std::endl;
	std::cout << "   complete tree - " << completeTreeRoot->isPerfectByMethod2() << std::endl;
	std::cout << "   random tree - "   << randomTreeRoot->isPerfectByMethod2() << std::endl;

	// Բացել այս կտորը 'isComplete()' ֆունկցիան իրականացնելուց հետո։
	/* // Ստուգում ենք տարբեր ծառերի ավարտունությունը (complete tree)
	std::cout << "Checking completeness of trees: " << std::endl;
	std::cout << "   full tree - "     << fullTreeRoot->isComplete() << std::endl;
	std::cout << "   perfect tree - "  << perfectTreeRoot->isComplete() << std::endl;
	std::cout << "   complete tree - " << completeTreeRoot->isComplete() << std::endl;
	std::cout << "   random tree - "   << randomTreeRoot->isComplete() << std::endl; */

	return 0;
}
