/**
 * 
 */
package org.tigris.ape.model.cppModelElements;

import org.tigris.ape.model.genericModelElements.DirectoryElement;

public class Components extends DirectoryElement {

	public Components(String name, String pathName, Model root) {
		super(name, pathName);
		this.parent = root;
		root.addChild(this);
	}

}
