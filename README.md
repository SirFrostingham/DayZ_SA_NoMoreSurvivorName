DayZ_SA_NoMoreSurvivor is a simple mod to encourage survivors to drop the generic name and name themselves!
=====


Introduction
---
Ever get tired of players with the name of "Survivor" connecting to your server? Do you want to encourage them to name themselves, but you also want to allow them to play? This is the mod for you!

This mod will spawn anyone with the name "Survivor" COMPLETELY naked, with messages that tell the player that they need to give themselves a name to receive a loadout. Anyone without that name gets a loadout. 

4 missions init.c examples are provided. 2 options for Vanilla DayZ missions and 2 options for Expansion mission. Take what works for you and implement it on your server.

Prerequisite / mod dependencies
---
1. This mod must be installed on the server for player messaging to work: @CF - https://steamcommunity.com/sharedfiles/filedetails/?id=1559212036 (Note: It used to be called: @RPCFramework)

Install instructions
---
1. Download all files
2. Edit your mission's init.c file
3. Review included "Missions" folder and merge all sections marked with (NOTE: There is more than one section) "//DayZ_NoMoreSurvivor:START" and "//DayZ_NoMoreSurvivor:END"
4. Optional: Review CustomLoadout section and uncomment code between "//OPTIONAL:DayZ_SA_NoMoreSurvivorName:CustomLoadoutExample:START" and "//OPTIONAL:DayZ_SA_NoMoreSurvivorName:CustomLoadoutExample:END"
5. Optional: If you did step #4, remove redundant handgun and 2 clips below "//OPTIONAL:DayZ_SA_NoMoreSurvivorName:CustomLoadoutExample:END"
6. Run game

How to test
---
1. Connect to the game with name (upper or lower case does not matter): Survivor
2. See messaging.

Support the developer
---
If you would like to support development of this software, you can contribute with a donation by clicking on the Donate Icon below. Thank you for your support!

[![Donate](https://www.paypalobjects.com/en_US/i/btn/btn_donate_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=PXV8MLB5KR5WG)

This work is licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
