package org.tigris.ape.model.genericModelElements;

import java.io.File;
import java.util.Vector;

import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.core.runtime.jobs.ISchedulingRule;
import org.eclipse.jface.resource.ImageDescriptor;
import org.eclipse.ui.progress.IDeferredWorkbenchAdapter;
import org.eclipse.ui.progress.IElementCollector;
import org.tigris.ape.model.cppModelElements.ElementFactory;
import org.tigris.ape.model.treeElements.TreeObject;
import org.tigris.ape.model.treeElements.TreeParent;

public abstract class DirectoryElement extends ModelElement implements TreeParent, IDeferredWorkbenchAdapter {

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
	
	public void fetchDeferredChildren(Object object, IElementCollector collector, IProgressMonitor monitor) {

		removeAllChildren();
		File thisDir = new File(getPathName());
		if (thisDir.exists() && thisDir.isDirectory()) {
			File[] files = thisDir.listFiles();
			monitor.beginTask("Loading", files.length);
			for (int i = 0; i < files.length; i++) {
				if (files[i].isDirectory() && !files[i].isHidden()) {
					ModelElement newElement = ElementFactory.getInstance()
							.getModelElement(files[i].getAbsolutePath());
					if (newElement != null) {
						addChild(newElement);
						newElement.setParent(this);
						collector.add(newElement, monitor);
					}
					monitor.worked(1);
				    if (monitor.isCanceled()){
				    	removeAllChildren();
				    	monitor.done();
				    	return;
				    }
				}
			}
			monitor.done();
		}
	}
	
	public boolean isContainer() {
		return (this instanceof TreeParent);
	}

	public ISchedulingRule getRule(Object object) {
		return null;
	}

	public ImageDescriptor getImageDescriptor(Object object) {
		return null;
	}

	public String getLabel(Object o) {
		return getName();
	}

	public Object[] getChildren(Object o) {
		return getChildren();
	}
	
	public Object getParent(Object o) {
		return getParent(o);
	}
}
