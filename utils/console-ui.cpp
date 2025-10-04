#include "../utils/console-ui.h"
#include <chrono>
#include <iostream>
#include <thread>

namespace ConsoleUI {
const int COLOR_DEFAULT = 7;
const int COLOR_GREEN = 10;
const int COLOR_RED = 12;
const int COLOR_YELLOW = 14;
const int COLOR_CYAN = 11;

void SetColor(int color) {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, color);
}

void ResetColor() { SetColor(COLOR_DEFAULT); }

void PrintColored(const std::string &text, int color) {
  SetColor(color);
  std::cout << text;
  ResetColor();
}

void PrintProgress(const std::string &task, int percentage) {
  std::cout << "\r";
  std::cout << task << " [";
  int barWidth = 40;
  int pos = barWidth * percentage / 100;
  for (int i = 0; i < barWidth; ++i) {
    if (i < pos)
      std::cout << "=";
    else if (i == pos)
      std::cout << ">";
    else
      std::cout << " ";
  }
  std::cout << "] " << percentage << "%  ";
  std::cout.flush();
}

void PrintHeader(const std::string &title) {
  std::cout << "\n";
  // PrintColored("========================================\n", COLOR_CYAN);
  PrintColored(/*"  " +*/title + "\n", COLOR_CYAN);
  // PrintColored("========================================\n", COLOR_CYAN);
  std::cout << "\n";
}

void PrintSuccess(const std::string &message) {
  PrintColored("[SUCCESS] ", COLOR_GREEN);
  std::cout << message << "\n";
}

void PrintError(const std::string &message) {
  PrintColored("[ERROR] ", COLOR_RED);
  std::cout << message << "\n";
}

void PrintWarning(const std::string &message) {
  PrintColored("[WARNING] ", COLOR_YELLOW);
  std::cout << message << "\n";
}

void AnimateProgress(const std::string &task, int durationMs) {
  int steps = 100;
  int delayPerStep = durationMs / steps;
  for (int i = 0; i <= steps; ++i) {
    PrintProgress(task, i);
    std::this_thread::sleep_for(std::chrono::milliseconds(delayPerStep));
  }
  std::cout << "\n";
}

void ClearLine() {
  std::cout << "\r" << std::string(80, ' ') << "\r";
  std::cout.flush();
}
} // namespace ConsoleUI
