package org.tigris.ape.views.ModelTree;

import java.io.File;

import org.apache.log4j.Logger;
import org.eclipse.jface.viewers.IStructuredContentProvider;
import org.eclipse.jface.viewers.ITreeContentProvider;
import org.eclipse.jface.viewers.TreeViewer;
import org.eclipse.jface.viewers.Viewer;
import org.eclipse.ui.IViewSite;
import org.eclipse.ui.progress.DeferredTreeContentManager;
import org.tigris.ape.Activator;
import org.tigris.ape.model.cppModelElements.ElementFactory;
import org.tigris.ape.model.cppModelElements.astadeElements.Model;
import org.tigris.ape.model.genericModelElements.DirectoryElement;
import org.tigris.ape.model.genericModelElements.IModelElementType;
import org.tigris.ape.model.genericModelElements.ModelElement;
import org.tigris.ape.model.genericModelElements.ModelElementType;
import org.tigris.ape.preferences.PreferenceConstants;

class ViewContentProvider implements IStructuredContentProvider,
			ITreeContentProvider {
	
		public static final Logger logger = Logger.getLogger(ViewContentProvider.class.getName());

		private DeferredTreeContentManager manager;
		
		private IViewSite mySite;
		
		private TreeRoot invisibleRoot;
		
		private class TreeRoot extends DirectoryElement{
			
			public TreeRoot(){
				super("");
			}

			@Override
			public IModelElementType getType() {
				return ModelElementType.ROOT;
			}
		}
		
		ViewContentProvider(TreeViewer viewer) {
			manager = new DeferredTreeContentManager(this, viewer);
			invisibleRoot = null;	
		}

		public void inputChanged(Viewer v, Object oldInput, Object newInput) {
			
			if(newInput != null){
				mySite = (IViewSite) newInput;
			}
		}

		public void dispose() {
		}

		public Object[] getElements(Object parent) {
			if (parent.equals(mySite)) {
				if (invisibleRoot == null){
					initialize();					
				}
				if(invisibleRoot != null){
					return invisibleRoot.getChildren();	
				}
			}
//			if(parent instanceof DirectoryElement){
//				return ((DirectoryElement)parent).getChildren();
//			}
			return new ModelElement[0];
		}

		public Object getParent(Object child) {
			if (child instanceof ModelElement) {
				return ((ModelElement) child).getParent();
			}
			return null;
		}
		
		public Object[] getChildren(Object parent) {
			if (parent==invisibleRoot) {
				return ( (TreeRoot) invisibleRoot).getChildren();
			} else if (parent instanceof DirectoryElement) {
				return manager.getChildren(parent);
			}
			return new Object[0];
		}

		public boolean hasChildren(Object parent) {
			return manager.mayHaveChildren(parent);
		}

		private void initialize() {
			File rootModelIni = new File(Activator.getDefault().
					getPreferenceStore().getString(PreferenceConstants.MODEL_PATH));
			Model model = (Model) ElementFactory.getInstance().getModelElement(rootModelIni);
			if(model != null){
				invisibleRoot = new TreeRoot();
				invisibleRoot.addChild(model);
				model.setParent(invisibleRoot);
			} else {
				logger.error("Model can not be loaded!");
			}
		}

		/**
		 * @return the manager
		 */
		public DeferredTreeContentManager getManager() {
			return manager;
		}
}
