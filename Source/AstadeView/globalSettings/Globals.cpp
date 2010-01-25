/*
 *  Created on: Nov 9, 2008
 *
 * Globals.cpp
 * Copyright (C) 2008 Stefan Eilers & Kyung Un Choi
 * Created by Stenfan Eilers's genconfig.py
 * Changed by Kyung Un Choi - XML paserse is added instead of using genconfig.py
 *
 * Astade is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License V2
 * as published by the Free Software Foundation.
 *
 * Astade  is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St., Fifth Floor, Boston, MA 02110-1301, USA
 */
#include "Globals.h"
#include <QApplication>

Globals* Globals::m_pGlobals = NULL;
GlobalsXmlHandler Globals::m_GlobalXML;
QSettings Globals::m_appDataBase("AstadeViewOpenSoftTeam", "AstadeView");

Globals& Globals::self() {
    if (m_pGlobals == NULL) {
        m_pGlobals = new Globals;
        m_pGlobals->setParent(QApplication::instance()); // This factory will be destroyed if qApp dies.
#if defined(Q_OS_MAC)
        m_GlobalXML.parseGlobalXML(":/Globals/Globals_mac.xml");
#elif defined(Q_OS_WIN)
        m_GlobalXML.parseGlobalXML(":/Globals/Globals_windows.xml");
#else //Linux or other
        m_GlobalXML.parseGlobalXML(":/Globals/Globals.xml");
#endif
    }
    Q_ASSERT( m_pGlobals );
    if (!m_pGlobals) {
        qFatal("Globals::self(): Out of memory!!");
    }
    return *m_pGlobals;
}

QString Globals::currentModel() {
    return m_appDataBase.value("Model/CurrentModel",
            m_GlobalXML.readDefaultKeyValue("Model/CurrentModel")).value<
            QString> ();
}

void Globals::setCurrentModel(const QString& v) {
    return m_appDataBase.setValue("Model/CurrentModel", v);
}

QString Globals::omdGenerator() {
    return m_appDataBase.value("Tools/OmdGenerator",
            m_GlobalXML.readDefaultKeyValue("Tools/OmdGenerator")).value<
            QString> ();
}

void Globals::setOmdGenerator(const QString& v) {
    return m_appDataBase.setValue("Tools/OmdGenerator", v);
}

QString Globals::dotAppPath() {
    return m_appDataBase.value("Tools/DotAppPath",
            m_GlobalXML.readDefaultKeyValue("Tools/DotAppPath")).value<QString> ();
}

void Globals::setDotAppPath(const QString& v) {
    return m_appDataBase.setValue("Tools/DotAppPath", v);
}

QString Globals::cCoder() {
    return m_appDataBase.value("Tools/cCoder", m_GlobalXML.readDefaultKeyValue(
            "Tools/cCoder")).value<QString> ();
}

void Globals::setCCoder(const QString& v) {
    return m_appDataBase.setValue("Tools/cCoder", v);
}

QString Globals::cppCoder() {
    return m_appDataBase.value("Tools/cppCoder",
            m_GlobalXML.readDefaultKeyValue("Tools/cppCoder")).value<QString> ();
}

void Globals::setCppCoder(const QString& v) {
    return m_appDataBase.setValue("Tools/cppCoder", v);
}

QString Globals::stateChartCoder() {
    return m_appDataBase.value("Tools/stateChartCoder",
            m_GlobalXML.readDefaultKeyValue("Tools/stateChartCoder")).value<
            QString> ();
}

void Globals::setStateChartCoder(const QString& v) {
    return m_appDataBase.setValue("Tools/stateChartCoder", v);
}

