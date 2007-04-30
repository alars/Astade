/**
 * 
 */
package org.tigris.ape.model.treeElements;

import org.eclipse.core.runtime.IAdaptable;


/**
 * @author Tobias Zipfel
 *
 */
public interface TreeParent extends IAdaptable, TreeObject {

	/**
	 * @param child
	 */
	public void addChild(TreeObject child);
	
	/**
	 * @param child
	 */
	public void removeChild(TreeObject child);
	
	/**
	 * @return
	 */
	public TreeObject [] getChildren();
	
	/**
	 * @return 
	 */
	public boolean hasChildren();	
	
}
