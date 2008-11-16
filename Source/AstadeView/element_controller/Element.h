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
#ifndef ELEMENT_H_
#define ELEMENT_H_

#include <QObject>
#include <QModelIndex>
#include <QPersistentModelIndex>
#include <QStringList>
#include <QAction>

#include <Elements.h>

class AstadeDataModel;
class ElementFactory;

// TODO: Remove virtual from "bool isXYZ();" and store state internally. Thus, subclasses have to use "setXYZ(bool)" to setup.

/**
 * Base class of all Astade Elements. Defines the common API for all Elements.
 * This class is derived from QObject to benefit from Qt magic.
 * All element attributes are stored as QMetaObject properties. Therefore
 * they can be requested and modified by Qt property aware tools (like QtPropertyEditor, Squish..)
 */
class Element: public QObject
{
    Q_OBJECT
    Q_PROPERTY( QStringList publicProperties READ publicProperties )
public:
    /**
     * Controls output of Element::toString(). This enum controls the output of the
     * function <i>Element::toString()</i>
     */
    enum StringOutputRole{
        /** Default output. This string is shown by the view */
        SOR_Default = 0,
        /** Internal representation. Shows a representation which is used internally only. */
        SOR_Internal
    };

    Element( QObject* parent = NULL );

    /**
     * Initialize the default properties of this element.
     * If an element is created by scratch, a basic set of properties needs to be initialized. This function
     * is called whenever a new element is created. No manual calling is needed.
     */
    // TODO: Make protected
    virtual void initElementProperties();

    void setDataBaseModel( AstadeDataModel* model );

    /** @return position in the children list */
    int posInChildrenList() const;

    /**
     * Returns whether the given string was found in element or one of its childs. This
     * function should be reimplemented to specify the search operation. The default implementation
     * checks whether the string was found in one of the stored properties.
     * @param pattern The string to search.
     * @return true When the string was found.
     */
    virtual bool contains( const QString& pattern );

    /**
     * Called when the order of child element has changed. This function is used
     * by elements which needs to get informed if the order in the list of childs
     * has changed.
     * The default implementation just calls orderChanged() for its child elements.
     */
    virtual void orderChanged();

#if 1
    // FIXME: This is low-level context information that should not be part of this high level interface.
    void setLowLevelModelIndex( QModelIndex index );
    QModelIndex lowLevelModelIndex() const;
    QString filename() const;
    void setFilePath( const QString& filePath );
    QString filePath() const;
    // True: The element is represented as directory
    bool isContainer() const;
    void setIsContainer( bool isContainer );
#endif

    /**
     * Returns true if this elements is editable. In this case,
     * the feature editor is provided. The default implementation returns false.
     */
    virtual bool isEditable() const;

    /**
     * Returns true if this element is dragable. The default implementation
     * returns false;
     */
    virtual bool isDragable() const;

    /**
     * Returns true if this element is dragable. The default implementation
     * returns false;
     */
    virtual bool isDropable() const;

    /**
     * Returns whether this element is a reference to an external element.
     * Elements may represent foreign elements (like a file in the file system).
     * Its internal data structure is unknown and cannot be handled by the generic framework.
     * These elements will be ignored on save operations.<br>
     * The default implementation returns true here.
     */
    virtual bool isReferenceToExternalElement() const;

    /**
     * Returns whether the element was modified.
     */
    bool isModified() const;

    /**
     * Fix modified flag of this element.
     * @param modified true if the element should be set as modified.
     */
    void setModified( bool modified );

    /**
     * Returns a list of action supported by this element.
     * The default implementation returns an empty list.
     * FIXME: While in development, this function provides an edit function.
     */
    virtual QList<QAction* > supportedActions() const;

    /**
     * Element representation as string.
     * This function returns the content of the element as string. There might be different
     * representations existing. Use stringRole to select the right one.
     * @param stringRole The role to define the output.
     */
    virtual QString toString( StringOutputRole stringRole = Element::SOR_Default ) const;

    /**
     * Returns the type of the element.
     */
    virtual Elements::ElementTypes type() const;

    /**
     * Stores properties as key/value pair into the QObject property list.
     */
    void setPropertyMap( const QMap<QString, QVariant>& data );

    /**
     * Returns a map of all properties in this object.
     */
    QMap<QString, QVariant> propertyMap() const;

    /**
     * Returns a list of public property names. Private properties should not be
     * accessed externally.
     */
    virtual QStringList publicProperties() const;

    /**
     * Update order of children in list.
     * The default implementation sorts for the type and the name of the element.
     */
    virtual void updateOrderOfChildren();

    /**
     * Move children element from pos <i>from</i> to <i>to</i>. This function calls oderChanged()
     * to the moved element internally.
     * @param from Position to start from.
     * @param to position to move to.
     * @param element Pointer of the element to be moved. This pointer is just used
     *        for safety reasons and will be compared with the element pointer at the start pos.
     * @return false if the given element pointer does not match with the element at pos <i>from</i>
     */
    bool moveChildElementFromTo( int from, int to, Element* element );

    /**
     * Decoration pixmap.
     * The returned pixmap is used as background pixmap. Overlay pixmaps might be
     * added on top of it. Empty (null) pixmaps are ignored.
     * @param The backround pixmap. The default implementation returns a null pixmap.
     */
    virtual QPixmap decorationPixmap() const;

public slots:
    void slotEdit();
    void slotAddChild();

protected:
    AstadeDataModel* model() const;

private:
    QPersistentModelIndex m_lowLevelModelIndex;
    AstadeDataModel* m_pDataBaseModel;
    bool m_isModified;
};

#endif // ELEMENT_H_
