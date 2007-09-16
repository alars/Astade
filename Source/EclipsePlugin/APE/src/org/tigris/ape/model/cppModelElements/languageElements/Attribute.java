package org.tigris.ape.model.cppModelElements.languageElements;

import org.tigris.ape.model.cppModelElements.CppModelElementType;
import org.tigris.ape.model.genericModelElements.FileElement;
import org.tigris.ape.model.genericModelElements.IModelElementType;

public class Attribute extends FileElement {

	public Attribute(String pathName, String fileName) {
		super(pathName, fileName);
	}

	@Override
	public IModelElementType getType() {
		return CppModelElementType.ATTRIBUTE;
	}
}
