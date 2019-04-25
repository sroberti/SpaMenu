#include "Menu.hh"

void Menu::defaultOptionOutput(const std::string& _entry, const std::string& _description)
{
  std::cout << _entry << ": " << _description << std::endl;
}

void Menu::defaultInvalidInputResponse()
{
  std::cout << "Invalid response." << std::endl;
}

Menu::Menu(std::initializer_list<Option> _options,
           std::function<void (const std::string& _entry, const std::string& _description)> _displayFormat)
{
  options = _options;
  displayOption= _displayFormat;
}

void Menu::display(std::function<void ()> _invalidInputEvent)
{
  for_each(options.begin(), options.end(), [this] (Option& line) {displayOption(line.entry, line.description);});
  std::string userResponse;
  std::cin >> userResponse;
  if(!matchResponse(userResponse)) _invalidInputEvent();
}

void Menu::displayUntilValid(std::function<void ()> _invalidInputEvent)
{
  for_each(options.begin(), options.end(), [this] (Option& line) {displayOption(line.entry, line.description);});
  std::string userResponse;
  std::cin >> userResponse;

  while(!matchResponse(userResponse))
    {
      _invalidInputEvent();
      for_each(options.begin(), options.end(), [this] (Option& line) {displayOption(line.entry, line.description);});
      std::cin >> userResponse;
    }
}

bool Menu::matchResponse(const std::string& _response) const
{
  bool valid = false;
  for_each(options.begin(), options.end(), [&] (Option op)
           {
             if(op.entry == _response)
               {
                 op.action();
                 valid = true;
               }
           });
  return valid;
}
