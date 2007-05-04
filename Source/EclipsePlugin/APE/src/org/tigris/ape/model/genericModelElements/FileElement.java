package org.tigris.ape.model.genericModelElements;

public abstract class FileElement extends ModelElement {

	public FileElement(String name, String pathName, DirectoryElement parent) {
		super(name, pathName);
		this.parent = parent;
		parent.addChild(this);
	}
}
