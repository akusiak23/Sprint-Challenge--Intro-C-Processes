#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
/**
 * Main
 */
int main(int argc, char **argv)
{
  DIR *dir;
  struct dirent *rdir;
  struct stat buf;
  char *path;

  // Parse command line
  if (argc < 2)
  {
    path = ".";
  }
  else if (argc > 2)
  {
    printf("usage: ./lsls pathname\n");
    exit(1);
  }
  else
  {
    path = strtok(argv[1], " \t\n\r");
  }

  // Open directory
  dir = opendir(path);
  if (dir == NULL)
  {
    fprintf(stderr, "Cannot find directory\n");
    exit(2);
  }

  // Repeatly read and print entries
  while ((rdir = readdir(dir)) != NULL)
  {
    stat(rdir->d_name, &buf);
    if (buf.st_mode & S_IFDIR && S_ISDIR(buf.st_mode))
    {
      printf("%10s %s\n", "<DIR>", rdir->d_name);
    }
    else
    {
      printf("%10ld %s\n", buf.st_size, rdir->d_name);
    }
  }

  // Close directory
  closedir(dir);

  return 0;
}