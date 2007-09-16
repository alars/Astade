package org.tigris.ape.model.cppModelElements.fileElements;

import org.tigris.ape.model.genericModelElements.FileElement;
import org.tigris.ape.model.genericModelElements.IModelElementType;
import org.tigris.ape.model.genericModelElements.ModelElementType;

public class Textfile extends FileElement {

	public Textfile(String pathName, String fileName) {
		super(pathName, fileName);
	}

	@Override
	public IModelElementType getType() {
		return ModelElementType.TEXTFILE;
	}
}
