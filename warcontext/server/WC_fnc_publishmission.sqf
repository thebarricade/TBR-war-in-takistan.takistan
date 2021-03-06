	// -----------------------------------------------
	// Author: code34 nicolas_boiteux@yahoo.fr
	// Send variables to join players (JIP)

	if (!isServer) exitWith {};

	private [
		"_count",
		"_ok",
		"_name",
		"_variables"
	];
	
	_name = _this select 1;

	diag_log format["WARCONTEXT: PLAYER %1 CONNECTING", _name];

	_ok = true;
	_count = 0;

	// WAIT THAT JIP CLIENT IS INITIALIZED
	while {_ok} do {
		if(_name in wcplayerready) then {
			_ok = false;
		};
		if(_count > 480) then {
			_ok = _false;
		};
		_count = _count + 1;
		sleep 1;
	};

	_variables = [
		"wcobjective",
		"wcnuclearzone",
		"wchostage",
		"wccfgpatches",
		"wcday",
		"wcweather",
		"wcselectedzone",
		"wcradioalive",
		"wcskill",
		"wclevel",
		"wcmissioncount",
		"wcmotd",
		"wcenemykilled",
		"wccivilkilled",
		"wconelife",
		"wcinteam",
		"wcteleport"
	];

	{
		[_x, "client"] call WC_fnc_publicvariable;
		sleep 0.2;
	}foreach _variables; 


	diag_log format["WARCONTEXT: PLAYER %1 CONNECTED", _name];
