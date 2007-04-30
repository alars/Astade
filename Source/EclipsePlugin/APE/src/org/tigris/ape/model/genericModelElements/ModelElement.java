/**
 * 
 */
package org.tigris.ape.model.genericModelElements;

import org.tigris.ape.model.treeElements.TreeObject;

/**
 * @author Tobias Zipfel
 * 
 */
public abstract class ModelElement implements TreeObject {

	protected String name;

	protected ModelContainer parent;

	private String pathName;

	private ModelElement() {
	}

	public ModelElement(String pathName) {
		parent = null;
		this.pathName = pathName;
		name = "unknown Element";
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

	public ModelContainer getParent() {
		return parent;
	}
	
	abstract public void setParent(ModelContainer parent);

	/**
	 * @return the pathName
	 */
	public String getPathName() {
		return pathName;
	}

}
