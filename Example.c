#include <stdio.h>
#include <unistd.h>
#include "Directory.h"
#include "File.h"


int main(void)
{
  size_t ulDirLen = 0;
  char *pDir = DirPathBufAlloc(&ulDirLen);
  printf("ulDirLen is [%lu]\n", ulDirLen);
  getcwd(pDir, ulDirLen);

  printf("pDir is [%s], ulDirLen is [%lu]\n",pDir, ulDirLen);

  printf("GetBestFileBuf() is [%u]\n", GetBestFileBuf(NULL));
  printf("GetBestFileBuf(./test) is [%u]\n", GetBestFileBuf("./test"));
  printf("GetBestFileBuf(./TestDir) is [%u]\n", GetBestFileBuf("./TestDir"));



  return 0;
}
