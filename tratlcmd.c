#include <stdio.h>
//#include <unistd.h>
#include <string.h>
  
void inOut (char *argv[ ],int argc,char **in,char **out )
{
  for(int c=1; c < argc; c+=2)
    if(strcmp( argv[c], "-i") == 0)
      *in = argv[c+1];
    else
      *out = argv[c+1]; 
  
}
