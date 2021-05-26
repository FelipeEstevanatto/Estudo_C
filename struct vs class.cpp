/* C struct vs C++ class
Struct: customized, composite data type, which may be constructed from the existing built-in data types [int, char, etc.], bit fields [integers of specified bit size]
and other structs.

Class: can also contain functions called methods, The member variables and methods are hidden from the outside world, unless their declaration follows a public label,
There can be a pair of special methods – the constructor and destructor – that are run automatically when an instance of the class [an object] is created and destroyed.
Operators to work on the new data type can be defined using special methods [member functions].
One class can be used as the basis for the definition of another [inheritance].
Declaring a variable of the new type [an instance of the class; an object] requires just the name of the class – the keyword class is not required.]

C++ struct vs C++ class
 only difference between a struct and class in C++ is the default accessibility of member variables and methods. In a struct they are public; in a class they
 are private.

https://stackoverflow.com/questions/2750270/c-c-struct-vs-class
*/

#include <iostream>

using namespace std;

int main(){
	
	class myclass
	{
		char a;
		int b;
	public:
		
	};
	
	struct mystruct
	{
		char a;
		int b;
	};
	
	struct mystruct var;
	
	var.b=14;
	
	
	cout << "teste =" << var.b;
	return 0;
}