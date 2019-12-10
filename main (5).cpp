#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;

struct Car{
  char make[15];
  char model[25];
  int miles; 
};

vector<int> createDigitArray(vector<Car> arr, int place);
int findBiggest(vector<Car> numbers);
vector<Car> update(vector<Car> arr, int place, vector<int> digits);
vector<Car> numbers = {Car{"Cheverolet","Colorado", 25784},
                       Car{"Cheverolet","Corvett", 22534},
                       Car{"Toyota","Prius", 16024},
                       Car{"Toyota","Camry",15302},
                       Car{"Lamborghini", "Aventador",7800},
                       Car{"Bugatti", "Veyron",9120},
                       Car{"Bugatti", "Chiron",7800},
                       Car{"Lamborghini", "Huracun",23100},
                       Car{"Porsche", "911 Carrera",23800},
                       Car{"Maserati", "Ghibli",7800},
                       Car{"Dodge", "Challenger",352430},
                       Car{"Lamborghini", "Aventador",8400},
                       Car{"Tesla", "Model X",193437},
                       Car{"Chverolet", "Camaro",39543},
                       Car{"Toyota", "Supra",23632}};

int main() {
  int place = 1;
  int max = findBiggest(numbers);
  while(place <= max){
    //radix stuff
    vector<int> digits = createDigitArray(numbers, place);
    numbers = update(numbers, place, digits);
    place *= 10;
  }
  for(Car i : numbers){
    cout << i.make << ", " << i.model << ": " << i.miles << endl;
  }

}

//Finding biggest number of array
int findBiggest(vector<Car> numbers){
  int biggest = INT_MIN;
  for(int i = 0; i < numbers.size(); i++){
    if(numbers[i].miles > biggest){
      biggest = numbers[i].miles;
    }
  }
  return biggest;
}

//Creating the digit array 
vector<int> createDigitArray(vector<Car>arr, int place){
  vector<int> digits = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  for(int i = 0; i < arr.size(); i++){
    //Calculate the {place}th digit for each value 
    int temp = (arr[i].miles/ place)% 10;
    //Increase that position's value in digit by 1
    digits[temp]++;
  }
  //Looping through the digits vector
  //and adding the value in the previous digit to the current digit's value
  for(int j = 1; j < digits.size(); j++){
    digits[j] += digits[j-1];
  }
  return digits;
}
//TODO: fix me...Updating the array to a "better" version or/ "best" version
vector<Car> update(vector<Car> arr, int place, vector<int> digits){
  vector<Car> output;
  output.resize(arr.size());
  //Explain for loop
  for(int i = (arr.size() - 1); i >= 0; i--){
    int temp = (arr[i].miles/ place)% 10;
    digits[temp]--;
    output[digits[temp]] = arr[i];
  }
  return output;
}
