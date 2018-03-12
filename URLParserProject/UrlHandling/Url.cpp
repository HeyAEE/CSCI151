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
	string OrigURL = url;


	// 1. Check for a fragment and remove it from url if it is 
	_fragmentExtractor = make_unique<FragmentExtractor>(parsing);
	cout << "FRAGMENT: ";
	if (_fragmentExtractor->HasComponent()) {
		cout << _fragmentExtractor->GetComponent();
		parsing = _fragmentExtractor->GetBase();
	}
	cout << endl;
//	cout << "Parsing after _fragmentExtractor: " << parsing << endl;

	// 2. Check for a scheme and remove it from url if it is found
	// 3. Check for a location and remove it from url if it is found
	// 4. Check for a query and remove it from url if it is found
	// 5. Only the path remains
	// 6. If a scheme was provided, but no network location, throw a UrlFormatException

	try
	{
		_schemeExtractor = make_unique<SchemeExtractor>(SchemeExtractor(parsing));
		if (_schemeExtractor->HasComponent())
		{
			parsing = _schemeExtractor->GetBase();
			if (parsing.empty()) // checking if base is NULL (NULL supposedly is equivalent to false)
			{
				throw UrlFormatException::UrlFormatException("Scheme? Yes. Location? No. What the hell, man? EXITING.");
			}
			else { cout << "SCHEME: " << _schemeExtractor->GetComponent() << endl; }
		}

		_locationExtractor = make_unique<LocationExtractor>(LocationExtractor(parsing));
		if (_locationExtractor->HasComponent())
		{
			parsing = _locationExtractor->GetBase();
			cout << "LOCATION: " << _locationExtractor->GetComponent() << endl;
		}
		_queryExtractor = make_unique<QueryExtractor>(QueryExtractor(parsing));
		if (_queryExtractor->HasComponent())
		{
			parsing = _queryExtractor->GetBase();
			cout << "QUERY: " << _queryExtractor->GetComponent() << endl;
		}

		_pathExtractor = make_unique<PathExtractor>(PathExtractor(parsing));
		if (_pathExtractor->HasComponent())
		{
			parsing = _pathExtractor->GetBase();
			cout << "PATH: " << _pathExtractor->GetComponent() << endl;
		}
	}
	catch (const UrlFormatException& u)
	{
		cout << u.what() << endl;;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

}


std::ostream& operator<<(ostream& out, const Url& url)
{
	// out << "URL: " << url << endl;
	out << "SCHEME: " << url._schemeExtractor->GetComponent() << endl;
	out << "PATH: " << url._pathExtractor->GetComponent() << endl;
	out << "NETLOC: " << url._locationExtractor->GetComponent() << endl;
	out << "QUERY: " << url._queryExtractor->GetComponent() << endl;
	out << "FRAGMENT: " << url._fragmentExtractor->GetComponent() << endl;
	out << "URL PIECED TOGETHER: ";
	if (url._schemeExtractor->HasComponent()) out << url._schemeExtractor->GetComponent() << "://";
	out << url._locationExtractor->GetComponent() << "/"
		<< url._pathExtractor->GetComponent() << "?"
		<< url._queryExtractor->GetComponent() << "#"
		<< url._fragmentExtractor->GetComponent();
		return out;
}

std::string Url::GetFragment() const
{
	return _fragmentExtractor->HasComponent() ? _fragmentExtractor->GetComponent() : "";
}

std::string Url::GetScheme() const
{
	return _schemeExtractor->HasComponent() ? _schemeExtractor->GetComponent() : "";
}

std::string Url::GetQuery() const
{
	return _queryExtractor->HasComponent() ? _queryExtractor->GetComponent() : "";
}

std::string Url::GetLocation() const
{
	return _locationExtractor->HasComponent() ? _locationExtractor->GetComponent() : "";
}

std::string Url::GetPath() const
{
	return _pathExtractor->HasComponent() ? _pathExtractor->GetComponent() : "";
}