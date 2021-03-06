private 
[
	"_display", "_map", "_transportBaseButton", "_text", "_lb", "_index", "_transportArray", "_transportUnitLb", "_chopper", "_status",
	"_supportMarker", "_slider", "_sliderText", "_transportHeightCombo", "_transportSpeedCombo", "_transportRoeCombo", "_transportComboText", "_flyingProperties", 
	"_height", "_speed", "_roeIndex", "_roe"
];
_display = findDisplay 655555;
_map = _display displayCtrl 655560;
_transportBaseButton = _display displayCtrl 655575;
_text = _display displayCtrl 655572;
_lb = _this select 0;
_index = _this select 1;
_transportArray = NEO_radioLogic getVariable format ["NEO_radioTrasportArray_%1", side player];
_transportUnitLb = _display displayCtrl 655568;
_chopper = _transportArray select (lbCurSel _transportUnitLb) select 0; if (!isNil { NEO_radioLogic getVariable "NEO_radioTalkWithPilot" }) then { _chopper = vehicle player };
_status = _chopper getVariable "NEO_radioTrasportUnitStatus";
_supportMarker = NEO_radioLogic getVariable "NEO_supportMarker";
_slider = _display displayCtrl 655578;
_sliderText = _display displayCtrl 655579;
_transportHeightCombo = _display displayCtrl 655630;
_transportSpeedCombo = _display displayCtrl 655631;
_transportRoeCombo = _display displayCtrl 655632;
_transportComboText = _display displayCtrl 655633;
_flyingProperties = _chopper getVariable "NEO_radioTrasportUnitFlyingProperties";
_height = _flyingProperties select 0;
_speed = _flyingProperties select 1;
_roe = _flyingProperties select 2;
uinamespace setVariable ["NEO_radioCbVehicle", _chopper];

//Help Text
_text ctrlSetStructuredText parseText (switch (_status) do
{
	case "NONE" : { "<t color='#00FF00' size='0.7' font='Zeppelin33Italic'>Unit is available and waiting for task</t>" };
	case "KILLED" : { "<t color='#FF0000' size='0.7' font='Zeppelin33Italic'>Unit is combat innefective</t>" };
	case "MISSION" : { "<t color='#FFFF00' size='0.7' font='Zeppelin33Italic'>Unit is on a mission, you may abort or change the current task</t>" };
	case "RTB" : { "<t color='#FFFF00' size='0.7' font='Zeppelin33Italic'>Unit is RTB</t>" };
	case "SMOKE" : { "<t color='#FFFF00' size='0.7' font='Zeppelin33Italic'>Unit is waiting for smoke</t>" };
	case "SMOKECONF" : { "<t color='#FFFF00' size='0.7' font='Zeppelin33Italic'>Unit is waiting for smoke confirmation</t>" };
	case "CARGO" : { "<t color='#FFFF00' size='0.7' font='Zeppelin33Italic'>Unit is waiting for cargo to board</t>" };
});

//Base Button
if (_status == "RTB" || _status == "NONE" || _status == "KILLED") then
{
	_transportBaseButton ctrlEnable false;
}
else
{
	_transportBaseButton ctrlEnable true;
};

//Smoke Confirm Buttons
private ["_transportSmokeFoundButton", "_transportSmokeNotFoundButton"];
_transportSmokeFoundButton = _display displayCtrl 655576;
_transportSmokeNotFoundButton = _display displayCtrl 655577;

if (_chopper getVariable "NEO_radioTrasportUnitStatus" == "SMOKECONF") then
{
	_transportSmokeFoundButton ctrlEnable true; _transportSmokeFoundButton ctrlSetPosition [safeZoneX + (safeZoneW / 2.3), safeZoneY + (safeZoneH / 1.425), (safeZoneW / 8), (safeZoneH / 20)]; _transportSmokeFoundButton ctrlCommit 0;
	_transportSmokeNotFoundButton ctrlEnable true; _transportSmokeNotFoundButton ctrlSetPosition [safeZoneX + (safeZoneW / 2.175), safeZoneY + (safeZoneH / 1.375), (safeZoneW / 10), (safeZoneH / 20)]; _transportSmokeNotFoundButton ctrlCommit 0;
}
else
{
	_transportSmokeFoundButton ctrlEnable false; _transportSmokeFoundButton ctrlSetPosition [safeZoneX + (safeZoneW / 2.3), safeZoneY + (safeZoneH / 1.425), (safeZoneW / 1000), (safeZoneH / 1000)]; _transportSmokeFoundButton ctrlCommit 0;
	_transportSmokeNotFoundButton ctrlEnable false; _transportSmokeNotFoundButton ctrlSetPosition [safeZoneX + (safeZoneW / 2.175), safeZoneY + (safeZoneH / 1.375), (safeZoneW / 1000), (safeZoneH / 1000)]; _transportSmokeNotFoundButton ctrlCommit 0;
};

//Transport Tasks
private ["_transportTaskLb", "_transportTaskText", "_transportHelpTaskText", "_tasksArray"];
_transportTaskLb = _display displayCtrl 655569;
_transportTaskText = _display displayCtrl 655571;
_transportHelpTaskText = _display displayCtrl 655573;
_tasksArray = _chopper getVariable "NEO_transportAvailableTasks";

//Re-initialize Controls
{ _x ctrlSetPosition [1, 1, (safeZoneW / 1000), (safeZoneH / 1000)]; _x ctrlCommit 0; } forEach [_slider, _sliderText, _transportHeightCombo, _transportSpeedCombo, _transportRoeCombo];
{ _x ctrlSetText "" } forEach [_sliderText, _transportTaskText, _transportHelpTaskText, _transportComboText];
{ lbClear _x } forEach [_transportTaskLb, _transportHeightCombo, _transportSpeedCombo, _transportRoeCombo];

if (_status != "KILLED") then
{
	//Help Text
	_transportTaskText ctrlSetStructuredText parseText "<t color='#FFFFFF' size='0.8' font='Zeppelin33Italic'>TASK</t>";
	_transportHelpTaskText ctrlSetStructuredText parseText "<t color='#FFFF00' size='0.7' font='Zeppelin33Italic'>Select a task</t>";
	
	{
		_transportTaskLb lbAdd (toUpper _x);
	} forEach _tasksArray;
	_transportTaskLb ctrlEnable true;
	_transportTaskLb ctrlSetEventHandler ["LBSelChanged", "_this call NEO_fnc_transportTaskLbSelChanged"];

	//GPS
	uinamespace setVariable ["NEO_transportMarkerCreated", nil];
	_supportMarker setMarkerAlphaLocal 0;
	
	//GPS
	_map ctrlSetEventHandler ["MouseButtonDown", "_this call NEO_fnc_radioMapEvent"];
	
	//ComboBoxes
	_transportHeightCombo ctrlEnable true; _transportHeightCombo ctrlSetPosition [safeZoneX + (safeZoneW / 3.000), safeZoneY + (safeZoneH / 1.601), (safeZoneW / 10), (safeZoneH / 60)]; _transportHeightCombo ctrlCommit 0;
	_transportSpeedCombo ctrlEnable true; _transportSpeedCombo ctrlSetPosition [safeZoneX + (safeZoneW / 3.000), safeZoneY + (safeZoneH / 1.557), (safeZoneW / 10), (safeZoneH / 60)]; _transportSpeedCombo ctrlCommit 0;
	_transportRoeCombo ctrlEnable true; _transportRoeCombo ctrlSetPosition [safeZoneX + (safeZoneW / 3.000), safeZoneY + (safeZoneH / 1.514), (safeZoneW / 10), (safeZoneH / 60)]; _transportRoeCombo ctrlCommit 0;
	_transportComboText ctrlSetText "Behaviour"; _transportComboText ctrlSetPosition [safeZoneX + (safeZoneW / 3.000), safeZoneY + (safeZoneH / 1.650), (safeZoneW / 10), (safeZoneH / 60)]; _transportComboText ctrlCommit 0;
	
	lbClear _transportHeightCombo;
	{
		_transportHeightCombo lbAdd _x;
	} forEach ["Height - Low", "Height - Medium", "Height - High"];
	_transportHeightCombo lbSetCurSel _height;
	
	lbClear _transportSpeedCombo;
	{
		_transportSpeedCombo lbAdd _x;
	} forEach ["Speed - Slow", "Speed - Normal", "Speed - Fast"];
	_transportSpeedCombo lbSetCurSel _speed;
	
	lbClear _transportRoeCombo;
	{
		_transportRoeCombo lbAdd _x;
	} forEach ["Roe - Hold Fire", "Roe - Fire"];
	_transportRoeCombo lbSetCurSel _roe;
	
	//ComboBoxes EventHandlers
	{
		_x ctrlSetEventHandler ["lbSelChanged", "_this call NEO_fnc_radioTransportOnComboCurSelChanged"];
	} forEach [_transportHeightCombo, _transportSpeedCombo, _transportRoeCombo];
};

//Confirm Button
[] call NEO_fnc_transportConfirmButtonEnable;
