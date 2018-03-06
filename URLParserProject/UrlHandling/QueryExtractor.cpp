#include "QueryExtractor.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;
/* Implement QueryExtractor. 

Search the string for a ? character. If found then the query component is
everything following that character. Remove the ? character and everything remaining (everything
before it) becomes the base. It is possible to have an empty query string (ex: http://example.com/path?).
In this case, the query still exists, but the value of the component is an empty string.
Once you have the query, you can parse the query parameters. Inside of the query component,
the query parameters are delimeted by a & character. A query (if it exists and is not an empty
string) will have one or more parameters. For example the query string (www.example.com/path?
this=true&that=false) has two parameters: this=true, followed by that=false. The & characters
are not part of the parameters, so my query parameters vector should have two strings, one for
each parameter noted above.
*/

/* My notes:
	This should get used AFTER LocationExtractor. The argument for LocationExtractor should be SchemeExtractor::_base.
	Example URL: http://hotdiggitydog.com/bunwithrelish?ketchup=true#vegan
	After FragmentExtractor: http://hotdiggitydog.com/bunwithrelish?ketchup=true
	After SchemeExtractor: //hotdiggitydog.com/bunwithrelish?ketchup=true
	After LocationExtractor: /bunwithrelish?ketchup=true

	First have to get whatever is to the right of the question mark. 

	Next, will recursively extract strings from the query with a breakpoint at the ampersands.

*/

QueryExtractor::QueryExtractor(const std::string& value) {
	size_t index = value.find("?");
	_base = value.substr(0, index-1); // Everything before the question mark, which is why "index - 1"
	_component = value.substr(index + 1); // Everything after the question mark.
	FindParameters();
	// Printing parameters just to see that I've gotten em.
	cout << "Parameters are: ";
	for (auto i = _parameters.begin(); i != _parameters.end(); ++i) {
		cout << *i;
	}
	cout << endl;

	// After QueryExtractor, _base should be /bunwithrelish
}

void QueryExtractor::FindParameters()
{
	shared_ptr<string> pargs(new string(_component)); // Copying _component to make a smart pointer. Will be deleted once out of scope.
	size_t index1 = 0;
	size_t index2 = 1; // Setting the initial value to 1 so we can enter the block below.
	while (index2 >= index1)
	{
		index2 = pargs->find("&");
		if (index2 >= index1) {
			_parameters.push_back(pargs->substr(index1, index2 - 1)); // Doing the -1 to remove the ampersand
		}
		else {
			_parameters.push_back(pargs->substr(index1)); // This will be the final argument in the list, assuming there have been others before.
		}
		index1 = index2 + 1; // trying to get rid of the ampersand
		pargs.reset(new string(pargs->substr(index1))); // should replace the old pointer with a new pointer to a new string, the substring of the previous one.
		// If you reach the end of the string... index2 will be -1... shit, this won't accept the last argument.
	}
	return;
}

const std::vector<std::string>& QueryExtractor::GetQueryParameters() const
{
	return _parameters;
}

bool QueryExtractor::HasComponent() const {
	return !GetComponent().empty();
}
const std::string & QueryExtractor::GetBase() const {
	return _base;
}
const std::string & QueryExtractor::GetComponent() const {
	return _component;
}