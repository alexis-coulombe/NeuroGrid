#include <cstdio>
#include "FSM.h"

//Flag used to prevent to enter recursively in state machine handler
#define RECURSIVE_STATE_CHECK                   FSM_STATE_BIT

typedef struct {
	FSM_state_t state;
	FSM_action_t onEntry;
	FSM_action_t onExit;
	uint8_t reserved;
} fsm_StateEntry_t;

static fsm_StateEntry_t const *fsmFindState(FSM_Object_t const *pFSM, FSM_state_t state);

FSM::FSM(FSM_Object_t const *pFSM, FSM_state_t *pActualState, FSM_state_t initialState) {
	*pActualState = initialState;
	fsm_StateEntry_t const *pStateEntry = fsmFindState(pFSM, initialState);

	if (pStateEntry) {
		*pActualState |= RECURSIVE_STATE_CHECK;
		pFSM->pPerformActionFunc(pStateEntry->onEntry);
		*pActualState &= ~RECURSIVE_STATE_CHECK;
	}
}

void FSM::processEvent(FSM_Object_t const *pFSM, FSM_state_t *pActualState, FSM_event_t event) {
	if (pFSM == nullptr || pActualState == nullptr) {
		return;
	}

	uint8_t found = false;
	uint32_t tableIndex = 0u;
	uint8_t state = 0u;
	FSM_Transition_t const *pTx = nullptr;
	fsm_StateEntry_t const *pCurrState = nullptr;
	fsm_StateEntry_t const *pDestState = nullptr;

	uint8_t entryAction = 0;
	uint8_t exitAction = 0;

	if (((*pActualState) & RECURSIVE_STATE_CHECK) != 0u) {
		printf("FSM: Recursive entry from state: %d, event: %d\n", *pActualState, event);
		return;
	}

	// find matching transition
	while ((!found) && (tableIndex < pFSM->tableSize)) {
		pTx = &(pFSM->pTransitionTable[tableIndex]);
		tableIndex++;

		if (pTx->event & FSM_STATE_BIT) {
			/* State entry */
			pCurrState = (fsm_StateEntry_t const *)pTx;
			state = pCurrState->state ^ FSM_STATE_BIT;

			/* We want to keep the current state exit action if we transition
			 * from any state
			 */
			if (state != FSM_ANY_STATE) {
				exitAction = pCurrState->onExit;
			}
		} else {
			/* Event entry */

			found = (state == FSM_ANY_STATE) || (state == *pActualState);
			found = found && (pTx->event == event);

			if (found) {
				*pActualState |= RECURSIVE_STATE_CHECK;
				found = pFSM->pConditionFunc(pTx->condition);
				*pActualState &= ~RECURSIVE_STATE_CHECK;
			}
		}
	}

	if (found) {
		if (pTx->nextState != FSM_SAME_STATE) {
			/* Execute exit action of the current state */
			*pActualState |= RECURSIVE_STATE_CHECK;
			pFSM->pPerformActionFunc(exitAction);
			*pActualState &= ~RECURSIVE_STATE_CHECK;

			/* Search the next state to get its entry action */
			pDestState = fsmFindState(pFSM, pTx->nextState);

			/* Change state */
			printf("FSM state %d->%d\n", *pActualState, pTx->nextState);
			*pActualState = pTx->nextState;
		}

		/* Execute transition action */
		*pActualState |= RECURSIVE_STATE_CHECK;
		pFSM->pPerformActionFunc(pTx->action);

		if (pTx->nextState != FSM_SAME_STATE && nullptr != pDestState) {
			/* Execute entry action of the destination state */
			pFSM->pPerformActionFunc(pDestState->onEntry);
		}

		*pActualState &= ~RECURSIVE_STATE_CHECK;
	} else {
		//no transition found
	}
}

void FSM::terminate(FSM_Object_t const *pFSM, FSM_state_t *pActualState) {
	if (nullptr == pFSM || nullptr == pActualState) {
		return;
	}

	fsm_StateEntry_t const *pState = fsmFindState(pFSM, *pActualState);

	if (pState != nullptr) {
		*pActualState |= RECURSIVE_STATE_CHECK;
		pFSM->pPerformActionFunc(pState->onExit);
		*pActualState &= ~RECURSIVE_STATE_CHECK;
	}
}

static fsm_StateEntry_t const *fsmFindState(FSM_Object_t const *const pFSM, FSM_state_t state) {
	uint32_t tableIndex = 0u;
	fsm_StateEntry_t const *pStateEntry = nullptr;
	for (tableIndex = 0; tableIndex < pFSM->tableSize; tableIndex++) {
		pStateEntry = (fsm_StateEntry_t const *)&(pFSM->pTransitionTable[tableIndex]);

		if (pStateEntry->state & FSM_STATE_BIT && (pStateEntry->state ^ FSM_STATE_BIT) == FSM_STATE_ID(state)) {
			return pStateEntry;
		}
	}

	return nullptr;
}