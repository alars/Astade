package org.tigris.ape.model.genericModelElements;

public abstract class OperationBase extends DirectoryElement {

	public OperationBase(String name, String pathName, DirectoryElement parent) {
		super(name, pathName);
		this.parent = parent;
		parent.addChild(this);
	}

}
