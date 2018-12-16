#include <iostream>
#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define LIVES 9
using namespace std;

void getword ( char word []);
char getguess(void);
int checkguess (char guess, char word[], char correct[]);

void printmessage (string message, bool printTop = true, bool printbottom = true) {

    if (printTop) {

      cout << "+---------------------------------+" << endl;
      cout << "|";

    }

    else

    cout << "|";

    bool front = true;

    for (int i = message.length(); i<33; i++) {
      if (front){
        message = " " + message;
      }
      else
        message = message + " ";

        front = !front;
    }

    cout << message.c_str();

    if (printbottom) {

      cout << "|" << endl;
      cout << "+---------------------------------+" << endl;

    }
    else
    cout << "|" <<endl;




}

void DrawHangman( int guessCount = 0) {

  if (guessCount >= 1) {
    printmessage("|", false, false);
  }
  else
    printmessage("", false, false);

  if (guessCount >= 2) {
    printmessage("|", false, false);
    }
  else
    printmessage("", false, false);


if (guessCount >= 3) {
  printmessage("O", false, false);
  }
else
  printmessage("", false, false);

if (guessCount == 4) {
  printmessage("/", false, false);
  }

if (guessCount == 5) {
  printmessage("/|", false, false);
  }

if (guessCount >= 6) {
    printmessage("/|\\", false, false);
  }
else
    printmessage("", false, false);

if (guessCount >= 7) {
    printmessage("|", false, false);
      }
else
    printmessage("", false, false);

if (guessCount == 8) {
    printmessage("/", false, false);
        }

if (guessCount >= 9) {
    printmessage("/ \\", false, false);
      }

else
    printmessage("", false, false);


}


int main (void) {

  int i=0;
  int lives = LIVES;
  int man = 0;
  int flag = 0;

  printmessage ("HANG MAN");


  char word [100] ={'c'};
  char correct[100] = {'c'};

  getword(word);

  if (checkguess (getguess(), word, correct) == TRUE) {
    printf ("%s", correct);

  }
  else {
    lives--;
    printf( "ERROR, you have %d lives remaining", lives);
    man++;
    DrawHangman(man);
  }

  if (lives == 0) {
    printf("GAME OVER");
    return 0;
  }

  while (word [i] != '\0') {
    if (word[i] == correct[i]) {
      flag =TRUE;
    }
    else
      flag= FALSE;
  }

if (flag == TRUE) {
printf("YOU WIN");
return 0;
}
}






void getword ( char word []) {

  int stopper = 0;
  int flag = TRUE;

  FILE* fp = 0;

  fp = fopen ("words.txt", "r");

  while (fscanf( fp, "%s", word ) != 0 && flag == TRUE) {

    if (stopper == rand()%100) {

      flag = FALSE;

    }

  }

  int wordlen = strlen(word);

  word[wordlen] = '\0';

  fclose(fp);

}




char getguess(void) {

char guess = '0';

printf("Please enter 1 alphabet of your choice");

scanf("%c", &guess);

return guess;

}




int checkguess (char guess, char word[], char correct[]) {

  int i = 0;
  int flag = FALSE;

  while ( word [i] != '\0') {

    if (word [i] == guess) {
      correct[i] = guess;
      flag = TRUE;
    }
    else
    correct[i] = ' ';


  }

  return flag;
}
