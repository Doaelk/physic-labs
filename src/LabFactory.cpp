#include <memory>
#include <stdexcept>

#include "LabFactory.h"
#include "labs/LabStruct.h"
#include "labs/lab2(1)/Lab2.h"

std::unique_ptr<LabStruct> LabFactory::create(const LabType type, pl::LabToken &token)
{
    switch (type)
    {
        case LabType::LAB1:
            break;

        case LabType::LAB2:
            return std::make_unique<Lab2>(token);
            
        case LabType::LAB3:
            break;

        case LabType::LAB4:
            break;

        case LabType::LAB5:
            break;
            
        default:
            throw std::runtime_error("Unknown lab type");
    }
}
