package org.tigris.ape.model.cppModelElements.fileElements;

import org.tigris.ape.model.cppModelElements.CppModelElementType;
import org.tigris.ape.model.genericModelElements.FileElement;
import org.tigris.ape.model.genericModelElements.IModelElementType;

public class Makefile extends FileElement {

	public Makefile(String pathName, String fileName) {
		super(pathName, fileName);
	}

	@Override
	public IModelElementType getType() {
		return CppModelElementType.MAKEFILE;
	}
}
