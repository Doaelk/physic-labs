#include "tokens/ExperimentToken.h"

#include <memory>
#include <string>

void pl::ExperimentToken::setExpirementData(std::string& key, std::string& value)
{ token[key] = std::make_shared<std::string>(value); }

const std::shared_ptr<std::string> pl::ExperimentToken::operator[](const std::string& key) const
{ return token.at(key); }

int pl::ExperimentToken::size() const
{ return token.size(); }

std::unordered_map<std::string, std::shared_ptr<std::string>>::iterator pl::ExperimentToken::begin() { return token.begin(); }
std::unordered_map<std::string, std::shared_ptr<std::string>>::iterator pl::ExperimentToken::end() { return token.end(); }
