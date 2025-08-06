#ifndef PHONENUMSUB_H
#define PHONENUMSUB_H

#include <stdio.h>

void getAllSubs(char *inPhoneNum, FILE * output);
void removeDashes(char * inPhoneNum);
int wordMatchNumber(char *phoneNum, char *word, char *phoneMapping[]);








#endif
