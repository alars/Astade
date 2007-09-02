package org.tigris.ape.views.ModelTree.Actions;

import java.io.IOException;

import org.apache.log4j.Logger;
import org.eclipse.jface.viewers.ITreeSelection;
import org.eclipse.ui.ISharedImages;
import org.eclipse.ui.PlatformUI;
import org.tigris.ape.Activator;
import org.tigris.ape.defines.AstadeDefines;
import org.tigris.ape.defines.IniDefines;
import org.tigris.ape.model.genericModelElements.ModelElement;
import org.tigris.ape.preferences.PreferenceConstants;
import org.tigris.ape.views.ModelTree.ModelTreeView;

public class FeaturesAction extends ModelTreeViewAction {

	public static final Logger logger = Logger.getLogger(FeaturesAction.class.getName());
	
	public FeaturesAction(ModelTreeView view) {
		super(view);
		setText("features");
		setToolTipText("Edit features");
		setImageDescriptor(PlatformUI.getWorkbench().getSharedImages()
				.getImageDescriptor(ISharedImages.IMG_OBJ_ELEMENT));

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

			ProcessBuilder builder = new ProcessBuilder(execCommand, path + IniDefines.INIFILE);
			
			try {
				Process featureEditor = builder.start();
				//TODO use return code for... 
				if(logger.isDebugEnabled()){
					logger.debug(AstadeDefines.FEATUREEDITOR + " returned with " + featureEditor.waitFor());
				} else {
					featureEditor.waitFor();
				}
				
			} catch (IOException e) {
				logger.error("Feature Editor did not start. Command line was:\n\t" + execCommand);
				e.printStackTrace();
			} catch (InterruptedException e) {
				// TODO: Check what's a Interrupted Exception really is...
				logger.error("Feature Editor thread was interrupted ");
				e.printStackTrace();
			}
		}
	}
	
	public void run() {
		
		ITreeSelection selectedElem = (ITreeSelection) view.getViewSite().getSelectionProvider().getSelection();
		
		ModelElement selectedModelElements = (ModelElement) selectedElem.getFirstElement();
		
		Thread test = new Thread(new FeatureEditorRunable(selectedModelElements.getPathName()));
		test.start();
//		view.showMessage(Activator.getDefault().getPreferenceStore().getString(PreferenceConstants.MODEL_PATH));	
	}
	
	@Override
	public boolean isEnabled() {
		
		// check the type...
		if(super.isEnabled()){
			return true;
		} 

		return false;
	}
}
