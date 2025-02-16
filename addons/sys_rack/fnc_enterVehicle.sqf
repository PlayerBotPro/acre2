#include "script_component.hpp"
/*
 * Author: ACRE2Team
 * Handles entering a vehicle.
 *
 * Arguments:
 * 0: Vehicle <OBJECT>
 * 1: Unit entering a vehicle <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [cursorTarget, player] call acre_sys_rack_fnc_enterVehicle
 *
 * Public: No
 */

params ["_vehicle", "_unit"];

if (_unit == _vehicle || {!(isNull remoteControlled _unit)}) exitWith {};

private _initialized = _vehicle getVariable [QGVAR(initialized), false];

if (!_initialized) then {
    // Only initialize if we are first in the crew array - This helps prevent multiple requests if multiple players enter a vehicle around the same time.
    private _crew = [_vehicle] call EFUNC(sys_core,getPlayersInVehicle);
    private _firstPlayer = objNull;
    {
        if (!isNull _x) exitWith {
            _firstPlayer = _x;
        };
    } forEach _crew;

    if (!isNull _firstPlayer) then {
        if (_unit == _firstPlayer) then {
            [_vehicle] call FUNC(initVehicle);

            // Give some time for the racks to initialise properly
            [{
                [_this select 0] call FUNC(configureRackIntercom);
                // Update the display
                [_this select 0, _this select 1] call EFUNC(sys_intercom,updateVehicleInfoText);
            }, [_vehicle, _unit], 0.5] call CBA_fnc_waitAndExecute;
        };
    } else { // No other players.
        [_vehicle] call FUNC(initVehicle);

        // Give some time for the racks to initialise properly
        [{
            [_this select 0] call FUNC(configureRackIntercom);
            // Update the display
            [_this select 0, _this select 1] call EFUNC(sys_intercom,updateVehicleInfoText);
        }, [_vehicle, _unit], 0.5] call CBA_fnc_waitAndExecute;
    };
};

// Enable the PFH if it is not active (can only be active if the unit is using an external radio before entering the vehicle)
if (GVAR(rackPFH) == -1) then {
    GVAR(rackPFH) = [DFUNC(rackPFH), 1, [_unit, _vehicle]] call CBA_fnc_addPerFrameHandler;
    TRACE_1("rack PFH",GVAR(rackPFH));
};

// Re-Use stored radios for the current position
private _varName = [_vehicle, _unit, QGVAR(usedRacks_%1)] call EFUNC(sys_intercom,getStationVariableName);
if (_varName isNotEqualTo "") then {
    private _usedRacks = _vehicle getVariable [_varName, []];
    {
        [_vehicle, _unit, _x] call FUNC(startUsingMountedRadio);
    } forEach _usedRacks;
};

// Load saved PTT assignments of previously used Racks
private _vehiclePTTs = _vehicle getVariable [QGVAR(MPTTAssignment), []];
if (_vehiclePTTs isNotEqualTo []) then {
    [_vehiclePTTs] call EFUNC(api,setMultiPushToTalkAssignment);
};
