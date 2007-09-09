/**
 * 
 */
package org.tigris.ape.views.ModelTree;

import org.eclipse.jface.viewers.ViewerSorter;
import org.tigris.ape.model.genericModelElements.IModelElement;

class NameSorter extends ViewerSorter {

	@Override
	public int category(Object element) {
		if (element instanceof IModelElement) {
			return ((IModelElement) element).getType().getOrdinal();
		}
		return super.category(element);
	}
}