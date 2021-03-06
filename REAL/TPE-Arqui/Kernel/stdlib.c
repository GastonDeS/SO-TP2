// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#ifndef STD_LIB_C
#define STD_LIB_C value

#include <stdlib.h>

int atoi(char * str);
// double strToDouble(char * str);
int intToString(int num, char * buffer);
int strlen(char *str);
int strcmp(char * str1, char * str2);
int intToBase(unsigned long long num, int base, char*buffer);
int iabs(int num);

void swap(char *a, char *b)                                                                                                                                                                       
  {
       if(!a || !b)
           return;

       char temp = *(a);
       *(a) = *(b);
       *(b) = temp;
   }

void reverse(char str[], int length){
    int start = 0;
    int end = length -1;
    while (start < end)
    {
        swap((str+start), (str+end));
        start++;
        end--;
    }
}

int atoi(char * str){
  int aux = 0;
  int isNegative = 1;
  if (str[0] == '-') {
    isNegative = -1;
    str++;
  }
  while (*str!=0){
    aux = aux*10 + (*str)-'0';
    str++;
  }
  return aux * isNegative;
}

int atohex(char * str) {
  int aux = 0;
  while (*str!= 0) {
    int value = 0;
    if (*str >= '0' && *str <= '9') {
      value = *str - '0';
    } else if (*str >= 'A' && *str <= 'F') {
      value = 10 + *str - 'A';
    } else if (*str >= 'a' && *str <= 'f') {
      value = 10 + *str - 'a';
    } else {
      return -1;
    }
    str++;
    aux *= 16;
    aux += value;
  }
  return aux;
}
char toLower(char letter){
  if (letter<='Z' && letter>='A'){
    return letter+'a'-'A';
  }
  return letter;
}

char toUpper(char letter){
  if (letter<='z' && letter>='a'){
    return letter+'A'-'a';
  }
  return letter;
}

int intToBase(unsigned long long num, int base, char*buffer){
    if (num == 0) {
      buffer[0] = '0';
      buffer[1] = 0;
      return 2;
    }
    char stack[11];
    int c = 0;
    int i=0;
    int remainder = 0;
    while(num!=0){
        remainder = num % base;
        stack[i]=remainder>=10? remainder+'A'-10:remainder+'0';
        num = num/base;
        i++;
    }
    c=i;
    i--;
    while(i>=0){
        *buffer=stack[i];
        buffer++;
        i--;
    }
    *buffer=0;
    return c;
}

int iabs(int num){
  if (num < 0){
   return -num;
  }
  return num;
}


int intToString(int num, char * buffer){
    int i = 0;
    int isNegative = 0;
  
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        buffer[i++] = '0';
        buffer[i] = '\0';
        return i;
    }
  
    // In standard itoa(), negative numbers are handled only with 
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0)
    {
        isNegative = 1;
        num = -num;
    }
  
    // Process individual digits
    while (num != 0)
    {
        int rem = num % 10;
        buffer[i++] = rem + '0';
        num = num/10;
    }
  
    // If number is negative, append '-'
    if (isNegative)
        buffer[i++] = '-';
  
    buffer[i] = '\0'; // Append string terminator
  
    // Reverse the string
    reverse(buffer, i);
  
    return i;
}

int strlen(char *str){
  int i =0;
  for ( i = 0; *(str+i); i++){}
  return i;
}

int strcmp(char * str1, char * str2){
    int i =0;
    while(str1[i] != 0 && str2[i] != 0 ){
        if(str1[i] != str2[i]){
            return str1[i]-str2[i];
        }
        i++;
    }
    return str1[i]-str2[i];
}

char * strcpy(char * dest, char * src) {
  int i;
  for ( i = 0; src[i] != 0; i++) {
    dest[i] = src[i];
  }
  dest[i] = 0;
  return dest;
}

int strcat2(char * dest, int* from, int strSize, char * src){
  int j;
  for (j=0; src[j] != 0 && *from < strSize; j++, (*from)++) {
    dest[*from] = src[j];
  }
  return j;
}

void addSpace(char *dest, int* from, int strSize, int numSpace){
  int j;
  for (j=0; j < numSpace && *from < strSize; j++, (*from)++){
    dest[*from] = ' ';
  }
  return;
}

char* strCopy(char* str){
  int strSize = strlen(str);
  char *copy = (char*) malloc(sizeof(char*)*strSize);
  if (copy == NULL) return 0;
  strcpy(copy, str);
  return copy;
}

#endif
