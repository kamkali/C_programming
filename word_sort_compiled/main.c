#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "qsort.h"
#include "strsorts.h"
#define MAX_STR_SIZE 255

char *prog;
char *argv;
int comp(const void* a, const void* b)              //compare do porownywania 2 stringow
{
	char **ia=(char**)a;
	char **ib=(char**)b;
	int x=strcmp(*ia,*ib);
	if(x<=0)
        return 0;
    else
        return 1;
}

void word_sort (const char* path,int char_count, int word_count){
int i;

char **wordarray=(char**)malloc(sizeof(char*)*word_count);      //deklaracja i lokowanie pamieci dla tablicy stringow

FILE *plik;
plik = fopen((const char*) path,"r");
if (plik == NULL){   //jakby plik nie istnial
        fprintf(stderr,"%sNie udalo sie otworzyc pliku do posortowania%c\n", prog, *argv);
        //perror("Nie udalo sie otworzyc pliku do posortowania");
        exit(1);
    }
    for(i=0; i <= word_count; i++){
         wordarray[i]=(char*)malloc(MAX_STR_SIZE+1);        //lokowanie pamieci dla poszczegolnych stringow
    }
fclose(plik);

plik = fopen((const char*) path,"r");

   for(i=0; i < word_count; i++){       //zapisywanie stringow do poszczegolnych komorek tablicy stringow
         fscanf(plik, "%s", wordarray[i]);
   }

if(word_count == 0){
    printf("\nBrak wyrazow do posortwania!\n");
}

   quicksort(wordarray,0,word_count,sizeof(char*),comp);        //sortowanie alfabetyczne wyrazow uzywajac naszej funkcji

//tutaj wpisuje posortowane wyrazy do nowego pliku "filename_sort.txt"
FILE *sorted_file;
char newname[255];
sscanf(path,"%[^.]",newname);  // usuwa rozszerzenie.txt
sprintf(newname,"%s_sort.txt",newname); // dopisuje "_sort.txt" - przywraca rozszerzenie
    sorted_file = fopen(newname,"w");

  for(i=0;i<word_count;i++){            //zapisanie posortowanych slow do pliku
  fprintf(sorted_file,"%s ", wordarray[i]);
  }
fclose(plik);
fclose(sorted_file);

  for(i=0;i<word_count;i++){        //zwalnianie zalokowanej pamieci dla poszczegolnych stringow
    free(wordarray[i]);
  }
 // free (*wordarray);         //zwalnianie zalokowanej tablicy stringow
}


int main(int argc, char *argv[]) {
char *prog = argv[0]; //nazwa programu do komunikatow

    if (argc == 1){
        printf("Brak pliku do posortowania!\nSproboj ponownie podajac nazwe pliku.");
    }    //bedzie potrzebne do odaplenia pliku do sortowania z konsoli
    //char *path = "notatki.txt";
    char *path= argv[1];
auu
    int count = signcount(path);
    int count1 = linecount(path);
    int count2 = wordcount(path);

    word_sort(path,count,count2);

    return 0;
}
