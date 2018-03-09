#pragma once

#include "UrlComponentExtractor.h"

#include "SchemeType.h"

class SchemeExtractor : public UrlComponentExtractor {
public:
	SchemeExtractor(const std::string& scheme); // value is the scheme we're looking for. Will find somewhere to put the URL later.
	bool HasComponent() const override;
	const std::string & GetBase() const override;
	const std::string & GetComponent() const override;
	SchemeType GetType() const;
	const std::string & ToLowerCase(const std::string& phrase) const;
private:
	std::string _base;
	std::string _component;
	SchemeType _type = SchemeType::Unknown;
};