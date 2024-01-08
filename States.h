//
// Created by Julio Anzaldo on 3/5/22.
//

#ifndef GUIPROJECT_STATES_H
#define GUIPROJECT_STATES_H
#include "EnumNames.h"
#include <map>

class States {
private:
    std::map<State, bool> states;
public:
    States();
    bool isEnabled(State state) const;
    void enabledState(State state);
    void disabledStates(State state);
};

#endif //GUIPROJECT_STATES_H
