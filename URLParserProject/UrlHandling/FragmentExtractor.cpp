#include "FragmentExtractor.h"
#include <string>

using namespace std;

FragmentExtractor::FragmentExtractor(const std::string & value)
{
//	Example URL: http://hotdiggitydog.com/bunwithrelish?ketchup=true#vegan
	// look for '#' character
	// if exists, _component = everything to the right of '#'
	// _base = everything to the left of '#', or the entire value string if '#' doesn't exist

	/* Steps for HasComponent:
	0. Create local versions of Base and Component.
	1. Scan through string for colon.
	If has colon, create new string out of the substring from 0 to the colon with string::substr()
	Else, return false.
	2. Compare substr to the Scheme with string::compare (const string& str) const;
	If same, return TRUE.
	Else, return FALSE.
	*/

	size_t index = value.find("#");
	if (index != string::npos && index > 0)
	{
		FragmentExtractor::_component = value.substr(index + 1); //doing index+1 so pound sign is not included.
		FragmentExtractor::_base = value.substr(0, index);
	}
	else
	{
		FragmentExtractor::_base = value;
		FragmentExtractor::_component = "";

	}

	// NOTE: Theoretically, base should now be http://hotdiggitydog.com/bunwithrelish?ketchup=true

}

bool FragmentExtractor::HasComponent() const
{
	/* Steps for HasComponent:
	0. Create local versions of Base and Component.
	1. Scan through string for colon.
	If has colon, create new string out of the substring from 0 to the colon with string::substr()
	Else, return false.
	2. Compare substr to the Scheme with string::compare (const string& str) const;
	If same, return TRUE.
	Else, return FALSE.
	*/

	if (FragmentExtractor::_component.empty())
	{
		return 0;
	}
	return 1;

}

const std::string & FragmentExtractor::GetBase() const
{
	return _base;
}

const std::string & FragmentExtractor::GetComponent() const
{
	return _component;
}
