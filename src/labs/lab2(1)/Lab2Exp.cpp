
#include "labs/lab2(1)/Lab2Exp.h"
#include <memory>
#include <string>

Lab2Exp::Lab2Exp(std::shared_ptr<pl::ExperimentToken> token)
{
    this->U0 = std::stof(*(*token)["U0"]);
    this->U = std::stof(*(*token)["U"]);
    this->I = std::stof(*(*token)["I"]);
}

