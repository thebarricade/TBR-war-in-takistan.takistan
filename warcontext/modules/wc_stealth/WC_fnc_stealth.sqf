	// -----------------------------------------------
	// Author:  code34 nicolas_boiteux@yahoo.fr
	// warcontext  - steatlh modules - 
	// player disguised until be discovered 

	private [
		"_detected",
		"_enemys",
		"_find",
		"_group",
		"_unit"
	];

	_unit = _this select 0;

	_detected = false;

	while { ((alive _unit) and !(_detected)) } do {
		_enemys = nearestObjects[_unit,["Man"], 10];
		_find = false;
		{		
			if!(_find) then {
				if((side _x) in wcenemyside) then {
					if((date select 4 < 20) and (date select 4 >5)) then {
						if (random 10 > (_x distance player)) then {
							_x dowatch player;
							wcalerttoadd = round ((10 - (_x distance player)) * 3);
							["wcalerttoadd", "server"] call WC_fnc_publicvariable;
							wcgarbage = [localize "STR_WC_MESSAGESTEALTH", localize "STR_WC_MESSAGEABEENLOOKED", localize "STR_WC_MESSAGESTEALTHRUN", 10] spawn WC_fnc_playerhint;
							_find = true;
						};
					} else {
						if (random 5 > (_x distance player)) then {
							_x dowatch player;
							wcalerttoadd = round ((10 - (_x distance player)) * 3);
							["wcalerttoadd", "server"] call WC_fnc_publicvariable;
							wcgarbage = [localize "STR_WC_MESSAGESTEALTH", localize "STR_WC_MESSAGEABEENLOOKED", localize "STR_WC_MESSAGESTEALTHRUN", 10] spawn WC_fnc_playerhint;
							_find = true;
						};
					};
					if(side player == west) then {
						_detected = true;
					};
				};
			};
		}foreach _enemys;
		if(wcalert > 99 ) then {
			_detected = true;
		};
		sleep 5;
	};
			

	if((_detected) and (alive _unit)) then {
		_group = creategroup west;
		[player] joinsilent _group;
		_enemys = nearestObjects[_unit,["Man"], 40];
		{		
			if((side _x) in wcenemyside) then {
				_x dotarget player;
				_x dofire player;
				(group _x) reveal player;
			};
		}foreach _enemys;

		sleep 2;

		wcgarbage = [localize "STR_WC_MESSAGESTEALTH", localize "STR_WC_MESSAGEABEENDETECTED", localize "STR_WC_MESSAGESTEALTHRUN", 10] spawn WC_fnc_playerhint;
	};