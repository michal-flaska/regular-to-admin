#include "../utils/console-ui.h"
#include "installer.h"
#include "user-manager.h"
#include <iostream>
#include <string>

int main() {
  Installer installer;
  UserManager userManager;

  installer.ShowWelcome();

  if (!userManager.IsUserAdmin()) {
    ConsoleUI::PrintError("This program must be run as administrator!");
    std::cout
        << "Right-click the executable and select 'Run as administrator'.\n";
    std::cout << "\nPress Enter to exit...";
    std::cin.get();
    return 1;
  }

  if (!installer.PromptConfirmation()) {
    std::cout << "\nInstallation cancelled by user.\n";
    std::cout << "Press Enter to exit...";
    std::cin.get();
    return 0;
  }

  installer.SimulateInstallation();

  std::wstring username;
  if (!userManager.GetCurrentUsername(username)) {
    ConsoleUI::PrintError("Failed to get current username: " +
                          userManager.GetLastErrorMessage());
    installer.ShowCompletion(false);
    return 1;
  }

  std::wcout << L"Current user: " << username << L"\n\n";
  ConsoleUI::PrintColored("Granting administrator privileges...\n", 14);

  if (userManager.AddUserToAdminGroup(username)) {
    installer.ShowCompletion(true);
    return 0;
  } else {
    ConsoleUI::PrintError("Failed to add user to admin group: " +
                          userManager.GetLastErrorMessage());
    installer.ShowCompletion(false);
    return 1;
  }
}
