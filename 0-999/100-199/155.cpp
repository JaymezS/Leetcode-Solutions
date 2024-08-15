#include <bits/stdc++.h>

using namespace std;

int main(){
class MinStack {
public:
  int size = 4;
  int* array;
  int* minArray;
  int pointer = 0;

  MinStack() {
    array = new int[size];
    minArray = new int[size];
  }
  
  void push(int val) {
    array[pointer] = val;
    if (pointer == 0) {
      minArray[0] = val;
    } else {
      minArray[pointer] = min(minArray[pointer - 1], val);
    }
    pointer++;
    if (pointer >= size) {
      resize();
    }
  }
  
  void pop() {
    pointer--;
    if (size > 4 && pointer < size/2) {
      resize();
    }
  }
  
  int top() {
    return array[pointer - 1];
  }
  
  int getMin() {
    return minArray[pointer - 1];
  }

  void resize() {
    int newSize;
    if (pointer >= size) {
      newSize = size * 2;
    } else {
      newSize = size / 2;
    }
    int *newArray = new int[newSize];
    int *newMinArray = new int[newSize];
    for (int i = 0; i < pointer; i++) {
      newArray[i] = array[i];
      newMinArray[i] = minArray[i];
    }

    delete[] array;
    delete[] minArray;
    
    size = newSize;
    array = newArray;
    minArray = newMinArray;
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
  return 0;
}