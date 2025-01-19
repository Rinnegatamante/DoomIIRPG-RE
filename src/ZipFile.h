#ifndef __ZIPFILE_H__
#define __ZIPFILE_H__

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <stdint.h>
#include <zlib.h>

#define ZIP_LOCAL_FILE_SIG 0x04034b50
#define ZIP_CENTRAL_DIRECTORY_SIG 0x02014b50
#define ZIP_END_OF_CENTRAL_DIRECTORY_SIG 0x06054b50
#define ZIP_ENCRYPTED_FLAG 0x1

typedef struct zip_entry_s
{
#ifdef __vita__
	char name[512];
#else
	char* name;
#endif
	int offset;
	int csize, usize;
}zip_entry_t;

class ZipFile
{
private:
	int entry_count;
#ifndef __vita__
	zip_entry_t* entry;
	FILE* file;
	int page_count;
	int* page;
#else
	zip_entry_t entry[1024];
	char path[256];
#endif
public:

	// Constructor
	ZipFile();
	// Destructor
	~ZipFile();

	void findAndReadZipDir(int startoffset);
	void openZipFile(const char* name);
	void closeZipFile();
	uint8_t* readZipFileEntry(const char* name, int* sizep);
#ifdef __vita__
	void scanDir(const char *name);
#endif
};

#endif