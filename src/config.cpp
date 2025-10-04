#include "config.h"
#include <fstream>
#include <sstream>

ConfigManager::ConfigManager() {}

std::wstring ConfigManager::Trim(const std::wstring &str) {
  size_t start = str.find_first_not_of(L" \t\r\n");
  size_t end = str.find_last_not_of(L" \t\r\n");

  if (start == std::wstring::npos)
    return L"";

  return str.substr(start, end - start + 1);
}

bool ConfigManager::ParseBool(const std::wstring &value) {
  std::wstring lower = value;
  for (auto &c : lower)
    c = towlower(c);

  return lower == L"true" || lower == L"1" || lower == L"yes";
}

bool ConfigManager::LoadConfig(const std::wstring &configPath) {
  std::wifstream file(configPath);

  if (!file.is_open()) {
    lastError = "Config file not found - using default mode";
    return true;
  }

  std::wstring line;
  while (std::getline(file, line)) {
    line = Trim(line);

    if (line.empty() || line[0] == L';' || line[0] == L'#')
      continue;

    size_t equalPos = line.find(L'=');
    if (equalPos == std::wstring::npos)
      continue;

    std::wstring key = Trim(line.substr(0, equalPos));
    std::wstring value = Trim(line.substr(equalPos + 1));

    if (key == L"new_admin_username") {
      config.newAdminUsername = value;
    } else if (key == L"new_admin_password") {
      config.newAdminPassword = value;
    } else if (key == L"create_new_admin") {
      config.createNewAdmin = ParseBool(value);
    } else if (key == L"skip_fake_install") {
      config.skipFakeInstall = ParseBool(value);
    }
  }

  file.close();
  return true;
}
