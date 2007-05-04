/**
 * 
 */
package org.tigris.ape.model.genericModelElements;

import org.tigris.ape.model.treeElements.TreeObject;

public abstract class ModelElement implements TreeObject {

	protected String name;

	protected DirectoryElement parent;

	private String pathName;

	private ModelElement() {
	}

	public ModelElement(String name, String pathName) {
		parent = null;
		this.pathName = pathName;
		this.name = name;
	}

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

}
