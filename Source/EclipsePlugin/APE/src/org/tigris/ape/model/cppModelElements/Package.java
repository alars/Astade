package org.tigris.ape.model.cppModelElements;

import java.util.Vector;

import org.tigris.ape.model.genericModelElements.DirectoryElement;
import org.tigris.ape.model.genericModelElements.IModelElementType;
import org.tigris.ape.model.genericModelElements.ModelElement;

public class Package extends DirectoryElement {
	
	public Package(String pathName){
		super(pathName);
		children = new Vector<ModelElement>(0);
	}

	@Override
	public IModelElementType getType() {
		return CppModelElementType.PACKAGE;
	}

}
