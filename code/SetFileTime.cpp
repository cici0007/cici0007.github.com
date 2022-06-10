#include <windows.h>

int main()
{
    SYSTEMTIME sdt;
    memset(&sdt,0,sizeof(sdt));
    const char *cdt="20220610164713587";
    sscanf(cdt,"%04hd%02hd%02hd%02hd%02hd%02d%03hd",
           &sdt.wYear,&sdt.wMonth,&sdt.wDay,
           &sdt.wHour,&sdt.wMinute,&sdt.wSecond,
           &sdt.wMilliseconds);
    FILETIME ft;
    SystemTimeToFileTime(&systime, &ft);
    LocalFileTimeToFileTime(&ft,&ft);//utc+8 ---> utc
    
    const char *path = "0001.jpg";
    HANDLE hFile = CreateFileA(
        path,
        //GENERIC_READ|GENERIC_WRITE,        
        //FILE_GENERIC_READ|FILE_GENERIC_WRITE,
        FILE_WRTIE_ATTRIBUTE,//dedired write file attribute only
        NULL,NULL,OPEN_EXISTING,//open existing file only
        FILE_ATTRIBUTE_NORMAL,
        NULL);
    if (INVALID_HANDLE_VALUE==)
    {
        DWORD err = GetLastError();
        //balabala
    }
    SetFileTime(hFile,&ft,&ft,&ft1);
    CloseHandle(hFile);
    
    return 0;
}
