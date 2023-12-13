#include <stdio.h>
#include <windows.h>
#include <string.h>

#define SIZE 4096

int main() {
    HANDLE hMapFile;
    LPCTSTR pBuf;

    hMapFile = CreateFileMapping(
            INVALID_HANDLE_VALUE,
            NULL,
            PAGE_READWRITE,
            0,
            SIZE,
            TEXT("SharedMemory"));

    if (hMapFile == NULL) {
        printf("Could not create file mapping object (%d).\n", GetLastError());
        return 1;
    }

    pBuf = (LPTSTR)MapViewOfFile(hMapFile,
                                 FILE_MAP_ALL_ACCESS,
                                 0,
                                 0,
                                 SIZE);

  