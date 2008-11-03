// Automatic generated configuration file. Do not change anything here!
#ifndef Globals_H_
#define Globals_H_

#include <QSettings>
#include <QObject>
#include <QString>
#include "GlobalsXmlHandler.h"

class Globals: public QObject
{
    Q_OBJECT
    Q_PROPERTY( QString currentModel READ currentModel WRITE setCurrentModel )
    Q_PROPERTY( QString omdGenerator READ omdGenerator WRITE setOmdGenerator )
    Q_PROPERTY( QString dotAppPath READ dotAppPath WRITE setDotAppPath )
    Q_PROPERTY( QString cCoder READ cCoder WRITE setCCoder )
    Q_PROPERTY( QString cppCoder READ cppCoder WRITE setCppCoder )
    Q_PROPERTY( QString stateChartCoder READ stateChartCoder WRITE setStateChartCoder )
public:
    static Globals& self();

	void init();
    QString currentModel();
    void setCurrentModel( const QString& v );
    QString omdGenerator();
    void setOmdGenerator( const QString& v );
    QString dotAppPath();
    void setDotAppPath( const QString& v );
    QString cCoder();
    void setCCoder( const QString& v );
    QString cppCoder();
    void setCppCoder( const QString& v );
    QString stateChartCoder();
    void setStateChartCoder( const QString& v );

private:
    static Globals* m_pGlobals;
    static QSettings m_appDataBase;
    //static QPointer<GlobalsXmlHandler> m_pGlobalXML;
    static GlobalsXmlHandler m_GlobalXML;
};

#endif // Globals_H_
