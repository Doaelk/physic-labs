#pragma once

#include "labs/ExperimentStruct.h"
#include "tokens/LabToken.h"

#include <memory>
#include <vector>

class LabStruct
{
private:
    std::vector<std::unique_ptr<ExperimentStruct>> experiments;
    std::vector<std::unique_ptr<ExperimentStruct>> calculatedExpetimets;
    std::vector<std::unique_ptr<ExperimentStruct>> errors;

public:
    LabStruct() = default;
    LabStruct(pl::LabToken&);
    LabStruct(LabStruct&&) = default;
    LabStruct& operator=(LabStruct&&) = default;

    LabStruct(const LabStruct&) = delete;
    LabStruct& operator=(const LabStruct&) = delete;

    virtual ~LabStruct() = default;

    void addExperiment(std::unique_ptr<ExperimentStruct>);

    ExperimentStruct* operator[](const int);

    int getQuantityExperiments();

    virtual void calculateLab();
    virtual void calculateError();

    virtual pl::LabToken getToken() const;
};
