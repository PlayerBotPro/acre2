#include "..\script_component.hpp"
/*
 * Author: ACRE2Team
 * Initialises a radio by givint it a radio ID. This only happens once and the default
 * preset (configuration) is copied.
 *
 * Arguments:
 * 0: Radio ID <STRING>
 * 1: Event: "initializeRadio" <STRING> (Unused)
 * 2: Event data [baseclass, preset] <ARRAY>
 * 3: Radio data <HASH>
 * 4: Remote <BOOL> (Unused)
 *
 * Return Value:
 * None
 *
 * Example:
 * ["ACRE_WS38_ID_1", "initializeRadio", ["ACRE_WS38_base", default1], [], false] call acre_sys_ws38_fnc_initializeRadio
 *
 * Public: No
 */

TRACE_1("INITIALIZING RADIO WS38", _this);

params ["_radioId", "_event", "_eventData", "_radioData", ""];

_eventData params ["_baseName", "_preset"];
private _presetData = [_baseName, _preset] call EFUNC(sys_data,getPresetData);
private _channels = HASH_GET(_presetData,"channels");
private _currentChannels = HASH_GET(_radioData,"channels");

SCRATCH_SET(_radioId, "currentTransmissions", []);

if (isNil "_currentChannels") then {
    _currentChannels = [];
    HASH_SET(_radioData,"channels",_currentChannels);
};

for "_i" from 0 to (count _channels)-1 do {
    private _channelData = HASH_COPY(_channels select _i);
    TRACE_1("Setting PRC-343 Init Channel Data", _channelData);
    PUSH(_currentChannels, _channelData);
};

HASH_SET(_radioData,"volume",EGVAR(sys_core,defaultRadioVolume));
HASH_SET(_radioData,"radioOn",0);
HASH_SET(_radioData,"mode_knob",0);
HASH_SET(_radioData,"currentView",1);
HASH_SET(_radioData,"currentChannel",0);
