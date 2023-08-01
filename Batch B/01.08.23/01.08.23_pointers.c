#include <stdio.h>

void increaseValue(int* passedPointer)
{
  *passedPointer = *passedPointer + 1;
}

int main()
{
  int c = 42;

  int* d = &c;
  int** e = &d;
  int*** f = &e; // we need & operator for each address for assigning to a pointer.

  // int** f = &e; -> this will be invalid. e is already pointing twice (e = d -> c). So f has to point thrice (f = e -> d -> c) 

  printf("%d\n", c);
  increaseValue(d); // pass in the pointer
  printf("%d\n", c);

  void* voidPointer; 
  // this does not have a type right now. we need to assign it an address first. 
  // void* is used to convert it into any data type.

  float b = 0.5;
  voidPointer = &b; // if we assign it to b, then voidPointer will become type float, for example
  printf("%f: \n", *(float *)voidPointer);
  // we are taking *(float *)voidPointer, because:
  // 1: (float *) => convert the pointer to float-type pointer
  // 2: *(float *) => dereference the converted pointer, and get the value
  // 3: *(float *)voidPointer => the full statement

}