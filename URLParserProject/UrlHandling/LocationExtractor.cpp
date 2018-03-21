#include "LocationExtractor.h"
#include <string>

using namespace std;

LocationExtractor::LocationExtractor(const std::string& value)
{
	// look for '//' characters
	// if exists, find index for the next '/'
	// _component = everything in between '//' and '/' (or end)
	// _base = everything including and to the right of '/', or nothing if '/' doesn't exist

	// This should get used AFTER SchemeExtractor. The argument for LocationExtractor should be SchemeExtractor::_base.
	// Example URL: http://hotdiggitydog.com/bunwithrelish?ketchup=true#vegan
	// After FragmentExtractor: http://hotdiggitydog.com/bunwithrelish?ketchup=true
	// After SchemeExtractor: //hotdiggitydog.com/bunwithrelish?ketchup=true

	/* Steps for HasComponent:
	0. Create local versions of Base and Component.
	1. Scan through string for colon.
	If has colon, create new string out of the substring from 0 to the colon with string::substr()
	Else, return false.
	2. Compare substr to the Location with string::compare (const string& str) const;
	If same, return TRUE.
	Else, return FALSE.
	*/

	LocationExtractor::_bounds[0] = value.find("//");
	LocationExtractor::_bounds[1] = value.substr(_bounds[0]+2).find("/");
	int* locationstart = &LocationExtractor::_bounds[0];
	int* locationend = &LocationExtractor::_bounds[1];
	if (*locationstart == string::npos || *locationstart == 0) // The double slashes either don't exist or they're at the beginning
	{
		if ((*locationstart + 2 != *locationend && *locationend == string::npos))
		{
			LocationExtractor::_component = value.substr(*locationstart + 2); // Clearly, there isn't a file here. Maybe there's a location though!
			LocationExtractor::_base = "";
		}
		else if (*locationstart + 2 != *locationend && *locationend > 0)
		{
			LocationExtractor::_component = value.substr(*locationstart + 2, *locationend+1); //doing *locationstart+2 so double slash is not included.
			LocationExtractor::_base = value.substr(*locationend+2);
		}
		else
		{
			LocationExtractor::_base = value.substr(*locationend); // Clearly, there isn't a location here. Maybe there's a file though!
			LocationExtractor::_component = ""; // Clearly, there isn't a location here. Maybe there's a file though!
			// This shouldn't be here. Will throw an exception if I end up with this.
		}
	}
	// NOTE: Theoretically, base should now be /bunwithrelish?ketchup=true
}

bool LocationExtractor::HasComponent() const 
{
	return !LocationExtractor::_component.empty();
}
const std::string & LocationExtractor::GetBase() const 
{
	return LocationExtractor::_base;
}
const std::string & LocationExtractor::GetComponent() const 
{
	return LocationExtractor::_component;
}