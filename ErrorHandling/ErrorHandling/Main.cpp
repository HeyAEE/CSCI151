#include <string>
#include <iostream>
using namespace std;
/*
Commenting all this out so I can do a helper function thing.
void sayHello(const string& name)
{
	cout << "Hello, " << name << endl;
}

void sayHelloSpanish(const string& nombre)
{
	cout << "Hola, " << nombre << endl;
}

void sayHelloFrench(const string& prenom)
{
	cout << "Bonjour, " << prenom << endl;
}
*/

string English()
{
	return "Hello";
}

string French()
{
	return "Bonjour";
}

string Spanish()
{
	return "Hola";
}
void sayHello(const string& name, string (*greetingFunction)())
{
	// string (*greetingFunction)() is a function pointer. That means the function to be used gets passed in by reference AS AN ARGUMENT.
	cout << greetingFunction() << ", " << name << endl;
}

void main()
{
	string name = "Adam";

	sayHello(name, &English);
	sayHello(name, &Spanish);
	sayHello(name, &French);
}