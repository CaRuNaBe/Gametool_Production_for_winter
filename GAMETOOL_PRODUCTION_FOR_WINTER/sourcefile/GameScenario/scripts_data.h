//!
//! @file scripts_data.h
//!
//! @brief スクリプトの読み込み定義
//!
#pragma once

#include <tchar.h>
#include <vector>
#include <string>
#include <memory>


class ScriptsData
{
public:
	ScriptsData() = default;
	ScriptsData( const ScriptsData& ) = default;
	ScriptsData( ScriptsData&& ) noexcept = default;

	virtual ~ScriptsData() = default;

	ScriptsData& operator=( const ScriptsData& right ) = default;
	ScriptsData& operator=( ScriptsData&& right ) noexcept = default;

	bool LoadJson( std::string filepath,std::string storyname,std::string filename );
	bool WriteJson( std::string newfilename,std::string storyname );
	std::vector<std::string> GetScript( const unsigned int index ) const;
	unsigned int GetScriptNum()  const;

private:
	std::string GetScriptLine( const unsigned int index ) const;
	std::wstring ConvertUTF8ToWide( const std::string& utf8 ) const;
	std::string ConvertWideToUTF8( const std::wstring& utf16 )const;
	std::string ConvertWideToMultiByte( const std::wstring& utf16 ) const;
	std::wstring ConvertMultiByteToWide( const std::string& mbs )const;
	std::unique_ptr<std::vector<std::string>> scripts;
};

