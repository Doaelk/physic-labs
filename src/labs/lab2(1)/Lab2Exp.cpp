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

std::shared_ptr<pl::ExperimentToken> Lab2Exp::getToken() const
{
    pl::ExperimentToken out;

    out.setExperimentData("I", std::to_string(I));
    out.setExperimentData("U", std::to_string(U));

    return std::make_shared<pl::ExperimentToken>(out);
}
