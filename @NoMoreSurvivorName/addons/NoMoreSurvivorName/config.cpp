class CfgMods
{
    class NoMoreSurvivorName
    {
        dir = "NoMoreSurvivorName";
        picture = "";
        action = "";
        hideName = 1;
        hidePicture = 1;
        name = "Better Loadouts";
        credits = "";
        author = "Chopper";
        authorID = "0"; 
        version = "1.0"; 
        extra = 0;
        type = "mod";
        dependencies[] = {};
    };
};

class CfgPatches
{
	class NoMoreSurvivorName
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
