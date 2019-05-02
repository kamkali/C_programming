#ifndef _STRSORT_H
#define _STRSORT_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "strsorts.h"

#define MAX_STR_SIZE 255

int signcount(char *path);
int linecount(char *path);
int wordcount(const char *path);


char *prog;
char *argv;
int signcount(char *path){
    int count=0;
    FILE *plik;
    plik = fopen((const char*)path,"r");
    if (plik == NULL){//jakby plik nie istnial
        fprintf(stderr,"%sNie udalo sie otworzyc pliku!%c\n", prog, *argv);
        exit(1);
    }
    getc(plik);
    while(!feof(plik)){
        count++;
        getc(plik);
    }

    fclose(plik);
    return count;
}

int linecount(char *path){
    long count1=1;
    FILE *plik;
    plik = fopen((const char*)path,"r");
    if (plik == NULL){   //jakby plik nie istnial
        fprintf(stderr,"%sNie udalo sie otworzyc pliku!%c\n", prog, *argv);
        exit(1);
    }

    while(!feof(plik)){
        switch(getc(plik)){
            case 10:
                count1++;
                break;
        }
    }
    fclose(plik);
    return count1;
}

int wordcount(const char *path){
    int ch;
    int state;
    int in,out;
    int count2=0;
    FILE *plik;
    plik = fopen((const char*)path,"r");

    if (plik == NULL){   //jakby plik nie istnial
        fprintf(stderr,"%sNie udalo sie otworzyc pliku!%c\n", prog, *argv);
        exit(1);
    }

    state = out;

    while ((ch = fgetc(plik)) != EOF){      //zliczanie slow
        if (!isalnum(ch))
            state = out;
        else if (state == out){
            state = in;
            ++count2;
        }
    }
    fclose(plik);
    return count2;
}

#endif
