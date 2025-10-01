#include "installer.h"
#include "../utils/console-ui.h"
#include <chrono>
#include <iostream>
#include <thread>

void Installer::ShowWelcome() {
  ConsoleUI::PrintHeader("MINECRAFT INSTALLER v1.0");
  std::cout << "Welcome to the totally legitimate Minecraft installer!\n";
  std::cout << "This will grant you admin privileges to install Minecraft.\n\n";
  ConsoleUI::PrintWarning("This program requires administrator rights.");
  std::cout << "\n";
}

bool Installer::PromptConfirmation() {
  std::cout << "Do you want to proceed with the installation? (y/n): ";
  char choice;
  std::cin >> choice;
  std::cin.ignore();
  return (choice == 'y' || choice == 'Y');
}

void Installer::SimulateInstallation() {
  std::cout << "\n";
  FakeInstallStep("Checking system requirements", 800);
  FakeInstallStep("Downloading Minecraft files", 1500);
  FakeInstallStep("Extracting game assets", 1200);
  FakeInstallStep("Configuring game settings", 900);
  FakeInstallStep("Setting up user permissions", 1000);
  std::cout << "\n";
}

void Installer::ShowCompletion(bool success) {
  std::cout << "\n";
  if (success) {
    ConsoleUI::PrintSuccess("Installation completed successfully!");
    std::cout << "You now have administrator privileges.\n";
    std::cout << "Please restart your session for changes to take effect.\n";
  } else {
    ConsoleUI::PrintError("Installation failed!");
    std::cout << "Please check the error messages above.\n";
  }
  std::cout << "\nPress Enter to exit...";
  std::cin.get();
}

void Installer::FakeInstallStep(const std::string &step, int delayMs) {
  ConsoleUI::AnimateProgress(step, delayMs);
}
