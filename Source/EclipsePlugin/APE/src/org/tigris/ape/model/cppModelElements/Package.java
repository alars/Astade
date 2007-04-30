package org.tigris.ape.model.cppModelElements;

import java.util.Vector;

import org.tigris.ape.model.genericModelElements.ModelContainer;
import org.tigris.ape.model.treeElements.TreeObject;

public class Package extends ModelContainer {
	
	private Vector<ModelContainer> children;
	
	public Package(String pathName, ModelContainer parent){
		super(pathName);
		this.parent = parent;
		children = new Vector<ModelContainer>(0);
		name = "default package";
		
	}
	
	@Override
	public void addChild(TreeObject child) {
		return;
	}

	public boolean hasChildren() {
		return children.isEmpty();
	}

	public void removeChild(TreeObject child) {
		// TODO Auto-generated method stub

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
	public void setParent(ModelContainer parent) {
		// TODO Auto-generated method stub
		
	}

}
