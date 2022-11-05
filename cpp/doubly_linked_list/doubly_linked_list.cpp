
#include <iostream>


/// Այս ստրուկտուրան իրենից ներկայացնում է կրկնակի-կապակցվաց ցուցակի 
/// մեկ հանգույց։
struct Node
{
	/// Այս հանգույցում պահվող արժեքը
	int value;

	/// Ցուցիչ հաջորդ հանգույցի վրա
	Node* next;

	/// Ցուցիչ նախորդ հանգույցի վրա
	Node* previous;
};


/// Այս դասը իրենից ներկայացնում է կրկնակի-կապակցված ցուցակ։
class DL_List
{
private:
	/// Ցուցիչ բոլոր արժեք կրող հանգույցներին "նախորդող" ֆիկտիվ հանգույցի վրա։
	Node* header;

	/// Ցուցիչ բոլոր արժեք կրող հանգույցներին "հաջորդող" ֆիկտիվ հանգույցի վրա։
	Node* trailer;

public:
	/// Կոնստրուկտոր
	/// Ստեղծում է դատարկ ցուցակ
	DL_List()
	{
		// Ստեղծում ենք ուղեկցող հանգույցները
		header = new Node;
		trailer = new Node;
		// Ուղսում ենք իրենց միմյանց վրա
		header->next = trailer;
		trailer->previous = header;
	}

	/// Դեստրուկտոր
	/// Հեռացնում է հիշողությունից ցուցակի բոլոր հանգույցները
	~DL_List()
	{
		// Հեռացնում ենք արժեք կրող հանգույցներին
		while ( header->next != trailer ) {
			// Դեռ 'header'-ի ու 'trailer'-ի միջև կա առնվազն մեկ հանգույց
			// Ուրեմն հեռացնում ենք արժեք կրողներից վերջինին
			remove( trailer->previous );
		}
		// Այս պահին արժեք կրող հանգույց չի մնացել, հեռացնում ենք ուղեկցող 
		// հանգույցներին
		delete trailer;
		delete header;
	}

	/// Ֆունկցիան վերադարձնում է ցուցակի արժեք կրող հանգույցներին նախորդող 
	/// 'header' հանգույցի ցուցիչը։ Դա մեզ պետք կգա ցուցակի տարբեր 
	/// հանգույցներին հասնելու համար։
	Node* getHeader() const
	{
		return header;
	}

	/// Ֆունկցիան վերադարձնում է ցուցակի արժեք կրող հանգույցներին հաջորդող 
	/// 'trailer' հանգույցի ցուցիչը։ Դա մեզ պետք կգա ցուցակի տարբեր 
	/// հանգույցներին հասնելու համար։
	Node* getTrailer() const
	{
		return trailer;
	}

	/// Այս ֆունկցիան տպում է ցուցակի արժեքները։
	void printForward() const
	{
		Node* ptr = header->next;
		std::cout << "[";
		while ( ptr != trailer ) {
			std::cout << " " << ptr->value;
			ptr = ptr->next;
		}
		std::cout << " ]" << std::endl;  // Ցուցակը տպելուց հետո անցնում ենք հաջորդ տող
	}

	/// Այս ֆունկցիան տպում է ցուցակի արժեքները, բայց վերջից սկիզբ։
	void printBackward() const
	{
		Node* ptr = trailer->previous;
		std::cout << "[";
		while ( ptr != header ) {
			std::cout << " " << ptr->value;
			ptr = ptr->previous;
		}
		std::cout << " ]" << std::endl;  // Ցուցակը տպելուց հետո անցնում ենք հաջորդ տող
	}

	/// Այս ֆունկցիան ավելացնում է ցուցակի մեջ նոր հանգույց, 'ptr' հանգույցից 
	/// հետո, և որի արժեքը կլինի հավասար 'newValue'-ի։
	void insert( Node* ptr, int newValue )
	{
		Node* ptr2 = ptr->next;  // Ավելացումը անելու ենք 'ptr' և 'ptr2'-ի միջև
		// Ստեղծում ենք նոր հանգույցը
		Node* newNode = new Node;
		newNode->value = newValue;
		// Ուղղում ենք իր ցուցիչները հարևանների վրա
		newNode->previous = ptr;
		newNode->next = ptr2;
		// Ուղղում ենք հարևանների ցուցիչները նոր հանգույցի վրա
		ptr2->previous = newNode;
		ptr->next = newNode;
	}

	/// Այս ֆունկցիան հեռացնում է ցուցակից 'ptr' հանգույցը
	void remove( Node* ptr )
	{
		// Հիշում ենք հարևան հանգույցներին
		Node* after = ptr->next;
		Node* before = ptr->previous;
		// Ուղղում ենք այդ հարևաններին միմյանց վրա
		before->next = after;
		after->previous = before;
		// Հեռացնում ենք 'ptr' հանգույցը
		delete ptr;
	}

	/// Ֆունկցիան տեղափոխում է 'ptr' հանգույցը իր հաջորդ հանգույցի հետ, 
	/// բայց անում է դա միայն իրենց 'previous' և 'next' ցուցիչները փոխելով։
	void swapWithNext( Node* ptr )
	{
		// Իրականացնել ինքնուրույն
		//
		//
	}

	/// Ֆունկցիան ստուգում է, արդյո՞ք այս ցուցակը իրենից ներկայացնում է պալինդրոմ, 
	/// այսինքն կարդացվում է նույն կերպ և սկզբից վերջ, և վերջից սկիզբ։
	bool isPalindrome() const
	{
		// Իրականացնել ինքնուրույն
		//
		//
		return false;
	}

	/// Ֆունկցիան շրջում է ցուցակի ողջ բովանդակությունը, այնպես որ առաջին արժեքը 
	/// դառնում է վերջինը, երկրորդը՝ նախավերջինը, և այդպես շարունակ։
	/// Դա կատարվում է միայն հանգույցների 'next' ու 'previous' ցուցիչները փոխելով։
	void reverse()
	{
		// Իրականացնել ինքնուրույն
		//
		//
	}

	/// Ֆունկցիան սորտավորում է այս ցուցակի բոլոր արժեքները փոքրից մեծ, 
	/// տեղադրումներով սորտավորման (insertion sort) ալգորիթմով։
	/// Դա կատարվում է միայն հանգույցների 'next' ու 'previous' ցուցիչները փոխելով։
	void insertionSortOnList()
	{
		// Իրականացնել ինքնուրույն
		//
		//
	}

	/// Համարելով որ ցուցակի հանգույցների 'next' դաշտերի ցուցիչները վնասվել են, 
	/// ֆունկցիան վերականգնում է իրենց, օգտվելով 'previous' ցուցիչներից։
	void restoreNextLinks()
	{
		// Իրականացնել ինքնուրույն
		//
		//
	}
};


int main( int argc, char* argv[] )
{
	// Ստեցծում ենք ցուցակ [14, 5, 2, 19, 23] արժեքներով։
	DL_List x;
	x.insert( x.getHeader(), 14 );
	x.insert( x.getHeader()->next, 5 );
	x.insert( x.getHeader()->next->next, 2 );
	x.insert( x.getTrailer()->previous, 19 );
	x.insert( x.getTrailer()->previous, 23 );

	// Տպում ենք
	x.printForward();   // Պետք է լինի [14, 5, 2, 19, 23]
	x.printBackward();  // Պետք է լինի [23, 19, 2, 5, 14]

	// Հեռացնում ենք '5'-ը
	x.remove( x.getHeader()->next->next );
	x.printForward();   // Պետք է լինի [14, 2, 19, 23]

	// Հեռացնում ենք '23'-ը
	x.remove( x.getTrailer()->previous );
	x.printForward();   // Պետք է լինի [14, 2, 19]

	// Բացել այս կտորը 'swapWithNext()' ֆունկցիան իրականացնելուց հետո
	/*{
		std::cout << " === swapWithNext() test === " << std::endl;
		DL_List y;
		y.insert( y.getTrailer()->previous, 29 );
		y.insert( y.getTrailer()->previous, 32 );
		y.insert( y.getTrailer()->previous, 14 );
		y.insert( y.getTrailer()->previous, 63 );
		y.printForward();   // Պետք է լինի [29, 32, 14, 63]
		y.swapWithNext( y.getHeader()->next->next );
		y.printForward();   // Պետք է լինի [29, 14, 32, 63]
	}*/

	// Բացել այս կտորը 'isPalindrome()' ֆունկցիան իրականացնելուց հետո
	/*{
		std::cout << " === isPalindrome() test === " << std::endl;
		DL_List y;
		y.insert( y.getHeader(), 24 );
		y.insert( y.getHeader(), 30 );
		y.insert( y.getHeader(), 8 );
		y.printForward();   // Պետք է լինի [8, 30, 24]
		std::cout << y.isPalindrome() << std::endl;  // Պետք է լինի 'false'
		y.insert( y.getTrailer()->previous, 30 );
		y.insert( y.getTrailer()->previous, 8 );
		y.printForward();   // Պետք է լինի [8, 30, 24, 30, 8]
		std::cout << y.isPalindrome() << std::endl;  // Պետք է լինի 'true'
	}*/

	// Բացել այս կտորը 'reverse()' ֆունկցիան իրականացնելուց հետո
	/*{
		std::cout << " === reverse() test === " << std::endl;
		DL_List y;
		y.insert( y.getTrailer()->previous, 18 );
		y.insert( y.getTrailer()->previous, 19 );
		y.insert( y.getTrailer()->previous, 2 );
		y.insert( y.getTrailer()->previous, 3 );
		y.printForward();   // Պետք է լինի [18, 19, 2, 3]
		y.reverse();
		y.printForward();   // Պետք է լինի [3, 2, 19, 18]
	}*/

	// Բացել այս կտորը 'insertionSortOnList()' ֆունկցիան իրականացնելուց հետո
	/*{
		std::cout << " === insertionSortOnList() test === " << std::endl;
		DL_List y;
		y.insert( y.getTrailer()->previous, 9 );
		y.insert( y.getTrailer()->previous, 22 );
		y.insert( y.getTrailer()->previous, 2 );
		y.insert( y.getTrailer()->previous, 8 );
		y.insert( y.getTrailer()->previous, 14 );
		y.insertionSortOnList();
		y.printForward();   // Պետք է լինի [2, 8, 9, 14, 22]
	}*/

	// Բացել այս կտորը 'restoreNextLinks()' ֆունկցիան իրականացնելուց հետո
	/*{
		std::cout << " === restoreNextLinks() test === " << std::endl;
		DL_List y;
		y.insert( y.getTrailer()->previous, 23 );
		y.insert( y.getTrailer()->previous, 18 );
		y.insert( y.getTrailer()->previous, 64 );
		y.insert( y.getTrailer()->previous, 32 );
		y.insert( y.getTrailer()->previous, 7 );
		y.insert( y.getTrailer()->previous, 6 );
		y.printForward();   // Պետք է լինի [23, 18, 64, 32, 7, 6]
		// 'Փչացնում' ենք 'next' ցուցիչների արժեքները
		for ( Node* ptr = y.getTrailer()->previous; 
				ptr != y.getHeader(); 
				ptr = ptr->previous )
			ptr->next = nullptr;
		y.printBackward();  // Պետք է լինի [6, 7, 32, 64, 18, 23]
		y.restoreNextLinks();
		y.printForward();   // Պետք է լինի [23, 18, 64, 32, 7, 6]
	}*/

	return 0;
}
