/*
 *  Created on: Nov 11, 2008
 *
 * Globals.h
 * Copyright (C) 2008 Stefan Eilers & Kyung Un Choi
 * Created by Stenfan Eilers's genconfig.py
 * Changed by Kyung Un Choi - XML paserse is used instead of using genconfig.py
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
    static GlobalsXmlHandler m_GlobalXML;
};

#endif // Globals_H_
