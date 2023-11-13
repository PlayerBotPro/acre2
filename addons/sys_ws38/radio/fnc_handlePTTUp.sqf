#include "..\script_component.hpp"
/*
 * Author: ACRE2Team
 * Function called when PTT key is released. The most important aspect is setting the PTTDown flag
 * of the radio to false.
 *
 * Arguments:
 * 0: Radio ID <STRING>
 * 1: Event: "handlePTTUp" <STRING> (Unused)
 * 2: Event data <ARRAY> (Unused)
 * 3: Radio data <HASH> (Unused)
 * 4: Remote <BOOL> (Unused)
 *
 * Return Value:
 * True <BOOL>
 *
 * Example:
 * ["ACRE_WS38_ID_1", "handlePTTUp", [], [], false] call acre_sys_ws38_fnc_handlePTTUp
 *
 * Public: No
 */

params ["_radioId", "", "", "", ""];

private _volume = [_radioId, "getVolume"] call EFUNC(sys_data,dataEvent);
private _currentMode = GET_STATE("mode_knob");
if(_currentMode == 2) then {
    SET_STATE("mode_knob", 1);
    [MAIN_DISPLAY] call FUNC(render);
};
[_radioId, "Acre_GenericClickOff", [0, 0, 0], [0, 1, 0], _volume] call EFUNC(sys_radio,playRadioSound);
SCRATCH_SET(_radioId, "PTTDown", false);
true;
