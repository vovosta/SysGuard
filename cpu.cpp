#include <iostream>
#include <filesystem>
#include <fstream>
#include "cpu.h"
#include <vector>

CPU cpu_data(){
	CPU cpu;
	std::vector<std::filesystem::path> paths;
	// We start by getting all of the data that we need
	int count = 0; // The number of CPU
	// The data paths, number or title may changer from a computer from an other so we first have to get all of the paths and name and numbers of cores fro example
	for (const auto& entry : std::filesystem::directory_iterator("/sys/class/hwmon"))
	{
	// So here we check if it's a directory (because we don't want to count "normal" files
	if (entry.is_directory())
	    {
        	// Here we add the file paths to a vector so like that we can access it later and we add 1 to our core count for later use
		paths.push_back(entry.path());
        	count++;
	    }
	}
	cpu.count = count;
	std::cout << "Total: " << count << '\n';
	// Now we will scan an other time the file to get all of the name to after access the date that we need
	// We will use these data later to do the average of the temperatures from all of the sondes the CPU/core have
	double total_temperature;
	int total_count_temperature;
	// Here we scan the file to get every paths possible
	for (const auto& path:paths){
		// Here we will scan every hwmon in the root hwmon directory (for example we can have hwmon1, hwmon2, hwmon3 etc)
		for (const auto& entry : std::filesystem::directory_iterator(path)){
			std::string filename = entry.path().filename().string();
			// We will now check if the file if a file where is temperature, because not all files in hwmon are temperature files (there are also fan speed etc)
			if (filename.starts_with("temp") && (filename.ends_with("_input"){
				// Here we open the file
				std::ifstream file(entry.path());
				// We create the variable where we will store the temperature's value
				double temperature;
				// We store the value in 'temperature'
				file >> temperature;
				// We do this operation to get °C and M°C
				temperature /= 1000.0;
				total_count_temperature++;
				total_temparature = total_temperature + temperature;
				}	
		}
		
	}
	// Here we are calculating the average of all of the temparature values
	if (total_count_temperature > 0){
	cpu.temperature = total_temperature / total_count_temperature;
}	
	std::cout << "The average temperature of the CPU is : " << cpu.temperature << '\n';







	return cpu;
	
}










int main()
{
    CPU cpu = cpu_data();

    return 0;
}
