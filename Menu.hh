#ifndef MENU_HH
#define MENU_HH
#include <string>
#include <functional>
#include <vector>

template <class T>
class Menu
{
private:
  struct Option {
    std::string entry;
    std::string description;
    std::function<void (T&)> action;
  };

  std::vector<Option> options;
  std::function<void (const std::string&, const std:: string&)> displayOption;
  void defaultFormat(const std::string&, const std:: string&) const;

public:
  Menu(std::initializer_list<Option>, std::function<void (const std::string&, const std:: string&)> displayFormat = defaultFormat);
  void display();
  void displayUntilValid();
};

#endif
