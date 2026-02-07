
#include "LabFactory.h"
#include "labs/LabStruct.h"
#include <memory>
#include <stdexcept>

std::unique_ptr<LabStruct> LabFactory::create(const LabType type, const pl::LabToken &token)
{
    switch (type)
    {
        default:
            throw std::runtime_error("Unknown lab type");
    }
}
