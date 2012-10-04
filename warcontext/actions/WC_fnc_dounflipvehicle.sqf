	// -----------------------------------------------
	// Author:  code34 nicolas_boiteux@yahoo.fr
	// warcontext : unlock vehicle for engineer
	// -----------------------------------------------
	 private ["_position", "_object", "_typeof", "_list", "_dir", "_mydir", "_dammage", "_wait"];

	_mydir = getdir player;
	_list = nearestObjects [position player, ["LandVehicle", "Air", "Tank", "Car"], 8];

	if (typeOf player in wcengineerclass) then { _wait = 10; } else { _wait = 20; };

	if(count _list == 0) exitwith {
		wcgarbage = [localize "STR_WC_MENUUNFLIPVEHICLE", localize "STR_WC_MESSAGENOVEHICLENEARYOU", localize "STR_WC_MESSAGEGOCLOSERUNFLIP", 3] spawn WC_fnc_playerhint;
	};

	player playMove "AinvPknlMstpSlayWrflDnon_medic";
	sleep _wait;

	if!(alive player) exitwith {};

	_object = _list select 0;

	wcflip = _object;
	["wcflip", "server"] call WC_fnc_publicvariable;