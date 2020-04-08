

#include <iostream>

#include"Ziphelper.h"

//#include "E:\zip7z\bit7z\include\bitextractor.hpp"
//#include "E:\zip7z\bit7z\include\bitarchiveinfo.hpp"

using namespace bit7z;

#define MAX_FILE_PATH 100

wchar_t * char2wchar(const char* cchar)
{
	wchar_t *m_wchar;
	int len = MultiByteToWideChar(CP_ACP, 0, cchar, strlen(cchar), NULL, 0);
	m_wchar = new wchar_t[len + 1];
	MultiByteToWideChar(CP_ACP, 0, cchar, strlen(cchar), m_wchar, len);
	m_wchar[len] = '\0';
	return m_wchar;
}

void Myextract(const vector< byte_t >& indices)
{
	const byte_t* item_indices = indices.empty() ? nullptr : indices.data();
	uint32_t num_items = indices.empty() ? static_cast<uint32_t>(-1) : static_cast<uint32_t>(indices.size());

	FILE* fp_write = fopen("F:\\APP_DATA\\VS2017_data\\project\\showlog_ver01\\Debug\\tboxlog\\132.tar", "wb");
	fwrite(item_indices, sizeof(byte_t), num_items, fp_write);
	fclose(fp_write);
}


int main()
{
	try { 
		////////////////////////////important///////////////////////////////   
		Bit7zLibrary lib{ L"F:\\APP_DATA\\VS2017_data\\project\\CommonFiles\\bit7z\\7z.dll" };
		BitExtractor extractor_gz{ lib, BitFormat::GZip };
		BitExtractor extractor_tar{ lib, BitFormat::Tar };
		int index = 0;

		vector<byte_t> out_buffer;

		/**
		   * @brief Extracts a file from the given archive into the output buffer.
		   *
		   * @param in_file      the input archive file.
		   * @param out_buffer   the output buffer where the content of the archive will be put.
		   * @param index        the index of the file to be extracted from in_file.
		   */

		extractor_gz.extract(L"F:\\APP_DATA\\VS2017_data\\project\\showlog_ver01\\Debug\\tboxlog\\132.enc", out_buffer,index);
		
		Myextract(out_buffer);

		//extracting a simple archive
		extractor_tar.extract(L"F:\\APP_DATA\\VS2017_data\\project\\showlog_ver01\\Debug\\tboxlog\\132.tar", L"F:\\APP_DATA\\VS2017_data\\project\\showlog_ver01\\Debug\\tboxlog\\log");
		///////////////////////end important//////////////////////////////////////////////////////////////////

		//vector<byte_t> out_buffer;
		//int index = 0;

		//Bit7zLibrary lib{ L"F:\\VS2017_data\\project\\CommonFiles\\bit7z\\7z.dll" };
		//BitExtractor extractor{ lib, BitFormat::SevenZip };

		////extractor.setPassword(L"123456");
		////extractor.extract(L"F:/test-zip/log.7z", L"out/dir");
		//extractor.extract(L"F:/test-zip/test.7z", out_buffer, index);
		//Myextract(out_buffer);

		
	}
	catch (const BitException& ex) {
		//do something with ex.what()...
	}
}