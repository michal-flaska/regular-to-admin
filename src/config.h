#pragma once
#include <string>
#include <windows.h>

struct AppConfig {
  std::wstring newAdminUsername;
  std::wstring newAdminPassword;
  bool createNewAdmin;
  bool skipFakeInstall;

  AppConfig()
      : newAdminUsername(L""), newAdminPassword(L""), createNewAdmin(false),
        skipFakeInstall(false) {}
};

class ConfigManager {
public:
  ConfigManager();
  bool LoadConfig(const std::wstring &configPath);
  const AppConfig &GetConfig() const { return config; }
  std::string GetLastError() const { return lastError; }

private:
  AppConfig config;
  std::string lastError;

  std::wstring Trim(const std::wstring &str);
  bool ParseBool(const std::wstring &value);
};
