#ifndef ASM_SRC_GAME_MISSION_MISSION2_H_
#define ASM_SRC_GAME_MISSION_MISSION2_H_

#include <vector>
#include <string>
/*
 * Mission2:
 * Transfer all given inputs to its respective outputs.
 * - Clamp the output values to 1-255.
 * - Values equals to 0 must be ignored.
 *
 * if InputA[i] == 0 -> continue
 * InputA[i] -> OutputD[i] % 255
 */

static inline std::vector<std::string> description = {
		"> Reading Entry - 0x4162797373",
		"",
		"I can feel it, the signals racing through my own nervous system.",
		"Synapses firing at the neuromuscular junction.",
		"",
		"A signal too strong and the muscle contracts violently,",
		"tearing itself apart.",
		"I've seen it before, flesh twisted into rigid, unnatural shapes.",
		"The actin-myosin cross-bridges don’t break, they *snap*, leaving necrosis.",
		"",
		"Under-stimulation is no kinder.",
		"A signal too weak, and the muscles starve, falling silent as they rot.",
		"Necrotic, fibers—eaten away by their failure, consumed by entropy.",
		"Death by quiet suffocation of the cells.",
		"",
		"Overload burns through them like a wildfire;",
		"undervoltage leaves them as hollow as dying nerves."
};

#endif //ASM_SRC_GAME_MISSION_MISSION2_H_
