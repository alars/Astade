package org.tigris.ape.views.ModelTree.Actions;

import java.io.File;
import java.io.IOException;

import org.apache.log4j.Logger;
import org.eclipse.jface.viewers.ISelection;
import org.eclipse.ui.ISharedImages;
import org.eclipse.ui.PlatformUI;
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

	public void run() {
		view.showWarn("run Features");
		logger.info("TEST");
		ISelection select = view.getViewSite().getSelectionProvider().getSelection();
		ProcessBuilder builder = new ProcessBuilder("ResourceEdit","");
		builder.directory(new File("C:/Programme/Astade/"));
		try {
			Process featureEditor = builder.start();
		} catch (IOException e) {
			view.showWarn("ResourceEdit can not be opend!");			
		}
//		view.showMessage(Activator.getDefault().getPreferenceStore().getString(PreferenceConstants.MODEL_PATH));	
	}
	
}
