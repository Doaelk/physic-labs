#include<iostream>
#include<fstream>
#include<format>
#include<array>
#include<cmath>

#define LEN 0.45
#define GRAV 9.8
#define PI 3.1415

struct velocityDispersion
{
    double velocityFirst;
    double velocitySecond;
    double dispersion;
};

/*class velocityDispersion
{
public:
    double velocityFirst;
    double velocitySecond;
    double dispersion;

    double averageAngle;
    double averageVelocity;
    double averageDispersion;
    
   
};*/

//---------df/f df=

double average(std::array<double, 10> data)
{
    double out = 0;
    int iteration = 0;

    for(int i = 0; i < 10; ++i)
    {
        if(!data[i])
            break;
        out += data[i];
        ++iteration;
    }

    return out/iteration;
}

double average(std::array<velocityDispersion, 10> data)
{
    double out = 0;
    int iteration = 0;

    for(int i = 0; i < 10; ++i)
    {
        if(!(data[i].velocitySecond))
            break;
        out += (data[i].velocitySecond);
        ++iteration;
    }

    return out/iteration;
}

double averageDispersion(std::array<velocityDispersion, 10> data)
{
    double out = 0;
    int iteration = 0;

    for(int i = 0; i < 5; ++i)
    {
        out += (data[i].dispersion);
        ++iteration;
    }

    return out/iteration;
}

double deltaMeasur(double averageMeasur, std::array<double, 10> measur)
{
    double out = 0;
    int counter = 0;

    for(int i = 0; i < 10; ++i)
    {
        if(!measur[i])
            break;
        out += pow(measur[i]-averageMeasur, 2);
        ++counter;
    }

    return sqrt(out/(counter*(counter-1)));
}

double BOOround(double base, int n = 2)
{
    return round(base*pow(10,n))/pow(10,n);
}

double velocity(double angle)
{
    return 2*sqrt(GRAV*LEN)*sin((angle*PI)/360);
}

double dispersion(velocityDispersion *exper)
{
    return (2*exper->velocitySecond*(exper->velocityFirst-exper->velocitySecond))
            /pow(exper->velocityFirst, 2);
}

double deltaVelocity(double angle, double accuracy)
{
    return fabs(sqrt(GRAV*LEN)*cos((angle*PI)/360))*accuracy*PI/180;
}

double deltaDispersion(double velocityFirst, double averageVelocity, double accuracy)
{
    //---------2/v0-4v/v0^2
    return fabs((2/velocityFirst)-((4*averageVelocity)/pow(velocityFirst, 2)))*accuracy;
}

int main()
{
    std::ofstream outFile ("calculatedVelocity.txt");

    if(!outFile.is_open())
    {
        std::cout << "File not opened\n";
        return 1;
    }

    std::array<std::array<double, 10>, 12> angleArray = { {
        {4, 4, 4, 4, 4.25, 3.75, 4, 4, 4.25, 3.75},
        {7.75, 8, 8, 8.25, 7.75, 8, 8, 8.25, 8, 8},
        {12.25, 12, 11.5, 12, 12, 11.75, 12.25, 12, 12, 12.25},
        {4.75, 4.5, 4.75, 5.0, 4.75}, 
        {8.0, 7.75, 7.5, 7.5, 7.75}, 
        {11.0, 11.5, 11.5, 12.0, 11.5}, 
        {4, 4.75, 4.5, 4.75, 4.25},
        {9, 9.5, 9.75, 9.25, 9.5},
        {14, 13.75, 13.75, 14.25, 14.25},
        {3.5, 3.5, 3.5, 3.5, 3.5},
        {6.5, 6.75, 6.5, 6.5, 6.25},
        {8.5, 9, 8.75, 8.75, 8.75}
    } };

    std::array<std::array<velocityDispersion, 10>, 12> calculatedDataArray;
    
    {
    constexpr std::string_view format = "{}---V0: {}\t{}---V1: {}\n";

    for(int exper = 0; exper < 12; ++exper) 
    {
        std::cout << std::format("{}----------------------------------------\n", exper+1);
        outFile << std::format("{}----------------------------------------\n", exper+1);

        for(int i = 0; i < 10; ++i)
        {
            calculatedDataArray[exper][i].velocityFirst = BOOround(velocity((exper%3+1)*5), 2);
            calculatedDataArray[exper][i].velocitySecond = BOOround(velocity(angleArray[exper][i]), 2);

            std::cout << std::format(format, (exper%3+1)*5, calculatedDataArray[exper][i].velocityFirst, angleArray[exper][i], calculatedDataArray[exper][i].velocitySecond);
            outFile << std::format(format, (exper%3+1)*5, calculatedDataArray[exper][i].velocityFirst, angleArray[exper][i], calculatedDataArray[exper][i].velocitySecond);
        }
        std::cout << std::endl;
        outFile << std::endl;
    }
    }

    outFile.close();
    outFile.open("calculatedDispersion.txt");
    if(!outFile.is_open())
    {
        std::cout << "File not opened\n";
        return 1;
    }
    
    {
    constexpr std::string_view format = "{}---b: {}\n";
    for(int exper = 0; exper < 12; ++exper)
    {
        std::cout << std::format("{}----------------------------------------\n", exper+1);
        outFile << std::format("{}----------------------------------------\n", exper+1);
        
        for(int i = 0; i < 10; ++i)
        {
            calculatedDataArray[exper][i].dispersion = BOOround(dispersion(&calculatedDataArray[exper][i]), 2);
            std::cout << std::format(format, (exper%3+1)*5, calculatedDataArray[exper][i].dispersion);
            outFile << std::format(format, (exper%3+1)*5, calculatedDataArray[exper][i].dispersion);
        }
        std::cout << std::endl;
        outFile << std::endl;
    }
    }

    outFile.close();
    outFile.open("calculatedAverageAngle.txt");
    if(!outFile.is_open())
    {
        std::cout << "File not opened\n";
        return 1;
    }

    std::cout << std::endl;

    std::array<double, 12> averageAngle;
    std::array<double, 12> deltaMeasurArray;

    {
    constexpr std::string_view format = "{0}---averag: {1}\t\t{0}---delta: {2}\n";

    for(int exper = 0; exper < 12; ++exper)
    {
        averageAngle[exper] = BOOround(average(angleArray[exper]), 2);
        deltaMeasurArray[exper] = BOOround(deltaMeasur(averageAngle[exper], angleArray[exper]), 2);
        std::cout << std::format(format, exper+1, averageAngle[exper], deltaMeasurArray[exper]);
        outFile << std::format(format, exper+1, averageAngle[exper], deltaMeasurArray[exper]);

        std::cout << std::endl;
        outFile << std::endl;
    }
    }

    std::cout << std::endl;

    std::array<double, 12> deltaVelocityArray;
    std::array<double, 12> averageVelocityArray;

    outFile.close();
    outFile.open("calculatedAverageVelocity.txt");
    if(!outFile.is_open())
    {
        std::cout << "File not opened\n";
        return 1;
    }

    {
    constexpr std::string_view format = "{0}---averag: {1}\t\t{0}---delta: {2}\n";

    for(int exper = 0; exper < 12; ++exper)
    {
        averageVelocityArray[exper] = BOOround(average(calculatedDataArray[exper]), 2);
        deltaVelocityArray[exper] = BOOround(deltaVelocity(averageAngle[exper], deltaMeasurArray[exper]), 4);
        std::cout << std::format(format, exper+1, averageVelocityArray[exper], deltaVelocityArray[exper]);
        outFile << std::format(format, exper+1, averageVelocityArray[exper], deltaVelocityArray[exper]);

        std::cout << std::endl;
        outFile << std::endl;
    }
    }
    
    std::cout << std::endl;

    std::array<double, 12> deltaDispersionArray;
    std::array<double, 12> averageDispersionArray;

    outFile.close();
    outFile.open("calculatedAverageDispersion.txt");
    if(!outFile.is_open())
    {
        std::cout << "File not opened\n";
        return 1;
    }

    {
    constexpr std::string_view format = "{0}---averag: {1}\t\t{0}---delta: {2}\n";

    for(int exper = 0; exper < 12; ++exper)
    {
        averageDispersionArray[exper] = BOOround(averageDispersion(calculatedDataArray[exper]), 2);
        deltaDispersionArray[exper] = BOOround(deltaDispersion(calculatedDataArray[exper][0].velocityFirst, averageVelocityArray[exper], deltaVelocityArray[exper]), 4);
        std::cout << std::format(format, exper+1, averageDispersionArray[exper], deltaDispersionArray[exper]);
        outFile << std::format(format, exper+1, averageDispersionArray[exper], deltaDispersionArray[exper]);

        std::cout << std::endl;
        outFile << std::endl;
    }
    }
    outFile.close();

    return 0;
}

