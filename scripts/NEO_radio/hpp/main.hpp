#include "common.hpp"

class NEO_resourceRadio
{
	idd = 655555;
	onLoad = "_this call NEO_fnc_radioOnLoad";
	onUnload = "_this call NEO_fnc_radioOnUnload";
	
	class controls
	{
		//Background
		class NEO_radioBackground : NEO_RscBackground
		{
			idc = -1;
			x = "(safeZoneX + (safeZoneW / 6))";
			y = "(safeZoneY + (safeZoneH / 3.25))";
			w = "(safeZoneW / 1.5)";
			h = "(safeZoneH / 2.1)";
			text = "\ca\ui\data\ui_messagebox_middle_ca.paa";
			moving = 0;
		};
		
		//GPS
		class NEO_radioGps : NEO_RscBackground
		{
			idc = -1;
			text = "\ca\ui\data\ui_gps_ca.paa";
			moving = 0;
		};
		
		//MAP
		class NEO_radioMap : NEO_RscMap
		{
			idc = 655560;
		};
		
		//Tour Logo
		class NEO_radioLogo : NEO_RscBackground
		{
			idc = -1;
			x = "(safeZoneX + (safeZoneW / 3.6))"; 
			y = "(safeZoneY + (safeZoneH / 3.085))"; 
			w = "(safeZoneW / 50)";
			h = "(safeZoneH / 50)";
			text = "scripts\NEO_radio\img\logo.paa";
			moving = 0;
		};
		
		//Radio Title
		class NEO_radioTitle : NEO_RscText
		{
			idc = -1;
			x = "(safeZoneX + (safeZoneW / 3.4))";
			y = "(safeZoneY + (safeZoneH / 3.1))";
			w = "(safeZoneW / 6.9)";
			h = "(safeZoneH / 40)";
			text = "SUPPORT RADIO";
			class Attributes 
			{ 
				font = "Zeppelin33Italic"; 
				color = "#FFFFFF"; 
				align = "center"; 
				valign = "middle"; 
				shadow = true;
				shadowColor = "#000000";
				size = "1.1";
			};
		};
		
		//Main Support Title
		class NEO_radioMainTitle : NEO_radioTitle
		{
			idc = -1;
			x = "(safeZoneX + (safeZoneW / 5.9))";
			y = "(safeZoneY + (safeZoneH / 2.5))";
			w = "(safeZoneW / 7.5)";
			h = "(safeZoneH / 60)";
			text = "AVAILABLE SUPPORT:";
			class Attributes 
			{ 
				font = "Zeppelin33Italic"; 
				color = "#FFFFFF"; 
				align = "center"; 
				valign = "middle"; 
				shadow = true; 
				shadowColor = "#000000";
				size = "0.8";
			};
		};
		
		//Abort Button
		class NEO_radioAbort : NEO_RscButton
		{
			idc = 655561;
			text = "CLOSE";
			x = "safeZoneX + (safeZoneW / 5.5)";
			y = "safeZoneY + (safeZoneH / 1.375)";
			w = "(safeZoneW / 7.5)";
			h = "(safeZoneH / 20)";
		};
		
		//Main Support ListBox
		class NEO_radioMainList : NEO_RscGUIListBox
		{
			idc = 655565;
			sizeEx = (safeZoneW / 75) + (safeZoneH / 275);
			rowHeight = (safeZoneW / 75) + (safeZoneH / 275);
			x = "safeZoneX + (safeZoneW / 5.7)";
			w = "(safeZoneW / 7.5)";
			h = "(safeZoneH / 6.5)";
		};
		
		//=========================
		//Transport Unit ListBox
		class NEO_radioTransportUnitList : NEO_RscGUIListBox
		{
			idc = 655568;
			sizeEx = (safeZoneW / 100) + (safeZoneH / 300);
			rowHeight = (safeZoneW / 100) + (safeZoneH / 300);
			x = "safeZoneX + (safeZoneW / 3)";
			y = "safeZoneY + (safeZoneH / 2.35)";
			w = "(safeZoneW / 10)";
			h = "(safeZoneH / 16)";
		};
		
		//Transport Task ListBox
		class NEO_radioTransportTaskList : NEO_radioTransportUnitList
		{
			idc = 655569;
			x = "safeZoneX + (safeZoneW / 2.25)";
		};
		
		//Transport Unit LB Text
		class NEO_radioTransportUnitText : NEO_RscText
		{
			idc = 655570;
			x = "(safeZoneX + (safeZoneW / 3))";
			y = "(safeZoneY + (safeZoneH / 2.5))";
			w = "(safeZoneW / 12)";
			h = "(safeZoneH / 50)";
			text = "";
		};
		
		//Transport Task LB Text
		class NEO_radioTransportTaskText : NEO_radioTransportUnitText
		{
			idc = 655571;
			x = "(safeZoneX + (safeZoneW / 2.25))";
			text = "";
		};
		
		//Transport Help Unit Text
		class NEO_radioTransportHelpUnitText : NEO_radioTransportUnitText
		{
			idc = 655572;
			x = "(safeZoneX + (safeZoneW / 3))";
			y = "(safeZoneY + (safeZoneH / 2))";
			w = "(safeZoneW / 12.5)";
			h = "(safeZoneH / 6)";
			text = "";
		};
		
		//Transport Help Task Text
		class NEO_radioTransportHelpTaskText : NEO_radioTransportHelpUnitText
		{
			idc = 655573;
			x = "(safeZoneX + (safeZoneW / 2.225))";
			text = "";
		};
		
		//Transport Confirm Button
		class NEO_radioTransportConfirmButton : NEO_RscButton
		{
			idc = 655574;
			x = "safeZoneX + (safeZoneW / 3)";
			y = "safeZoneY + (safeZoneH / 1.425)";
			w = "(safeZoneW / 1000)";
			h = "(safeZoneH / 1000)";
			text = "Confirm";
		};
		
		//Transport Base Button
		class NEO_radioTransportBaseButton : NEO_radioTransportConfirmButton
		{
			idc = 655575;
			y = "safeZoneY + (safeZoneH / 1.375)";
			text = "Go back to Base";
		};
		
		//Transport Smoke Found Button
		class NEO_radioTransportSmokeFoundButton : NEO_radioTransportConfirmButton
		{
			idc = 655576;
			x = "safeZoneX + (safeZoneW / 2.75)";
			text = "Confirm Smoke";
		};
		
		//Transport Smoke Found Button
		class NEO_radioTransportSmokeNotFoundButton : NEO_radioTransportBaseButton
		{
			idc = 655577;
			y = "safeZoneY + (safeZoneH / 1.375)";
			text = "New Smoke";
		};
		
		//Circle Slider
		class NEO_radioTransportCircleSlider : NEO_RscSlider
		{
			idc = 655578;
			x = "safeZoneX + (safeZoneW / 2.275)";
			y = "safeZoneY + (safeZoneH / 1.601)";
			w = "(safeZoneW / 1000)";
			h = "(safeZoneH / 1000)";
		};
		
		//Circle Slider Text
		class NEO_radioTransportCircleSliderText : NEO_radioTransportHelpUnitText
		{
			idc = 655579;
			x = "safeZoneX + (safeZoneW / 2.255)";
			y = "safeZoneY + (safeZoneH / 1.650)";
			w = "safeZoneW / 1000";
			h = "safeZoneH / 1000";
			text = "Radius: 100/300";
			class Attributes 
			{ 
				font = "Zeppelin33Italic"; 
				color = "#FFFFFF"; 
				align = "center"; 
				valign = "middle"; 
				shadow = true; 
				shadowColor = "#000000";
				size = "0.55";
			};
		};
		
		//Properties Text
		class NEO_radioTransportPropertiesText : NEO_radioTransportCircleSliderText
		{
			idc = 655633;
			text = "Behaviour";
			x = "safeZoneX + (safeZoneW / 100)";
			y = "safeZoneY + (safeZoneH / 100)";
			w = "safeZoneW / 1000";
			h = "safeZoneH / 1000";
		};
		
		//FlyInHeight CB
		class NEO_radioTransportHeightCb : NEO_RscComboBox
		{
			idc = 655630;
			x = "safeZoneX + (safeZoneW / 100)";
			y = "safeZoneY + (safeZoneH / 100)";
			w = "safeZoneW / 1000";
			h = "safeZoneH / 1000";
			colorSelectBackground[] = {0.500, 0.800, 0.500, 1.000};
			colorSelect[] = {0.023529, 0, 0.0313725, 1.000};
			colorText[] = {1.000, 1.000, 1.000, 1.000};
			colorBackground[] = {0.050, 0.100, 0.050, 0.600};
			colorScrollbar[] = {0.95, 0.95, 0.95, 0.000};
		};
		
		//Speed CB
		class NEO_radioTransportSpeedCb : NEO_radioTransportHeightCb
		{
			idc = 655631;
		};
		
		//ROE
		class NEO_radioTransportRoeCb : NEO_radioTransportHeightCb
		{
			idc = 655632;
		};
		
		//=======================
		//Cas Unit ListBox
		class NEO_radioCasUnitList : NEO_RscGUIListBox
		{
			idc = 655582;
			sizeEx = (safeZoneW / 100) + (safeZoneH / 300);
			rowHeight = (safeZoneW / 100) + (safeZoneH / 300);
			x = "safeZoneX + (safeZoneW / 3)";
			y = "safeZoneY + (safeZoneH / 2.35)";
			w = "(safeZoneW / 10)";
			h = "(safeZoneH / 16)";
		};
		
		//Cas Unit LB Text
		class NEO_radioCasUnitText : NEO_RscText
		{
			idc = 655583;
			x = "(safeZoneX + (safeZoneW / 3))";
			y = "(safeZoneY + (safeZoneH / 2.5))";
			w = "(safeZoneW / 12)";
			h = "(safeZoneH / 50)";
			text = "";
		};
		
		//Cas Help Unit Text
		class NEO_radioCasHelpUnitText : NEO_radioCasUnitText
		{
			idc = 655584;
			x = "(safeZoneX + (safeZoneW / 3))";
			y = "(safeZoneY + (safeZoneH / 2))";
			w = "(safeZoneW / 12.5)";
			h = "(safeZoneH / 6)";
			text = "";
		};
		
		//Cas Confirm Button
		class NEO_radioCasConfirmButton : NEO_radioTransportConfirmButton
		{
			idc = 655585;
			x = "safeZoneX + (safeZoneW / 3)";
			y = "safeZoneY + (safeZoneH / 1.425)";
			w = "(safeZoneW / 1000)";
			h = "(safeZoneH / 1000)";
			text = "Confirm";
		};
		
		//Cas Base Button
		class NEO_radioCasBaseButton : NEO_radioCasConfirmButton
		{
			idc = 655586;
			y = "safeZoneY + (safeZoneH / 1.375)";
			text = "Go back to Base";
		};
		
		//CAS Task LB
		class NEO_radioCasTaskList : NEO_radioCasUnitList
		{
			idc = 655587;
			sizeEx = (safeZoneW / 100) + (safeZoneH / 300);
			rowHeight = (safeZoneW / 100) + (safeZoneH / 300);
			x = "safeZoneX + (safeZoneW / 2.25)";
			y = "safeZoneY + (safeZoneH / 2.35)";
			w = "(safeZoneW / 10)";
			h = "(safeZoneH / 16)";
		};
		
		//Cas Task Text
		class NEO_radioCasTaskText : NEO_radioCasUnitText
		{
			idc = 655588;
			x = "(safeZoneX + (safeZoneW / 2.20))";
			w = "(safeZoneW / 12.5)";
			text = "";
		};
		
		//Cas Task Help Text
		class NEO_radioCasHelpTaskText : NEO_radioCasHelpUnitText
		{
			idc = 655589;
			x = "(safeZoneX + (safeZoneW / 2.225))";
			text = "";
		};
		
		//Cas FlyInHeight Slider
		class NEO_radioCasFlyHeightSlider : NEO_radioTransportCircleSlider
		{
			idc = 655590;
			x = "safeZoneX + (safeZoneW / 3.10)";
			w = "(safeZoneW / 1000)";
			h = "(safeZoneH / 1000)";
		};
		
		//Cas FlyInHeight Slider Text
		class NEO_radioCasFlyHeightText : NEO_radioTransportCircleSliderText
		{
			idc = 655591;
			x = "safeZoneX + (safeZoneW / 3.05)";
			w = "(safeZoneW / 1000)";
			h = "(safeZoneH / 1000)";
			text = "";
		};
		
		//Cas Radius Slider
		class NEO_radioCasRadiusSlider : NEO_radioTransportCircleSlider
		{
			idc = 655592;
			x = "safeZoneX + (safeZoneW / 3.10)";
			w = "(safeZoneW / 1000)";
			h = "(safeZoneH / 1000)";
		};
		
		//Cas Radius Slider Text
		class NEO_radioCasRadiusText : NEO_radioTransportCircleSliderText
		{
			idc = 655593;
			x = "safeZoneX + (safeZoneW / 3.05)";
			w = "(safeZoneW / 1000)";
			h = "(safeZoneH / 1000)";
			text = "";
		};
		
		//=============================
		//Arty Unit List Box
		class NEO_radioArtyUnitList : NEO_radioCasUnitList
		{
			idc = 655594;
		};
		
		//Arty Unit ListBox Title
		class NEO_radioArtyUnitText : NEO_radioCasUnitText
		{
			idc = 655595;
			text = "";
		};
		
		//Arty Unit Help text
		class NEO_radioArtyHelpUnitText : NEO_radioCasHelpUnitText
		{
			idc = 655596;
			x = "safeZoneX + (safeZoneW / 2.3)";
			y = "safeZoneY + (safeZoneH / 2.35)";
			w = "(safeZoneW / 10)";
			h = "(safeZoneH / 16)";
			text = "";
		};
		
		//Arty Confirm Button
		class NEO_radioArtyConfirmButton : NEO_radioCasConfirmButton
		{
			idc = 655597;
		};
		
		//Arty Base Button
		class NEO_radioArtyBaseButton : NEO_radioArtyConfirmButton
		{
			idc = 655610;
			text = "Go back to Base";
		};
		
		//Arty Ordnance Type Text
		class NEO_radioArtyOrdnanceTypeText : NEO_radioCasUnitText
		{
			idc = 655600;
			y = "safeZoneY + (safeZoneH / 2)";
			text = "";
		};
		
		//Arty Ordnance Type LB
		class NEO_radioArtyOrdnanceTypeLb : NEO_radioArtyUnitList
		{
			idc = 655601;
			y = "safeZoneY + (safeZoneH / 1.95)";
			h = "(safeZoneH / 17)";
		};
		
		//Arty Rate Of Fire Text
		class NEO_radioArtyRateOfFireText : NEO_radioArtyOrdnanceTypeText
		{
			idc = 655602;
			x = "safeZoneX + (safeZoneW / 2.25)";
		};
		
		//Arty Rate Of Fire Lb
		class NEO_radioArtyRateOfFireLb : NEO_radioArtyOrdnanceTypeLb
		{
			idc = 655603;
			x = "safeZoneX + (safeZoneW / 2.3)";
		};
		
		//Arty Round Count Text
		class NEO_radioArtyRoundCountText : NEO_radioArtyOrdnanceTypeText
		{
			idc = 655604;
			y = "safeZoneY + (safeZoneH / 1.70)";
		};
		
		//Arty Round Count Lb
		class NEO_radioArtyRoundCountLb : NEO_radioArtyOrdnanceTypeLb
		{
			idc = 655605;
			y = "safeZoneY + (safeZoneH / 1.66)";
		};
		
		//Arty Move button
		class NEO_radioArtyMoveButton : NEO_radioTransportSmokeFoundButton
		{
			idc = 655606;
			text = "Get in Range";
		};
		
		//Arty Dont Move
		class NEO_radioArtyDontMoveButton : NEO_radioTransportSmokeNotFoundButton
		{
			idc = 655607;
			text = "Don't Move";
		};
		
		//Arty Dispersion Text
		class NEO_radioArtyDispersionText : NEO_radioCasUnitText
		{
			idc = 655608;
			text = "";
			x = "safeZoneX + (safeZoneW / 2.25)";
			y = "safeZoneY + (safeZoneH / 1.70)";
			w = "(safeZoneW / 10)";
		};
		
		//Arty Dispersion Slider
		class NEO_radioArtyDispersionSlider : NEO_radioCasRadiusSlider
		{
			idc = 655609;
			x = "safeZoneX + (safeZoneW / 2.95)";
			y = "safeZoneY + (safeZoneH / 1.427)";
			w = "(safeZoneW / 1000)";
			h = "(safeZoneH / 1000)";
		};
		
		//Arty Rate Delay Text
		class NEO_radioArtyRateDelaySliderText : NEO_radioArtyDispersionText
		{
			idc = 655611;
			y = "safeZoneY + (safeZoneH / 1.60)";
		};
		
		//Arty Rate Delay Slider
		class NEO_radioArtyRateDelaySlider : NEO_radioArtyDispersionSlider
		{
			idc = 655612;
		};
		
		//=======================================
		//DMC BUTTON
		/*class NEO_radioDmcReconButton : NEO_RscButton
		{
			idc = -1;
			action = "[] execVM 'scripts\TDMC\misc\TDMC_requestinfo.sqf'";
			text = "REUEST UAV RECON";
			x = "safeZoneX + (safeZoneW / 5.5)";
			y = "safeZoneY + (safeZoneH / 1.425)";
			w = "(safeZoneW / 7.5)";
			h = "(safeZoneH / 20)";
		};*/
	};
};
