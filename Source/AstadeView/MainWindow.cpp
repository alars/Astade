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
#include "MainWindow.h"

#include <QSortFilterProxyModel>
#include <QToolBar>
#include <QDialog>
#include <QVBoxLayout>
#include <QFileDialog>

#include "Globals.h"
#include "AstadeDataModel.h"
#include "ProxyModel.h"
#include "RootElementMenu.h"
#include "ui_ConfigDialog.h"

#include "SearchWidget.h"

class Spacer: public QWidget
{
public:
    Spacer(QWidget *parent = 0)
    :QWidget(parent)
    {
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        setSizePolicy(sizePolicy);
    }

    QSize sizeHint() const
    {
        return QSize(1, 1);
    }

};


MainWindow::MainWindow( QWidget* parent ):
QMainWindow( parent ), m_pFilterProxy( NULL ), m_pAstadeModel( NULL )
{
    setupUi( this );

    m_pRootMenu = new RootElementMenu( tr( "Root" ), NULL, menubar );
    menubar->addMenu( m_pRootMenu );

    QToolBar* toolBar = addToolBar(tr("Search"));
    SearchWidget* search_widget = new SearchWidget;
    toolBar->addWidget(new Spacer());
    toolBar->addWidget( search_widget );

    setUnifiedTitleAndToolBarOnMac(true);

    // Open the default model
    createAndSetModel();

    // Connect search field to handle searching..
    connect( search_widget, SIGNAL( signalTextChanged( const QString& ) ),
            this, SLOT( slotSearchPatternChanged( const QString& ) ) );

    connect( actionPreferences, SIGNAL( triggered( bool ) ),
            this, SLOT( slotPreferencesRequested() ) );

    connect( actionOpen, SIGNAL( triggered( bool ) ),
            this, SLOT( slotOpenModel() ) );

    connect( actionClose, SIGNAL( triggered( bool ) ),
            this, SLOT( slotCloseModel() ) );

    connect( actionNew, SIGNAL( triggered( bool ) ),
            this, SLOT( slotNewModel() ) );
    
    connect( actionExit, SIGNAL( triggered( bool ) ),
    		QApplication::instance(), SLOT( quit() ) );
}

void MainWindow::slotSearchPatternChanged( const QString& pattern )
{
    Q_ASSERT( m_pFilterProxy );
    m_pFilterProxy->setFilterWildcard( pattern );
}

void MainWindow::slotPreferencesRequested()
{
    QDialog config_dialog;

    Ui_configDialog ui_config_dialog;
    ui_config_dialog.setupUi( &config_dialog );
    QStringList black_list; black_list << "objectName";
    ui_config_dialog.configWidget->ignoreProperties( black_list );
    ui_config_dialog.configWidget->setObject( &Globals::self() );

    if ( config_dialog.exec() == QDialog::Accepted )
    {
        ui_config_dialog.configWidget->commit();
    }
}

void MainWindow::slotOpenModel( bool newModel )
{
    QString model_path;
    if ( newModel )
    {
        model_path = QFileDialog::getExistingDirectory( this,
                                                       tr( "Select path for new Model" ),
                                                       Globals::self().currentModel() );
    }
    else
    {
        model_path = QFileDialog::getExistingDirectory( this,
                                                       tr( "Open existing Model" ),
                                                       Globals::self().currentModel() );
    }

    if ( model_path.isEmpty() )
    { return; }

    if ( !model_path.endsWith( "/" ) )
    { model_path += "/"; }
    Globals::self().setCurrentModel( model_path );

    slotCloseModel();
    createAndSetModel( model_path );
}

void MainWindow::slotCloseModel()
{
    if ( !m_pFilterProxy || !m_pAstadeModel )
    { return; };

    m_pAstadeModel->slotCommit();

    delete m_pFilterProxy;
    m_pFilterProxy = NULL;

    treeView->setRootIndex( QModelIndex() );
    columnView->setRootIndex( QModelIndex() );
    umlWidget->setRootIndex( QModelIndex() );

    setWindowTitle( tr( "AstadeView" ) );
}

void MainWindow::slotNewModel()
{
    slotOpenModel( true );
}


void MainWindow::createAndSetModel( const QString& pathToModel )
{
    Q_ASSERT( m_pRootMenu );
    if ( !m_pRootMenu )
    { return; }

    QString model_path = pathToModel;
    if ( model_path.isEmpty() )
    { model_path = Globals::self().currentModel(); }
    if ( !model_path.endsWith( "/" ) )
    { model_path += "/"; }

    m_pFilterProxy = new ProxyModel( this );
    m_pAstadeModel = new AstadeDataModel( m_pFilterProxy );
    m_pFilterProxy->setSourceModel( m_pAstadeModel );

    QModelIndex root_index = m_pAstadeModel->setModelRootDir( model_path );

    QItemSelectionModel *selections = new QItemSelectionModel( m_pFilterProxy );

    treeView->setModels( m_pFilterProxy, selections );
    columnView->setModels( m_pFilterProxy, selections );
    umlWidget->setModels( m_pFilterProxy, selections );
    m_pRootMenu->setModel( m_pAstadeModel );

    treeView->setRootIndex( root_index );
    columnView->setRootIndex( root_index );
    umlWidget->setRootIndex( root_index );

    setWindowTitle( tr( "AstadeView - Model: %1" ).arg(model_path) );
}



