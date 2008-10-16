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
#ifndef MainWindow_H_
#define MainWindow_H_

#include <QMainWindow>
#include <QPointer>
#include <ui_MainWindow.h>

class ProxyModel;
class RootElementMenu;
class m_pAstadeModel;

class MainWindow: public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT
public:
    MainWindow( QWidget* parent );

private slots:
    void slotSearchPatternChanged( const QString& pattern );
    void slotPreferencesRequested();
    void slotOpenModel( bool newModel = false );
    void slotCloseModel();
    void slotNewModel();


protected:
    void createAndSetModel( const QString& pathToModel = QString::null );
private:
    QPointer<ProxyModel> m_pFilterProxy;
    QPointer<RootElementMenu> m_pRootMenu;
    QPointer<AstadeDataModel> m_pAstadeModel;
};


#endif // MainWindow_H_
