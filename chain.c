#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]) {

   int opt;
   int nprocs;
   int nchars;
   int sleeptime;
   int niters;
   char* textfile;

   nprocs = 4;
   nchars = 80;
   sleeptime = 3;
   niters = -1;

   while((opt = getopt(argc, argv, "hpcsi:")) != -1) {
      switch(opt) {
         case 'h':
            printf("Usage: ./chain -h -p nprocs -c nchars -s sleeptime -i niters < textfile\n");
            printf("p = number of processes (optional)\n");
            printf("c = number of characters read into buffer (optional)\n");
            printf("s = time to sleep in each iteration (optional)\n");
            printf("i = number of iterations in the loop (required)\n");
            printf("textfile = gile containing text to be read through stdin (required)\n");
            return -1;
         case 'p':
            nprocs = atoi(optarg);
            break;
         case 'c':
            nchars = atoi(optarg);
            break;
         case 's':
            sleeptime = atoi(optarg);
            break;
         case 'i':
            niters = atoi(optarg);
            break;
         default:
            printf("%s: ", argv[0]);
            perror("Error: ");
            //printf("Arguments are required\n");
            return -1;
      }
   }

   if(niters < 1) {
      printf("invalid number of iterations\n");
      return -1;
   }
   
   printf("nprocs %i nchars %i sleeptime %i niters %i\n", nprocs, nchars, sleeptime, niters);




   pid_t childpid = 0;
   int i, n;
   int k, m, j;
   //if (argc != 2) {
     // fprintf(stderr, "Usage: %s processes\n",argv[0]);
     // return 1;
   //}
   n = nprocs;
   k = niters;
   m = sleeptime;
   for (i = 1; i < n; i++)
      if ((childpid = fork()))
         break;
   
   //sleep(10);
   //perror("Error: ");

   for(j = 0; j < k; j++) {
      //sleep(m);
      //wait();
      //fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n",
         //i, (long)getpid(), (long)getppid(), (long)childpid);
      fprintf(stderr, "i:%d ", i);
      fprintf(stderr, "process ID:%ld ", (long)getpid());
      fprintf(stderr, "parent ID:%ld ", (long)getppid());
      fprintf(stderr, "child ID:%ld\n", (long)childpid);
   }
   return 0;
}



