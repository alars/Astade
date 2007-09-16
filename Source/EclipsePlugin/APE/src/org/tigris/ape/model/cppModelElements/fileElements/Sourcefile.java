package org.tigris.ape.model.cppModelElements.fileElements;

import org.tigris.ape.model.cppModelElements.CppModelElementType;
import org.tigris.ape.model.genericModelElements.FileElement;
import org.tigris.ape.model.genericModelElements.IModelElementType;

public class Sourcefile extends FileElement {

	public Sourcefile(String pathName, String fileName) {
		super(pathName, fileName);
	}
	
	@Override
	public IModelElementType getType() {
		return CppModelElementType.SOURCEFILE_CPP;
	}

}
