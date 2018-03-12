#include "SchemeExtractor.h"
#include <iostream>
#include <string>

using namespace std;

SchemeExtractor::SchemeExtractor(const std::string& value)
{
	// look for ':' character
	// if exists, _component = everything to the left of ':'
	// _base = everything to the right of ':', or the entire value string if ':' doesn't exist

	// This should get used AFTER FragmentExtractor. The argument for SchemeExtractor should be FragmentExtractor::_base.
	// Example URL: http://hotdiggitydog.com/bunwithrelish?ketchup=true#vegan
	// After FragmentExtractor: http://hotdiggitydog.com/bunwithrelish?ketchup=true

	/* Steps for HasComponent:
	0. Create local versions of Base and Component.
	1. Scan through string for colon.
	If has colon, create new string out of the substring from 0 to the colon with string::substr()
	Else, return false.
	2. Compare substr to the Scheme with string::compare (const string& str) const;
	If same, return TRUE.
	Else, return FALSE.
	*/

	size_t index = value.find(":");
	if (index != string::npos && index > 0)
	{
		SchemeExtractor::_base = value.substr(index + 1); //doing index+1 so pound sign is not included.
		SchemeExtractor::_component = value.substr(0, index);
		ToLowerCase(SchemeExtractor::_component);
	//	cout << SchemeExtractor::_component << endl;
		if (SchemeExtractor::_component == "http" || SchemeExtractor::_component == "https") {
			_type = SchemeType::Net;
		}
		else if (SchemeExtractor::_component == "file")
		{
			_type = SchemeType::Local;
		}
		else
		{
			_type = SchemeType::Unknown;
		}

	}
	else
	{
		SchemeExtractor::_base = value;
		SchemeExtractor::_component = "";
		SchemeExtractor::_type = SchemeType::Unknown;
	}
	// NOTE: Theoretically, base should now be //hotdiggitydog.com/bunwithrelish?ketchup=true
}

const string &SchemeExtractor::GetBase() const
{
	return SchemeExtractor::_base;
}

const string &SchemeExtractor::GetComponent() const
{
	return SchemeExtractor::_component;
}

bool SchemeExtractor::HasComponent() const
{
	if (SchemeExtractor::_component.empty())
	{
		return 0;
	}
	return 1;
}

void SchemeExtractor::ToLowerCase(string &phrase) {
	// string lc = "";
//	cout << "SchemeExtractor Phrase before: " << phrase << endl;
	for (int i = 0; i < phrase.size(); i++)
	{
		phrase[i] = tolower(phrase[i]);
	}
//	cout << "SchemeExtractor Phrase after: " << phrase << endl;
}