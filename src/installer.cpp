#include "installer.h"
#include "../utils/console-ui.h"
#include <chrono>
#include <iostream>
#include <thread>

void Installer::ShowWelcome() {
  ConsoleUI::PrintHeader("MINECRAFT COMET INSTALLER beta-16.2.4");
  std::cout << "Welcome to Minecraft COMET Setup!\n\n";
  std::cout
      << "Minecraft COMET is a premium modding client for Minecraft that\n";
  std::cout
      << "enhances your gameplay with custom shaders, performance boosters,\n";
  std::cout << "and exclusive multiplayer features.\n\n";
  std::cout << "Features included in free trial:\n";
  std::cout << "  - Advanced shader support (Ray-tracing compatible)\n";
  std::cout << "  - 60+ FPS optimization mods\n";
  std::cout << "  - Custom texture pack manager\n";
  std::cout << "  - Voice chat integration\n";
  std::cout << "  - Server browser with anti-cheat protection\n\n";
  ConsoleUI::PrintWarning(
      "Setup requires administrator privileges to install system-level mods.");
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
  FakeInstallStep("Verifying system requirements", 1200);
  FakeInstallStep("Connecting to download server", 150);
  FakeInstallStep("Downloading Minecraft COMET core (248 MB)", 19000);
  FakeInstallStep("Downloading Minecraft COMET Anti-Cheat (726 MB)", 42000);
  FakeInstallStep("Downloading shader packages (512 MB)", 10000);
  FakeInstallStep("Downloading optimization mods (89 MB)", 7500);
  FakeInstallStep("Extracting COMET Mod Loader files", 20000);
  FakeInstallStep("Setting up COMET Mod Loader", 8000);
  FakeInstallStep("Installing additional DX dependencies", 8500);
  FakeInstallStep("Configuring Java runtime environment", 6200);
  FakeInstallStep("Installing shader engine", 12000);
  FakeInstallStep("Configuring graphics settings", 500);
  FakeInstallStep("Setting up multiplayer components", 2500);
  FakeInstallStep("Registering file associations", 3100);
  std::cout << "\n";
}

void Installer::ShowCompletion(bool success) {
  std::cout << "\n";
  if (success) {
    ConsoleUI::PrintSuccess("Minecraft COMET has been installed successfully!");
    std::cout << "\nInstallation complete! You can now launch Minecraft COMET "
                 "from:\n";
    std::cout << "  - Desktop shortcut\n";
    std::cout << "  - Start Menu > Minecraft COMET\n\n";
    ConsoleUI::PrintWarning(
        "IMPORTANT: Please log out and log back in to apply all changes.");
    std::cout << "\nFirst launch tips:\n";
    std::cout << "  - Allow Java through your firewall if prompted\n";
    std::cout << "  - Update your graphics drivers for best performance\n";
    std::cout << "  - Check shader settings in Options > Video Settings\n";
  } else {
    ConsoleUI::PrintError("Installation failed!");
    std::cout << "Please check the errors above and try again.\n";
    std::cout << "\nCommon solutions:\n";
    std::cout << "  - Ensure you have administrator rights\n";
    std::cout << "  - Disable antivirus temporarily\n";
    std::cout << "  - Check available disk space (minimum 2 GB required)\n";
  }
  std::cout << "\nMake sure to restart your computer.";
  std::cout << "\nPress Enter to exit...";
  std::cin.get();
}

void Installer::FakeInstallStep(const std::string &step, int delayMs) {
  ConsoleUI::AnimateProgress(step, delayMs);
}
