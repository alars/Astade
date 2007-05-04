/**
 * 
 */
package org.tigris.ape.views.ModelTree;

import org.eclipse.jface.viewers.LabelProvider;
import org.eclipse.swt.graphics.Image;
import org.tigris.ape.Activator;
import org.tigris.ape.preferences.PreferenceConstants;

class ViewLabelProvider extends LabelProvider {
	
	/**
	 * 
	 */
	private final ModelTreeView view;

	/**
	 * @param view
	 */
	ViewLabelProvider(ModelTreeView view) {
		this.view = view;
	}

	public String getText(Object obj) {
		return obj.toString();
	}
	
	public Image getImage(Object obj) {
	
		Image myImage = null;
		if(Activator.getDefault().getPreferenceStore().getBoolean(PreferenceConstants.LARGE_ICONS)){
			myImage = Activator.getDefault().getImageRegistry().get(obj.getClass().getName()); 
		}
		else {
			myImage = Activator.getDefault().getImageRegistry().get(obj.getClass().getName() + "small");
		}
		return myImage;
	}
}