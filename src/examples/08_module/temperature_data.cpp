//temperature_data.cpp
#include "temperature_data.h"

void TemperatureData::save_temps(std::vector<Temperature>& ts)//list of temperatures
{
    std::ofstream file_out(file_name, std::ios_base::trunc);//ofstream to open, use truncate mode

    for(auto temp: ts)
    {
        file_out<<temp.get_hour();
        file_out<<" ";
        file_out<<temp.get_reading();
        file_out<<"\n";
    }

    file_out.close();//Explicitly closes file, if we forget, C++ still closes file for us
}
//^Created a file with records - We are writing to file

std::vector<Temperature> TemperatureData::get_temps()const //Reading a file
{
    std::vector<Temperature> temps;//Create a Temperature vector
    std::ifstream read_file(file_name);

    int hour;
    double reading;

    if(read_file.is_open())//If open for reading
    {
        while(read_file>>hour>>reading)//Take hour and temp
        {
            Temperature temp(hour, reading);//Add temp and hour to vector
            temps.push_back(temp);
        }
    }

    read_file.close();
    return temps;
}