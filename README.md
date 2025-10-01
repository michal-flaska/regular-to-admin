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
# Minecraft Installer (regular-to-admin)

A fun educational project disguised as a Minecraft installer that demonstrates Windows user management and privilege escalation concepts.

## What is this?

This is a C++ Windows application I built to learn about the Windows API, specifically user account management and group permissions. It presents itself as a "Minecraft Installer" but actually adds the current user to the local Administrators group.

**The name is an inside joke with a friend - this is NOT actual malware or a scam. Please don't report me.**

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

**For Educational Purposes Only**

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

---

## Frequently Asked Questions

### Why does Windows/Discord flag this as malicious?

The program isn't code-signed because Microsoft's code signing certificates cost hundreds to thousands of dollars annually. Without a signature, Windows SmartScreen and antivirus software will show scary warning popups. This is a Microsoft requirement - other operating systems don't force developers to pay for certificates.

**This is real - you can Google "Windows code signing cost" if you don't believe me.**

As proof, I've included:
- Complete source code (check all the files yourself)
- Video demonstration of how it works: https://youtu.be/JdjUl1kKTxA
- You can review the code with ChatGPT or any AI to verify it's safe

### What's the actual use case?

It's meant for **ONE TIME use** in specific situations. For example:

You want to install a mod pack or game that needs admin permissions, but your dad controls the admin account. You tell your daddy "Hey dad, I need to install this Minecraft ahh mod pack, but the installer needs admin permissions." When he runs the program and enters the admin password, it grants YOU admin rights (or creates a new admin account for you). - **The actual internal joke between me and my friend**

After that, you have permanent admin access and don't need to ask anymore.

### Is this actually safe?

The entire source code is available in this repository. Every single line is visible and can be reviewed. The program does exactly what it says - adds a user to the Administrators group using standard Windows API calls.

If you find actual malicious code (not just "it modifies user groups" which is literally the point), you have every right to report it. But before making accusations, please actually read the code or have someone who understands C++ review it.

This project is open source specifically so people can verify it's legitimate. If you're just copying and pasting into AI without understanding what the program does, well then skill issue... that's on you.
