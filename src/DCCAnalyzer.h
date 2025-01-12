#ifndef DCC_ANALYZER_H
#define DCC_ANALYZER_H

#include <Analyzer.h>
#include "DCCAnalyzerSettings.h"
#include "DCCAnalyzerResults.h"
#include "DCCSimulationDataGenerator.h"
#include <memory>

class ANALYZER_EXPORT DCCAnalyzer : public Analyzer2
{
public:
	DCCAnalyzer();
	virtual ~DCCAnalyzer();

	virtual void SetupResults();
	virtual void WorkerThread();

	virtual U32 GenerateSimulationData( U64 newest_sample_requested, U32 sample_rate, SimulationChannelDescriptor** simulation_channels );
	virtual U32 GetMinimumSampleRateHz();

	virtual const char* GetAnalyzerName() const;
	virtual bool NeedsRerun();

protected: //vars
	DCCAnalyzerSettings mSettings;
	std::unique_ptr<DCCAnalyzerResults> mResults;
	AnalyzerChannelData* mSerial;

	DCCSimulationDataGenerator mSimulationDataGenerator;
	bool mSimulationInitilized;

	//Serial analysis vars:
	U32 mSampleRateHz;
	U32 mStartOfStopBitOffset;
	U32 mEndOfStopBitOffset;
};

extern "C" ANALYZER_EXPORT const char* __cdecl GetAnalyzerName();
extern "C" ANALYZER_EXPORT Analyzer* __cdecl CreateAnalyzer( );
extern "C" ANALYZER_EXPORT void __cdecl DestroyAnalyzer( Analyzer* analyzer );

#endif //DCC_ANALYZER_H
