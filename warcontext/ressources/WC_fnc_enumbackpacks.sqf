// -----------------------------------------------
	// Author:  thebarricade anders@thebarricade.net
	// Enums backpacks - warcontext
	// -----------------------------------------------

	private ["_cfg", "_cfgsides", "_objectype", "_objectname", "_object", "_count", "_backpacks", "_ace_backpacks", "_cfg","_displayname", "_displaynames"];

	_backpacks = [];
	_displaynames = [];

	_backpacks = [
		"US_Assault_Pack_EP1",
		"US_Patrol_Pack_EP1",
		"US_Backpack_EP1",
		"CZ_Backpack_EP1",
		"CZ_VestPouch_EP1",
		"TK_ALICE_Pack_EP1",
		"TK_Assault_Pack_EP1"
	];

	if(wcwithACE == 1) then {
		if(isClass(configFile >> "cfgPatches" >> "ace_main")) then {
			_ace_backpacks = [
				"ACE_ALICE_Backpack",
				"ACE_ANPRC77",
				"ACE_AssaultPack_BAF",
				"ACE_BackPack",
				"ACE_BackPack_ACR",
				"ACE_BackPack_ACR_DDPM",
				"ACE_BackPack_ACR_DPM",
				"ACE_BackPack_ACR_FL",
				"ACE_BackPack_ACR_MTP",
				"ACE_BackPack_ACR_TT",
				"ACE_Backpack_ACU",
				"ACE_Backpack_CivAssault",
				"ACE_Backpack_FL",
				"ACE_Backpack_Multicam",
				"ACE_Backpack_Olive",
				"ACE_Backpack_RPG",
				"ACE_Backpack_TT",
				"ACE_Backpack_US",
				"ACE_Backpack_Wood",
				"ACE_CharliePack",
				"ACE_CharliePack_ACU",
				"ACE_CharliePack_ACU_Medic",
				"ACE_CharliePack_FLORA",
				"ACE_CharliePack_Multicam",
				"ACE_CharliePack_WMARPAT",
				"ACE_Combat_Pack",
				"ACE_Coyote_Pack",
				"ACE_Coyote_Pack_Black",
				"ACE_Coyote_Pack_Flora",
				"ACE_Coyote_Pack_Multicam",
				"ACE_Coyote_Pack_Wood",
				"ACE_FAST_PackEDC",
				"ACE_FAST_PackEDC_ACU",
				"ACE_P159_RD54",
				"ACE_P159_RD90",
				"ACE_P159_RD99",
				"ACE_P168_RD90",
				"ACE_PRC119",
				"ACE_PRC119_ACU",
				"ACE_PRC119_MAR",
				"ACE_Rucksack_EAST",
				"ACE_Rucksack_EAST_Medic",
				"ACE_Rucksack_MOLLE_ACU",
				"ACE_Rucksack_MOLLE_ACU_Medic",
				"ACE_Rucksack_MOLLE_Brown",
				"ACE_Rucksack_MOLLE_Brown_Medic",
				"ACE_Rucksack_MOLLE_DMARPAT",
				"ACE_Rucksack_MOLLE_DMARPAT_Medic",
				"ACE_Rucksack_MOLLE_Green",
				"ACE_Rucksack_MOLLE_Green_Medic",
				"ACE_Rucksack_MOLLE_WMARPAT",
				"ACE_Rucksack_MOLLE_WMARPAT_Medic",
				"ACE_Rucksack_MOLLE_Wood",
				"ACE_Rucksack_RD54",
				"ACE_Rucksack_RD90",
				"ACE_Rucksack_RD91",
				"ACE_Rucksack_RD92",
				"ACE_Rucksack_RD99",
				"ACE_Stretcher",
				"ACE_VTAC_RUSH72",
				"ACE_VTAC_RUSH72_ACU",
				"ACE_VTAC_RUSH72_FT_MEDIC",
				"ACE_VTAC_RUSH72_OD",
				"ACE_VTAC_RUSH72_TT_MEDIC"
			];

			_backpacks = _backpacks + _ace_backpacks
		};
	};

	_backpacks;