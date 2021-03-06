#ifndef UMLView_H_
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
#define UMLView_H_

#include <QPointer>
#include <QItemSelection>
#include <QProcess>

#include <AstadeView.h>

class QAbstractItemModel;
class QSvgWidget;
class QProcess;
class QCheckBox;
class QSpinBox;
class QProgressBar;

/** 
 * This class shows the model as UML diagram. This is just a quick hack to show how
 * to use shared selections. 
 */
class UMLView: public AstadeView
{
    Q_OBJECT
public:
    UMLView( QWidget* parent );
    void setModels( QAbstractItemModel* model, QItemSelectionModel *selections );
    void setRootIndex( const QModelIndex& index );
    
protected slots:
    void slotSelectionChanged( const QItemSelection& selected, const QItemSelection& deselected );  
    void slotOMDGeneratorFinished( int exitcode, QProcess::ExitStatus exitStatus ); 
    void slotUpdateView( int exitcode, QProcess::ExitStatus exitStatus );
    void slotStdErrorDataAvailable();
    void slotUpdateStateOfPipeline( int state );
    
private:
    QPointer<QAbstractItemModel> m_pModel;
    QSvgWidget* m_pSvgView;
    QProcess* m_pProcess;
    QCheckBox* m_pShowExternalsCheckBox;
    QCheckBox* m_pAllClassesCheckBox;
    QSpinBox* m_pAttDisplayLevelSpinBox;
    QSpinBox* m_pOperationsDisplayLevelSpinBox;
    QProgressBar* m_pProgressBar;
};


#endif // UMLView_H_
