#ifndef DCC_SIMULATION_DATA_GENERATOR
#define DCC_SIMULATION_DATA_GENERATOR

#include <SimulationChannelDescriptor.h>
#include <string>
class DCCAnalyzerSettings;

class DCCSimulationDataGenerator
{
public:
	DCCSimulationDataGenerator();
	~DCCSimulationDataGenerator();

	void Initialize( U32 simulation_sample_rate, DCCAnalyzerSettings* settings );
	U32 GenerateSimulationData( U64 newest_sample_requested, U32 sample_rate, SimulationChannelDescriptor** simulation_channel );

protected:
	DCCAnalyzerSettings* mSettings;
	U32 mSimulationSampleRateHz;

protected:
	void CreateSerialByte();
	std::string mSerialText;
	U32 mStringIndex;

	SimulationChannelDescriptor mSerialSimulationData;

};
#endif //DCC_SIMULATION_DATA_GENERATOR