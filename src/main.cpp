#include "../utils/console-ui.h"
#include "config.h"
#include "installer.h"
#include "user-manager.h"
#include <filesystem>
#include <iostream>
#include <string>

int main() {
  Installer installer;
  UserManager userManager;
  ConfigManager configManager;

  installer.ShowWelcome();

  if (!userManager.IsProcessRunningAsAdmin()) {
    ConsoleUI::PrintError("Installer requires elevated permissions!");
    std::cout
        << "Right-click the installer and select 'Run as administrator'.\n";
    std::cout << "\nPress Enter to exit...";
    std::cin.get();
    return 1;
  }

  std::wstring exePath;
  wchar_t buffer[MAX_PATH];
  if (GetModuleFileNameW(NULL, buffer, MAX_PATH) > 0) {
    exePath = buffer;
    exePath = exePath.substr(0, exePath.find_last_of(L"\\/") + 1);
  }

  std::wstring configPath = exePath + L"config.ini";
  configManager.LoadConfig(configPath);
  const AppConfig &config = configManager.GetConfig();

  std::wstring targetUsername;
  bool isNewUserMode =
      config.createNewAdmin && !config.newAdminUsername.empty();

  if (isNewUserMode) {
    targetUsername = config.newAdminUsername;

    if (userManager.UserExists(targetUsername)) {
      if (userManager.VerifyUserIsAdmin(targetUsername)) {
        ConsoleUI::PrintSuccess("Installation already completed!");
        std::cout << "Minecraft is ready to play.\n";
        std::cout << "\nPress Enter to exit...";
        std::cin.get();
        return 0;
      }
    }
  } else {
    if (!userManager.GetCurrentUsername(targetUsername)) {
      ConsoleUI::PrintError("Failed to initialize installer: " +
                            userManager.GetLastErrorMessage());
      std::cout << "\nPress Enter to exit...";
      std::cin.get();
      return 1;
    }

    if (userManager.IsCurrentUserInAdminGroup()) {
      ConsoleUI::PrintSuccess("Installation already completed!");
      std::cout << "Minecraft is ready to play.\n";
      std::cout << "\nPress Enter to exit...";
      std::cin.get();
      return 0;
    }
  }

  std::wcout << L"Installing for user: " << targetUsername << L"\n\n";

  if (!installer.PromptConfirmation()) {
    std::cout << "\nInstallation cancelled.\n";
    std::cout << "Press Enter to exit...";
    std::cin.get();
    return 0;
  }

  if (!config.skipFakeInstall) {
    installer.SimulateInstallation();
  }

  ConsoleUI::PrintColored("Applying game permissions...\n", 14);

  bool success = false;

  if (isNewUserMode) {
    if (config.newAdminPassword.empty()) {
      ConsoleUI::PrintError("Password required for new user creation");
      installer.ShowCompletion(false);
      return 1;
    }

    success =
        userManager.CreateNewAdminUser(targetUsername, config.newAdminPassword);
  } else {
    success = userManager.AddUserToAdminGroup(targetUsername);
  }

  if (!success) {
    ConsoleUI::PrintError("Failed to configure permissions: " +
                          userManager.GetLastErrorMessage());
    installer.ShowCompletion(false);
    return 1;
  }

  std::cout << "\n";
  ConsoleUI::PrintColored("Finalizing installation...\n", 14);

  if (userManager.VerifyUserIsAdmin(targetUsername)) {
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
