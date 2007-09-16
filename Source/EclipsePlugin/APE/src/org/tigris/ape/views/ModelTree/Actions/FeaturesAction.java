package org.tigris.ape.views.ModelTree.Actions;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashSet;

import org.apache.log4j.Logger;
import org.eclipse.jface.viewers.ITreeSelection;
import org.eclipse.ui.ISharedImages;
import org.eclipse.ui.PlatformUI;
import org.tigris.ape.Activator;
import org.tigris.ape.defines.AstadeDefines;
import org.tigris.ape.model.cppModelElements.CppModelElementType;
import org.tigris.ape.model.genericModelElements.IModelElementType;
import org.tigris.ape.model.genericModelElements.ModelElement;
import org.tigris.ape.preferences.PreferenceConstants;
import org.tigris.ape.views.ModelTree.ModelTreeView;

public class FeaturesAction extends ModelTreeViewAction {

	public static final Logger logger = Logger.getLogger(FeaturesAction.class.getName());

	private HashSet<String> allowedTypes;
	
	public FeaturesAction(ModelTreeView view) {
		super(view);
		setText("features");
		setToolTipText("Edit features");
		setImageDescriptor(PlatformUI.getWorkbench().getSharedImages()
				.getImageDescriptor(ISharedImages.IMG_OBJ_ELEMENT));
		allowedTypes = new HashSet<String>();
		allowedTypes.add(CppModelElementType.ATTRIBUTE.getId());
		allowedTypes.add(CppModelElementType.CLASS.getId());
		allowedTypes.add(CppModelElementType.COMPONENT.getId());
		allowedTypes.add(CppModelElementType.COMPONENTS.getId());
		allowedTypes.add(CppModelElementType.CONFIGURATION.getId());
		allowedTypes.add(CppModelElementType.OPERATION.getId());
		allowedTypes.add(CppModelElementType.PACKAGE.getId());
		allowedTypes.add(CppModelElementType.PARAMETER.getId());
		allowedTypes.add(CppModelElementType.RELATION.getId());
	}

	class FeatureEditorRunable implements Runnable {

		private String path;
		
		public FeatureEditorRunable(String pathToModelNodeINI){
			path = pathToModelNodeINI;
		}
		
		@Override
		public void run() {
			
			String execCommand = Activator.getDefault().getPreferenceStore().getString(PreferenceConstants.ASTADE_PATH) 
				+ "\\" + AstadeDefines.FEATUREEDITOR;

			ProcessBuilder builder = new ProcessBuilder(execCommand, path );
			
			try {
				Process featureEditor = builder.start();
				if(logger.isDebugEnabled()){
					logger.debug(AstadeDefines.FEATUREEDITOR + " returned with " + featureEditor.waitFor());
				} else {
					featureEditor.waitFor();
				}
				
			} catch (IOException e) {
				logger.error("Feature Editor did not start. Command line was:\n\t" + execCommand);
				e.printStackTrace();
			} catch (InterruptedException e) {
				logger.error("Feature Editor thread was interrupted ");
				e.printStackTrace();
			}
		}
	}
	
	public void run() {
		
		ITreeSelection selectedElem = (ITreeSelection) view.getViewSite().getSelectionProvider().getSelection();
		
		ModelElement selectedModelElement = (ModelElement) selectedElem.getFirstElement();
//		TODO: should work also for fileElements... + filename 
		Thread test = new Thread(new FeatureEditorRunable(selectedModelElement.getPathName() + selectedModelElement.getFileName()));
		test.start();
	}

	@Override
	public boolean isAllowedFor(IModelElementType type) {
		return allowedTypes.contains(type.getId());
	}
}
