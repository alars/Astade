package org.tigris.ape.model.genericModelElements;

import java.io.File;
import java.util.Vector;

import org.tigris.ape.model.cppModelElements.ElementFactory;
import org.tigris.ape.model.treeElements.TreeObject;
import org.tigris.ape.model.treeElements.TreeParent;

public abstract class DirectoryElement extends ModelElement implements TreeParent {

	protected Vector<ModelElement> children;

	public DirectoryElement(String pathName) {
		super(pathName);
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
	
	public void removeAllChildren(){
		children.clear();		
	}
	
	public void loadChildren(){
		
		File thisDir = new File(getPathName());
		if(thisDir.exists() && thisDir.isDirectory()) {
			File[] files = thisDir.listFiles();
			for (int i = 0; i < files.length; i++) {
				if(files[i].isDirectory() && !files[i].isHidden()){
					ModelElement newElement = ElementFactory.getInstance().getModelElement(files[i].getAbsolutePath());
					if(newElement != null){
						addChild(newElement);
						newElement.setParent(this);
						((DirectoryElement)newElement).loadChildren();
					}
				}
			}
		}
	}
}
