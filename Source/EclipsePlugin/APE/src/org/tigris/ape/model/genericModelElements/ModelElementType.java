package org.tigris.ape.model.genericModelElements;

import org.eclipse.swt.graphics.Image;
import org.tigris.ape.Activator;

public abstract class ModelElementType implements IModelElementType {
	
	private final String id;
	private final String printName;
	protected final int ordinal;
	
	protected ModelElementType(String id, String printName, int ordinal){
		this.id = id;
		this.printName = printName;
		this.ordinal = ordinal;
	}
	
	@Override
	public int getOrdinal() {
		return ordinal;
	}
	
	public String getId() {
		return id;
	}

	public String getPrintName() {
		return printName;
	}

	public Image getImage() {
		return Activator.getDefault().getImageRegistry().get(getId());
	}

	public Image getSmallImage() {
		return Activator.getDefault().getImageRegistry().get(
				getId() + Activator.SMALL_PIC);
	}
	
	public static final ModelElementType ROOT = new ModelElementType("Root", "Root", 1){

		@Override
		public int compareTo(IModelElementType o) {
			return 0;
		}};
		
	public static final ModelElementType LOADING = new ModelElementType("Loading", "Loading...", Integer.MAX_VALUE){

		@Override
		public int compareTo(IModelElementType arg0) {
			return Integer.MAX_VALUE;
		}
		
	};
}
	
