#include "core/headers/dispatcherPanelInfo.h"

Dispatcher * DispatcherPanelInfo::getLogged() {
    return logged;
}

void DispatcherPanelInfo::setLogged(int idDispatcher) {
    logged = Dispatcher::constructDispatcherFromId(idDispatcher);
    logged->loadColisOfDispatcherFromDB();
}