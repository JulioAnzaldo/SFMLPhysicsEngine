//
// Created by Julio Anzaldo on 3/5/22.
//

#include "States.h"

States::States()
{
    for(int i = 0; i < LASTSTATE; i++)
        states[static_cast<State>(i)] = false;
}

bool States::isEnabled(State state) const
{
    return states.at(state);
}

void States::enabledState(State state)
{
    states[state] = true;
}

void States::disabledStates(State state)
{
    states[state] = false;
}
