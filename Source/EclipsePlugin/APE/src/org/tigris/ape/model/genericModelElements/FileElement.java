package org.tigris.ape.model.genericModelElements;

public abstract class FileElement extends ModelElement {

	public FileElement(String pathName, DirectoryElement parent) {
		super(pathName);
		this.parent = parent;
		parent.addChild(this);
	}
}
