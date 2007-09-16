package org.tigris.ape.model.cppModelElements.astadeElements;

import org.tigris.ape.model.cppModelElements.CppModelElementType;
import org.tigris.ape.model.genericModelElements.DirectoryElement;
import org.tigris.ape.model.genericModelElements.IModelElementType;

public class Autofolder extends DirectoryElement {

	public Autofolder(String pathName) {
		super(pathName);
	}

	@Override
	public IModelElementType getType() {
		return CppModelElementType.AUTOFOLDER;
	}
}
