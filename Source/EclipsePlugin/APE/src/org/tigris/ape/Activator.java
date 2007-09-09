 package org.tigris.ape;

import org.apache.log4j.PropertyConfigurator;
import org.eclipse.jface.resource.ImageRegistry;
import org.eclipse.swt.SWT;
import org.eclipse.swt.SWTError;
import org.eclipse.swt.graphics.GC;
import org.eclipse.swt.graphics.Image;
import org.eclipse.swt.graphics.Rectangle;
import org.eclipse.swt.widgets.Display;
import org.eclipse.ui.PlatformUI;
import org.eclipse.ui.plugin.AbstractUIPlugin;
import org.osgi.framework.BundleContext;
import org.tigris.ape.model.cppModelElements.CppModelElementType;
import org.tigris.ape.model.genericModelElements.ModelElementType;

/**
 * The activator class controls the plug-in life cycle
 */
public class Activator extends AbstractUIPlugin {

	// The plug-in ID
	public static final String PLUGIN_ID = "APE";

	// Constant values for icons
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
    		registerImage(myImageRegistry, CppModelElementType.COMPONENTS.getId(), "icons/folder.png", "icons/component.png");
    		registerImage(myImageRegistry, CppModelElementType.COMPONENT.getId(), "icons/component.png");
    		registerImage(myImageRegistry, CppModelElementType.CONFIGURATION.getId(), "icons/configuration.png");
    		registerImage(myImageRegistry, CppModelElementType.PACKAGE.getId(), "icons/package.png");
    		registerImage(myImageRegistry, CppModelElementType.CLASSES.getId(), "icons/folder.png", "icons/class.png");
    		registerImage(myImageRegistry, CppModelElementType.CLASS.getId(), "icons/class.png");
    		registerImage(myImageRegistry, CppModelElementType.OPERATIONS.getId(), "icons/folder.png", "icons/operation.png");
    		registerImage(myImageRegistry, CppModelElementType.OPERATION.getId(), "icons/operation.png");
    		registerImage(myImageRegistry, CppModelElementType.ATTRIBUTES.getId(), "icons/folder.png", "icons/attribute.png");
    		registerImage(myImageRegistry, CppModelElementType.PARAMETERS.getId(), "icons/folder.png", "icons/parameter.png");
    		registerImage(myImageRegistry, CppModelElementType.RELATION.getId(), "icons/relation.png");
    		registerImage(myImageRegistry, CppModelElementType.RELATIONS.getId(), "icons/folder.png", "icons/relation.png");
    		registerImage(myImageRegistry, CppModelElementType.SEQUENCES.getId(), "icons/folder.png", "icons/sequence.png");
    		registerImage(myImageRegistry, CppModelElementType.STATE.getId(), "icons/state.png");
    		registerImage(myImageRegistry, CppModelElementType.TYPES.getId(), "icons/folder.png", "icons/type.png");
    		registerImage(myImageRegistry, CppModelElementType.USECASEDIAGRAMS.getId(), "icons/folder.png", "icons/usecasediagram.png");
    		
    		registerImage(myImageRegistry, ModelElementType.LOADING.getId(), "icons/loading.png");
    		
    		return myImageRegistry;
    	}
    	
       	//Invalid thread access if it is not the UI Thread 
    	//and the workbench is not created.
    	throw new SWTError(SWT.ERROR_THREAD_INVALID_ACCESS);
	}
	
	private void registerImage(ImageRegistry myImageRegistry, String key, String path){
		Image originalImage = imageDescriptorFromPlugin(PLUGIN_ID, path).createImage();
		Image largeImage = new Image(getWorkbench().getDisplay(), originalImage.getImageData());
		Image smallImage = new Image(getWorkbench().getDisplay(), originalImage.getImageData().scaledTo((originalImage.getBounds().width*2)/3,(originalImage.getBounds().height*2)/3));
	
		myImageRegistry.put(key, largeImage);
		myImageRegistry.put(key + SMALL_PIC, smallImage);
		originalImage.dispose();
	}
	
	private void registerImage(ImageRegistry myImageRegistry, String key, String pathToBackground, String pathToForeground){
		
		// load the background image
		Image backgroundImage = imageDescriptorFromPlugin(PLUGIN_ID, pathToBackground).createImage();
		
		// load the foreground image
		Image foregroundImage = imageDescriptorFromPlugin(PLUGIN_ID, pathToForeground).createImage();
		
		Image tmp = new Image(getWorkbench().getDisplay(), new Rectangle(0,0, backgroundImage.getBounds().width,backgroundImage.getBounds().height));
		GC drawer = new GC(tmp);
		drawer.drawImage(backgroundImage, 0, 0);
		drawer.drawImage(foregroundImage, 
				0, 0, foregroundImage.getBounds().width, foregroundImage.getBounds().height, 
				java.lang.Math.abs(tmp.getBounds().width-foregroundImage.getBounds().width)/2, 
				java.lang.Math.abs(tmp.getBounds().height-foregroundImage.getBounds().height)/2, 
				foregroundImage.getBounds().width,foregroundImage.getBounds().height
		);
		myImageRegistry.put(key, tmp);
		myImageRegistry.put(key + SMALL_PIC, new Image(getWorkbench().getDisplay(), tmp.getImageData().scaledTo((tmp.getBounds().width*2)/3,(tmp.getBounds().height*2)/3)));

		drawer.dispose();
		backgroundImage.dispose();
		foregroundImage.dispose();
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
