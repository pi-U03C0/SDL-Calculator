#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* stradd(char* fires,char* toadd)
{
  size_t fires_len = strlen(fires);
  size_t toadd_len = strlen(toadd);

  char* return_string = (char*)malloc(fires_len+toadd_len+1);

  for (size_t i = 0 ; i < fires_len ; i++)
  {
    return_string[i] = fires[i];
  }

  for (size_t i = fires_len ; i < toadd_len+fires_len ; i++)
  {
    return_string[i] = toadd[i-fires_len];
  }

  return_string[fires_len+toadd_len] = 0;
  return return_string;
}
