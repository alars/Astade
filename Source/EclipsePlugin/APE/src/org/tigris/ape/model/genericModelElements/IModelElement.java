package org.tigris.ape.model.genericModelElements;


public interface IModelElement {

	public IModelElementType getType();
	public DirectoryElement getParent();
	public void setParent(DirectoryElement parent);
	public String getPathName();
	
	
}
