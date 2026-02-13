#pragma once

#include "labs/LabStruct.h"
#include "tokens/LabToken.h"

class Lab2 : public LabStruct
{
private:
    void calcResE();
    void calcResI();
    void calcPowE();
    void calcPowI();
    void calcShCirCur();
    void calcPowZ();
    void calcK1();
    void calcK2();
    void calcSum();
    void calcEff();

public:
    explicit Lab2(pl::LabToken&);
};
