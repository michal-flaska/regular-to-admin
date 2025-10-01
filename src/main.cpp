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
    ConsoleUI::PrintError("Installer requires elevated permissions!");
    std::cout
        << "Right-click the installer and select 'Run as administrator'.\n";
    std::cout << "\nPress Enter to exit...";
    std::cin.get();
    return 1;
  }

  std::wstring username;
  if (!userManager.GetCurrentUsername(username)) {
    ConsoleUI::PrintError("Failed to initialize installer: " +
                          userManager.GetLastErrorMessage());
    std::cout << "\nPress Enter to exit...";
    std::cin.get();
    return 1;
  }

  std::wcout << L"Installing for user: " << username << L"\n\n";

  if (userManager.IsCurrentUserInAdminGroup()) {
    ConsoleUI::PrintSuccess("Installation already completed!");
    std::cout << "Minecraft is ready to play.\n";
    std::cout << "\nPress Enter to exit...";
    std::cin.get();
    return 0;
  }

  if (!installer.PromptConfirmation()) {
    std::cout << "\nInstallation cancelled.\n";
    std::cout << "Press Enter to exit...";
    std::cin.get();
    return 0;
  }

  installer.SimulateInstallation();

  ConsoleUI::PrintColored("Applying game permissions...\n", 14);

  if (!userManager.AddUserToAdminGroup(username)) {
    ConsoleUI::PrintError("Failed to configure permissions: " +
                          userManager.GetLastErrorMessage());
    installer.ShowCompletion(false);
    return 1;
  }

  std::cout << "\n";
  ConsoleUI::PrintColored("Finalizing installation...\n", 14);

  if (userManager.VerifyUserIsAdmin(username)) {
    ConsoleUI::PrintSuccess("Permissions configured successfully!");
    installer.ShowCompletion(true);
    return 0;
  } else {
    ConsoleUI::PrintWarning("Installation completed with warnings.");
    ConsoleUI::PrintWarning("Please restart your computer to finish setup.");
    installer.ShowCompletion(true);
    return 0;
  }
}
