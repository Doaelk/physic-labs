#include <iostream>
#include <cmath>

#include "PendulumLab.h"
#include "CalculatedDataPendulum.h"
#include "ErrorPendulum.h"

#include "OberbeckLab.h"
#include "CalculatedDataOberbeck.h"
#include "ErrorOberbeck.h"

#include "calc.h"
#include "constants.h"
#include "dataStruct.h"

#define TEST

struct Coeffs
{
    double a;
    double b;
};

void calculatePendulumLab(std::string rawData, std::string outDir)
{
    std::cout << "[Pendulum] start\n";

    dataStruct<PendulumLab> laboratory(rawData);
    {
        dataStruct<CalculatedDataPendulum> calculatedLab;
        dataStruct<ErrorPendulum> errorLab;

        Coeffs pend;

        std::vector<double> Tvec;
        std::vector<double> Lvec;


        for(int i = 0; i < laboratory.experimentsQuantity; ++i)
        {
            CalculatedDataPendulum calExp;
            calExp.calcPeriod(laboratory.experiments[i].shkaloebonen, laboratory.experiments[i].mathTime);
            calExp.calcGravity(laboratory.experiments[i].length);
            calculatedLab.addExperiment(calExp);
        }

        for(size_t i = 0; i < 4; ++i)
        {
            Tvec.push_back(pow(calculatedLab.experiments[i].period, 2));
            Lvec.push_back(laboratory.experiments[i].length);
        }

        pend.a = calcData::coeffA(Tvec, Lvec);


        calculatedLab.experiments[0].gk = 4*pow(constants::pi, 2)*pend.a;

        for(int i = 0; i < laboratory.experimentsQuantity; ++i)
        {
            ErrorPendulum errorExp;
            errorExp.calcPeriod(laboratory.experiments[i].shkaloebonen);
            errorExp.calcGravity(calculatedLab.experiments[i].period, laboratory.experiments[i].length);
            errorLab.addExperiment(errorExp);
            errorExp.calcK(calculatedLab.experiments[0].period, calculatedLab.experiments[i].period, laboratory.experiments[0].length, laboratory.experiments[i].length, errorLab.experiments[0].deltaPeriod);
            errorExp.calcGK(calculatedLab.experiments[i].k);
            errorLab.setExperiment(i, errorExp);

        }

        laboratory.writeCSV(outDir + "data.csv");
        calculatedLab.writeCSV(outDir + "MATHcalcData.csv");
        errorLab.writeCSV(outDir + "MATHerrorData.csv");

    }

    dataStruct<CalculatedDataPendulum> calculatedLab;
    dataStruct<ErrorPendulum> errorLab;

    Coeffs pends;

    std::vector<double> Tvec;
    std::vector<double> Lvec;


    for(int i = 0; i < laboratory.experimentsQuantity; ++i)
    {
        CalculatedDataPendulum calExp;
        calExp.calcAverageTime(laboratory.experiments[i].time);
        calExp.calcPeriod(laboratory.experiments[i].shkaloebonen);
        calExp.calcGravity(laboratory.experiments[i].length);
        calculatedLab.addExperiment(calExp);
    }


    Tvec.clear();
    Lvec.clear();
    for(size_t i = 0; i < 4; ++i)
    {
        Tvec.push_back(pow(calculatedLab.experiments[i].period, 2));
        Lvec.push_back(laboratory.experiments[i].length);
    }

    pends.a = calcData::coeffA(Tvec, Lvec);

    calculatedLab.experiments[0].gk = 4*pow(constants::pi, 2)*pends.a;

    for(int i = 0; i < laboratory.experimentsQuantity; ++i)
    {
        ErrorPendulum errorExp;
        errorExp.calcTime(laboratory.experiments[i].time);
        errorExp.calcPeriod(laboratory.experiments[i].shkaloebonen, errorExp.deltaTime);
        errorExp.calcGravity(calculatedLab.experiments[i].period, laboratory.experiments[i].length);
        errorLab.addExperiment(errorExp);
        errorExp.calcK(calculatedLab.experiments[0].period, calculatedLab.experiments[i].period, laboratory.experiments[0].length, laboratory.experiments[i].length, errorLab.experiments[0].deltaPeriod);
        errorExp.calcGK(calculatedLab.experiments[i].k);
        errorLab.setExperiment(i, errorExp);
    }

    calculatedLab.writeCSV(outDir + "calcData.csv");
    errorLab.writeCSV(outDir + "errorData.csv");

    std::cout << "[Pendulum] end\n";

}

void calculateOberbeckLab(std::string rawData, std::string outDir)
{
    std::cout << "[Oberbeck] start\n";

    dataStruct<OberbeckLab> laboratory(rawData);

    dataStruct<CalculatedDataOberbeck> calculatedLab;
    dataStruct<ErrorOberbeck> errorLab;

    Coeffs ober;

    std::vector<double> Kvec;
    std::vector<double> bvec;

    for(int i = 0; i < laboratory.experimentsQuantity; ++i)
    {
        CalculatedDataOberbeck calExp;
        calExp.calcAverageTime(laboratory.experiments[i].time);
        calExp.calcAcceleration(laboratory.experiments[i].height);
        calExp.calcAngleAcceleration(laboratory.experiments[i].radius);
        calExp.calcForceMoment(laboratory.experiments[i].addMass, laboratory.experiments[i].radius);
        calExp.calcInertiaMoment();
        calculatedLab.addExperiment(calExp);
    }

    for(size_t i = 0; i < 4; ++i)
    {
        Kvec.clear();
        bvec.clear();
        for(size_t j = 0; j < 4; ++j)
        {
            Kvec.push_back(calculatedLab.experiments[i*4+j].forceMoment);
            bvec.push_back(calculatedLab.experiments[i*4+j].angleAcceleration);
        }

        ober.a = calcData::coeffA(Kvec, bvec);
        ober.b = calcData::coeffB(Kvec, bvec);

        calculatedLab.experiments[i*4].frictionForce = ober.b/ober.a;
        calculatedLab.experiments[i*4].inertiaG = 1/ober.a;

    }


    for(int i = 0; i < laboratory.experimentsQuantity; ++i)
    {
        ErrorOberbeck errorExp;
        errorExp.calcTime(laboratory.experiments[i].time);
        errorExp.calcAcceleration(calculatedLab.experiments[i].averageTime, laboratory.experiments[i].height);
        errorExp.calcAngleAcceleration(calculatedLab.experiments[i].acceleration, laboratory.experiments[i].radius);
        errorExp.calcForceMoment(laboratory.experiments[i].addMass, laboratory.experiments[i].radius, calculatedLab.experiments[i].acceleration);
        errorExp.calcInertiaMoment(calculatedLab.experiments[i].forceMoment, calculatedLab.experiments[i].angleAcceleration);
        errorLab.addExperiment(errorExp);
        errorExp.calcInertiaG(calculatedLab.experiments[(i/4)*4].forceMoment, calculatedLab.experiments[i].forceMoment, calculatedLab.experiments[(i/4)*4].angleAcceleration, calculatedLab.experiments[i].angleAcceleration, calculatedLab.experiments[i].inertiaMoment);
        errorExp.calcFrictionForce(calculatedLab.experiments[i].forceMoment, calculatedLab.experiments[i].angleAcceleration, calculatedLab.experiments[i].inertiaG);
        errorLab.setExperiment(i, errorExp);
    }

    laboratory.writeCSV(outDir + "data.csv");
    calculatedLab.writeCSV(outDir + "calcData.csv");
    errorLab.writeCSV(outDir + "errorData.csv");

    std::cout << "[Oberbeck] end\n";

}

int main()
{
    calculatePendulumLab("rawData/pendulumData.csv", "calculatedData/pendulumData/");
    calculateOberbeckLab("rawData/oberbeckData.csv", "calculatedData/oberbeckData/");
}
