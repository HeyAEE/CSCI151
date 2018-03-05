#include <iostream>
using namespace std;

#include "../UrlHandling/Url.h"
#include "../UrlHandling/UrlFormatException.h"

int main(int argc, char* argv[]) try
{
	// get command line arguments
	string name = argv[0];
	vector<string> arguments;	
	for (int i = 1; i < argc; ++i)
	{
		arguments.push_back(argv[i]);
	}

	// validate command line arguments
	if (arguments.size() < 1)
	{
		cout << "Expected Use: " << name << " <url>";
		return EXIT_FAILURE;
	}

	// parse and print url details
	Url url{ arguments.at(0) };
	cout << url << endl;
	cout << "SCHEME: " << url.GetScheme() << endl;
	cout << "NETLOC: " << url.GetLocation() << endl;
	cout << "PATH: " << url.GetPath() << endl;
	cout << "QUERY: " << url.GetQuery() << endl;
	cout << "FRAGMENT: " << url.GetFragment() << endl;
}
catch (const UrlFormatException& e)
{
	cout << "ERROR (UrlFormatException): " << e.what() << endl;
	throw;
}