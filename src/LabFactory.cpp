#include <memory>
#include <stdexcept>

#include "LabFactory.h"
#include "labs/LabStruct.h"
#include "labs/lab2(1)/Lab2.h"

std::shared_ptr<LabStruct> LabFactory::create(const LabType type, std::shared_ptr<pl::LabToken> token)
{
    switch (type)
    {
        case LabType::LAB1:
            break;

        case LabType::LAB2:
            return std::make_shared<Lab2>(token);
            
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
