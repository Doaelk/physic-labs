#pragma once

#include "labs/ExperimentStruct.h"
#include "tokens/LabToken.h"

#include <memory>
#include <vector>

class LabStruct
{
protected:
    std::vector<std::shared_ptr<ExperimentStruct>> experiments;
    std::vector<std::shared_ptr<ExperimentStruct>> errors;

public:
    LabStruct() = default;
    LabStruct(LabStruct&&) = default;
    LabStruct& operator=(LabStruct&&) = default;

    LabStruct(const LabStruct&) = delete;
    LabStruct& operator=(const LabStruct&) = delete;

    virtual ~LabStruct() = default;

    void addExperiment(std::shared_ptr<ExperimentStruct>);
    void addError(std::shared_ptr<ExperimentStruct>);

    //ExperimentStruct* operator[](const int);

    int getQuantityExperiments();

    void calculateLab();
    virtual void calculateError();

    virtual pl::LabToken getToken() const;
};
