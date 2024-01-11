
#include <stdio.h>
#include <string.h>

#define N 7

char digit[N] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int values[N] = {1, 5, 10, 50, 100, 500, 1000};

int digitsToValues(char ch)
{
  int i;
  for (i = 0; i < N; i++)
  {
    if (digit[i] == ch)
    {
      return values[i];
    }
  }

  return 0;
}

int findMaxIndex(char str[], int L, int R)
{
  int max = digitsToValues(str[L]);

  int maxIndex = L;
  int i;
  for (i = L; i <= R; i++)
  {
    int d = digitsToValues(str[i]);
    if (d > max)
    {
      max = d;
      maxIndex = i;
    }
  }

  return maxIndex;
}

int romanToNumber(char str[], int L, int R)
{
  if (L == R)
  {
    return digitsToValues(str[L]);
  }
  else if (L > R)
  {
    return 0;
  }
  else
  {
    int i = findMaxIndex(str, L, R);
    int n = digitsToValues(str[i]);
    return n - romanToNumber(str, L, i - 1) + romanToNumber(str, i + 1, R);
  }
}

int romanToNumber1(char str[])
{
  int L = 0;
  int R = strlen(str) - 1;
  return romanToNumber(str, L, R);
}

int main()
{
  // char str[] = "MCMLIV";
  // int res = romanToNumber(str, 0, 5);
  // printf("res = %d\n", res);

  // // char str[] = "CLMIV";
  // int rr = findMaxIndex(str, 0, 5);
  // printf("r = %d\n", rr);

  char str[1000];
  scanf("%s", str);
  int result = romanToNumber1(str);
  printf("%d\n",result);
}
