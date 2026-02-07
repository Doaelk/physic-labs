#pragma once

#include <memory>
#include <string>
#include <unordered_map>

namespace pl 
{

class ExperimentToken
{
private:
    std::unordered_map<std::string, std::shared_ptr<std::string>> token;

public:
    void setExpirementData(std::string& key, std::string& value);
    const std::shared_ptr<std::string> operator[](const std::string&) const noexcept(false);
    int size() const;

    std::unordered_map<std::string, std::shared_ptr<std::string>>::iterator begin();
    std::unordered_map<std::string, std::shared_ptr<std::string>>::iterator end();
};

};
