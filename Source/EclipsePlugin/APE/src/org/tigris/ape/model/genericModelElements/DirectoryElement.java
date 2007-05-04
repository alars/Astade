package org.tigris.ape.model.genericModelElements;

import java.util.Vector;

import org.tigris.ape.model.treeElements.TreeObject;
import org.tigris.ape.model.treeElements.TreeParent;

public abstract class DirectoryElement extends ModelElement implements TreeParent {

	protected Vector<ModelElement> children;

	public DirectoryElement(String name, String pathName) {
		super(name, pathName);
		children = new Vector<ModelElement>(0); 
	}

	public TreeObject[] getChildren(){
		return (TreeObject[]) children.toArray(new TreeObject[children.size()]);
	}
		
	public void addChild(TreeObject child){
		children.add((ModelElement) child);
	};
	
	public void removeChild(TreeObject child) {
		children.removeElement(child);
	}
	
	public boolean hasChildren() {
		return !children.isEmpty();
	}
}
