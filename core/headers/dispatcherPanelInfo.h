#ifndef PROJET_TULLE_DISPATCHERPANELINFO_H
#define PROJET_TULLE_DISPATCHERPANELINFO_H

#include "core/headers/Dispatcher.h"

class DispatcherPanelInfo {
private:
    inline static Dispatcher * logged;
public:
    static Dispatcher * getLogged();
    static void setLogged(int idDispatcher);
};


#endif //PROJET_TULLE_DISPATCHERPANELINFO_H
