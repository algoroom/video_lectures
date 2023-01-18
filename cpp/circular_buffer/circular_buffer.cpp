
#include <iostream>


/// Այս դասը իրենից ներկայացնում է Շրջանաձև Բուֆերի համառոտ իրականացում։
class CircularBuffer
{
private:
	/// Շրջանաձև բուֆերի զանգվածի չափսը՝ իր տարողությունը։
	static const int CAP = 8;

	/// Շրջանաձև բուֆերի տվյալների տարածքը՝ զանգվածը։
	int data[ CAP ];

	/// Զանգվածի այն ինդեքսը, որտեղից "սկսվում են" տվյալները։
	int begin;

	/// Զանգվածի այն ինդեքսը, որտեղ "ավարտվում են" տվյալները։
	int end;

public:
	/// Կոնստրուկտոր
	/// Ստեղծում է դատարկ բուֆեր։
	CircularBuffer()
		: begin( 0 ), end( 0 )
		{}

	/// Ֆունկցիան ավելացնում է բուֆերի մեջ 'x' արժեքը։
	void push( int x )
	{
		data[ end++ ] = x;
		// Ստուգում ենք, արդյո՞ք կարիք կա ինդեքսը զրոյացնելու
		if ( end == CAP )
			end = 0;
	}

	/// Ֆունկցիան հեռացնում է բուֆերի միջից ամենահին արժեքը։
	void pop()
	{
		if ( begin == end )
			return;  // Բուֆերը արդեն դատարկ է
		++begin;
		// Ստուգում ենք, արդյո՞ք կարիք կա ինդեքսը զրոյացնելու
		if ( begin == CAP )
			begin = 0;
	}

	/// Ֆունկցիան վերադարձնում է այս պահին բուֆերում առկա արժեքների քանակը։
	int size() const
	{
		if ( begin <= end ) {
			// Բուֆերը "նորմալ" վիճակում է
			return end - begin;
		}
		else {
			// Բուֆերը "շրջված" վիճակում է
			return end + CAP - begin;
		}
	}

	/// Ֆունկցիան վերադարձնում է բուֆերի միջի 'i' տեղում եղած արժեքը, եթե 
	/// հաշվենք ամենահին տեղադրված արժեքից։
	/// i-ի համարակալումը սկսվում է 0-ից։
	int at( int i ) const
	{
		if ( begin + i < CAP ) {
			// Շրջվելու կարիք չկա
			return data[ begin + i ];
		}
		else {
			// Արժեքը գտնելու համար պետք է "նայել" սկզբից
			return data[ begin + i - CAP ];
		}
	}

	/// Ֆունկցիան տպում է բուֆերի բոլոր արժեքները՝ ամենահնից մինչև ամենանորը։
	void print() const
	{
		// Իրականացնել ինքնուրույն
		//
		//
	}

	friend bool areEqual( const CircularBuffer& cb1, const CircularBuffer& cb2 );
};


/// Ֆունկցիան ստուգում է, արդյո՞ք տրված երկու շրջանաձև բուֆերների պարունակությունը 
/// համընկնում է, եթե կարդալ ամենահին արժեքներից մինչև ամենանորերը։
bool areEqual( const CircularBuffer& cb1, const CircularBuffer& cb2 )
{
	// Իրականացնել ինքնուրույն
	//
	//
	return false;
}


int main( int argc, char* argv[] )
{
	CircularBuffer cb;

	// Ավելացնում ենք արժեքներ
	std::cout << " === Pushing values === " << std::endl;
	cb.push( 4 );
	cb.push( 7 );
	cb.push( 2 );
	cb.push( 12 );
	cb.push( 8 );

	// Ստուգում ենք պարունակությունը
	std::cout << "Size is equal to " << cb.size() << std::endl;
	std::cout << "Value at index 0 is " << cb.at( 0 ) << std::endl;
	std::cout << "Value at index 1 is " << cb.at( 1 ) << std::endl;
	std::cout << "Value at index 3 is " << cb.at( 3 ) << std::endl;

	// Հեռացնում ենք որոշ արժեքներ
	std::cout << " === Popping values === " << std::endl;
	cb.pop();
	cb.pop();

	// Ստուգում ենք պարունակությունը
	std::cout << "Size is equal to " << cb.size() << std::endl;
	std::cout << "Value at index 0 is " << cb.at( 0 ) << std::endl;
	std::cout << "Value at index 1 is " << cb.at( 1 ) << std::endl;
	std::cout << "Value at index 2 is " << cb.at( 2 ) << std::endl;

	std::cout << " === Pushing values again === " << std::endl;
	// Կրկին ավելացնում ենք արժեքներ
	cb.push( 20 );
	cb.push( 18 );
	cb.push( 39 );
	cb.push( 1 );

	// Կրկին ստուգում ենք պարունակությունը
	std::cout << "Size is equal to " << cb.size() << std::endl;
	std::cout << "Value at index 0 is " << cb.at( 0 ) << std::endl;
	std::cout << "Value at index 1 is " << cb.at( 1 ) << std::endl;
	std::cout << "Value at index 2 is " << cb.at( 2 ) << std::endl;
	std::cout << "Value at index 5 is " << cb.at( 5 ) << std::endl;
	std::cout << "Value at index 6 is " << cb.at( 6 ) << std::endl;

	// Բացել այս կտորը "print()" մեթոդը իրականացնելուց հետո
	/* std::cout << " === Printing content === " << std::endl;
	cb.print();           // Պետք է լինի [2, 12, 8, 20, 18, 39, 1]
	cb.pop();
	cb.pop();
	cb.pop();
	cb.print();           // Պետք է լինի [20, 18, 39, 1]
	cb.push( 11 );
	cb.push( 38 );
	cb.print(); */           // Պետք է լինի [20, 18, 39, 1, 11, 38]

	// Բացել այս կտորը "areEqual()" գլոբալ ֆունկցիան իրականացնելուց հետո
	/* {
		std::cout << " === Testing for same content === " << std::endl;

		CircularBuffer cb1;
		cb1.push( 4 );
		cb1.push( 5 );
		cb1.push( 6 );

		CircularBuffer cb2;
		cb2.push( 1 );
		cb2.push( 2 );
		cb2.push( 4 );

		std::cout << "   is content same: " << areEqual( cb1, cb2 ) << std::endl;
				// պետք է լինի 'false'

		cb2.pop();
		cb2.pop();
		cb2.push( 5 );
		cb2.push( 6 );

		std::cout << "   is content same: " << areEqual( cb1, cb2 ) << std::endl;
				// պետք է լինի 'true'

		cb1.pop();
		cb1.pop();

		std::cout << "   is content same: " << areEqual( cb1, cb2 ) << std::endl;
				// պետք է լինի 'false'
	} */

	return 0;
}
