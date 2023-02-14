
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

	/// Ֆունկցիան տպում է այս հանգույցից դեպի արմատ բոլոր հանգույցների 
	/// (նախածնողների) արժեքները։
	void printDescendants() const
	{
		const Node* x = this;  // Հիշում ենք այս հանգույցի ցուցիչը 'x'-ի մեջ, 
		                       // որպիսի կարողանանք իրեն փոփոխել։
		while ( x != nullptr ) {
			std::cout << " " << x->value;
			x = x->parent;
		}
		std::cout << std::endl;
	}

	/// Ֆունկցիան հաշվում և վերադարձնում է այս (this) հանգույցի խորությունը։
	int depth() const
	{
		// Իրականացնել ինքնուրույն
		//
		//
		return -1;
	}

	/// Ֆունկցիան տպում է այս (this) հանգույցից մինչև իր ենթածառի որևէ 
	/// պատահական տերև ճանապարհի հանգույցների արժեքները։
	void printPathToRandomPath()
	{
		// Իրականացնել ինքնուրույն
		//
		//
	}

	/// Ֆունկցիան վերադարձնում է այս (this) հանգույցի ենթածառի միջից մի 
	/// պատահական տերև։
	Node* randomLeaf()
	{
		// Իրականացնել ինքնուրույն
		//
		//
		return nullptr;
	}

	/// Ֆունկցիան հաշվում և վերադարձնում է այս (this) հանգույցով սկսվող 
	/// ենթածառի բարձրությունը։
	int treeHeight() const
	{
		if ( left == nullptr && right == nullptr )
			return 0;  // Տերևի բարձրությունը միշտ 0 է
		// Հաշվում ենք ձախ ենթածառի բարձրությունը
		int leftHeight = 0;
		if ( left != nullptr )
			leftHeight = left->treeHeight();
		// Հաշվում ենք աջ ենթածառի բարձրությունը
		int rightHeight = 0;
		if ( right != nullptr )
			rightHeight = right->treeHeight();
		// Միացնում ենք արդյունքները իրար
		int height = std::max( leftHeight, rightHeight ) + 1;
		return height;
	}

	/// Ֆունկցիան հաշվում և վերադարձնում է այս (this) հանգույցով սկսվող 
	/// ենթածառի հանգույցների քանակը։
	int treeSize() const
	{
		// Իրականացնել ինքնուրույն
		//
		//
		return -1;
	}

	/// Ֆունկցիան հաշվում և վերադարձնում է այս (this) հանգույցով սկսվող 
	/// ենթածառի լայնությունը։
	int treeWidth() const
	{
		// Իրականացնել ինքնուրույն
		//
		//
		return -1;
	}

};


int main( int argc, char* argv[] )
{
	// Ստեղծում ենք ինչ-որ ծառ
	//
	//
	//                     8
	//        9                          2
	//    4        6                             4
	//  5   3          1                     12
	//
	Node* root = new Node( 8, 
			new Node( 9, 
					new Node( 4, new Node( 5 ), new Node( 3 ) ), 
					new Node( 6, nullptr, new Node( 1 ) ) ), 
			new Node( 2, 
					nullptr, 
					new Node( 4, new Node( 12 ), nullptr ) ) );

	// Տպում ենք նախածնողներին (descendants)
	std::cout << " === Printing descendants === " << std::endl;
	Node* nodeWith6 = root->left->right;
	nodeWith6->printDescendants();
	Node* nodeWith1 = root->left->right->right;
	nodeWith1->printDescendants();
	Node* nodeWith12 = root->right->right->left;
	nodeWith12->printDescendants();

	// Հանել մեկնաբանությունից 'depth()' ֆունկցիան իրականացնելուց հետո
	/* // Հաշվում ենք հանգույցների խորությունները
	std::cout << " === Calculating depths of nodes === " << std::endl;
	std::cout << "Depth of '6' is: " << nodeWith6->depth() << std::endl;
	std::cout << "Depth of '12' is: " << nodeWith12->depth() << std::endl; */

	// Հանել մեկնաբանությունից 'printPathToRandomPath()' ֆունկցիան իրականացնելուց հետո
	/* // Տպում ենք պատահական ճանապարհներ դեպի տերևներ
	std::cout << " === Printing paths to random leaves === " << std::endl;
	root->printPathToRandomPath();
	root->printPathToRandomPath();
	root->printPathToRandomPath(); */

	// Հանել մեկնաբանությունից 'randomLeaf()' ֆունկցիան իրականացնելուց հետո
	/* // Տպում ենք պատահական տերևներ
	std::cout << " === Printing random leaves === " << std::endl;
	std::cout << root->randomLeaf()->value << std::endl;
	std::cout << root->randomLeaf()->value << std::endl;
	std::cout << root->randomLeaf()->value << std::endl; */

	// Հաշվում ենք ծառի (և ենթածառերի) բարձրությունները
	std::cout << " === Calculating heights of subtrees === " << std::endl;
	std::cout << "Height of the tree is " << root->treeHeight() << std::endl;
	Node* nodeWith9 = root->left;
	std::cout << "Height of subtree with '9' is " << nodeWith9->treeHeight() << std::endl;

	// Հանել մեկնաբանությունից 'treeSize()' ֆունկցիան իրականացնելուց հետո
	/* // Հաշվում ենք ծառի (և ենթածառերի) հանգույցների քանակները
	std::cout << " === Calculating sizes of subtrees === " << std::endl;
	std::cout << "Size of the tree is " << root->treeSize() << std::endl;
	std::cout << "Size of subtree with '9' is " << nodeWith9->treeSize() << std::endl; */

	// Հանել մեկնաբանությունից 'treeWidth()' ֆունկցիան իրականացնելուց հետո
	/* // Հաշվում ենք ծառի (և ենթածառերի) լայնությունները
	std::cout << " === Calculating widths of subtrees === " << std::endl;
	std::cout << "Width of the tree is " << root->treeWidth() << std::endl;
	std::cout << "Width of subtree with '9' is " << nodeWith9->treeWidth() << std::endl; */

	return 0;
}
