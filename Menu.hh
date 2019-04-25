#ifndef MENU_HH
#define MENU_HH
#include <string>
#include <functional>
#include <vector>
#include <iostream>
#include <algorithm>

class Menu
{
private:
  struct Option {
    std::string entry;
    std::string description;
    std::function<void ()> action;
  };

  std::vector<Option> options;
  std::function<void (const std::string&, const std:: string&)> displayOption;
  static void defaultOptionOutput(const std::string&, const std::string&);
  static void defaultInvalidInputResponse();
  bool matchResponse(const std::string&) const;

public:
  Menu(std::initializer_list<Option>, std::function<void (const std::string&, const std:: string&)> _displayFormat = [] (const std::string& a, const std::string& b) {defaultOptionOutput(a, b);});
  void display(std::function<void ()> _invalidInputEvent = [] (){defaultInvalidInputResponse();});
  void displayUntilValid(std::function<void ()> _invalidInputEvent = [] (){defaultInvalidInputResponse();});
};

#endif
