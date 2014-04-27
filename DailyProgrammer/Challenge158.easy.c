//The Torn Number

#include <stdio.h>
#include <stdbool.h>


bool valid(int number); 

int main(void)
{
  int i;

  for (i = 1000 ; i < 10000 ; i++)
  {
    if (valid(i))
      printf("%d is a valid number.\n", i);
  }

  return 0;
}//end main


bool valid(int number)
{
  int left, right;
  int sum;
  int a,b,c,d; //for all 4 numbers

  // set a b c and d
  a = number /1000;
  b = (number%1000)/100;
  c = (number%100)/10;
  d = number%10;
  
  //set left and right and sum
  left = number/100; //left half of number
  right = number%100; // right half of number
  sum = left + right; //add them together


 
  if (sum * sum == number)
    if (!(a == b || a == c || a == d || b == c || b == d || c == d))
      return true;
  return false;
}
