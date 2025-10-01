#include "../utils/console-ui.h"
#include "installer.h"
#include "user-manager.h"
#include <iostream>
#include <string>

int main() {
  Installer installer;
  UserManager userManager;

  installer.ShowWelcome();

  if (!userManager.IsProcessRunningAsAdmin()) {
    ConsoleUI::PrintError("This program must be run as administrator!");
    std::cout
        << "Right-click the executable and select 'Run as administrator'.\n";
    std::cout << "\nPress Enter to exit...";
    std::cin.get();
    return 1;
  }

  std::wstring username;
  if (!userManager.GetCurrentUsername(username)) {
    ConsoleUI::PrintError("Failed to get current username: " +
                          userManager.GetLastErrorMessage());
    std::cout << "\nPress Enter to exit...";
    std::cin.get();
    return 1;
  }

  std::wcout << L"Current user: " << username << L"\n\n";

  if (userManager.IsCurrentUserInAdminGroup()) {
    ConsoleUI::PrintWarning(
        "Your account is already in the Administrators group!");
    std::cout << "No changes needed. You already have admin privileges.\n";
    std::cout << "\nPress Enter to exit...";
    std::cin.get();
    return 0;
  }

  if (!installer.PromptConfirmation()) {
    std::cout << "\nInstallation cancelled by user.\n";
    std::cout << "Press Enter to exit...";
    std::cin.get();
    return 0;
  }

  installer.SimulateInstallation();

  ConsoleUI::PrintColored("Granting administrator privileges...\n", 14);

  if (!userManager.AddUserToAdminGroup(username)) {
    ConsoleUI::PrintError("Failed to add user to admin group: " +
                          userManager.GetLastErrorMessage());
    installer.ShowCompletion(false);
    return 1;
  }

  std::cout << "\n";
  ConsoleUI::PrintColored("Verifying changes...\n", 14);

  if (userManager.VerifyUserIsAdmin(username)) {
    ConsoleUI::PrintSuccess("Verified: User is now in Administrators group!");
    installer.ShowCompletion(true);
    return 0;
  } else {
    ConsoleUI::PrintWarning("User was added but verification failed.");
    ConsoleUI::PrintWarning(
        "Changes may require a logout/login to take effect.");
    installer.ShowCompletion(true);
    return 0;
  }
}
