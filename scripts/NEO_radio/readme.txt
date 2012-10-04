=========================================================================================================================================================================================
Name: 		Support Radio
Developer: 	_neo_
Version:	1.00
Credits:	Deto for the logo image, Osmo, Mr Ben, Outlander, Igmmig and all other Tour members for the great ideas, suggestions, feedback and testing

=========================================================================================================================================================================================
Changelogs:

v1.00
- First Public Release

v1.00 RC
- Fixed: EmptyH not used anymore on Land task
- Removed: Coordinates on chat (BIS_fnc_posToGrid bugged for OA islands)
- Optimized: Interface loading is now much more efficient and faster
- Added: Possibility to change FlyInHeight/SpeedMode/Roe on-the-fly in Transport support
- Added: Unit List box now shows Unit icon
- Added: Player can now "Talk to Artillery Crew" when near arty guns and control that arty group, does not need itemRadio/itemGps to do so
- Fixed: Talk with Pilot non functional when one or more choppers were combat inefective
- Fixed: Arty D30 units were not working for all factions
- Fixed: When player opens interface in-game GPS is hidden
- Fixed: If more then one unit needs player interaction, interface goes directly to the last unit in list instead of main menu
- Fixed: Operation Arrowhead Arty vehicles were not compatible
- Changed: Arty rounds are now 1, 2, 3, 6, 12, 24
- Changed: ItemRadio and ItemGps are now required to use the Support Radio instead of just ItemRadio
- Removed: OnPlayerDisconnected function because it is not stackable

v0.9 RC
- Fixed: Hint interface text size and position for bigger interface sizes
- Added: Notes
- Added: If one support unit is waiting for player interface, when dialog is opened it goes to that unit
- Added: Functions to Add/Remove supports on the fly - (NEO_fnc_radioSupportAdd / NEO_fnc_radioSupportRemove)
- Changed: Support Radio can now be used at same time by multiple players of same side
- Changed: Transport High FlyInHeight is now 500m intead of 150m
- Optimized: Transport precision of Land Tasks sorted by - Near Helipad (< 50) >> Position is safe >> Near Helipad (< 100) >> Near safe position within 250m >> Use clicked position if all else fails

v0.8
- Added: Arty batteries keeps asking for move confirmation if no answer from players
- Added: Transport units keeps asking for smoke/smoke confirmation if no answer from players
- Added: New Transport Task "land (eng off)", very similar to "land" task with the difference that unit will shutdown his engine
- Added: Action "Talk with pilot" when inside a Transport unit where player can access directly and only that chopper (Does not need ItemRadio)
- Added: To be able to use radio player no longer needs to be a leader but needs a ItemRadio in his gear
- Added: Physical Radio now appears when a player is using Support Radio (if not inside a vehicle)
- Added: Hint interface for special interactions
- Changed: If only one unit within a support type interface goes directly there
- Changed: If only one support type available interface goes directly there
- Fixed: Arty Ammo System not considering unit out of ammo when it should
- Fixed: Arty Ammo System not registering the ammo used correctly
- Fixed: Possibility for transport to take off right after landing in pickup task

v0.7
- Added: Arty Ammunition System
- Added: Arty mobile units can be sent back to base while moving into range of target
- Added: Code is now supported as parameter for each support unit/s
- Optimized: Arty interface optimizations and tweaks

v0.6
- Added: Artillery Support
- Fixed: Transport units did not re-arm when at base
- Fixed: Support Radio action not showing up after respawn
- Fixed: GroupId not being broadcasted over the network
- Improved: UI does not close anymore when confirming something
- Improved: UI now refreshes at the last main support selected instead of "home page"

v0.5 HotFix
- New: Interface is re-initialized after asking for a support instead of closing
- Fixed: Bug introduced in v0.5 related to re-initialization of interface after support being asked (Reported by Outlander)
- Fixed: Text resource had the debug activated after v0.5

v0.5
- Changed: There is no delay between player issuing a task mission and unit starting to move like before until I find a better/more reliable solution
- Fixed: Player group side does not show up anymore in chat between player and units (Reported by Mr. Ben)
- Fixed: Possibility for CAS plane to become unresponsive to new task when sent to RTB before being airborn
- Fixed: Flying Altitude text not showing correctly with bigger Interface Size

=========================================================================================================================================================================================
Intallation:
- Copy the folder "scripts" to your mission root folder
- In the "description.ext" (create one if you don't have it) paste:

	#include "scripts\NEO_radio\hpp\main.hpp"
	
	class RscTitles 
	{    										
		#include "scripts\NEO_radio\hpp\titles.hpp"
	};

- In your "init.sqf" file (create one if you don't have it) is where you'll execute the Support Radio, and the passed array MUST have the following structure:

[
	NEO_coreLogic,															//GAME LOGIC (CAN BE FUNCTIONS MODULE)
	[
		WEST,																//WEST SIDE SUPPORTS
		[																	//TRANSPORT ARRAY MUST COME FIRST, EMPTY ARRAY IF NO TRANSPORT UNIT TO BE ADDED TO SIDE
			[																//Transport Unit 1
				getMarkerPos "NEO_mkr_transport_00", 						//Spawn position
				270, 														//Spawn direction
				"BAF_Merlin_HC3_D",											//Class Name of Helicopter
				"Eagle-One", 												//Unit Callsign
				["pickup", "land", "land (eng off)", "move", "circle"], 	//Unit available tasks
				{}															//Code to execute, you can access in _this variable [_chopper, _grp, _crew]
			],
			[																//Transport Unit 2
				getMarkerPos "NEO_mkr_transport_00", 						//Spawn position
				270, 														//Spawn direction
				"BAF_Merlin_HC3_D",											//Class Name of Helicopter
				"Eagle-One", 												//Unit Callsign
				["pickup", "land"], 										//Unit available tasks
				{}															//Code to execute, you can access in _this variable [_chopper, _grp, _crew]
			]
		],
		[																	//CAS ARRAY MUST COME IN SECOND, USE EMPTY ARRAY IF NO CAS UNITS SHOULD BE ADDED TO SIDE
			[																//CAS Unit 1
				getMarkerPos "NEO_mkr_cas_00", 								//Spawn position
				270,														//Spawn direction
				"AH64D",													//Class Name of Aircraft (Plane or Chopper)
				"Falcon-One",												//Unit Callsign
				0,															//Airport ID - ONLY needed for Planes, if chopper can be any number
				{}															//Code to execute, you can access in _this variable [_aircraft, _grp, _crew]
			],
			[
				cas 2......
			]
		],
		[																	//ARTY ARRAY MUST COME IN THIRD, USE EMPTY ARRAY IF NO ARTY UNITS SHOULD BE ADDED TO SIDE
			[																//ARTY Battery 1
				getMarkerPos "NEO_mkr_arty_00",								//Spawn Position
				"MLRS",														//Vehicle Class name
				"MLRS FATMAN",												//Callsign
				2,															//Number of weapons in the battery group
				[["HE", 30]],												//Available Rounds/Ammo (Will be checked later if matches the currect vehicle type of ammo)
				{}															//Code to execute, you can access in _this variable [_battery(gamelogic), _grp, _vehicles, _crew]
			]
		]
	],
	[
		EAST,																//EAST SIDE SUPPORTS
		etc........
	];
] execVM "scripts\NEO_radio\init.sqf";

==========================
//Functions
==========================
//Add support
[
	WEST,
	"TRANSPORT",
	[
		getMarkerPos "NEO_mkr_transport_00", 								//Spawn position
		270, 																//Spawn direction
		"BAF_Merlin_HC3_D",													//Class Name of Helicopter
		"Eagle-One", 														//Unit Callsign
		["pickup", "land", "land (eng off)", "move", "circle"], 			//Unit available tasks				
		{}																	//Code to execute, you can access in _this variable [_chopper, _grp, _crew]
	]
] call NEO_fnc_radioSupportAdd;

//Remove Support
[
	WEST,
	"TRANSPORT",
	"Eagle-One"
] call NEO_fnc_radioSupportRemove;

=========================================================================================================================================================================================
