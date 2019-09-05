#include "traverse.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>
#include <getopt.h>
#include <errno.h>

void help(void);

int main(int argc, char *argv[])
{
  extern int optopt;
  int c = 0; // variable used for getopt

  extern char* optarg;
  char* arg_v_string = argv[0];
  char* error_message = ":Error";
  char* combined_error_message = malloc( strlen(arg_v_string) + strlen(error_message) + 1);

  strcpy(combined_error_message, arg_v_string);
  strcat(combined_error_message, error_message);
  
  while ((c = getopt(argc, argv, "hILtpiugsdl:")) != -1)
  {

    switch(c)
    {
      case 'h':
        help();
        break;

      case 'I':
        break; 

      case 'L':
        break; 

      case 't':
        break; 

      case 'p':
        break; 

      case 'i':
        break; 

      case 'u':
        break; 

      case 'g':
        break; 

      case 's':
        break; 

      case 'd':
        break; 

      case 'l':
        break; 
      
      case '?':
        if(optopt == 'c')
        {
          fprintf(stderr, "Option -%c requires an argument.\n", optopt);
          help();
        }
        else if( isprint(optopt))
        {

          fprintf(stderr, "Unknown option '-%c'.\n", optopt);
          help();           
        }
        else
        {

          fprintf(stderr, "Unknown option character '\\x%x'.\n", optopt);
          return 1;
        }
       
      default:
        break;
    }
  }
  printf("Hello world\n");

  return 0;
}


void help(void)
{

  printf("---------------------------");
  printf("\t\t\n	Help Menu	|\n");
  printf("---------------------------\n");
  printf("-h   \"Print a help message and exit.\"\n");
  printf("-I n \"Change indentation to (n) spaces for each level.\"\n");
  printf("-L   \"Follow symbolic links, if any. Default will be to not follow symbolic links.\"\n");
  printf("-t   \"Print information on file type\"\n");
  printf("-p   \"Print permission bits as rwxrwxrwx\"\n");
  printf("-i   \"Print the number of links to file in inode table.\"\n");
  printf("-u   \"Print the UID associated with the file.\"\n");
  printf("-g   \"Print the GID associated with the flie\"\n");
  printf("-s   \"Print the sizze of file in bytes. \"\n");
  printf("-d   \"Show the time of last modification\"\n");
  printf("-l   \"This option prints information on the file as if tpiugs are chosen\"\n");
  printf("-----------------------\n");
 
}



