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
	if (_fragmentExtractor->HasComponent())
		parsing = _fragmentExtractor->GetBase();

	// 2. Check for a scheme and remove it from url if it is found
	// 3. Check for a lication and remove it from url if it is found
	// 4. Check for a query and remove it from url if it is found
	// 5. Only the path remains
	// 6. If a scheme was provided, but no network location, throw a UrlFormatException

	_schemeExtractor = make_unique<SchemeExtractor>(parsing);
	_locationExtractor = make_unique<LocationExtractor>(parsing);
	_queryExtractor = make_unique<QueryExtractor>(parsing);
	_pathExtractor = make_unique<PathExtractor>(parsing);
}

std::string Url::GetFragment() const
{
	return _fragmentExtractor->HasComponent() ? _fragmentExtractor->GetComponent() : "";
}
