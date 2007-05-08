package org.tigris.ape.model.genericModelElements;

public abstract class OperationBase extends DirectoryElement {

	public OperationBase(String pathName, DirectoryElement parent) {
		super(pathName);
		this.parent = parent;
		parent.addChild(this);
	}

}
