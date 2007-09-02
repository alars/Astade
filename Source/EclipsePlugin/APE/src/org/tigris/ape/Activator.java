 package org.tigris.ape;

import org.apache.log4j.PropertyConfigurator;
import org.eclipse.jface.resource.ImageRegistry;
import org.eclipse.swt.SWT;
import org.eclipse.swt.SWTError;
import org.eclipse.swt.graphics.Image;
import org.eclipse.swt.widgets.Display;
import org.eclipse.ui.PlatformUI;
import org.eclipse.ui.plugin.AbstractUIPlugin;
import org.osgi.framework.BundleContext;
import org.tigris.ape.model.cppModelElements.Attributes;
import org.tigris.ape.model.cppModelElements.Class;
import org.tigris.ape.model.cppModelElements.Classes;
import org.tigris.ape.model.cppModelElements.Component;
import org.tigris.ape.model.cppModelElements.Components;
import org.tigris.ape.model.cppModelElements.Configuration;
import org.tigris.ape.model.cppModelElements.Model;
import org.tigris.ape.model.cppModelElements.CppModelElementType;
import org.tigris.ape.model.cppModelElements.Operation;
import org.tigris.ape.model.cppModelElements.Operations;
import org.tigris.ape.model.cppModelElements.Package;
import org.tigris.ape.model.cppModelElements.Parameters;
import org.tigris.ape.model.cppModelElements.Relation;
import org.tigris.ape.model.cppModelElements.Relations;
import org.tigris.ape.model.cppModelElements.Sequences;
import org.tigris.ape.model.cppModelElements.State;
import org.tigris.ape.model.cppModelElements.Types;
import org.tigris.ape.views.ModelTree.ModelTreeView;

/**
 * The activator class controls the plug-in life cycle
 */
public class Activator extends AbstractUIPlugin {

	// The plug-in ID
	public static final String PLUGIN_ID = "APE";

	public static final String SMALL_PIC = "SMALL_PIC"; 
	
	// The shared instance
	private static Activator plugin;
	
	/**
	 * The constructor
	 */
	public Activator() {
		plugin = this;
		
	}

	/*
	 * (non-Javadoc)
	 * @see org.eclipse.ui.plugin.AbstractUIPlugin#start(org.osgi.framework.BundleContext)
	 */
	public void start(BundleContext context) throws Exception {
		super.start(context);
		PropertyConfigurator.configure(getBundle().getEntry("log4j.properties"));
	}

	/*
	 * (non-Javadoc)
	 * @see org.eclipse.ui.plugin.AbstractUIPlugin#stop(org.osgi.framework.BundleContext)
	 */
	public void stop(BundleContext context) throws Exception {
		plugin = null;
		super.stop(context);
	}

	@Override
	protected ImageRegistry createImageRegistry() {

		ImageRegistry myImageRegistry = null;
		
		//If we are in the UI Thread use that
    	if(Display.getCurrent() != null) {
			myImageRegistry = new ImageRegistry(Display.getCurrent());
		}
    	
    	if(PlatformUI.isWorkbenchRunning()) {
    		myImageRegistry =  new ImageRegistry(PlatformUI.getWorkbench().getDisplay());
		}
    	
    	if(myImageRegistry != null){
    		registerImage(myImageRegistry, CppModelElementType.MODEL.getId(), "icons/model.png");
    		registerImage(myImageRegistry, CppModelElementType.COMPONENTS.getId(), "icons/components.png");
    		registerImage(myImageRegistry, CppModelElementType.COMPONENT.getId(), "icons/component.png");
    		registerImage(myImageRegistry, CppModelElementType.CONFIGURATION.getId(), "icons/configuration.png");
    		registerImage(myImageRegistry, CppModelElementType.PACKAGE.getId(), "icons/package.png");
    		registerImage(myImageRegistry, CppModelElementType.CLASSES.getId(), "icons/classes.png");
    		registerImage(myImageRegistry, CppModelElementType.CLASS.getId(), "icons/class.png");
    		registerImage(myImageRegistry, CppModelElementType.OPERATIONS.getId(), "icons/operations.png");
    		registerImage(myImageRegistry, CppModelElementType.OPERATION.getId(), "icons/operation.png");
    		registerImage(myImageRegistry, CppModelElementType.ATTRIBUTES.getId(), "icons/attributes.png");
    		registerImage(myImageRegistry, CppModelElementType.PARAMETERS.getId(), "icons/parameters.png");
    		registerImage(myImageRegistry, CppModelElementType.RELATION.getId(), "icons/relation.png");
    		registerImage(myImageRegistry, CppModelElementType.RELATIONS.getId(), "icons/relations.png");
    		registerImage(myImageRegistry, CppModelElementType.SEQUENCES.getId(), "icons/sequences.png");
    		registerImage(myImageRegistry, CppModelElementType.STATE.getId(), "icons/state.png");
    		registerImage(myImageRegistry, CppModelElementType.TYPES.getId(), "icons/types.png");
    		
    		return myImageRegistry;
    	}
    	
       	//Invalid thread access if it is not the UI Thread 
    	//and the workbench is not created.
    	throw new SWTError(SWT.ERROR_THREAD_INVALID_ACCESS);
	}
	
	private void registerImage(ImageRegistry myImageRegistry, String key, String path){
		Image originalImage = imageDescriptorFromPlugin(PLUGIN_ID, path).createImage();
		Image largeImage = new Image(getWorkbench().getDisplay(), originalImage.getImageData().scaledTo(20, 20));
		Image smallImage = new Image(getWorkbench().getDisplay(), originalImage.getImageData().scaledTo(16, 16));
		myImageRegistry.put(key, largeImage);
		myImageRegistry.put(key + ModelTreeView.SMALLPIC, smallImage);
		originalImage.dispose();
	}
	
	/**
	 * Returns the shared instance
	 *
	 * @return the shared instance
	 */
	public static Activator getDefault() {
		return plugin;
	}

}
