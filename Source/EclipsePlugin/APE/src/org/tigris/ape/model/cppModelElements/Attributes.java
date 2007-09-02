package org.tigris.ape.model.cppModelElements;

import org.tigris.ape.model.genericModelElements.DirectoryElement;
import org.tigris.ape.model.genericModelElements.IModelElementType;

public class Attributes extends DirectoryElement {

	public Attributes(String pathName) {
		super(pathName);
	}

	@Override
	public IModelElementType getType() {
		return CppModelElementType.ATTRIBUTES;
	}

}
