package org.tigris.ape.model.genericModelElements;

import org.eclipse.swt.graphics.Image;

public interface IModelElementType extends Comparable<IModelElementType>{
	
	public String getId();
	public String getPrintName();
	public Image getImage();
	public Image getSmallImage();
	public int getOrdinal();
}
