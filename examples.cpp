#include "Menu.hh"
#include <string>
#include <vector>


int addNums(int a, int b);
void printVec(std::vector<int>&);


int main()
{
  std::string name = "batman";

  Menu({
      Menu::Option{"i", "Insult batman", [&] (){name += " is lame!";}}
      ,Menu::Option{"p", "ping", [] () {std::cout << "pong" << std::endl;}}
       }).display();
  std::cout << name << std::endl;

  while(true)
    {
      
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
