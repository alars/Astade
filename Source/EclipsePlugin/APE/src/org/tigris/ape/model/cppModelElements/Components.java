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
public class Components extends ModelContainer {

	private Vector<ModelContainer> children;
	
	public Components(String pathName, ModelRoot root) {
		super(pathName);
		this.parent = root;
		children = new Vector<ModelContainer>(0);
		name = "Components";
	}

	/* (non-Javadoc)
	 * @see org.tigris.ape.model.genericModelElements.ModelContainer#addChild(org.tigris.ape.model.treeElements.TreeObject)
	 */
	@Override
	public void addChild(TreeObject child) {
		// TODO Auto-generated method stub

	}

	/* (non-Javadoc)
	 * @see org.tigris.ape.model.genericModelElements.ModelContainer#getChildren()
	 */
	@Override
	public TreeObject[] getChildren() {
		return (TreeObject[]) children.toArray(new TreeObject[children.size()]);
	}

	/* (non-Javadoc)
	 * @see org.tigris.ape.model.genericModelElements.ModelContainer#refreshChildren()
	 */
	@Override
	public void refreshChildren() {
		// TODO Auto-generated method stub

	}

	/* (non-Javadoc)
	 * @see org.tigris.ape.model.genericModelElements.ModelElement#setParent(org.tigris.ape.model.genericModelElements.ModelContainer)
	 */
	@Override
	public void setParent(ModelContainer parent) {
		this.parent = parent;
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
		// TODO Auto-generated method stub

	}

}
