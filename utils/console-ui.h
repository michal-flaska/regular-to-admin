#pragma once
#include <string>
#include <windows.h>

namespace ConsoleUI {
void SetColor(int color);
void ResetColor();
void PrintColored(const std::string &text, int color);
void PrintProgress(const std::string &task, int percentage);
void PrintHeader(const std::string &title);
void PrintSuccess(const std::string &message);
void PrintError(const std::string &message);
void PrintWarning(const std::string &message);
void AnimateProgress(const std::string &task, int durationMs);
void ClearLine();
} // namespace ConsoleUI
