
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
	void printTree( int indent = 0 ) const
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

	// Բացել այս կտորը 'inorderNext()' ֆունկցիան իրականացնելուց հետո
	//
	/* // Գտնում ենք ըստ inorder հաջորդականության հաջորդ արժեքներին
	{
		Node* nodeWith16 = root->left;  // 16-ը արմատի ձախ երեխան է
		Node* nextOf16 = inorderNext( nodeWith16 );
		std::cout << " Inorder next from '16' is: " << nextOf16->value << std::endl;
				// Պետք է լինի '3'
	}
	{
		Node* nodeWith4 = root;  // 4-ը արմատում է
		Node* nextOf4 = inorderNext( nodeWith4 );
		std::cout << " Inorder next from '4' is: " << nextOf4->value << std::endl;
				// Պետք է լինի '14'
	}
	{
		Node* nodeWith19 = root->right->left->right;  // 19 արժեքով հանգույցը
		Node* nextOf19 = inorderNext( nodeWith19 );
		std::cout << " Inorder next from '19' is: " << nextOf19->value << std::endl;
				// Պետք է լինի '20'
	} */

	// Ստեղծում ենք ինչ-որ այլ ծառ
	//
	//
	//            25
	//      33           20
	//    7      12             4
	//  1      4              9
	//                      32
	//
	Node* root2 = new Node( 25, 
			new Node( 33, 
					new Node( 7, 
							new Node( 1 ), 
							nullptr ), 
					new Node( 12, 
							new Node( 4 ), 
							nullptr ) ), 
			new Node( 20, 
					nullptr,
					new Node( 4, 
							new Node( 9, 
									new Node( 32 ), 
									nullptr ), 
							nullptr ) ) );

	// Տպում ենք էկրանին այդ 2 ծառերը
	std::cout << " === Tree 1 === " << std::endl;
	root->printTree();
	std::cout << " === Tree 2 === " << std::endl;
	root2->printTree();

	// Բացել այս կտորը 'traverseBFS()' ֆունկցիան իրականացնելուց հետո։
	//
	/* std::cout << "BFS traversal of tree 1: " << std::endl;
	traverseBFS( root );
			// Պետք է ստացվի [ 4, 16, 20, 7, 3, 8, 4, 14, 19 ]
	std::cout << "BFS traversal of tree 2: " << std::endl;
	traverseBFS( root2 );
			// Պետք է ստացվի [ 25, 33, 20, 7, 12, 4, 1, 4, 9, 32 ]
			*/

	return 0;
}
