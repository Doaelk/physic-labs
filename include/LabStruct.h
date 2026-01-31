#pragma once

#include "labs/IExperiment.h"

#include <memory>
#include <vector>

class LabStruct
{
private:
    std::vector<std::unique_ptr<IExperiment>> experiments;

public:
    LabStruct(LabStruct&&) noexcept = default;

    LabStruct(const LabStruct&) = delete;
    LabStruct& operator=(const LabStruct&) = delete;

    void addExperiment(std::unique_ptr<IExperiment>);

    IExperiment* operator[] (const int);

    int getQuantityExperiments();

    void caclculateLab();
};
