#include <iostream>
#include <filesystem>
#include <fstream>
#include "cpu.h"

CPU cpu_data(){
	CPU cpu;
	// We start by getting all of the date that we need
	int count = 0;
	// The data paths, number or title may changer from a computer from an other so we first have to get all of the paths and name and numbers of cores fro example
	for (const auto& entry : std::filesystem::directory_iterator("/sys/class/hwmon"))
	{
	// So here we check if it's a directory (because we don't want to count "normal" files
	if (entry.is_directory())
	    {
        	// Here we print the file path and add 1 to our core count for later use
		std::cout << entry.path() << '\n';
        	count++;
	    }
	}
	// Here we print the total number of cores in the computer/phone/whatever
	cpu.count = count;
	std::cout << "Total: " << count << '\n';
	return cpu;
}
int main()
{
    CPU cpu = cpu_data();

    return 0;
}
