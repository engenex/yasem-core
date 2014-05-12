#ifndef PROFILECONFIG_H
#define PROFILECONFIG_H

#include <QObject>
#include <QHash>
#include <QString>

namespace yasem
{

class ProfileConfig
{
public:
    ProfileConfig(){}

    enum Types {
        STRING = 5,
        BOOL = 6,
        INT = 7,
        VARIANT = 8
    };

    class Option
    {
    public:
        Option(const QString &tag, const QString &name, int value, const QString &title, const QString &comment = "")
        {
            //qDebug() << "FILL++++ INT";
            fill_data(tag, name, title, comment, INT);
            this->intValue = value;
        }
        Option(const QString &tag, const QString &name, const QString& value, const QString &title, const QString &comment = "")
        {
            //qDebug() << "FILL++++ STRING";
            fill_data(tag, name, title, comment, STRING);
            this->strValue = value;
        }
        Option(const QString &tag, const QString &name, const char* value, const QString &title, const QString &comment = "")
        {
            //qDebug() << "FILL++++ std::string";
            fill_data(tag, name, title, comment, STRING);
            this->strValue = QString::fromStdString(value);
        }
        /*Option(const QString &tag, const QString &name, bool value, const QString &title, const QString &comment = "")
        {
            qDebug() << "FILL++++ bool";
            fill_data(tag, name, title, comment, BOOL);
            this->boolValue = value;
        }*/
        Option(const QString &tag, const QString &name, const QVariant &value, const QString &title, const QString &comment = "")
        {
            //qDebug() << "FILL++++ QVariant";
            fill_data(tag, name, title, comment,VARIANT);
            this->varValue = value;
        }

        QString title;
        QString comment;
        QString tag;
        QString name;
        int intValue;
        QString strValue;
        bool boolValue;
        QVariant varValue;
        Types type;
        QList<QString> variants;


    protected:
        void fill_data(const QString &tag, const QString &name, const QString &title, const QString &comment, Types type)
        {
            this->tag = tag;
            this->name = name;
            this->type = type;
            this->title = title;
            this->comment = comment;
        }

        friend class ProfileConfig;
    };

    void add(const Option &option) {
        optionList.append(option);
    }

    QList<Option> options() { return optionList; }
protected:

    QList<Option> optionList;
};

}

#endif // PROFILECONFIG_H