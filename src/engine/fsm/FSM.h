#ifndef ASM_SRC_ENGINE_FSM_H_
#define ASM_SRC_ENGINE_FSM_H_

#include <cstdint>
#include <functional>

//Internal identifier of state
#define FSM_STATE_BIT   (0x80)

/* Extract the state id from a `FSM_state_t` */
#define FSM_STATE_ID(state) (state & ~FSM_STATE_BIT)

/** From-state placeholder to specify 'from any state'. */
#define FSM_ANY_STATE    (0x7F)

/**
 * Tells FSM to not change state when an action occurs; to use as the
 * `nextState` argument in `FSM_EVENT`.
 */
#define FSM_SAME_STATE	(0x7F)

//Macro helper to define a state entry in transition table
#define FSM_STATE(_state, _entry, _exit) {(uint8_t)(_state | FSM_STATE_BIT), _entry, _exit, 0}

//Macro helper to define an event entry in transition table
#define FSM_EVENT(event, cond, action, nextState) {(uint8_t)(event),(uint8_t)(cond),(uint8_t)(action),(uint8_t) (nextState)}

// Macro helper to calculate the size of the transition table
#define FSM_GET_TABLE_SIZE(table) ((uint32_t)(sizeof(table)/sizeof(*(table))))

typedef uint8_t FSM_event_t;
typedef uint8_t FSM_condition_t;
typedef uint8_t FSM_action_t;
typedef uint8_t FSM_state_t;

typedef struct {
  FSM_event_t event;
  FSM_condition_t condition;
  FSM_action_t action;
  FSM_state_t nextState;
} FSM_Transition_t;

typedef struct {
  FSM_Transition_t const *pTransitionTable;                      //Pointer to transition table
  uint32_t tableSize;                               //Number of elements in transition table
  std::function<bool(FSM_condition_t condition)> pConditionFunc; // Conditional function
  std::function<void(FSM_action_t action)> pPerformActionFunc;   // Action executer function
} FSM_Object_t;

class FSM {
 public:
  FSM(FSM_Object_t const *pFSM, FSM_state_t *pActualState, FSM_state_t initialState);
  void processEvent(FSM_Object_t const *pFSM, FSM_state_t *pActualState, FSM_event_t event);
  void terminate(FSM_Object_t const *pFSM, FSM_state_t *pActualState);
};

#endif //ASM_SRC_ENGINE_FSM_H_
