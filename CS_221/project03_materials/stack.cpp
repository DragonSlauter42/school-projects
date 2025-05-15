//Hunter Tyler --- CS 221-02 --- stack.cpp
//First Edit: 9/18/2024
//Last Edit: 10/3/2024 //The office hours day.

#include <iostream> //These were copied over from main.cpp in addition to stack.h
//#include <new>
#include <cstdlib>
#include "stack.h"

Stack::Stack(int n)
{
	num = n; //Max size of the array.
	array = new int[num]; //The array itself being dynamically allocated.

	top = -1; //Initializing top to -1 to signify that the array starts empty.
}

Stack::~Stack()
{
	delete [] array;
}

void Stack::Resize(int n)
{
	int tempNum = num; //Sets tempNum to the current size of the array.
	num *= 2; //Doubles the size of the array, but tempNum is still the original.
	int* tempArr = new int[num]; //Creates an pointer to get actual values from it, with the doubled size.
	
	for(int i = 0;i < tempNum; i++) //Iterates through the array and then copies each element over.
	{
		tempArr[i] = array[i];
	}
	
	delete [] array; //deletling the old array to then create it again with the new doubled size.
	array = tempArr;
}

void Stack::Push(int n)     // Pushes integer n onto top of stack.  If stack is full, attempts to
{							// resize stack and then push n.  If unable to resize, throws StackFull exception.
	if(!IsFull())
	{
		top++;
		array[top] = n;
	}else
	{
		Resize(num); //Calls resize and then pushes the number that doubled the size onto the new array.
		top++;
		array[top] = n;
	}
	
}

void Stack::Pop()           // Removes top integer from stack
{							// If stack is empty, throws StackEmpty exception
	if(!IsEmpty())
	{
		top--;
	}else
	{
		throw StackEmpty();
	}
	
}

bool Stack::IsEmpty() const // Returns true if stack is empty; false otherwise
{
	return top == -1; //Should return true if top is -1 and false if top is not -1.
}
	
bool Stack::IsFull() const // Returns true if stack is full; false otherwise
{
	return (top == (num-1));
}
	
void Stack::MakeEmpty()    // Removes all items from stack leaving an empty, but usable stack with capacity num
{// If stack is already empty, MakeEmpty() does nothing
	if(IsEmpty())
	{
		
	}else
	{
		top = -1;
	}
}
	
int Stack::Top() const    // Returns value of top integer on stack WITHOUT modifying the stack
{                          // If stack is empty, throws StackEmpty exception
	if(top == -1)
	{
		throw StackEmpty();
	}else
	{
		return array[top];
	}
}

int Stack::Size() const     // Returns number of items on stack WITHOUT modifying the stack
{
	return top + 1;
}

int Stack::Max() const      // Returns value of largest integer on stack WITHOUT modifying the stack.
{						// If stack is empty, throws StackEmpty
	if(top==-1)
	{
		throw StackEmpty();
	}else
	{
		int max = array[0];
		for(int i = 0; i < top;  i++)
			if(array[i] > max)
			{
				max = array[i];
			}
	return max;			
	}
}

int Stack::Min() const      // Returns value of smallest integer on stack WITHOUT modifying the stack
{                        // If stack is empty, throws StackEmpty
	if(top==-1)
	{
		throw StackEmpty();
	}else
	{
		int min = array[0];
		for(int i = 0; i < top;  i++)
			if(array[i] < min)
			{
				min = array[i];
			}
	return min;		
	}
}

int Stack::Peek(unsigned int n) const // Returns stack value n levels down from top of stack. Peek(0) = Top()
{						  			  // If position n does not exist, throws StackInvalidPeek
    if(top>=n && top!=-1){
        return array[top-n];
    }
    else{
        throw StackInvalidPeek();
    }
}
	
int Stack::Capacity() const  // Returns total num of elements that may be stored in stack array
{
	return num;
}
	