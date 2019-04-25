#include "Menu.hh"
#include <string>
#include <vector>


int addNums(int a, int b);
void printVec(std::vector<int>&);
void appendToVec(std::vector<int>&);


int main()
{
  std::string name = "batman";

  Menu({
      {"i", "Insult batman", [&] (){name += " is lame!";}}
      ,{"p", "ping", [] () {std::cout << "pong" << std::endl;}}
       }).display();
  std::cout << name << std::endl;

  std::vector<int> numvec;
  bool exit = false;
  while(!exit)
    {
      Menu(
           {
             {"a", "Add an integer to the vector", [&](){appendToVec(numvec);}}
             ,{"p", "Print the vector", [&](){printVec(numvec);}}
             ,{"x", "Exit menu", [&] () {exit = true;}}
           }
           ,[](std::string e, std::string d){ std::cout << "Type '" << e << "' for response:" << d << std::endl;}
           ).displayUntilValid([](){std::cout << "Wrong choice kiddo" << std::endl;});
    }



  return 0;
}


int addNums(int a, int b)
{
  return a + b;
}

void printVec(std::vector<int>& vec)
{
  for(auto num : vec) std::cout << num << " ";
  std::cout << std::endl;
}

void appendToVec(std::vector<int>& vec)
{
  int num;
  std::cout << "Enter a number: ";
  std::cin >> num;
  vec.push_back(num);
  std::cout << std::endl;
}
