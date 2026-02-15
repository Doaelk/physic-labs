#pragma once

#include <memory>
#include <string>
#include <unordered_map>

namespace pl 
{

class ExperimentToken
{
private:
    std::unordered_map<std::string, std::string> token;

public:
    void setExperimentData(std::string key, std::string value);

    void addExperimentData(std::shared_ptr<ExperimentToken>);

    std::string operator[](const std::string&) const noexcept(false);
    int size() const;

    std::unordered_map<std::string, std::string>::iterator begin();
    std::unordered_map<std::string, std::string>::iterator end();
};

};
