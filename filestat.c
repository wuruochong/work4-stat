#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

int filestat(char * path){
  // int fd = open(path, O_RDONLY);
  struct stat st;
  stat(path, &st);
  printf("Filename: '%s':\n", path);
  printf("Size: %lu bytes\n", st.st_size);
  printf("Permissions: %o\n", st.st_mode);
  printf("Accessed: %s", ctime((time_t *)&st.st_atim));
}

int main(){
  filestat("test");
  return 0;
}
