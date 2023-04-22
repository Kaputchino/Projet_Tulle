#ifndef PROJET_TULLE_ADMINPANELINFO_H
#define PROJET_TULLE_ADMINPANELINFO_H

class Admin;

class AdminPanelInfo {
public:
    inline static Admin * logged = nullptr;
    static void setLogged(int id);
};


#endif //PROJET_TULLE_ADMINPANELINFO_H
