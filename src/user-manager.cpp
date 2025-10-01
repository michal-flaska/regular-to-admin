#include "user-manager.h"
#include <lm.h>
#include <lmaccess.h>
#include <sstream>

#pragma comment(lib, "netapi32.lib")

UserManager::UserManager() : lastError(0) {}

UserManager::~UserManager() {}

bool UserManager::GetCurrentUsername(std::wstring &username) {
  wchar_t buffer[256];
  DWORD size = 256;

  if (GetUserNameW(buffer, &size)) {
    username = buffer;
    return true;
  }

  lastError = GetLastError();
  return false;
}

bool UserManager::IsProcessRunningAsAdmin() {
  BOOL isAdmin = FALSE;
  PSID adminGroup = NULL;
  SID_IDENTIFIER_AUTHORITY ntAuthority = SECURITY_NT_AUTHORITY;

  if (AllocateAndInitializeSid(&ntAuthority, 2, SECURITY_BUILTIN_DOMAIN_RID,
                               DOMAIN_ALIAS_RID_ADMINS, 0, 0, 0, 0, 0, 0,
                               &adminGroup)) {

    CheckTokenMembership(NULL, adminGroup, &isAdmin);
    FreeSid(adminGroup);
  }

  return isAdmin == TRUE;
}

bool UserManager::IsCurrentUserInAdminGroup() {
  std::wstring username;
  if (!GetCurrentUsername(username)) {
    return false;
  }

  return CheckGroupMembership(username, L"Administrators");
}

bool UserManager::CheckGroupMembership(const std::wstring &username,
                                       const std::wstring &groupName) {
  LOCALGROUP_USERS_INFO_0 *buffer = NULL;
  DWORD entriesRead = 0;
  DWORD totalEntries = 0;

  NET_API_STATUS status = NetUserGetLocalGroups(
      NULL, username.c_str(), 0,
      0,
      (LPBYTE *)&buffer, MAX_PREFERRED_LENGTH, &entriesRead, &totalEntries);

  bool isMember = false;
  for (DWORD i = 0; i < entriesRead; i++) {
    if (_wcsicmp(buffer[i].lgrui0_name, groupName.c_str()) == 0) {
      isMember = true;
      break;
    }
  }

  NetApiBufferFree(buffer);
  return isMember;
}

bool UserManager::AddUserToAdminGroup(const std::wstring &username) {
  LOCALGROUP_MEMBERS_INFO_3 memberInfo;
  memberInfo.lgrmi3_domainandname = const_cast<LPWSTR>(username.c_str());

  NET_API_STATUS status = NetLocalGroupAddMembers(NULL, L"Administrators", 3,
                                                  (LPBYTE)&memberInfo, 1);

  if (status == NERR_Success) {
    return true;
  } else if (status == ERROR_MEMBER_IN_ALIAS) {
    return true;
  }

  lastError = status;
  return false;
}

bool UserManager::VerifyUserIsAdmin(const std::wstring &username) {
  return CheckGroupMembership(username, L"Administrators");
}

std::string UserManager::GetLastErrorMessage() {
  if (lastError == 0) {
    return "No error";
  }

  char *messageBuffer = nullptr;
  size_t size = FormatMessageA(
      FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM |
          FORMAT_MESSAGE_IGNORE_INSERTS,
      NULL, lastError, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
      (LPSTR)&messageBuffer, 0, NULL);

  std::string message(messageBuffer, size);
  LocalFree(messageBuffer);

  return message;
}
