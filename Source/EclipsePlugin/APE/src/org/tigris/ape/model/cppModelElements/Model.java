/**
 * 
 */
package org.tigris.ape.model.cppModelElements;

import java.util.Vector;

import org.tigris.ape.model.genericModelElements.ModelContainer;
import org.tigris.ape.model.genericModelElements.ModelRoot;
import org.tigris.ape.model.treeElements.TreeObject;

/**
 * @author Tobias Zipfel
 *
 */
public class Model extends ModelRoot {

	private Vector<ModelContainer> children;
	
	public Model(String pathName) {
		super(pathName);
		children = new Vector<ModelContainer>(0);
		name = "Model";
	}

	/* (non-Javadoc)
	 * @see org.tigris.ape.model.genericModelElements.ModelContainer#addChild(org.tigris.ape.model.treeElements.TreeObject)
	 */
	@Override
	public void addChild(TreeObject child) {
		if (child instanceof ModelContainer) {
			children.add((ModelContainer) child);
		}
	}
	
	/* (non-Javadoc)
	 * @see org.tigris.ape.model.genericModelElements.ModelElement#getParent()
	 */
	@Override
	public ModelContainer getParent() {
		return null;
	}

	/* (non-Javadoc)
	 * @see org.tigris.ape.model.genericModelElements.ModelElement#setParent(org.tigris.ape.model.genericModelElements.ModelContainer)
	 */
	@Override
	public void setParent(ModelContainer parent) {
		return;
	}

	/* (non-Javadoc)
	 * @see org.tigris.ape.model.treeElements.TreeParent#hasChildren()
	 */
	public boolean hasChildren() {
		return children.isEmpty();
	}

	/* (non-Javadoc)
	 * @see org.tigris.ape.model.treeElements.TreeParent#removeChild(org.tigris.ape.model.treeElements.TreeObject)
	 */
	public void removeChild(TreeObject child) {
		children.removeElement(child);
	}

	@Override
	public TreeObject[] getChildren() {
		return (TreeObject[]) children.toArray(new TreeObject[children.size()]);
	}

	@Override
	public void refreshChildren() {
		// TODO Auto-generated method stub
	}

	@Override
	public void loadModel() {
		// TODO Auto-generated method stub
		
	}
}
