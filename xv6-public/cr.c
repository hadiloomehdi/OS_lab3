#include "types.h"
#include "stat.h"
#include "user.h"

float stof(const char* s);
void convertFloatToString (float number, char* stringNumber);

int main(int argc, char *argv[])
{

	int pid;
    float R ;

	if(argc != 3)
		printf(1, "inappropriate arguments\n");
	else
	{
        R = stof(argv[2]);
        char a[10] ;
        convertFloatToString(R,a); 
        pid = atoi(argv[1]);
        changeR(pid,a);
		// printf(1, "R of procrss %d is %s    \n", pid, a);
	}
	exit();
}




float stof(const char* s){
  float rez = 0, fact = 1;
  if (*s == '-'){
    s++;
    fact = -1;
  };
  for (int point_seen = 0; *s; s++){
    if (*s == '.'){
      point_seen = 1; 
      continue;
    };
    int d = *s - '0';
    if (d >= 0 && d <= 9){
      if (point_seen) fact /= 10.0f;
      rez = rez * 10.0f + (float)d;
    };
  };
  return rez * fact;
};



void convertFloatToString (float number, char* stringNumber) {
  int integerPart = number, powerNumber = 1;
  int intSize = 0;
  int stringIndex = 0;
  number = number - integerPart;
  for (int i = 0; ; i++) {
    if (integerPart < powerNumber)
      break;
    else {
      intSize++;
      powerNumber *= 10;
    }
  }

  if (intSize == 0)
    stringNumber[stringIndex++] = '0';
  for (int i = 0; i < intSize; i++) {
    powerNumber = powerNumber / 10;
    stringNumber[stringIndex++] = (int)(integerPart / powerNumber) + '0';
    integerPart = integerPart - ((int)(integerPart / powerNumber)) * powerNumber;
  }
  if (number == 0) {
    stringNumber[stringIndex++] = '\0';
    return;
  }
  stringNumber[stringIndex++] = '.';
  for (int i = 0 ; i < 2; i++) {
    if (number == 0)
      break;
    number = number * 10;
    integerPart = number;
    stringNumber[stringIndex++] = (int)(integerPart) + '0';
    number = number - integerPart;
  }
  stringNumber[stringIndex++] = 0;
  return;
}
