#include "helper.h"
#include <iostream>

using namespace std;

Helper::Helper()
{

}

Helper::Helper(const QString& path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
      m_db.setDatabaseName(path);

      if (!m_db.open())
      {
         qDebug() << "Error: connection with database failed";
      }
      else
      {
         qDebug() << "Database: connection ok";
      }

      int petid = 0;
      int tagid = 0;
}
void Helper::addPet()
{
    int numTags = 0;
    string name;
    cout << "Enter pet's name: ";
    cin >> name;
    string species;
    cout << "Enter pet's species: ";
    cin >> species;
    bool done;
    vector<Tag> tags;
    Tag t(species,"species");
    tags.push_back(t);
    numTags++;
    while (!done)
    {
        string misc;
        cout << "Enter misc tags, or 'end' to finish.";
        cin >> misc;
        if (misc.compare("end") == 0)
        {
            done = true;
        }
        else
        {
        Tag tag(misc, "misc");
        tags.push_back(tag);
        numTags++;
        }
    }
    QSqlQuery q(m_db);
    string s;
    s = "INSERT INTO pets (petid, name, numTags) VALUES ( " + std::to_string(petid) + ", \""  + name + "\", " + std::to_string(numTags) + ");";
    QString qs = QString::fromStdString(s);
    cout << q.prepare(qs) << endl;
    q.exec();
    for (int i = 0; i < tags.size(); i++)
    {
        string ts;
        ts = "INSERT INTO tags (tagid, name, type) VALUES ( "+ std::to_string(tagid) + ", \""  + tags.at(i).getName() + "\" " + ", \"" + tags.at(i).getType() + "\" );";
        QString qts = QString::fromStdString(ts);
        cout << q.prepare(qts) << endl;
        q.exec();
        string pts;
        pts = "INSERT INTO petTags (petid, tagid) VALUES ( "+ std::to_string(petid) + ", " + std::to_string(tagid) + ");";
        QString qpts =QString::fromStdString(pts);
        q.prepare(qpts);
        q.exec();
        tagid++;
    }
    petid++;
}
void Helper::showPets()
{
    QSqlQuery q("SELECT * from pets");
    int idName = q.record().indexOf("name");
    while(q.next())
    {
        QString name = q.value(idName).toString();
        qDebug() << name;
    }
    //q.prepare("SELECT * FROM pets;");
   // q.exec();
    /**
    if(q.prepare(QString("SELECT * FROM pets;")))
    {
        cout << "Success" << endl;
    }
    else
    {
        qDebug() << "showPets error:" << q.lastError();
    }
    */


}
void Helper::search(string name)
{
    QSqlQuery q;
    string s = "SELECT * from pets WHERE name = \"" + name + "\";";
    cout << s << endl;
    QString qs = QString::fromStdString(s);
    cout << q.prepare(qs) << endl;
    if (q.exec())
    {
        if(q.next())
        {
            QString n = q.value("name").toString();
            cout << "Name: " << n.toStdString() << endl;
            int numTags = q.value("numTags").toInt();
            cout << numTags << endl;
            //int id = q.value("petid").toString();
            QString pts = "SELECT tagid from petTags WHERE petid = " + q.value("petid").toString() + ";";
            cout << pts.toStdString() << endl;
            q.prepare(pts);

            if (q.exec())
            {
                vector<QString> tagIDList;
                q.next();
                for (int i = 0; i < numTags; i++)
                {
                    tagIDList.push_back(q.value(0).toString()); //The value isn't returning what it should
                    q.next();
                }
                for (int i = 0; i < tagIDList.size(); i++)
                {
                    cout << tagIDList.at(i).toStdString() << endl;
                }
                vector<Tag> tagList;
                string species;
                for (int i = 0; i < numTags; i++)
                {
                    QString s = "SELECT name, type FROM tags WHERE tagid = " + tagIDList.at(i);
                    q.prepare(s);
                    q.exec();
                    q.next();
                    string name = q.value(0).toString().toLocal8Bit().constData();
                    string type = q.value(1).toString().toLocal8Bit().constData();
                    if (type.compare("species") == 0)
                    {
                        species = name;
                        continue;
                        //Only saves the misc tags, we'll need to rewrite this when
                        //There's more categories of tags than just "misc"
                    }
                    Tag t (name,type);
                    tagList.push_back(t);
                }
                cout << "Species: "  << species << endl;
                cout << "Misc Tags: " << endl;
                for (int i = 0; i < tagList.size(); i++)
                {
                    cout << tagList.at(i).getName() << endl;
                }
                string cont;
                cout << "Press enter to return to the list." << endl;
                cin >> cont;

                //Somehow record all tags associated with the pet's id and print them here
                //Take all of the tagids associated with petid
                //Search through
            }
        }
        else
        {
            cout << "Could not find pet." << endl;
        }
    }
}

