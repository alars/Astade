// Automatic generated configuration file. Do not change anything here!
#include "Globals.h"
#include <QApplication>

Globals* Globals::m_pGlobals = NULL;
GlobalsXmlHandler Globals::m_GlobalXML;
QSettings Globals::m_appDataBase("EilersSoft", "Astade");

Globals& Globals::self() {
	if (m_pGlobals == NULL) {
		m_pGlobals = new Globals;
		m_pGlobals->setParent(QApplication::instance()); // This factory should be destroyed if qApp dies.
		m_pGlobals->init();
	}
	Q_ASSERT( m_pGlobals );
	if (!m_pGlobals) {
		qFatal("Globals::self(): Out of memory!!");
	}
	return *m_pGlobals;
}

void Globals::init() {
#if defined(Q_OS_MAC)
m_GlobalXML.parseGlobalXML(":/Globals/Globals.xml");
setCurrentModel(m_GlobalXML.readDefaultKeyValue("Model/CurrentModel"));
setOmdGenerator(m_GlobalXML.readDefaultKeyValue("Tools/OmdGenerator"));
setDotAppPath(m_GlobalXML.readDefaultKeyValue("Tools/DotAppPath"));
setCCoder(m_GlobalXML.readDefaultKeyValue("Tools/cCoder"));
setCppCoder(m_GlobalXML.readDefaultKeyValue("Tools/cppCoder"));
setStateChartCoder(m_GlobalXML.readDefaultKeyValue("Tools/stateChartCoder"));
#elif defined(Q_OS_WIN)
m_GlobalXML.parseGlobalXML(":/Globals/Globals_windows.xml");
setCurrentModel(m_GlobalXML.readDefaultKeyValue("Model/CurrentModel"));
setOmdGenerator(m_GlobalXML.readDefaultKeyValue("Tools/OmdGenerator"));
setDotAppPath(m_GlobalXML.readDefaultKeyValue("Tools/DotAppPath"));
setCCoder(m_GlobalXML.readDefaultKeyValue("Tools/cCoder"));
setCppCoder(m_GlobalXML.readDefaultKeyValue("Tools/cppCoder"));
setStateChartCoder(m_GlobalXML.readDefaultKeyValue("Tools/stateChartCoder"));
#endif
}

QString Globals::currentModel()
{
return m_appDataBase.value( "Model/CurrentModel", "/Users/imagine/AstadeSVN/Model/" ).value<QString>();
}

void Globals::setCurrentModel( const QString& v )
{
return m_appDataBase.setValue( "Model/CurrentModel", v );
}

QString Globals::omdGenerator()
{
return m_appDataBase.value( "Tools/OmdGenerator", "/Users/imagine/bin/OMDgenerator" ).value<QString>();
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
return m_appDataBase.value( "Tools/cCoder", "/Users/imagine/bin/CGenerator" ).value<QString>();
}

void Globals::setCCoder( const QString& v )
{
return m_appDataBase.setValue( "Tools/cCoder", v );
}

QString Globals::cppCoder()
{
return m_appDataBase.value( "Tools/cppCoder", "/Users/imagine/bin/CppGenerator" ).value<QString>();
}

void Globals::setCppCoder( const QString& v )
{
return m_appDataBase.setValue( "Tools/cppCoder", v );
}

QString Globals::stateChartCoder()
{
return m_appDataBase.value( "Tools/stateChartCoder", "/Users/imagine/bin/StateChartCoder" ).value<QString>();
}

void Globals::setStateChartCoder( const QString& v )
{
return m_appDataBase.setValue( "Tools/stateChartCoder", v );
}

