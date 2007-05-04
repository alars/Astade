package org.tigris.ape.model.cppModelElements;

import java.util.Vector;

import org.tigris.ape.model.genericModelElements.DirectoryElement;
import org.tigris.ape.model.genericModelElements.ModelElement;

public class Package extends DirectoryElement {
	
	public Package(String name, String pathName, DirectoryElement parent){
		super(name, pathName);
		this.parent = parent;
		parent.addChild(this);
		children = new Vector<ModelElement>(0);
		name = "package";
	}
}
