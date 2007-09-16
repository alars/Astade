/**
 * 
 */
package org.tigris.ape.model.genericModelElements;

import org.apache.log4j.Logger;
import org.tigris.ape.model.treeElements.TreeObject;

public abstract class ModelElement implements TreeObject, IModelElement {
	
	static Logger logger = Logger.getLogger(ModelElement.class.getName());

	protected String name;

	protected DirectoryElement parent;

	private String pathName;
	
	public ModelElement(String pathName) {
		parent = null;
		this.pathName = pathName;
		this.name = "unknown";
	}
	
	abstract public String getFileName();
	
	/*
	 * (non-Javadoc)
	 * 
	 * @see org.eclipse.core.runtime.IAdaptable#getAdapter(java.lang.Class)
	 */
	public Object getAdapter(Class adapter) {
		// TODO Auto-generated method stub
		return null;
	}

	public void setName(String newName) {
		this.name = newName;
	}

	public String getName() {
		return name;
	}

	@Override
	public String toString() {
		return name;
	}

	public DirectoryElement getParent() {
		return parent;
	}
	
	public void setParent(DirectoryElement parent){
		this.parent = parent;
	}

	public String getPathName() {
		return pathName;
	}
	
	@Override
	public IModelElementType getType() {
		return ModelElementType.UNKNOWN;
	}

}
