#include <string>

#include "tokens/ExperimentToken.h"

void pl::ExperimentToken::setExperimentData(std::string key, std::string value)
{ 
    token[std::move(key)] = std::move(value); 
}

std::string pl::ExperimentToken::operator[](const std::string& key) const
{ return token.at(key); }

int pl::ExperimentToken::size() const
{ return token.size(); }

std::unordered_map<std::string, std::string>::iterator pl::ExperimentToken::begin() 
{ return token.begin(); }

std::unordered_map<std::string, std::string>::iterator pl::ExperimentToken::end() 
{ return token.end(); }
