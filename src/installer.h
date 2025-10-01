#pragma once
#include <string>

class Installer {
public:
  void ShowWelcome();
  bool PromptConfirmation();
  void SimulateInstallation();
  void ShowCompletion(bool success);

private:
  void FakeInstallStep(const std::string &step, int delayMs);
};
