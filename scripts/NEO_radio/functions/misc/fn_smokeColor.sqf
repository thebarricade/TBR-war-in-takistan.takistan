private ["_smoke", "_color"];
_smoke = _this;
_color = switch (typeOf _smoke) do
{
	case "SmokeShell" : { "white" };
	case "SmokeShellRed": { "red" };
	case "SmokeShellGreen": { "green" };
	case "SmokeShellYellow": { "yellow" };
	case "SmokeShellPurple": { "purple" };
	case "SmokeShellBlue": { "blue" };
	case "SmokeShellOrange": { "orange" };
	case "1Rnd_Smoke_M203": { "white" };
	case "1Rnd_SmokeRed_M203": { "red" };
	case "1Rnd_SmokeGreen_M203": { "green" };
	case "1Rnd_SmokeYellow_M203": { "yellow" };
	case "1Rnd_SMOKE_GP25": { "white" };
	case "1Rnd_SMOKERED_GP25": { "red" };
	case "1Rnd_SMOKEGREEN_GP25": { "green" };
	case "1Rnd_SMOKEYELLOW_GP25": { "yellow" };
	case DEFAULT { "white" };
};

_color;
