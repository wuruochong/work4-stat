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
  long b = st.st_size;
  long kb = b/1024;
  long mb = kb/1024;
  long gb = mb/1024;
  printf("Size: ", st.st_size);
  char p = 0;
  if (gb>1 && !p){
    printf("%lugb\n", gb);
    p=1;
  }
  if (mb>1 && !p){
    printf("%lumb\n", mb);
    p=1;
  }
  if (kb>1 && !p){
    printf("%lukb\n", kb);
    p=1;
  }
  else{
    printf("%lub\n",b);
    p=1;
  }
  printf("Permissions: %o\n", st.st_mode);
  printf("Readable Mode: ");
  int mode = st.st_mode;
  int i = 0;
  if (mode & S_IRUSR){
    printf("r");
  }
  else{
    printf("-");
  }
  if (mode & S_IWUSR){
    printf("w");
  }
  else{
    printf("-");
  }
  if (mode & S_IXUSR){
    printf("x");
  }
  else{
    printf("-");
  }
  if (mode & S_IRGRP){
    printf("r");
  }
  else{
    printf("-");
  }
  if (mode & S_IWGRP){
    printf("w");
  }
  else{
    printf("-");
  }
  if (mode & S_IXGRP){
    printf("x");
  }
  else{
    printf("-");
  }
  if (mode & S_IROTH){
    printf("r");
  }
  else{
    printf("-");
  }
  if (mode & S_IWOTH){
    printf("w");
  }
  else{
    printf("-");
  }
  if (mode & S_IXOTH){
    printf("x");
  }
  else{
    printf("-");
  }
  printf("\n");
  printf("Accessed: %s", ctime((time_t *)&st.st_atim));
}

int main(){
  filestat("test");
  return 0;
}
