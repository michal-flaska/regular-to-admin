#pragma once
#include <string>
#include <windows.h>

class UserManager {
public:
  UserManager();
  ~UserManager();

  bool GetCurrentUsername(std::wstring &username);
  bool IsUserAdmin();
  bool AddUserToAdminGroup(const std::wstring &username);
  std::string GetLastErrorMessage();

private:
  DWORD lastError;
};
