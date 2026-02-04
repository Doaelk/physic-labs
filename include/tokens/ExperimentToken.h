#pragma once

#include <memory>
#include <string>
#include <unordered_map>

//FIX ME 
//add return refferences
namespace pl 
{

class ExperimentToken
{
private:
    std::unordered_map<std::string, std::shared_ptr<std::string>> token;

public:
    void setData(std::string& key, std::unique_ptr<std::string> value);
    const std::shared_ptr<std::string> operator[](const std::string&) const noexcept(false);
    int size() const;

};

};
