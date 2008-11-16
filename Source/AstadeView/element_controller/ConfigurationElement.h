/*
 * AstadeView
 * Copyright (C) 2008 Stefan Eilers
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
#ifndef CONFIGURATION_ELEMENT_H_
#define CONFIGURATION_ELEMENT_H_

#include "Element.h"

class QProcess;

/**
 * Class to define the behavior of a configuration.
 */
class ConfigurationElement: public Element
{
    Q_OBJECT
public:
    ConfigurationElement( QObject* parent );
    virtual ~ConfigurationElement();

    bool isEditable() const;
    bool isReferenceToExternalElement() const;
    QList<QAction* > supportedActions() const;
    void initElementProperties();

    QString toString( StringOutputRole stringRole = Element::SOR_Default ) const;

    QPixmap decorationPixmap() const;

protected:
    void build( const QString& command, const QStringList& arguments = QStringList() );

protected slots:
    void slotBuild();
    void slotRebuild();
    void slotClean();
    void slotInstall();
    void slotRun();
    void slotStopProcess();
    void slotReadyReadStandardOutput();
    void slotReadyReadStandardError();
    void slotProcessStarted();
    void slotProcessFinished();

private:
    QProcess* m_pProcess;

};

#endif // CONFIGURATION_ELEMENT_H_
