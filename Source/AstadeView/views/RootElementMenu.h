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
#ifndef RootElementMenu_H_
#define RootElementMenu_H_

#include <QMenu>
#include <QPointer>

class AstadeDataModel;

/** 
 * Menu to create and children to the root element. 
 * The root element is not visible which blocks the usual context menu approach. Thus,
 * a root element menu is provided by this class.
 */
class RootElementMenu: public QMenu
{
    Q_OBJECT
public:
    RootElementMenu( QWidget* parent = NULL );
    RootElementMenu( const QString & title, AstadeDataModel* model = NULL, QWidget * parent = NULL );
    ~RootElementMenu();

    void setModel( AstadeDataModel* model );

protected:
    void init();
    
protected slots:
    void slotAboutToShow();
    
private:
    QPointer<AstadeDataModel> m_pModel;
};

#endif // RootElementMenu_H_

