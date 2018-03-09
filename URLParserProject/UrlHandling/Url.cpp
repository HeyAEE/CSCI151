#include "Url.h"

#include <numeric>
#include <sstream>
#include <memory>

#include "FragmentExtractor.h"
#include "SchemeExtractor.h"
#include "LocationExtractor.h"
#include "QueryExtractor.h"
#include "PathExtractor.h"
#include "UrlFormatException.h"
using namespace std;

Url::Url(const string& url)
	: _fragmentExtractor(nullptr)
	, _schemeExtractor(nullptr)
	, _locationExtractor(nullptr)
	, _queryExtractor(nullptr)
	, _pathExtractor(nullptr)
{
	// URL should be parsed as follows
	string parsing = url;


	// 1. Check for a fragment and remove it from url if it is 
	_fragmentExtractor = make_unique<FragmentExtractor>(parsing);
	cout << "FRAGMENT: " << _fragmentExtractor->GetComponent() << endl;
	if (_fragmentExtractor->HasComponent())
		parsing = _fragmentExtractor->GetBase();

	// 2. Check for a scheme and remove it from url if it is found
	// 3. Check for a location and remove it from url if it is found
	// 4. Check for a query and remove it from url if it is found
	// 5. Only the path remains
	// 6. If a scheme was provided, but no network location, throw a UrlFormatException

	try
	{
		_schemeExtractor = make_unique<SchemeExtractor>(parsing);
		if (_schemeExtractor->HasComponent())
		{
			parsing = _schemeExtractor->GetBase();
			if (parsing.empty()) // checking if base is NULL (NULL supposedly is equivalent to false)
			{
				throw UrlFormatException::UrlFormatException("Scheme? Yes. Location? No. What the hell, man? EXITING.");
			}
			else { cout << "SCHEME: " << _schemeExtractor->GetComponent() << endl; }
		}

		_locationExtractor = make_unique<LocationExtractor>(parsing);
		if (_locationExtractor->HasComponent())
		{
			parsing = _locationExtractor->GetBase();
			cout << "LOCATION: " << _locationExtractor->GetComponent() << endl;
		}
		_queryExtractor = make_unique<QueryExtractor>(parsing);
		if (_queryExtractor->HasComponent())
		{
			parsing = _queryExtractor->GetBase();
			cout << "LOCATION: " << _queryExtractor->GetComponent() << endl;
		}

		_pathExtractor = make_unique<PathExtractor>(parsing);
		if (_pathExtractor->HasComponent())
		{
			parsing = _pathExtractor->GetBase();
			cout << "PATH: " << _pathExtractor->GetComponent();
		}
	}
	catch (const UrlFormatException& u)
	{
		cout << u.what();
	}

}

std::string Url::GetFragment() const
{
	return _fragmentExtractor->HasComponent() ? _fragmentExtractor->GetComponent() : "";
}
