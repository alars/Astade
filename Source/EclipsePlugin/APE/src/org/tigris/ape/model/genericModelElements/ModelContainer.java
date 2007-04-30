package org.tigris.ape.model.genericModelElements;

import org.tigris.ape.model.treeElements.TreeObject;
import org.tigris.ape.model.treeElements.TreeParent;

/**
 * @author Tobias Zipfel
 * 
 */
public abstract class ModelContainer extends ModelElement implements TreeParent {

	public ModelContainer(String pathName) {
		super(pathName);
	}

	abstract public void refreshChildren();
	
	abstract public TreeObject[] getChildren();
		
	abstract public void addChild(TreeObject child);
}
