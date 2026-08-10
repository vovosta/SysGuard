#ifndef CPU_H
#define CPU_H
// Here we are creating the function that will get the CPU data

struct CPU{
	double temperature;	// To get the temperature of the CPU °C
	double usage;		// To get the percentage of the CPU usage % 
	double frequency;	// The actual frequency of the CPU (when it's asked) MHz
	double max_frequency;	// The maximum frequency for the CPU MHz
	int count; 		// The number of cores in the computer
};
#endif
