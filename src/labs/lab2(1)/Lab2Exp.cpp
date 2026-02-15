#include "labs/lab2(1)/Lab2Exp.h"
#include "tokens/ExperimentToken.h"
#include <memory>
#include <string>

Lab2Exp::Lab2Exp(std::shared_ptr<pl::ExperimentToken> token)
{
    U0 = std::stof((*token)["U0"]);
    U = std::stof((*token)["U"]);
    I = std::stof((*token)["I"]);
}
