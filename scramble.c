
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define ARR_LEN 7
int main(){
   
   char* names[ARR_LEN][2] = {{"groelkebj"   ,"Ben Grolke"},
			      {"migirditchbw"   ,"Ben Migirditch"},
			      {"waterscm" ,"Cody Waters"},
			      //{"biagiolist" ,"Sam Biagioli"},
			      {"migirditchsv" ,"Sam Migirditch"},
			      {"sullivanst" ,"Sam Sullivan"},
			      {"lena" ,"Nick Le"},
			      {"mancilea" ,"Ethan Mancil"}};
   int data[ARR_LEN];
   int flags[ARR_LEN];
   int cycles[ARR_LEN];
   srand(time(NULL));

   // Initalizes the arrays
   int i = 0;
   while (i < ARR_LEN){
      flags[i] = 0;
      cycles[i] = 0;
      data[i] = i;
      i++;
   }

   // Scrambles the array into a permutation group
   i = 0;
   while (i < ARR_LEN){
      int r = rand() % ARR_LEN;
      while ( flags[r] == 1 ){
	 r = rand() % ARR_LEN;
      }
      flags[r] = 1;
      data[i] = r;
      i++;
   }

   // Sends the email and logs the report in report.txt
   i = 0;
   while (i < ARR_LEN){
      char * command = malloc(400);
      //sprintf(command, "mailx -s \"Target Assignment\" %s@appstate.edu <<< \"Your target is %s. Once you succeed in elimination, ask who your target was hunting.\"", names[data[i]][0], names[data[(i+1)%ARR_LEN]][1]);
      sprintf(command, "mailx -s \"Target Assignment\" %s@appstate.edu <<< \"Your target is %s. Once you succeed in elimination, ask who your target was hunting. Remember, Turkeys are people too.\"", names[data[i]][0], "Sam Biagioli");
      //printf("%s\n",command);
      system(command);

      char * reportEntry = malloc (100);
      //sprintf(reportEntry, "%s \ttargeted %s", names[data[i]][1], names[data[(i+1)%ARR_LEN]][1]);
      sprintf(reportEntry, "%s \ttargeted %s", names[data[i]][1], "Pasta Sam");
      char * reportEntryCommand = malloc(100);
      sprintf(reportEntryCommand, "echo \"%s\" >> report.txt", reportEntry);
      system(reportEntryCommand);
      printf("%d targeted %d\n", data[i], data[(i+1) % ARR_LEN]);
      i++;
   }

   char * breaker = malloc(100);
   sprintf(breaker, "echo \"------------------\n\" >> report.txt");
   system(breaker);
   
   return 0;
}
