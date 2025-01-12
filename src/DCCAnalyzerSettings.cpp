#include "DCCAnalyzerSettings.h"
#include <AnalyzerHelpers.h>


DCCAnalyzerSettings::DCCAnalyzerSettings()
:	mInputChannel( UNDEFINED_CHANNEL ),
	mBitRate( 9600 ),
	mInputChannelInterface(),
	mBitRateInterface()
{
	mInputChannelInterface.SetTitleAndTooltip( "Serial", "Standard DCC" );
	mInputChannelInterface.SetChannel( mInputChannel );

	mBitRateInterface.SetTitleAndTooltip( "Bit Rate (Bits/S)",  "Specify the bit rate in bits per second." );
	mBitRateInterface.SetMax( 6000000 );
	mBitRateInterface.SetMin( 1 );
	mBitRateInterface.SetInteger( mBitRate );

	AddInterface( &mInputChannelInterface );
	AddInterface( &mBitRateInterface );

	AddExportOption( 0, "Export as text/csv file" );
	AddExportExtension( 0, "text", "txt" );
	AddExportExtension( 0, "csv", "csv" );

	ClearChannels();
	AddChannel( mInputChannel, "Serial", false );
}

DCCAnalyzerSettings::~DCCAnalyzerSettings()
{
}

bool DCCAnalyzerSettings::SetSettingsFromInterfaces()
{
	mInputChannel = mInputChannelInterface.GetChannel();
	mBitRate = mBitRateInterface.GetInteger();

	ClearChannels();
	AddChannel( mInputChannel, "DCC", true );

	return true;
}

void DCCAnalyzerSettings::UpdateInterfacesFromSettings()
{
	mInputChannelInterface.SetChannel( mInputChannel );
	mBitRateInterface.SetInteger( mBitRate );
}

void DCCAnalyzerSettings::LoadSettings( const char* settings )
{
	SimpleArchive text_archive;
	text_archive.SetString( settings );

	text_archive >> mInputChannel;
	text_archive >> mBitRate;

	ClearChannels();
	AddChannel( mInputChannel, "DCC", true );

	UpdateInterfacesFromSettings();
}

const char* DCCAnalyzerSettings::SaveSettings()
{
	SimpleArchive text_archive;

	text_archive << mInputChannel;
	text_archive << mBitRate;

	return SetReturnString( text_archive.GetString() );
}
