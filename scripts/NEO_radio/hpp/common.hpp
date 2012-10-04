/***************************
//BACKGROUND
***************************/
class NEO_RscBackground
{
	idc = -1; 
	type = 0;
	style = 48;
	colorBackground[] = { };
	colorText[] = { };
	font = "Zeppelin32";
	sizeEx = 0.023;
	moving = 0;
	x = "(safeZoneX + (safeZoneW / 1.8))"; 
	y = "(safeZoneY + (safeZoneH / 3.25))"; 
	w = "(safeZoneW / 3)";
	h = "(safeZoneH / 2)";
};

/***************************
Edit
***************************/
class NEO_RscEdit 
{
	idc = -1;
	type = 2;
	style = 0x00;
	x = "1";
	y = "1";
	w = "safeZoneW / 25";
	h = "safeZoneH / 30";
	
	sizeEx = 0.03;
	font = "Zeppelin32";
	text = "";
	
	colorText[] = {1,1,1,1};
	autocomplete = 0;
	colorSelection[] = {0,0,0,1};
};

/***************************
Text
***************************/
class NEO_RscText
{ 
	idc = -1; 
	type = 13; 
	style = 0x00;
	colorBackground[] = { 0, 0, 0, 0 };
	size = "((safeZoneW / 75) + (safeZoneH / 225))";
	x = "safeZoneX + (safeZoneW / 6)"; 
	y = "safeZoneY + (safeZoneH / 6)"; 
	w = "safeZoneW / 5"; 
	h = "safeZoneH / 10";
	text = "SUPPORT MENU";
	class Attributes 
	{ 
		font = "Zeppelin33Italic"; 
		color = "#C0C0C0"; 
		align = "center"; 
		valign = "middle"; 
		shadow = true; 
		shadowColor = "#000000";
		size = "1"; 
	};
};

/***************************
//Slider
***************************/
class NEO_RscSlider
{ 
	idc = -1;
	type = 43;
	style = 0x400 + 0x10;
	x = "safeZoneX + (safeZoneW / 5.6)";
	y = "safeZoneY + (safeZoneH / 1.6)";
	w = "safeZoneW / 5.5";
	h = "safeZoneH / 40";
	color[] = {1, 1, 1, 0.4};
	colorActive[] = {1, 1, 1, 1};
	colorDisabled[] = {1, 1, 1, 0.2};
	arrowEmpty = "\ca\ui\data\ui_arrow_left_ca.paa";
	arrowFull = "\ca\ui\data\ui_arrow_left_active_ca.paa";
	border = "\ca\ui\data\ui_border_frame_ca.paa";
	thumb = "\ca\ui\data\ui_slider_bar_ca.paa";
};

/***************************
//ListBox
***************************/
class NEO_RscListBox {
	type = 5;
	style = 0 + 0x10;
	font = "Zeppelin32";
	sizeEx = (safeZoneH / 100) + (safeZoneH / 100);
	x = "safeZoneX + (safeZoneW / 5)";
	y = "safeZoneY + (safeZoneH / 2.25)";
	w = "(safeZoneW / 10)";
	h = "(safeZoneH / 17)";
	color[] = {1, 1, 1, 1};
	colorText[] = {0.95, 0.95, 0.95, 1};
	colorScrollbar[] = {0.95, 0.95, 0.95, 1};
	colorSelect[] = {0.023529, 0, 0.0313725, 1};
	colorSelect2[] = {0.023529, 0, 0.0313725, 1};
	colorSelectBackground[] = {0.58, 0.1147, 0.1108, 1};
	colorSelectBackground2[] = {0.58, 0.1147, 0.1108, 1};
	period = 1;
	colorBackground[] = {0, 0, 0, 1};
	maxHistoryDelay = 1.0;
	autoScrollSpeed = -1;
	autoScrollDelay = 5;
	autoScrollRewind = 0;
	soundSelect[] = {"", 0.0, 1};
	soundExpand[] = {"", 0.0, 1};
	soundCollapse[] = {"", 0.0, 1};
};

class NEO_RscGUIListBox : NEO_RscListBox {
	color[] = {1, 1, 1, 1};
	colorText[] = {1, 1, 1, 0.75};
	colorScrollbar[] = {0.95, 0.95, 0.95, 1};
	colorSelect[] = {0.95, 0.95, 0.95, 1};
	colorSelect2[] = {0.95, 0.95, 0.95, 1};
	colorSelectBackground[] = {0.6, 0.839, 0.47, 0.3};
	colorSelectBackground2[] = {0.6, 0.839, 0.47, 1};
	period = 0;
	sizeEx = (safeZoneH / 100) + (safeZoneH / 100);
	class ScrollBar
	{
		color[] = {1, 1, 1, 0.6};
		colorActive[] = {1, 1, 1, 1};
		colorDisabled[] = {1, 1, 1, 0.3};
		thumb = "\ca\ui\data\igui_scrollbar_thumb_ca.paa";
		arrowFull = "\ca\ui\data\igui_arrow_top_active_ca.paa";
		arrowEmpty = "\ca\ui\data\igui_arrow_top_ca.paa";
		border = "\ca\ui\data\igui_border_scroll_ca.paa";
	};
};

/***************************
//ComboBox
***************************/
class NEO_RscComboBox
{
	access = 0;
	type = 4;
	style = 0;
	colorSelect[] = {0.023529,0,0.0313725,1};
	colorText[] = {0.023529,0,0.0313725,1};
	colorBackground[] = {0.95,0.95,0.95,1};
	colorScrollbar[] = {0.023529,0,0.0313725,1};
	soundSelect[] = {"",0.1,1};
	soundExpand[] = {"",0.1,1};
	soundCollapse[] = {"",0.1,1};
	maxHistoryDelay = 1;
	class ScrollBar
	{
		color[] = {1,1,1,0.6};
		colorActive[] = {1,1,1,1};
		colorDisabled[] = {1,1,1,0.3};
		shadow = 0;
		thumb = "\ca\ui\data\ui_scrollbar_thumb_ca.paa";
		arrowFull = "\ca\ui\data\ui_arrow_top_active_ca.paa";
		arrowEmpty = "\ca\ui\data\ui_arrow_top_ca.paa";
		border = "\ca\ui\data\ui_border_scroll_ca.paa";
	};
	x = "safeZoneX + (safeZoneW / 8)";
	y = "safeZoneY + (safeZoneH / 5)";
	w = "(safeZoneW / 10)";
	h = "(safeZoneH / 20)";
	shadow = 0;
	colorSelectBackground[] = {0.8784,0.8471,0.651,1};
	arrowEmpty = "\ca\ui\data\ui_arrow_combo_ca.paa";
	arrowFull = "\ca\ui\data\ui_arrow_combo_active_ca.paa";
	wholeHeight = 0.45;
	color[] = {0,0,0,0.6};
	colorActive[] = {0,0,0,1};
	colorDisabled[] = {0,0,0,0.3};
	font = "Zeppelin32";
	sizeEx = "(safeZoneH / 100) + (safeZoneH / 100)";
};


/***************************
//Button
***************************/
class NEO_RscButton
{
	idc = -1;
	type = 16;
	style = 0x00;
	default = 0;
	shadow = 2;
	x = "safeZoneX + (safeZoneW / 5)";
	y = "safeZoneY + (safeZoneH / 1.525)";
	w = "(safeZoneW / 12.5)";
	h = "(safeZoneH / 20)";
	color[] = {0.8784, 0.8471, 0.651, 1.0};
	color2[] = {0.95, 0.95, 0.95, 1};
	colorBackground[] = {1, 1, 1, 1};
	colorbackground2[] = {1, 1, 1, 0.4};
	colorDisabled[] = {1, 1, 1, 0.25};
	periodFocus = 1.2;
	periodOver = 0.8;
	
	class HitZone
	{
		left = "safeZoneW / 100";
		top = "safeZoneH / 100";
		right = "safeZoneW / 100";
		bottom = "safeZoneH / 100";
	};
	
	class ShortcutPos
	{
		left = "safeZoneW / 100";
		top = "safeZoneH / 100";
		w = "safeZoneW / 100";
		h = "safeZoneH / 100";
	};
	
	class TextPos
	{
		left = "safeZoneW / 50";
		right = "safeZoneW / 50";
		top = "safeZoneH / 75";
		bottom = "safeZoneH / 100";
	};
	animTextureNormal = "\ca\ui\data\ui_button_normal_ca.paa";
	animTextureDisabled = "\ca\ui\data\ui_button_disabled_ca.paa";
	animTextureOver = "\ca\ui\data\ui_button_over_ca.paa";
	animTextureFocused = "\ca\ui\data\ui_button_focus_ca.paa";
	animTexturePressed = "\ca\ui\data\ui_button_down_ca.paa";
	animTextureDefault = "\ca\ui\data\ui_button_default_ca.paa";
	period = 0.4;
	font = "Zeppelin32";
	size = "(safeZoneW / 125) + (safeZoneH / 125)";
	text = "";
	soundEnter[] = {"\ca\ui\data\sound\onover", 0.09, 1};
	soundPush[] = {"\ca\ui\data\sound\new1", 0.0, 0};
	soundClick[] = {"\ca\ui\data\sound\onclick", 0.07, 1};
	soundEscape[] = {"\ca\ui\data\sound\onescape", 0.09, 1};
	textureNoShortcut = "";
	action = "";
	
	class Attributes
	{
		font = "Zeppelin32";
		color = "#E5E5E5";
		align = "left";
		shadow = "true";
	};
	
	class AttributesImage
	{
		font = "Zeppelin32";
		color = "#E5E5E5";
		align = "left";
	};
};

/***********************
//Map Resource
***********************/
class NEO_RscMap
{	
	idc = -1;
	access = 0;
	type = 101;
	
	style = 48;
	colorBackground[] =
	{
		1,
		1,
		1,
		1
	};
	colorOutside[] =
	{
		0,
		0,
		0,
		1
	};
	colorText[] =
	{
		0,
		0,
		0,
		1
	};
	font = "TahomaB";
	sizeEx = 0.04;
	colorSea[] =
	{
		0.46,
		0.65,
		0.74,
		0.5
	};
	colorForest[] =
	{
		0.45,
		0.64,
		0.33,
		0.5
	};
	colorRocks[] =
	{
		0,
		0,
		0,
		0.3
	};
	colorCountlines[] =
	{
		0.85,
		0.8,
		0.65,
		1
	};
	colorMainCountlines[] =
	{
		0.45,
		0.4,
		0.25,
		1
	};
	colorCountlinesWater[] =
	{
		0.25,
		0.4,
		0.5,
		0.3
	};
	colorMainCountlinesWater[] =
	{
		0.25,
		0.4,
		0.5,
		0.9
	};
	colorForestBorder[] =
	{
		0,
		0,
		0,
		0
	};
	colorRocksBorder[] =
	{
		0,
		0,
		0,
		0
	};
	colorPowerLines[] =
	{
		0.1,
		0.1,
		0.1,
		1
	};
	colorRailWay[] =
	{
		0.8,
		0.2,
		0,
		1
	};
	colorNames[] =
	{
		0.1,
		0.1,
		0.1,
		0.9
	};
	colorInactive[] =
	{
		1,
		1,
		1,
		0.5
	};
	colorLevels[] =
	{
		0.65,
		0.6,
		0.45,
		1
	};
	stickX[] =
	{
		0.2,
		{
			"Gamma",
			1,
			1.5
		}
	};
	stickY[] =
	{
		0.2,
		{
			"Gamma",
			1,
			1.5
		}
	};
	class Legend
	{
		colorBackground[] =
		{
			0.906,
			0.901,
			0.88,
			0
		};
		color[] =
		{
			0,
			0,
			0,
			1
		};
		x = "SafeZoneX";
		y = "SafeZoneY";
		w = 0.34;
		h = 0.152;
		font = "Zeppelin32";
		sizeEx = 0.03921;
	};
	class ActiveMarker
	{
		color[] =
		{
			0.3,
			0.1,
			0.9,
			1
		};
		size = 50;
	};
	class Command
	{
		color[] =
		{
			0,
			0.9,
			0,
			1
		};
		icon = "\ca\ui\data\map_waypoint_ca.paa";
		size = 18;
		importance = 1;
		coefMin = 1;
		coefMax = 1;
	};
	class Task
	{
		colorCreated[] =
		{
			0.95,
			0.95,
			0.95,
			1
		};
		colorCanceled[] =
		{
			0.606,
			0.606,
			0.606,
			1
		};
		colorDone[] =
		{
			0.424,
			0.651,
			0.247,
			1
		};
		colorFailed[] =
		{
			0.706,
			0.0745,
			0.0196,
			1
		};
		color[] =
		{
			0.863,
			0.584,
			0,
			1
		};
		icon = "\ca\ui\data\ui_taskstate_current_CA.paa";
		iconCreated = "\ca\ui\data\ui_taskstate_new_CA.paa";
		iconCanceled = "#(argb,8,8,3)color(0,0,0,0)";
		iconDone = "\ca\ui\data\ui_taskstate_done_CA.paa";
		iconFailed = "\ca\ui\data\ui_taskstate_failed_CA.paa";
		size = 27;
		importance = 1;
		coefMin = 1;
		coefMax = 1;
	};
	class CustomMark
	{
		color[] =
		{
			0.6471,
			0.6706,
			0.6235,
			1
		};
		icon = "\ca\ui\data\map_waypoint_ca.paa";
		size = 18;
		importance = 1;
		coefMin = 1;
		coefMax = 1;
	};
	class Tree
	{
		color[] =
		{
			0.45,
			0.64,
			0.33,
			0.4
		};
		icon = "\ca\ui\data\map_tree_ca.paa";
		size = 12;
		importance = "0.9 * 16 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class SmallTree
	{
		color[] =
		{
			0.45,
			0.64,
			0.33,
			0.4
		};
		icon = "\ca\ui\data\map_smalltree_ca.paa";
		size = 12;
		importance = "0.6 * 12 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Bush
	{
		color[] =
		{
			0.45,
			0.64,
			0.33,
			0.4
		};
		icon = "\ca\ui\data\map_bush_ca.paa";
		size = 14;
		importance = "0.2 * 14 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Church
	{
		color[] =
		{
			0,
			0.9,
			0,
			1
		};
		icon = "\ca\ui\data\map_church_ca.paa";
		size = 16;
		importance = "2 * 16 * 0.05";
		coefMin = 0.9;
		coefMax = 4;
	};
	class Chapel
	{
		color[] =
		{
			0,
			0,
			0,
			1
		};
		icon = "\ca\ui\data\map_chapel_ca.paa";
		size = 16;
		importance = "1 * 16 * 0.05";
		coefMin = 0.9;
		coefMax = 4;
	};
	class Cross
	{
		color[] =
		{
			0,
			0.9,
			0,
			1
		};
		icon = "\ca\ui\data\map_cross_ca.paa";
		size = 16;
		importance = "0.7 * 16 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Rock
	{
		color[] =
		{
			0.1,
			0.1,
			0.1,
			0.8
		};
		icon = "\ca\ui\data\map_rock_ca.paa";
		size = 12;
		importance = "0.5 * 12 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Bunker
	{
		color[] =
		{
			0,
			0,
			0,
			1
		};
		icon = "\ca\ui\data\map_bunker_ca.paa";
		size = 14;
		importance = "1.5 * 14 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Fortress
	{
		color[] =
		{
			0,
			0.9,
			0,
			1
		};
		icon = "\ca\ui\data\map_bunker_ca.paa";
		size = 16;
		importance = "2 * 16 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Fountain
	{
		color[] =
		{
			0.2,
			0.45,
			0.7,
			1
		};
		icon = "\ca\ui\data\map_fountain_ca.paa";
		size = 11;
		importance = "1 * 12 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class ViewTower
	{
		color[] =
		{
			0,
			0.9,
			0,
			1
		};
		icon = "\ca\ui\data\map_viewtower_ca.paa";
		size = 16;
		importance = "2.5 * 16 * 0.05";
		coefMin = 0.5;
		coefMax = 4;
	};
	class Lighthouse
	{
		color[] =
		{
			0,
			0.9,
			0,
			1
		};
		icon = "\ca\ui\data\map_lighthouse_ca.paa";
		size = 14;
		importance = "3 * 16 * 0.05";
		coefMin = 0.9;
		coefMax = 4;
	};
	class Quay
	{
		color[] =
		{
			0,
			0.9,
			0,
			1
		};
		icon = "\ca\ui\data\map_quay_ca.paa";
		size = 16;
		importance = "2 * 16 * 0.05";
		coefMin = 0.5;
		coefMax = 4;
	};
	class Fuelstation
	{
		color[] =
		{
			0,
			0.9,
			0,
			1
		};
		icon = "\ca\ui\data\map_fuelstation_ca.paa";
		size = 16;
		importance = "2 * 16 * 0.05";
		coefMin = 0.75;
		coefMax = 4;
	};
	class Hospital
	{
		color[] =
		{
			0.78,
			0,
			0.05,
			1
		};
		icon = "\ca\ui\data\map_hospital_ca.paa";
		size = 16;
		importance = "2 * 16 * 0.05";
		coefMin = 0.5;
		coefMax = 4;
	};
	class BusStop
	{
		color[] =
		{
			0.15,
			0.26,
			0.87,
			1
		};
		icon = "\ca\ui\data\map_busstop_ca.paa";
		size = 12;
		importance = "1 * 10 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Transmitter
	{
		color[] =
		{
			0,
			0.9,
			0,
			1
		};
		icon = "\ca\ui\data\map_transmitter_ca.paa";
		size = 20;
		importance = "2 * 16 * 0.05";
		coefMin = 0.9;
		coefMax = 4;
	};
	class Stack
	{
		color[] =
		{
			0,
			0.9,
			0,
			1
		};
		icon = "\ca\ui\data\map_stack_ca.paa";
		size = 20;
		importance = "2 * 16 * 0.05";
		coefMin = 0.9;
		coefMax = 4;
	};
	class Ruin
	{
		color[] =
		{
			0,
			0.9,
			0,
			1
		};
		icon = "\ca\ui\data\map_ruin_ca.paa";
		size = 16;
		importance = "1.2 * 16 * 0.05";
		coefMin = 1;
		coefMax = 4;
	};
	class Tourism
	{
		color[] =
		{
			0,
			0,
			1,
			1
		};
		icon = "\ca\ui\data\map_tourism_ca.paa";
		size = 16;
		importance = "1 * 16 * 0.05";
		coefMin = 0.7;
		coefMax = 4;
	};
	class Watertower
	{
		color[] =
		{
			0.2,
			0.45,
			0.7,
			1
		};
		icon = "\ca\ui\data\map_watertower_ca.paa";
		size = 20;
		importance = "1.2 * 16 * 0.05";
		coefMin = 0.9;
		coefMax = 4;
	};
	class Waypoint
	{
		color[] =
		{
			0,
			0,
			0,
			1
		};
		size = 24;
		importance = 1;
		coefMin = 1;
		coefMax = 1;
		icon = "\ca\ui\data\map_waypoint_ca.paa";
	};
	class WaypointCompleted
	{
		color[] =
		{
			0,
			0,
			0,
			1
		};
		size = 24;
		importance = 1;
		coefMin = 1;
		coefMax = 1;
		icon = "\ca\ui\data\map_waypoint_completed_ca.paa";
	};
	moveOnEdges = 1;
	x = "(safeZoneX + (safeZoneW / 1.67))";
	y = "(safeZoneY + (safeZoneH / 2.49))";
	w = "(safeZoneW / 4.05)";
	h = "(safeZoneH / 4.2)";
	ptsPerSquareSea = 8;
	ptsPerSquareTxt = 10;
	ptsPerSquareCLn = 10;
	ptsPerSquareExp = 10;
	ptsPerSquareCost = 10;
	ptsPerSquareFor = "6.0f";
	ptsPerSquareForEdge = "15.0f";
	ptsPerSquareRoad = "3f";
	ptsPerSquareObj = 15;
	showCountourInterval = "false";
	maxSatelliteAlpha = 0.75;
	alphaFadeStartScale = 0.15;
	alphaFadeEndScale = 0.29;
	fontLabel = "Zeppelin32";
	sizeExLabel = 0.034;
	fontGrid = "Zeppelin32";
	sizeExGrid = 0.03;
	fontUnits = "Zeppelin32";
	sizeExUnits = 0.034;
	fontNames = "Zeppelin32";
	sizeExNames = 0.056;
	fontInfo = "Zeppelin32";
	sizeExInfo = 0.034;
	fontLevel = "Zeppelin32";
	sizeExLevel = 0.024;
	text = "\ca\ui\data\map_background2_co.paa";
};