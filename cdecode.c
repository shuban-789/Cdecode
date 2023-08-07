#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void docs(void);

struct cipherkey
{
  int key;
} ciphersolvekey;

char* caesar(int key, char ciphertext[])
{
  int lenstr = strlen(ciphertext);
  char* res = malloc((lenstr + 1) * sizeof(char));
  for (int i = 0; i < lenstr; i++)
  {
        if (ciphertext[i] >= 65 && ciphertext[i] <= 90)
        {
            if (ciphertext[i] - key >= 65) {
                res[i] = ciphertext[i] - key;
            } else {
                res[i] = ((ciphertext[i] - key - 65 + 26) % 26) + 65;
            }
        } 
        else if (ciphertext[i] >= 97 && ciphertext[i] <= 122)
        {
            if (ciphertext[i] - key >= 97)
            {
                res[i] = ciphertext[i] - key;
            } 
            else
            {
                res[i] = ((ciphertext[i] - key - 97 + 26) % 26) + 97;
            }
        }
        else
        {
            res[i] = ciphertext[i];
        }
  }
  res[lenstr] = '\0';
  return res;
}

void docs(void)
{
  printf("Usage: ./cdecode -c <cipher> -k <key> -t <ciphertext>\n");
  printf("\n");
  printf("Current Version: V1.0\n");
  printf("If cipher requires no key, type 'none' for the key parameter\n");
  printf("\n");
  printf("Put ciphertext in quotations, as versions go by, support for more ciphers will be added, as well as better formatting\n");
  printf("\n");
  printf("+-----Supported Ciphers-----+\n");
  printf("|Caesar (-c arg: caesar)    |\n");
  printf("+---------------------------+\n");
}
int main(int argc, char *argv[])
{
    if (argc != 7)
    {
      docs();
    }
    else if (strcmp(argv[1],"-c") != 0 || strcmp(argv[3],"-k") != 0 || strcmp(argv[5],"-t") != 0)
    {
      docs();
    }
    else
    {
      if (strcmp(argv[2],"caesar") == 0)
      {
        int keyint = atoi(argv[4]);
        ciphersolvekey.key = keyint;
        const char* decrypted = caesar(ciphersolvekey.key, argv[6]);
        printf("%s\n",decrypted);
      }
    }
}
