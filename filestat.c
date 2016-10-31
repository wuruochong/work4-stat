#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

int filestat(char path[]){
  int fd = open(path, O_RDONLY);
  struct stat *st = malloc(sizeof(struct stat));
  stat(fd, st);
  printf("%s",st->st_mode);
}

int main(){
  filestat("test");
  return 0;
}
