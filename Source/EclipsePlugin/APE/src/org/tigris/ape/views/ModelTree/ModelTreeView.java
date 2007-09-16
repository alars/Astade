package org.tigris.ape.views.ModelTree;

import org.eclipse.jface.action.Action;
import org.eclipse.jface.action.IMenuListener;
import org.eclipse.jface.action.IMenuManager;
import org.eclipse.jface.action.IToolBarManager;
import org.eclipse.jface.action.MenuManager;
import org.eclipse.jface.action.Separator;
import org.eclipse.jface.dialogs.MessageDialog;
import org.eclipse.jface.util.IPropertyChangeListener;
import org.eclipse.jface.util.PropertyChangeEvent;
import org.eclipse.jface.viewers.DoubleClickEvent;
import org.eclipse.jface.viewers.IDoubleClickListener;
import org.eclipse.jface.viewers.ISelection;
import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.jface.viewers.ITreeSelection;
import org.eclipse.jface.viewers.TreeViewer;
import org.eclipse.swt.SWT;
import org.eclipse.swt.events.TreeEvent;
import org.eclipse.swt.events.TreeListener;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Menu;
import org.eclipse.swt.widgets.Tree;
import org.eclipse.ui.IActionBars;
import org.eclipse.ui.ISharedImages;
import org.eclipse.ui.IViewReference;
import org.eclipse.ui.IViewSite;
import org.eclipse.ui.IWorkbenchActionConstants;
import org.eclipse.ui.PartInitException;
import org.eclipse.ui.PlatformUI;
import org.eclipse.ui.part.DrillDownAdapter;
import org.eclipse.ui.part.ViewPart;
import org.tigris.ape.Activator;
import org.tigris.ape.model.cppModelElements.CppModelElementType;
import org.tigris.ape.model.genericModelElements.IModelElement;
import org.tigris.ape.model.genericModelElements.IModelElementType;
import org.tigris.ape.model.genericModelElements.ModelElement;
import org.tigris.ape.views.ModelTree.Actions.FeaturesAction;

public class ModelTreeView extends ViewPart {

	private TreeViewer viewer;

	private IPropertyChangeListener preferenceListener;

	private DrillDownAdapter drillDownAdapter;

	private Action action2;

	private FeaturesAction featuresAction;

	private Action doubleClickAction;

	/**
	 * The constructor.
	 */
	public ModelTreeView() {
	}

	/**
	 * This is a callback that will allow us to create the viewer and initialize
	 * it.
	 */
	public void createPartControl(Composite parent) {

		viewer = new TreeViewer(parent, SWT.MULTI | SWT.H_SCROLL | SWT.V_SCROLL
				| SWT.VIRTUAL);
		drillDownAdapter = new DrillDownAdapter(viewer);
		viewer.setContentProvider(new ViewContentProvider(viewer));
		viewer.setLabelProvider(new ViewLabelProvider());
		viewer.setSorter(new NameSorter());
		viewer.setInput(getViewSite());

		((Tree) viewer.getControl()).addTreeListener(new TreeListener() {

			public void treeCollapsed(TreeEvent e) {
				viewer.refresh(e.item.getData());
			}

			public void treeExpanded(TreeEvent e) {
			}
		});
		makeActions();
		hookContextMenu();
		hookDoubleClickAction();
		contributeToActionBars();
		getSite().setSelectionProvider(viewer);
	}

	private void hookContextMenu() {
		MenuManager menuMgr = new MenuManager("#PopupMenu");
		menuMgr.setRemoveAllWhenShown(true);
		menuMgr.addMenuListener(new IMenuListener() {
			public void menuAboutToShow(IMenuManager manager) {
				ModelTreeView.this.fillContextMenu(manager);
			}
		});
		Menu menu = menuMgr.createContextMenu(viewer.getControl());
		viewer.getControl().setMenu(menu);
		getSite().registerContextMenu(menuMgr, viewer);
	}

	private void contributeToActionBars() {
		IActionBars bars = getViewSite().getActionBars();
		fillLocalPullDown(bars.getMenuManager());
		fillLocalToolBar(bars.getToolBarManager());
	}

	private void fillLocalPullDown(IMenuManager manager) {
		manager.add(action2);
		manager.add(new Separator());
		manager.add(featuresAction);
	}

	private void fillContextMenu(IMenuManager manager) {

		// TODO: delete if not needed
		manager.add(action2);

		if (!viewer.getSelection().isEmpty()) {
			ITreeSelection selection = (ITreeSelection) getSite()
					.getSelectionProvider().getSelection();

			if (selection.getFirstElement() instanceof IModelElement) {
				IModelElement element = (IModelElement) selection
						.getFirstElement();
				
				IModelElementType type = element.getType();
				
//				check which actions are allowed for this element
				if (featuresAction.isAllowedFor(type)){
					manager.add(featuresAction);
				}
			}
		}

		manager.add(new Separator());
		// drillDownAdapter.addNavigationActions(manager);
		// Other plug-ins can contribute there actions here
		manager.add(new Separator(IWorkbenchActionConstants.MB_ADDITIONS));
	}

	private void fillLocalToolBar(IToolBarManager manager) {
		manager.add(action2);
		manager.add(new Separator());
		// drillDownAdapter.addNavigationActions(manager);
	}

	private void makeActions() {

		featuresAction = new FeaturesAction(this);

		action2 = new Action() {
			public void run() {
				showMessage("Action 2 executed");
			}
		};
		action2.setText("Action 2");
		action2.setToolTipText("Action 2 tooltip");
		action2.setImageDescriptor(PlatformUI.getWorkbench().getSharedImages()
				.getImageDescriptor(ISharedImages.IMG_OBJS_INFO_TSK));

		doubleClickAction = new Action() {
			public void run() {
				ISelection selection = viewer.getSelection();
				ModelElement element = (ModelElement) ((IStructuredSelection) selection)
						.getFirstElement();
				showMessage("Double-click detected on "
						+ element.getClass().getName() + " \n\twith realname "
						+ element.getPathName());

			}
		};
	}

	private void hookDoubleClickAction() {
		viewer.addDoubleClickListener(new IDoubleClickListener() {
			public void doubleClick(DoubleClickEvent event) {
				doubleClickAction.run();
			}
		});
	}

	public void showWarn(String message) {
		MessageDialog.openError(viewer.getControl().getShell(), "Model Tree",
				message);
	}

	public void showMessage(String message) {
		MessageDialog.openInformation(viewer.getControl().getShell(),
				"Model Tree", message);
	}

	/**
	 * Passing the focus request to the viewer's control.
	 */
	public void setFocus() {
		viewer.getControl().setFocus();
	}

	@Override
	public void init(IViewSite site) throws PartInitException {
		super.init(site);
		preferenceListener = new IPropertyChangeListener() {
			public void propertyChange(PropertyChangeEvent event) {

				IViewReference[] test = PlatformUI.getWorkbench()
						.getActiveWorkbenchWindow().getActivePage()
						.getViewReferences();
				for (int i = 0; i < test.length; i++) {
					if (test[i].getTitle()
							.equals(ModelTreeView.this.getTitle())) {
						PlatformUI.getWorkbench().getActiveWorkbenchWindow()
								.getActivePage().hideView(test[i]);
						try {
							PlatformUI.getWorkbench()
									.getActiveWorkbenchWindow().getActivePage()
									.showView(test[i].getId());
						} catch (PartInitException e) {
							System.err
									.println("Model Tree view could not be initialized!");
							e.printStackTrace();
						}
					}
				}
			}
		};
		Activator.getDefault().getPreferenceStore().addPropertyChangeListener(
				preferenceListener);
		// getSite().setSelectionProvider(viewer);
	}

	@Override
	public void dispose() {
		Activator.getDefault().getPreferenceStore()
				.removePropertyChangeListener(preferenceListener);
		super.dispose();
	}
}