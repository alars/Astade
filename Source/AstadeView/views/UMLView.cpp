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
// TODO: Optimize Process handling

// This implementation shows how pipelining may be implemented with Qt. It uses connect() and disconnect() to
// define the next stage of the pipeline.

#include "UMLView.h"

#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QCheckBox>
#include <QSpinBox>
#include <QLabel> 
#include <QSvgWidget>
#include <QSvgRenderer>
#include <QProgressBar>
#include <QSpacerItem>

#include "AstadeDataModel.h"
#include "Globals.h"
#include "ProcessView.h"

namespace
{
#ifdef Q_OS_WIN32
    const QString g_tmpDir = "C:/Windows/Temp";
#else
    const QString g_tmpDir = "/tmp";
#endif
}
UMLView::UMLView( QWidget* parent ):
AstadeView( parent ),
m_pSvgView( NULL ),
m_pProcess( NULL ),
m_pShowExternalsCheckBox( NULL ),
m_pAllClassesCheckBox( NULL ),
m_pAttDisplayLevelSpinBox( NULL ),
m_pOperationsDisplayLevelSpinBox( NULL ),
m_pProgressBar( NULL )
{
    // Create main view
    QVBoxLayout* v_layout = new QVBoxLayout( this );
    
    QHBoxLayout* config_items_layout = new QHBoxLayout();
    v_layout->addLayout(config_items_layout);
    
    // Config checkboxes
    m_pShowExternalsCheckBox = new QCheckBox( tr("Show Externals"), this );
    m_pShowExternalsCheckBox->setChecked( false );
    
    m_pAllClassesCheckBox = new QCheckBox( tr( "All Classes" ), this );
    m_pAllClassesCheckBox->setChecked( true );
    
    QLabel* att_display_level = new QLabel( tr( "Attribute Display Level:" ), this );
    
    m_pAttDisplayLevelSpinBox = new QSpinBox( this );
    m_pAttDisplayLevelSpinBox->setMaximum( 3 );
    m_pAttDisplayLevelSpinBox->setMinimum( 0 );
    m_pAttDisplayLevelSpinBox->setValue( 2 );
    
    QLabel* op_display_level = new QLabel( tr( "Operation Display Level:" ), this );

    m_pOperationsDisplayLevelSpinBox = new QSpinBox( this );
    m_pOperationsDisplayLevelSpinBox->setMaximum( 3 );
    m_pOperationsDisplayLevelSpinBox->setMinimum( 0 );
    m_pOperationsDisplayLevelSpinBox->setValue( 2 );
    
    // ProgressBar to show state of pipeline.
    m_pProgressBar = new QProgressBar( this );
    m_pProgressBar->setRange( 0, 3 );
    
    config_items_layout->addWidget( m_pShowExternalsCheckBox );
    config_items_layout->addWidget( m_pAllClassesCheckBox );
    config_items_layout->addWidget( att_display_level );
    config_items_layout->addWidget( m_pAttDisplayLevelSpinBox );
    config_items_layout->addWidget( op_display_level );
    config_items_layout->addWidget( m_pOperationsDisplayLevelSpinBox );
    
    config_items_layout->addItem( new QSpacerItem( 1, 1, QSizePolicy::MinimumExpanding, QSizePolicy::Maximum ) );
    config_items_layout->addWidget( m_pProgressBar );
    
    QScrollArea* scroll_area = new QScrollArea( this );
    v_layout->addWidget( scroll_area );
    m_pSvgView = new QSvgWidget( this );
    scroll_area->setWidget( m_pSvgView );

    
}

void UMLView::setModels( QAbstractItemModel* model, QItemSelectionModel *selections )
{
    m_pModel = model;

    connect( selections, SIGNAL( selectionChanged( const QItemSelection&, const QItemSelection& ) ),
            this, SLOT( slotSelectionChanged( const QItemSelection&, const QItemSelection& ) ) );
    

    m_pProcess = new QProcess( ProcessView::self() );
    connect( m_pProcess, SIGNAL( readyReadStandardError() ),
            this, SLOT( slotStdErrorDataAvailable() ) );
}

void UMLView::slotSelectionChanged( const QItemSelection& selected, const QItemSelection& deselected )
{
    Q_UNUSED( deselected );
    
    // Get path of current selected element    
    if ( selected.indexes().count() == 0 )
        return;
    
    slotUpdateStateOfPipeline( 1 );
    
    disconnect( m_pProcess, SIGNAL( finished( int , QProcess::ExitStatus  ) ), 0 , 0 );
    
    QModelIndex selected_item = selected.indexes()[0];
    
    QString path_to_node = m_pModel->data( selected_item, AstadeDataModel::CR_PathToNode ).toString();
    qDebug() << "path to node: " << path_to_node;
    
    // Update view.
    QString program = Globals::self().omdGenerator();
    QStringList arguments;
    
    if ( m_pShowExternalsCheckBox->checkState() == Qt::Checked )
        arguments << "-e" ;
    
    if ( m_pAllClassesCheckBox->checkState() == Qt::Checked )
        arguments << "-s";
    
    arguments << "-o " + QString::number( m_pOperationsDisplayLevelSpinBox->value() );
    arguments << "-a " + QString::number( m_pAttDisplayLevelSpinBox->value() );

    arguments << path_to_node;
    qDebug() << "slotSelectionChanged: Argument: " << arguments;
    
    if ( ( m_pProcess->state() == QProcess::Starting ) 
        || ( m_pProcess->state() == QProcess::Running ) )
        m_pProcess->kill();
    
    m_pProcess->setStandardOutputFile( g_tmpDir + "/omg_out.dot" );
    
    connect ( m_pProcess, SIGNAL( finished( int , QProcess::ExitStatus  ) ),
             this, SLOT( slotOMDGeneratorFinished( int, QProcess::ExitStatus ) ) );

    qDebug() << "Start omg generator with: " << program << "and arguments: " << arguments;
    m_pProcess->start(program, arguments, QIODevice::WriteOnly | QIODevice::Text );
}

void UMLView::slotOMDGeneratorFinished( int exitcode, QProcess::ExitStatus exitStatus )
{
    Q_UNUSED( exitcode );
    Q_UNUSED( exitStatus );
    
    slotUpdateStateOfPipeline( 2 );
    
    disconnect( m_pProcess, SIGNAL(finished ( int , QProcess::ExitStatus  ) ), 0 , 0 );
    delete m_pProcess;
    m_pProcess = new QProcess( ProcessView::self() );
    
    QString program = Globals::self().dotAppPath();
    QStringList arguments;
    arguments << "-Tsvg" << QString( "-o%1/omg_out.svg" ).arg( g_tmpDir ) << QString( "%1/omg_out.dot" ).arg( g_tmpDir );
    
    if ( ( m_pProcess->state() == QProcess::Starting ) 
        || ( m_pProcess->state() == QProcess::Running ) ){
        qDebug() << "KILL PROCESS!!";
        m_pProcess->kill();
    }
        
    connect ( m_pProcess, SIGNAL( finished( int , QProcess::ExitStatus  ) ),
             this, SLOT( slotUpdateView( int, QProcess::ExitStatus ) ) );
    
    qDebug() << "Start dot with: " << program << "and arguments: " << arguments;
    m_pProcess->start(program, arguments);
}

void UMLView::slotUpdateView( int exitcode, QProcess::ExitStatus exitStatus )
{
    Q_UNUSED( exitcode );
    Q_UNUSED( exitStatus );

    slotUpdateStateOfPipeline( 3 );

    disconnect( m_pProcess, SIGNAL( finished ( int , QProcess::ExitStatus  ) ), 0 , 0 );

    m_pSvgView->setAutoFillBackground( true );
    m_pSvgView->load( QString( "%1/omg_out.svg" ).arg( g_tmpDir ) );
    m_pSvgView->resize(m_pSvgView->renderer()->defaultSize());

    slotUpdateStateOfPipeline( 0 );
}

void UMLView::slotStdErrorDataAvailable()
{
    qDebug() << "UMLView::slotStdErrorDataAvailable(): Error occured:" << m_pProcess->readAllStandardError();
}

void UMLView::slotUpdateStateOfPipeline( int state )
{
    m_pProgressBar->setValue( state );
}

void UMLView::setRootIndex( const QModelIndex& index )
{
    Q_UNUSED( index );
}
