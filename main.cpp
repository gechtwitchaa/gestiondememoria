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

 