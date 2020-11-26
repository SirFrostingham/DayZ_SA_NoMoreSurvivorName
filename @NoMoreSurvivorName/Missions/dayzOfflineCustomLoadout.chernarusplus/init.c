void main()
{
	//INIT WEATHER BEFORE ECONOMY INIT------------------------
	Weather weather = g_Game.GetWeather();

	weather.MissionWeather(false);    // false = use weather controller from Weather.c

	weather.GetOvercast().Set( Math.RandomFloatInclusive(0.4, 0.6), 1, 0);
	weather.GetRain().Set( 0, 0, 1);
	weather.GetFog().Set( Math.RandomFloatInclusive(0.05, 0.1), 1, 0);

	//INIT ECONOMY--------------------------------------
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

	//DATE RESET AFTER ECONOMY INIT-------------------------
	int year, month, day, hour, minute;
	int reset_month = 9, reset_day = 20;
	GetGame().GetWorld().GetDate(year, month, day, hour, minute);

	if ((month == reset_month) && (day < reset_day))
	{
		GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
	}
	else
	{
		if ((month == reset_month + 1) && (day > reset_day))
		{
			GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
		}
		else
		{
			if ((month < reset_month) || (month > reset_month + 1))
			{
				GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
			}
		}
	}
}

class CustomMission: MissionServer
{
	void SetRandomHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			int rndHlt = Math.RandomInt(55,100);
			itemEnt.SetHealth("","",rndHlt);
		}
	}

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");//Creates random player
		Class.CastTo(m_player, playerEnt);

		GetGame().SelectPlayer(identity, m_player);

		return m_player;
	}

	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		//DayZ_SA_NoMoreSurvivorName:START
		bool playerNameIsSurvivor = false;
		string characterName = player.GetIdentity().GetName();
		characterName.ToLower();
		
		if ( characterName.Contains("survivor") )
		{
			playerNameIsSurvivor = true;
		}
		//DayZ_SA_NoMoreSurvivorName:END
		
		EntityAI itemTop;
		EntityAI itemEnt;
		ItemBase itemBs;
		float rand;

		itemTop = player.FindAttachmentBySlotName("Body");

		if ( itemTop )
		{
			itemEnt = itemTop.GetInventory().CreateInInventory("Rag");
			if ( Class.CastTo(itemBs, itemEnt ) )
				itemBs.SetQuantity(4);

			SetRandomHealth(itemEnt);

			string chemlightArray[] = { "Chemlight_White", "Chemlight_Yellow", "Chemlight_Green", "Chemlight_Red" };
			int rndIndex = Math.RandomInt(0, 4);
			itemEnt = itemTop.GetInventory().CreateInInventory(chemlightArray[rndIndex]);
			SetRandomHealth(itemEnt);

			rand = Math.RandomFloatInclusive(0.0, 1.0);
			if ( rand < 0.35 )
				itemEnt = player.GetInventory().CreateInInventory("Apple");
			else if ( rand > 0.65 )
				itemEnt = player.GetInventory().CreateInInventory("Pear");
			else
				itemEnt = player.GetInventory().CreateInInventory("Plum");

			SetRandomHealth(itemEnt);
		}
		
		//OPTIONAL:DayZ_SA_NoMoreSurvivorName:CustomLoadoutExample:START
		
			// UNCOMMENT THE FOLLOWING BLOCK IF YOU WANT A NICE LOADOUT
			// // NICE LOADOUT
			// player.RemoveAllItems();
			// switch (Math.RandomInt(0, 1)) { 
			// case 0:
			// // FNX45
			
				// player.GetInventory().CreateInInventory("CoyoteBag_Green");itemBs = ItemBase.Cast(itemEnt);
				// player.GetInventory().CreateInInventory("TTSKOPants");itemBs = ItemBase.Cast(itemEnt);
				// player.GetInventory().CreateInInventory("TTsKOJacket_Camo");itemBs = ItemBase.Cast(itemEnt);
				// player.GetInventory().CreateInInventory("CombatBoots_Black");itemBs = ItemBase.Cast(itemEnt);
				// player.GetInventory().CreateInInventory("CombatKnife");itemBs = ItemBase.Cast(itemEnt);
				
				// player.GetInventory().CreateInInventory("FNX45");itemBs = ItemBase.Cast(itemEnt);
				// player.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");itemBs = ItemBase.Cast(itemEnt);
				// player.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");itemBs = ItemBase.Cast(itemEnt);	
				// player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");itemBs = ItemBase.Cast(itemEnt); 
				// player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");itemBs = ItemBase.Cast(itemEnt);
				// player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");itemBs = ItemBase.Cast(itemEnt);
				// itemEnt = player.GetInventory().CreateInInventory( "akm" ); 
				// itemEnt.GetInventory().CreateAttachment( "PSO11Optic" ); 
				// itemEnt.GetInventory().CreateAttachment( "AK_WoodBttstck" ); 
				// itemEnt.GetInventory().CreateAttachment( "AK_WoodHndgrd" );
				// itemEnt.GetInventory().CreateAttachment( "AK_Suppressor" );
				
				// player.GetInventory().CreateInInventory("Rag");itemBs = ItemBase.Cast(itemEnt); 
				// player.GetInventory().CreateInInventory("Chemlight_White");itemBs = ItemBase.Cast(itemEnt); 
				// player.GetInventory().CreateInInventory("StoneKnife");itemBs = ItemBase.Cast(itemEnt); 
				// player.GetInventory().CreateInInventory("Apple");itemBs = ItemBase.Cast(itemEnt); 
				// player.GetInventory().CreateInInventory("Apple");itemBs = ItemBase.Cast(itemEnt); 
				
				// player.GetInventory().CreateInInventory("SpaghettiCan");itemBs = ItemBase.Cast(itemEnt); 
				// player.GetInventory().CreateInInventory("SpaghettiCan");itemBs = ItemBase.Cast(itemEnt); 
				// player.GetInventory().CreateInInventory("BakedBeansCan");itemBs = ItemBase.Cast(itemEnt); 
				// player.GetInventory().CreateInInventory("BakedBeansCan");itemBs = ItemBase.Cast(itemEnt); 
				
				// player.GetInventory().CreateInInventory("Waterbottle");itemBs = ItemBase.Cast(itemEnt); 
				// player.GetInventory().CreateInInventory("Waterbottle");itemBs = ItemBase.Cast(itemEnt); 
			// break; 
			// case 1: 
			// // M4A1_Black
				// player.GetInventory().CreateInInventory("CoyoteBag_Green");itemBs = ItemBase.Cast(itemEnt);
				// player.GetInventory().CreateInInventory("GorkaPants_Autumn");itemBs = ItemBase.Cast(itemEnt);
				// player.GetInventory().CreateInInventory("GorkaEJacket_Autumn");itemBs = ItemBase.Cast(itemEnt);
				// player.GetInventory().CreateInInventory("CombatBoots_Black");itemBs = ItemBase.Cast(itemEnt);
				// player.GetInventory().CreateInInventory("CombatKnife");itemBs = ItemBase.Cast(itemEnt); 
				
				// itemEnt = player.GetInventory().CreateInInventory( "M4A1_Black" ); 
				// itemEnt.GetInventory().CreateAttachment( "M4_Suppressor" ); 
				// itemEnt.GetInventory().CreateAttachment( "M4_RISHndgrd_Black" ); 
				// itemEnt.GetInventory().CreateAttachment( "M4_MPBttstck_Black" );
				// itemEnt.GetInventory().CreateAttachment( "ACOGOptic" );
				
					
				// player.GetInventory().CreateInInventory("FNX45");itemBs = ItemBase.Cast(itemEnt);
				// player.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");itemBs = ItemBase.Cast(itemEnt);
				// player.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");itemBs = ItemBase.Cast(itemEnt);	
				// player.GetInventory().CreateInInventory("Mag_STANAGCoupled_30Rnd");itemBs = ItemBase.Cast(itemEnt); 
				// player.GetInventory().CreateInInventory("Mag_STANAGCoupled_30Rnd");itemBs = ItemBase.Cast(itemEnt); 
				// player.GetInventory().CreateInInventory("Mag_STANAGCoupled_30Rnd");itemBs = ItemBase.Cast(itemEnt); 
				
				// player.GetInventory().CreateInInventory("Rag");itemBs = ItemBase.Cast(itemEnt); 
				// player.GetInventory().CreateInInventory("Chemlight_White");itemBs = ItemBase.Cast(itemEnt); 
				// player.GetInventory().CreateInInventory("StoneKnife");itemBs = ItemBase.Cast(itemEnt); 
				// player.GetInventory().CreateInInventory("Apple");itemBs = ItemBase.Cast(itemEnt); 
				// player.GetInventory().CreateInInventory("Apple");itemBs = ItemBase.Cast(itemEnt); 
				
				// player.GetInventory().CreateInInventory("SpaghettiCan");itemBs = ItemBase.Cast(itemEnt); 
				// player.GetInventory().CreateInInventory("SpaghettiCan");itemBs = ItemBase.Cast(itemEnt); 
				// player.GetInventory().CreateInInventory("BakedBeansCan");itemBs = ItemBase.Cast(itemEnt); 
				// player.GetInventory().CreateInInventory("BakedBeansCan");itemBs = ItemBase.Cast(itemEnt); 
				
				// player.GetInventory().CreateInInventory("Waterbottle");itemBs = ItemBase.Cast(itemEnt); 
				// player.GetInventory().CreateInInventory("Waterbottle");itemBs = ItemBase.Cast(itemEnt); 
			// break; 
			// }
		
		// Custom low quality gear
		player.GetInventory().CreateInInventory("FNX45");itemBs = ItemBase.Cast(itemEnt);
		player.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");itemBs = ItemBase.Cast(itemEnt);
		player.GetInventory().CreateInInventory("Mag_FNX45_15Rnd");itemBs = ItemBase.Cast(itemEnt);
		player.GetInventory().CreateInInventory("Flashlight");itemBs = ItemBase.Cast(itemEnt);
		player.GetInventory().CreateInInventory("Battery9V");itemBs = ItemBase.Cast(itemEnt);
		
		// required to get nice loadout to happen
		itemTop = player.FindAttachmentBySlotName("Body");

		if ( itemTop )
		{
			itemEnt = itemTop.GetInventory().CreateInInventory("Rag");
			if ( Class.CastTo(itemBs, itemEnt ) )
				itemBs.SetQuantity(4);

			SetRandomHealth(itemEnt);
			itemEnt = itemTop.GetInventory().CreateInInventory(chemlightArray[rndIndex]);
			SetRandomHealth(itemEnt);
		}
		//OPTIONAL:DayZ_SA_NoMoreSurvivorName:CustomLoadoutExample:END
		
		//DayZ_SA_NoMoreSurvivorName:START
		if ( playerNameIsSurvivor )
		{
			player.RemoveAllItems();
			
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(SurvivorDetected, 5000, true, player);
		}
		//DayZ_SA_NoMoreSurvivorName:END
	}
	
	//DayZ_SA_NoMoreSurvivorName START
	protected void SurvivorDetected(PlayerBase player)
	{
		sendPlayerMessage(player, "Since your name is 'Survivor', you spawn NAKED!");
		sendPlayerMessage(player, "If you give yourself a name, you get starter gear with clothes, backpack, basic gear and a handgun with ammo!");
		sendPlayerMessage(player, "Name process: Steam -> DayZ -> right-click / properties -> set launch parameters -> set to: -name=\"Your Name\"");
	}
	
	protected void sendPlayerMessage(PlayerBase player, string message)    
    {
		if((player) && (message != ""))
		{
			Param1<string> Msgparam;
			Msgparam = new Param1<string>(message);
			GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, Msgparam, true, player.GetIdentity());
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(SurvivorDetected);
		}
    }
	//DayZ_SA_NoMoreSurvivorName END
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}