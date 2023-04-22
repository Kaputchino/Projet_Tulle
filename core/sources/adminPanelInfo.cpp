#include "core/headers/adminPanelInfo.h"
#include "core/headers/admin.h"

void AdminPanelInfo::setLogged(int id) {
    AdminPanelInfo::logged = Admin::constructAdminFromId(id);
}
