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
#ifndef PROPERTY_EDITOR_H_
#define PROPERTY_EDITOR_H_

#include <QWidget>

class QLineEdit;

/**
 * Property Editor for children of QObject. 
 * This class makes the properties of an QObject read and writeable. It shows
 * all static and dynamic properties and makes them editable.
 * A property "publicProperties" may be exported by the observed object, to control which properties should be accessable.
 * To do so, you have to add "Q_PROPERTY( QStringList publicProperties READ publicProperties )" to you class definition and
 * to implement "QStringList publicProperties()" which returns the names of all properties that should be shown.
 * If this function returns an empty list or the function is not available, all properties will be shown.
 */
class PropertyEditor: public QWidget
{
    Q_OBJECT
public:
    PropertyEditor( QWidget* parent = NULL, Qt::WindowFlags f = 0 );
    void setObject( QObject* object );

    /** 
     * Commits changes and writes them directly into the object 
     * <b>Danger:</b> This will bypass any undo possibility..
     */
    void commit();
    
    /**
     * Ignore all Properties which names are in the list.
     */
    void ignoreProperties( const QStringList& propertyNames );
    
    /**
     * Returns a map with all changed properties.
     * Key: Property name, Value: Property value
     */ 
    QMap<QString, QVariant> changedProperties();
        
protected:
    void updateView();
    
private:
    QObject* m_pProcessedObject;
    QList<QLineEdit*> m_inputWidgets;
    QStringList m_ignoredProperties;
};


#endif // PROPERTY_EDITOR_H_
