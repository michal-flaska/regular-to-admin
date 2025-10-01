# Minecraft Installer (regular-to-admin)

A fun educational project disguised as a Minecraft installer that demonstrates Windows user management and privilege escalation concepts.

## What is this?

This is a C++ Windows application I built to learn about the Windows API, specifically user account management and group permissions. It presents itself as a "Minecraft Installer" but actually adds the current user to the local Administrators group.

> [!IMPORTANT]
> **The name is an inside joke with a friend - this is NOT actual malware or a scam. Please don't report me. Thanks**

## Educational Purpose

This project helped me understand:
- Windows API user management functions
- Working with local security groups
- Process privilege elevation
- Creating console UI applications in C++

## How it works

1. Checks if running with administrator privileges
2. Gets the current username
3. Verifies if user is already in Administrators group
4. Prompts for confirmation (disguised as "install Minecraft")
5. Adds user to local Administrators group
6. Verifies the changes

## Requirements

- Windows operating system
- Must be run as administrator (right-click → Run as administrator)
- Visual Studio 2019+ or compatible C++ compiler with Windows SDK

## Usage

**For Educational Purposes Only PLEASEEE 🙏**

1. Build the project in Visual Studio
2. Navigate to `x64/Debug/` or `x64/Release/`
3. Right-click `minecraft-installer.exe` → Run as administrator
4. Follow the on-screen prompts

## Security Note

This program modifies system security settings. Only use it on your own computer or with explicit permission. Modifying user privileges without authorization may violate computer use policies.

## Disclaimer

This is a learning project and inside joke. It's provided as-is for educational purposes. Use responsibly and only on systems you own or have permission to modify.

## Technical Details

Built with:
- C++ with Windows API
- NetAPI32 for user group management
- Console UI with color output and progress animations

## Frequently asked question
... will add soon
