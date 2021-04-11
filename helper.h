#ifndef HELPER_H
#define HELPER_H
#include <vector>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QStringList>
#include <QSqlRecord>
#include "tag.h"
#include "pet.h"

class Helper
{
public:
    Helper();
    Helper(const QString& path);
    void addPet();
    void showPets();
    void search(string name);
private:
    QSqlDatabase m_db;
    int petid;
    int tagid;
};

#endif // HELPER_H
