#ifndef PLUGINDEPENDENCY_H
#define PLUGINDEPENDENCY_H

#include "enums.h"

#include <QObject>

namespace yasem
{

class PluginDependency {
public:
    PluginDependency(QString name, bool required = true) {
        init(name, required, ROLE_UNKNOWN);
    }

    PluginDependency(PluginRole role, bool required = true) {
        init("", required, role);
    }

    PluginDependency(QString name, PluginRole role, bool required = true) {
        init(name, required, role);
    }

    QString roleName() const
    {
        switch(m_role)
        {
            case ROLE_UNKNOWN:          { return QObject::tr("Unknown");                 }
            case ROLE_UNSPECIFIED:      { return QObject::tr("Unspecified");             }
            case ROLE_GUI:              { return QObject::tr("GUI plugin");              }
            case ROLE_MEDIA:            { return QObject::tr("Media player plugin");     }
            case ROLE_STB_API:          { return QObject::tr("STB API plugin");          }
            case ROLE_STB_API_SYSTEM:   { return QObject::tr("System STB API plugin");   }
            case ROLE_BROWSER:          { return QObject::tr("Browser plugin");          }
            case ROLE_DATASOURCE:       { return QObject::tr("Datasource plugin");       }
            case ROLE_WEB_SERVER:       { return QObject::tr("Web server plugin");       }
            case ROLE_WEB_GUI:          { return QObject::tr("Web GUI plugin");          }
            default:                    { return QObject::tr("Unknown plugin role");     }
        }
    }

    bool isRequired()           const { return m_required; }
    PluginRole getRole()        const { return m_role; }
    QString getDependencyName() const { return m_dependency_name; }

protected:
    QString m_dependency_name; // A name of registered plugin dependency
    PluginRole m_role;         // A role of a dependency.
                               // You should declare at least one of dependency_name or role (or both).
    bool m_required;           // Set this flag if plugin cannot be loaded without this dependency.

    void init(const QString& dependency_name, const bool required, const PluginRole role)
    {
        this->m_dependency_name = dependency_name;
        this->m_required = required;
        this->m_role = role;
    }
};

}

#endif // PLUGINDEPENDENCY_H
