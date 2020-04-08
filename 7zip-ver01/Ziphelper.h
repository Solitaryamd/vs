#pragma once
#ifndef NIMO_OBS_ZLIB_H
#define NIMO_OBS_ZLIB_H
#include <iostream>
#include <string>
#include <functional>
#include "..//..//CommonFiles/bit7z/bit7z.hpp"
#include "..//..//CommonFiles/bit7z/bit7zlibrary.hpp"

class ZlibHelper {
private:
	std::string msSourcePath;
	std::string msDestDir;
	uint64_t mSize;

	typedef std::function<void(double process)> UnZipProcessCallback;
	typedef std::function<void(std::string filename)> UnZipFileCallback;
	UnZipProcessCallback upc;
	UnZipFileCallback ufc;
public:
	ZlibHelper(std::string src, std::string dest);
	~ZlibHelper();

	void Extract();											// Ω‚—π
	void SetUnZipProcessCallback(UnZipProcessCallback upc);
	void SetUnZipFileCallback(UnZipFileCallback ufc);
private:
	void GetSizeOfZipPackage();
	void ProcessCallback(uint64_t size);
	void FileCallback(std::wstring filename);
};
#endif
#pragma once
