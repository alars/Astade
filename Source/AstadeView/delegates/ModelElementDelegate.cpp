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
#include "ModelElementDelegate.h"

#include <QDebug>
#include <QMenu>
#include <QWidget>
#include <QAction>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QPainter>
#include <QAbstractTextDocumentLayout>
#include <QTextDocument>
#include <QAbstractTextDocumentLayout>
#include <QAbstractItemView>
#include <QAbstractProxyModel>
#include <QAbstractItemModel>
#include <QIcon>

#include "AstadeDataModel.h"
#include "FeatureEditor.h"

ModelElementDelegate::ModelElementDelegate ( QObject * parent ):
QItemDelegate( parent ),
m_pTextDocument( NULL )
{
    // Use special Editor factory..
    setClipping( false );
    
    connect( this, SIGNAL( closeEditor ( QWidget *, QAbstractItemDelegate::EndEditHint ) ),
             this, SLOT( slotEditorClosed( QWidget *, QAbstractItemDelegate::EndEditHint ) ) );
}

QWidget* ModelElementDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex& index) const
{
    Q_UNUSED( option );
    qDebug() << "ModelElementDelegate::createEditor()";
    
    FeatureEditor* feature_editor = new FeatureEditor( parent );
    feature_editor->setAutoFillBackground( true );
    
    const AstadeDataModel* astade_model = qobject_cast<const AstadeDataModel*>( index.model() );
    const QAbstractProxyModel* proxy_model = qobject_cast<const QAbstractProxyModel*>( index.model() );
    QModelIndex astade_model_index = index;
    if ( ( NULL == astade_model ) && ( NULL != proxy_model ) )
    {
        // The astade model is hidden by proxy models. We will dig through all the source models
        // to find it.
        while ( NULL == astade_model )
        {
            astade_model_index = proxy_model->mapToSource( astade_model_index );
            astade_model       = qobject_cast<const AstadeDataModel*>( proxy_model->sourceModel() );
            proxy_model        = qobject_cast<const QAbstractProxyModel*>( proxy_model->sourceModel() );
            
            // Stop if there is no proxy model below..
            if ( NULL == proxy_model )
            { break; }
        }
    }
    Q_ASSERT( astade_model );
    Element* element = astade_model->elementForIndex( astade_model_index );
    feature_editor->setElement( element );
    
    // Override constness to keep some context information
    const_cast<ModelElementDelegate*>(this)->m_editorWidget = feature_editor;
    const_cast<ModelElementDelegate*>(this)->m_editedIndex = astade_model_index;
    
    // Relayout items
    // const_cast<QAbstractItemModel*>(index.model())->setData(index,QVariant(context_widget->sizeHint()),Qt::SizeHintRole);
    qDebug() << "Forcing layout";
    qobject_cast<QAbstractItemView*>( parent->parent() )->doItemsLayout();
    
    return feature_editor;
    
}

void ModelElementDelegate::setEditorData ( QWidget* editor, const QModelIndex& index ) const
{
    Q_UNUSED( editor );
    Q_UNUSED( index );
    // We don't need this. The Editor is fetching its data from the object.
}

void ModelElementDelegate::setModelData ( QWidget* editor, QAbstractItemModel* model, const QModelIndex& index ) const
{
    Q_UNUSED( editor );
    Q_UNUSED( model );
    Q_UNUSED( index );
    qDebug() << "ModelElementDelegate::setModelData()";
    FeatureEditor* feature_editor = qobject_cast<FeatureEditor*>( editor );
    if ( feature_editor )
    {
        QMap<QString, QVariant> changed_attributes = feature_editor->changedProperties();
        
        if ( !changed_attributes.isEmpty() )
        {
            model->setData( index, changed_attributes, AstadeDataModel::CR_ElementAttributes  );
        }
    }
}

QSize ModelElementDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{

    if ( m_editorWidget && ( m_editedIndex == index ) ){
        qDebug() << "->sizeHint(<1>): " << m_editorWidget->sizeHint();
        return m_editorWidget->sizeHint();
    } else {
        QTextDocument text_render( NULL );
        text_render.setDefaultFont( option.font );
        
        setTextOptions( &text_render, option );
        QString text = index.data( Qt::DisplayRole ).toString();
        text_render.setHtml( text );
        
        QRect display_rect = rect( option, index, Qt::DisplayRole );
        QRect decorationRect = rect(option, index, Qt::DecorationRole);
        QRect checkRect = rect(option, index, Qt::CheckStateRole);
        
        // FIXME: Why this offsets? (se)
        text_render.setTextWidth( option.rect.width() - ( (decorationRect.width() > 0) ? 40 : 5 ) /* display_rect.width() */ );
        // text_render.adjustSize();
        QSize text_size = text_render.size().toSize();
        // replace original display_rect with new from richtext layouter
        display_rect = QRect( display_rect.topLeft(), text_size );
        
        doLayout(option, &checkRect, &decorationRect, &display_rect, true);
        
        return (decorationRect|display_rect|checkRect).size();
    }
    
}

void ModelElementDelegate::updateEditorGeometry ( QWidget * editor, const QStyleOptionViewItem & option, const QModelIndex & index ) const
{
    Q_UNUSED( index );
    qDebug() << "ModelElementDelegate::updateEditorGeometry(): " << option.rect;
    // FIXME: We get the wrong height here.. Sizehint for this item was called but not used for the editor.. Is it a Qt bug?
    QRect editor_rect( option.rect.x(), option.rect.y(), option.rect.width(), editor->sizeHint().height() );
    editor->setGeometry( editor_rect );
}

// Protected
void ModelElementDelegate::drawDisplay ( QPainter* painter, const QStyleOptionViewItem& option, const QRect& rect, const QString& text ) const
{
    QTextDocument text_render( NULL /* const_cast<TableDelegate*>( this ) */ );
    text_render.setDefaultFont( option.font );
    setTextOptions( &text_render, option );
    text_render.setHtml( text );
    
    text_render.setTextWidth( 0 );
    QSize min_size = text_render.size().toSize();
    int min_width = min_size.width();
    
    text_render.setTextWidth( rect.width() );
    
    // If the text does not fit into cell, we will show an elided version of it and calculate
    // an offset for vertical alignment. This emulates the behavior of QItemDelegate.
    // Info: The elidedText() function needs plain text ..
    int v_offset = 0;
    if ( ( rect.width() < min_width ) || ( rect.height() < ( text_render.size().toSize().height() - 5 ) ) )
    {
        // Remove all line breaks.
        QString plain_text = text_render.toPlainText();
        plain_text.replace( QString::fromLatin1( "\n" ), " " );
        plain_text.replace( QString::fromLatin1( "\r" ), " " );
        
        // Elide text now.
        QString elided_text = option.fontMetrics.elidedText( plain_text, option.textElideMode, rect.width() - 5 );
        text_render.setPlainText( elided_text );
        
        // Disable word wrapping. We just want to show the text in one line.
        QTextOption text_option = text_render.defaultTextOption();
        text_option.setWrapMode( QTextOption::NoWrap );
        text_render.setDefaultTextOption( text_option );
        
        v_offset = ( rect.height() / 2 ) - ( text_render.size().toSize().height() / 2 );
    }  
    
    painter->save();
    
#if 0
    painter->setPen( Qt::yellow );
    painter->drawRect( QRect( rect.topLeft(), min_size ) );
#endif
    
#if 0
    painter->setPen( Qt::red );
    painter->drawRect( QRect( rect.topLeft(), text_render.size().toSize() ) );
#endif
    
#if 0
    painter->setPen( Qt::red );
    painter->drawRect( option.rect );
#endif
#if 0
    painter->setPen( Qt::green );
    painter->drawRect( rect.adjusted( 0, 0, -1, 0 ) );
    // qDebug() << "drawrect: " << rect;
#endif
    
    QRect text_paint_rect( rect );
    if ( v_offset )
    {
        text_paint_rect.adjust( 0, v_offset, 0, 0 );
    }
    painter->translate( text_paint_rect.topLeft() );
    if ( rect.width() > 0 )
    {
        text_render.drawContents( painter, QRect( QPoint( 0, 0 ), rect.size() ) );
    }
    painter->restore();
}

// Private Slots
void ModelElementDelegate::slotEditorClosed( QWidget *editor, QAbstractItemDelegate::EndEditHint hint )
{
    Q_UNUSED( hint );
    qDebug() << "ModelElementDelegate::slotEditorClosed()";
    m_editorWidget = NULL;
    qobject_cast<QAbstractItemView*>( editor->parent()->parent() )->doItemsLayout();
}

// Private
void ModelElementDelegate::updateLayoutWithText( const QString& text )
{
    if ( !m_pTextDocument )
        m_pTextDocument = new QTextDocument( const_cast<ModelElementDelegate*>( this ) );
    
    m_pTextDocument->setHtml( text );

}

bool ModelElementDelegate::isTextToWrap( const QStyleOptionViewItemV2& option ) const
{
    return option.features & QStyleOptionViewItemV2::WrapText;
}

void ModelElementDelegate::setTextOptions( QTextDocument* textDocument, const QStyleOptionViewItemV2& option ) const
{
    QTextOption text_option = textDocument->defaultTextOption();
    text_option.setTextDirection(option.direction);
    text_option.setWrapMode( isTextToWrap( option ) ? QTextOption::WordWrap : QTextOption::ManualWrap );
    text_option.setAlignment( QStyle::visualAlignment(option.direction, option.displayAlignment) );
    textDocument->setDefaultTextOption( text_option );
}

QRect ModelElementDelegate::decorationRect( const QStyleOptionViewItemV2& option, const QModelIndex& index ) const
{
    QRect decoration_rect;
    const int textMargin = QApplication::style()->pixelMetric(QStyle::PM_FocusFrameHMargin) + 1;

    QVariant value = index.data( Qt::DecorationRole );
    if ( value.isValid() ) {
        if ( value.type() == QVariant::Icon ) {
            QIcon icon = qvariant_cast<QIcon>( value );
            decoration_rect = QRect( QPoint(0, 0),
                                    option.decorationSize /*, iconMode, iconState */ );
        } else {
//            pixmap = decoration(opt, value);
//            decorationRect = QRect(QPoint(0, 0), pixmap.size());
        }
    }
    QSize pm(0, 0);
    pm = decoration_rect.size();
    pm.rwidth() += 2 * textMargin;
    decoration_rect = QRect( QPoint( 0, 0 ), pm );
    return decoration_rect;
}
