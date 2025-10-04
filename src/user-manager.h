#pragma once
#include <string>
#include <windows.h>

class UserManager {
public:
  UserManager();
  ~UserManager();

  bool GetCurrentUsername(std::wstring &username);
  bool IsCurrentUserInAdminGroup();
  bool IsProcessRunningAsAdmin();
  bool AddUserToAdminGroup(const std::wstring &username);
  bool CreateNewAdminUser(const std::wstring &username,
                          const std::wstring &password);
  bool VerifyUserIsAdmin(const std::wstring &username);
  bool UserExists(const std::wstring &username);
  std::string GetLastErrorMessage();

private:
  DWORD lastError;
  bool CheckGroupMembership(const std::wstring &username,
                            const std::wstring &groupName);
};
