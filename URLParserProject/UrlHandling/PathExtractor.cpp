#include "PathExtractor.h"
#include <string>
#include <vector>
#include <iostream>
#include <memory>

using namespace std;
/*
Impelement PathExtractor. 

Everything remaining is the path. Either nothing remains (path does not
exist) or something remains and it is considered the path. If the path exists and begins with a / character,
then the path is absolute. 
	If so, remove the / character and save what remains as the component.

	The path extractor also has a vector of strings to hold the path subcomponents. Much like we did
for query parameters, the path subcomponents are delimted by / characters. 
		Separate out and store each one as an individual element in the _pathComponents vector. 
				For example, if our url is example.com/path/to/file.txt?query, then the path subcomponents are:
					path,
					to,
					and file.txt. 
		Notice that the / characters are not part of the subcomponents.

		private:
		std::string _base;
		std::string _component;
		bool _isAbsolute;
		std::vector<std::string> _pathComponents;
		};

		This should get used AFTER QueryExtractor. The argument for PathExtractor should be QueryExtractor::_base.
		Example URL: http://hotdiggitydog.com/bunwithrelish?ketchup=true#vegan
		After FragmentExtractor: http://hotdiggitydog.com/bunwithrelish?ketchup=true
		After SchemeExtractor: //hotdiggitydog.com/bunwithrelish?ketchup=true
		After LocationExtractor: /bunwithrelish?ketchup=true
		After QueryExtractor: /bunwithrelish
*/


PathExtractor::PathExtractor(const string& value) {
	if (value.size() < 1) {
		_component = value;
		_base = nullptr;
		_isAbsolute = false;
		cout << "No path!" << endl;
	}
	else if (value[0] == "/"[0])
	{
		_base = "";
		_component = value.substr(1);
		_isAbsolute = true;
		PathExtractor::FindComponents(); // puts components in the _pathComponents variable;
		cout << "Path components are: " << _component << endl;
	}
	else
	{
		PathExtractor::_base = "";
		PathExtractor::_component = value;
		PathExtractor::_isAbsolute = false;
		PathExtractor::FindComponents();
		cout << "Path components are: " << _component << endl;
			
	}
	cout << "You survived PathExtractor!" << endl;
}


bool PathExtractor::HasComponent() const {
	return !PathExtractor::_component.empty();
}
const std::string& PathExtractor::GetBase() const {
	return PathExtractor::_base;
}

const std::string& PathExtractor::GetComponent() const {
	return PathExtractor::_component;
}

bool PathExtractor::IsAbsolute() const {
	return _isAbsolute; // the path is absolute
}

const std::vector<std::string>& PathExtractor::GetPathComponents() const {
	return PathExtractor::_pathComponents;
}

void PathExtractor::FindComponents()
{
	shared_ptr<string> pargs(new string(_component)); // Copying _component to make a smart pointer. Will be deleted once out of scope.
	size_t index1 = 0;
	size_t index2 = 1; // Setting the initial value to 1 so we can enter the block below.
	while (index2 >= index1)
	{
		index2 = pargs->find("/");
		if (index2 >= index1) {
			_pathComponents.push_back(pargs->substr(index1, index2 - 1)); // Doing the -1 to remove the slash
		}
		else {
			_pathComponents.push_back(pargs->substr(index1)); // This will be the final argument in the list, assuming there have been others before.
		}
		index1 = index2 + 1; // trying to get rid of the ampersand
		pargs.reset(new string(pargs->substr(index1))); // should replace the old pointer with a new pointer to a new string, the substring of the previous one.
	}
	return;
}