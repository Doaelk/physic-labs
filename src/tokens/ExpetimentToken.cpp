#include "tokens/ExperimentToken.h"

#include <string>

void pl::ExperimentToken::setData(std::string& key, std::unique_ptr<std::string> value)
{ token[key] = std::move(value); }

const std::shared_ptr<std::string> pl::ExperimentToken::operator[](const std::string& key) const
{ return token.at(key); }

int pl::ExperimentToken::size() const
{ return token.size(); }
