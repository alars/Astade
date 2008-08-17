// Automatic generated configuration file. Do not change anything here!
#include "Globals.h"

#include <QApplication>

Globals* Globals::m_pGlobals = NULL;
QSettings Globals::m_appDataBase( "EilersSoft", "Astade" );

Globals& Globals::self()
{
    if ( m_pGlobals == NULL ){
        m_pGlobals = new Globals;
        m_pGlobals->setParent( QApplication::instance() );  // This factory should be destroyed if qApp dies.
    }
    Q_ASSERT( m_pGlobals );
    if ( !m_pGlobals )
    { qFatal( "Globals::self(): Out of memory!!" ); }
    return *m_pGlobals;
}

QString Globals::currentModel()
{
    return m_appDataBase.value( "Model/CurrentModel", "/Users/stefan/Developer/Astade-UML/astade/Model/" ).value<QString>();
}

void Globals::setCurrentModel( const QString& v )
{
    return m_appDataBase.setValue( "Model/CurrentModel", v );
}

QString Globals::omdGenerator()
{
    return m_appDataBase.value( "Tools/OmdGenerator", "/Users/stefan/bin/OMDgenerator" ).value<QString>();
}

void Globals::setOmdGenerator( const QString& v )
{
    return m_appDataBase.setValue( "Tools/OmdGenerator", v );
}

QString Globals::dotAppPath()
{
    return m_appDataBase.value( "Tools/DotAppPath", "/usr/local/bin/dot" ).value<QString>();
}

void Globals::setDotAppPath( const QString& v )
{
    return m_appDataBase.setValue( "Tools/DotAppPath", v );
}

QString Globals::cCoder()
{
    return m_appDataBase.value( "Tools/cCoder", "/Users/stefan/bin/CGenerator" ).value<QString>();
}

void Globals::setCCoder( const QString& v )
{
    return m_appDataBase.setValue( "Tools/cCoder", v );
}

QString Globals::cppCoder()
{
    return m_appDataBase.value( "Tools/cppCoder", "/Users/stefan/bin/CppGenerator" ).value<QString>();
}

void Globals::setCppCoder( const QString& v )
{
    return m_appDataBase.setValue( "Tools/cppCoder", v );
}

QString Globals::stateChartCoder()
{
    return m_appDataBase.value( "Tools/stateChartCoder", "/Users/stefan/bin/StateChartCoder" ).value<QString>();
}

void Globals::setStateChartCoder( const QString& v )
{
    return m_appDataBase.setValue( "Tools/stateChartCoder", v );
}

