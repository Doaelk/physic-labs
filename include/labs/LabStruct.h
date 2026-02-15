#pragma once

#include "labs/ExperimentStruct.h"
#include "tokens/LabToken.h"

#include <memory>
#include <vector>

class LabStruct
{
protected:
    std::vector<std::shared_ptr<ExperimentStruct>> experiments;
    std::shared_ptr<ExperimentStruct> calculate;
    std::shared_ptr<ExperimentStruct> errors;

public:
    LabStruct() = default;
    LabStruct(LabStruct&&) = default;
    LabStruct& operator=(LabStruct&&) = default;

    LabStruct(const LabStruct&) = delete;
    LabStruct& operator=(const LabStruct&) = delete;

    ~LabStruct() = default;

    void addExperiment(std::shared_ptr<ExperimentStruct>);
    void setCalc(std::shared_ptr<ExperimentStruct>);
    void setError(std::shared_ptr<ExperimentStruct>);

    //ExperimentStruct* operator[](const int);

    int getQuantityExperiments();

    virtual void calculateLab() = 0;
    virtual void calculateData() = 0;
    virtual void calculateError() = 0;

    std::shared_ptr<pl::LabToken> getToken() const;
};
