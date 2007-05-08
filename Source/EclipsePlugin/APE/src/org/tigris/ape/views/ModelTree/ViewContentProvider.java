/**
 * 
 */
package org.tigris.ape.views.ModelTree;

import org.eclipse.jface.viewers.IStructuredContentProvider;
import org.eclipse.jface.viewers.ITreeContentProvider;
import org.eclipse.jface.viewers.Viewer;
import org.tigris.ape.Activator;
import org.tigris.ape.model.cppModelElements.ElementFactory;
import org.tigris.ape.model.cppModelElements.Model;
import org.tigris.ape.model.genericModelElements.DirectoryElement;
import org.tigris.ape.model.genericModelElements.ModelElement;
import org.tigris.ape.preferences.PreferenceConstants;

class ViewContentProvider implements IStructuredContentProvider,
			ITreeContentProvider {
		/**
		 * 
		 */
		private final ModelTreeView view;

		/**
		 * @param view
		 */
		ViewContentProvider(ModelTreeView view) {
			this.view = view;
		}

		private Model invisibleRoot;
		
		private boolean initDone = false;

		public void inputChanged(Viewer v, Object oldInput, Object newInput) {
		}

		public void dispose() {
		}

		public Object[] getElements(Object parent) {
			if (parent.equals(this.view.getViewSite())) {
				if (invisibleRoot == null)
					initialize();
				return getChildren(invisibleRoot);
			}
			return getChildren(parent);
		}

		public Object getParent(Object child) {
			if (child instanceof ModelElement) {
				return ((ModelElement) child).getParent();
			}
			return null;
		}

		public Object[] getChildren(Object parent) {
			if (parent instanceof DirectoryElement) {
				((DirectoryElement)parent).removeAllChildren();
				((DirectoryElement)parent).loadChildren();
				initDone = true;
				return ((DirectoryElement) parent).getChildren();
			}
			return new ModelElement[0];
		}

		public boolean hasChildren(Object parent) {
			if (parent instanceof DirectoryElement)
				
				return ((DirectoryElement) parent).hasChildren();
			return false;
		}

		private void initialize() {
			invisibleRoot = (Model) ElementFactory.getInstance().getModelElement(Activator.getDefault().
					getPreferenceStore().getString(PreferenceConstants.MODEL_PATH));
		}
	}
