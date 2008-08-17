#include <Carbon/Carbon.h>
#include <QWidget>
#include <QMenu>

// The SearchWidget_ class wraps a native HISearchField.
class SearchWidget_ : public QWidget
{
    Q_OBJECT
private:
    HIViewRef searchField;
    CFStringRef searchFieldText;

public:
    SearchWidget_(QWidget *parent = 0)
    :QWidget(parent)
    {
        // Create a native search field and pass its window id to QWidget::create.
        searchFieldText = CFStringCreateWithCString(0, "search", 0);
        HISearchFieldCreate(NULL/*bounds*/, kHISearchFieldAttributesSearchIcon | kHISearchFieldAttributesCancel,
                            NULL/*menu ref*/, searchFieldText, &searchField);
        create(reinterpret_cast<WId>(searchField));

    
        // Use a Qt menu for the search field menu.
        QMenu *searchMenu = new QMenu(this);
        
        QAction * indexAction = searchMenu->addAction("Index Search");
        indexAction->setCheckable(true);
        indexAction->setChecked(true);

        QAction * fulltextAction = searchMenu->addAction("Full Text Search");
        fulltextAction->setCheckable(true);

        QActionGroup *searchActionGroup = new QActionGroup(this);
        searchActionGroup->addAction(indexAction);
        searchActionGroup->addAction(fulltextAction);
        searchActionGroup->setExclusive(true);
        
        MenuRef macSearchMenu = searchMenu->macMenu(0);
        HISearchFieldSetSearchMenu(searchField, macSearchMenu);
        setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

    }

    ~SearchWidget_()
    {
        CFRelease(searchField);
        CFRelease(searchFieldText);
    }

    // Get the size hint from the search field.
    QSize sizeHint() const
    {
        EventRef event;
        HIRect optimalBounds;
        CreateEvent(0, kEventClassControl,
            kEventControlGetOptimalBounds,
            GetCurrentEventTime(),
            kEventAttributeUserEvent, &event);

        SendEventToEventTargetWithOptions(event,
            HIObjectGetEventTarget(HIObjectRef(winId())),
            kEventTargetDontPropagate);

        GetEventParameter(event,
            kEventParamControlOptimalBounds, typeHIRect,
            0, sizeof(HIRect), 0, &optimalBounds);

        ReleaseEvent(event);
        return QSize(optimalBounds.size.width + 400, // make it a bit wider.
                     optimalBounds.size.height);
    }
};

class SearchWidget : public QWidget
{
Q_OBJECT
public:
    SearchWidget(QWidget *parent = 0)
    :QWidget(parent)
    {
        s = new SearchWidget_(this);
        s->move(2,2);
        setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
    }

    QSize sizeHint() const
    {
        return s->sizeHint() + QSize(6, 4);
    }
   
    SearchWidget_ *s;
};
