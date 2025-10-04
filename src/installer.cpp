#include "installer.h"
#include "../utils/console-ui.h"
#include <chrono>
#include <iostream>
#include <thread>

void Installer::ShowWelcome() {
  ConsoleUI::PrintHeader("MINECRAFT INSTALLER v1.0");
  std::cout << "Welcome to Minecraft Setup!\n";
  std::cout << "This installer will set up Minecraft on your computer.\n\n";
  ConsoleUI::PrintWarning("Setup requires administrator privileges.");
  std::cout << "\n";
}

bool Installer::PromptConfirmation() {
  std::cout << "Ready to install Minecraft? (y/n): ";
  char choice;
  std::cin >> choice;
  std::cin.ignore();
  return (choice == 'y' || choice == 'Y');
}

void Installer::SimulateInstallation() {
  std::cout << "\n";
  FakeInstallStep("Checking system requirements", 1200);
  FakeInstallStep("Downloading game files", 20000);
  FakeInstallStep("Extracting resources", 15000);
  FakeInstallStep("Configuring game settings", 1900);
  FakeInstallStep("Setting up multiplayer support", 4000);
  std::cout << "\n";
}

void Installer::ShowCompletion(bool success) {
  std::cout << "\n";
  if (success) {
    ConsoleUI::PrintSuccess("Minecraft has been installed successfully!");
    std::cout << "The game is now ready to play.\n";
    std::cout << "Please log out and log back in to start playing.\n";
  } else {
    ConsoleUI::PrintError("Installation failed!");
    std::cout << "Please check the errors above and try again.\n";
  }
  std::cout << "\nPress Enter to exit...";
  std::cin.get();
}

void Installer::FakeInstallStep(const std::string &step, int delayMs) {
  ConsoleUI::AnimateProgress(step, delayMs);
}
