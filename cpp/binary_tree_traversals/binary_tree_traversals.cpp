
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

	/// Ֆունկցիան կատարում է այս (this) հանգույցով սկսվող ենթածառի preorder 
	/// շրջանցում, տպելով արժեքները էկրանին։
	void traversePreorder() const
	{
		std::cout << " " << value;
		if ( left != nullptr )
			left->traversePreorder();
		if ( right != nullptr )
			right->traversePreorder();
	}

	/// Ֆունկցիան կատարում է այս (this) հանգույցով սկսվող ենթածառի inorder 
	/// շրջանցում, տպելով արժեքները էկրանին։
	void traverseInorder() const
	{
		// Իրականացնել ինքնուրույն
		//
		//
	}

	/// Ֆունկցիան կատարում է այս (this) հանգույցով սկսվող ենթածառի postorder 
	/// շրջանցում, տպելով արժեքները էկրանին։
	void traversePostorder() const
	{
		// Իրականացնել ինքնուրույն
		//
		//
	}

	/// Ֆունկցիան տպում է այս (this) հանգույցով սկսվող ենթածառը էկրանին, պտտած 
	/// 90 աստիճանով դեպի ձախ, էկրանի ձախ եզրից 'indent' հեռավորության վրա։
	void printTree( int indent ) const
	{
		// Տպում ենք աջ ենթածառը
		if ( right != nullptr )
			right->printTree( indent + 3 );
		// Տպում ենք ներկայիս արմատը
		for ( int i = 0; i < indent; ++i )
			std::cout.put( ' ' );
		std::cout << value << std::endl;
		// Տպում ենք ձախ ենթածառը
		if ( left != nullptr )
			left->printTree( indent + 3 );
	}

};


/// Ֆունկցիան գտնում և վերադարձնում է ըստ inorder շրջանցման այն հանգույցը, 
/// որ գալիս է փոխանցված 'node'-ից հետո, կամ null, եթե 'node'-ը ըստ inorder 
/// շրջանցման վերջին հանգույցն է։
Node* inorderNext( Node* node )
{
	// Իրականացնել ինքնուրույն
	//
	//
	return nullptr;
}


/// Ֆունկցիան կատարում է 'node' հանգույցով սկսվող ծառի BFS շրջանցում, և տպում է 
/// արժեքները էկրանին։
/// Այդ շրջանցման ժամանակ արժեքները թվարկվում են ըստ մակարդակների՝ ամենաբարձրից 
/// դեպի ամենացածր մակարդակը, և ամեն մակարդակում ձախից աջ։
void traverseBFS( const Node* node )
{
	// Իրականացնել ինքնուրույն
	//
	//
}


int main( int argc, char* argv[] )
{
	// Ստեղծում ենք ինչ-որ ծառ
	//
	//
	//            4
	//      16              20
	//    7    3       8         4
	//               14  19
	//
	Node* root = new Node( 4, 
			new Node( 16, 
					new Node( 7 ), 
					new Node( 3 ) ), 
			new Node( 20, 
					new Node( 8, 
							new Node( 14 ), 
							new Node( 19 ) ),
					new Node( 4 ) ) );

	// Տպում ենք ըստ preorder շրջանցման
	std::cout << "Preorder traversal: " << std::endl;
	std::cout << " [";
	root->traversePreorder();
	std::cout << " ]" << std::endl;

	// Բացել այս կտորը 'traverseInorder()' ֆունկցիան իրականացնելուց հետո
	// 
	/* // Տպում ենք ըստ inorder շրջանցման
	std::cout << "Inorder traversal: " << std::endl;
	std::cout << " [";
	root->traverseInorder();
	std::cout << " ]" << std::endl; */

	// Բացել այս կտորը 'traversePostorder()' ֆունկցիան իրականացնելուց հետո
	// 
	/* // Տպում ենք ըստ postorder շրջանցման
	std::cout << "Postorder traversal: " << std::endl;
	std::cout << " [";
	root->traversePostorder();
	std::cout << " ]" << std::endl; */


	// Write test for 'inorderNext()'


	// Write test for 'print()'


	// Write test for 'traverseBFS()'


	return 0;
}
