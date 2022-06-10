#include <windows.h>

int main()
{
    SYSTEMTIME systime;
    const char *dt="20220610164713587";
    sscanf(dt,"%04hd%02hd%02hd%02hd%02hd"
    
    FILETIME ft;
    SystemTimeToFileTime(&systime, &ft);
    LocalFileTimeToFileTime(&ft,&ft);
    
    HANDLE hFile = CreateFileA(
        argv[1],
        GENERIC_READ | GENERIC_WRITE,
        FILE_SHARE_READ| FILE_SHARE_WRITE,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL);
    if (hFile== INVALID_HANDLE_VALUE)
    {
        cout<<"打开文件失败\n";
    }
    SetFileTime(hFile, NULL, &ft1, &ft1);
    CloseHandle(hFile);
    
    return 0;
}
