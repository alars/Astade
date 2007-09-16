package org.tigris.ape.views.ModelTree;

import org.eclipse.jface.viewers.LabelProvider;
import org.eclipse.swt.graphics.Image;
import org.tigris.ape.Activator;
import org.tigris.ape.model.genericModelElements.IModelElement;
import org.tigris.ape.model.genericModelElements.ModelElementType;
import org.tigris.ape.preferences.PreferenceConstants;

class ViewLabelProvider extends LabelProvider {
	
	public String getText(Object obj) {
		if (obj instanceof org.eclipse.ui.progress.PendingUpdateAdapter){
			return "loading...";
		}
		return obj.toString();
	}
	
	
	public Image getImage(Object obj) {
	
		if(obj instanceof org.eclipse.ui.progress.PendingUpdateAdapter){
			return Activator.getDefault().getImageRegistry().get(ModelElementType.LOADING.getId());
		}
			
		if(Activator.getDefault().getPreferenceStore().getBoolean(PreferenceConstants.LARGE_ICONS)){
			return ((IModelElement)obj).getType().getImage();
		}
		else {
			return ((IModelElement)obj).getType().getSmallImage();
		}
	}
}