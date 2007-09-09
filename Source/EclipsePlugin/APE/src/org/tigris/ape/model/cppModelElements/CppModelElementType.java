package org.tigris.ape.model.cppModelElements;

import org.eclipse.swt.graphics.Image;
import org.tigris.ape.model.genericModelElements.IModelElementType;
import org.tigris.ape.model.genericModelElements.ModelElementType;

public abstract class CppModelElementType extends ModelElementType {

	private CppModelElementType(String id, String printName, int ordinal) {
		super(id, printName, ordinal);
	}

	@Override
	public int compareTo(IModelElementType arg0) {
		return this.ordinal - arg0.getOrdinal();
	}

	public static final CppModelElementType UNKNOWN = new CppModelElementType(
			"Unknown", "Unknown", 0) {

		@Override
		public Image getSmallImage() {
			return null;
		}

		@Override
		public Image getImage() {
			return null;
		}
	};

	public static final CppModelElementType MODEL = new CppModelElementType(
			"Model", "Model", 1) {
	};

	public static final CppModelElementType COMPONENTS = new CppModelElementType(
			"Components", "Components", 1) {
	};

	public static final CppModelElementType COMPONENT = new CppModelElementType(
			"Component", "Component", 1) {
	};

	public static final CppModelElementType CONFIGURATION = new CppModelElementType(
			"Configuration", "Configruation", 1) {
	};

	public static final CppModelElementType PACKAGE = new CppModelElementType(
			"Package", "Package", 2) {
	};

	public static final CppModelElementType CLASSES = new CppModelElementType(
			"Classes", "Classes", 1) {
	};

	public static final CppModelElementType CLASS = new CppModelElementType(
			"Class", "Class", 1) {
	};

	public static final CppModelElementType OPERATIONS = new CppModelElementType(
			"Operations", "Operations", 2) {
	};

	public static final CppModelElementType OPERATION = new CppModelElementType(
			"Operation", "Operation", 1) {
	};

	public static final CppModelElementType ATTRIBUTES = new CppModelElementType(
			"Attributes", "Attributes", 1) {
	};

	public static final CppModelElementType PARAMETERS = new CppModelElementType(
			"Parameters", "Parameters", 1) {
	};

	public static final CppModelElementType RELATION = new CppModelElementType(
			"Relation", "Relation", 1) {
	};

	public static final CppModelElementType RELATIONS = new CppModelElementType(
			"Relations", "Relations", 3) {
	};

	public static final CppModelElementType SEQUENCES = new CppModelElementType(
			"Sequences", "Sequence  Diagrams", 4) {
	};

	public static final CppModelElementType SEQUENCE = new CppModelElementType(
			"Sequence", "Sequence Diagram", 1) {
	};

	public static final CppModelElementType STATE = new CppModelElementType(
			"State", "State", 1) {
	};

	public static final CppModelElementType TYPES = new CppModelElementType(
			"Types", "Types", 5) {
	};

	public static final CppModelElementType USECASEDIAGRAMS = new CppModelElementType(
			"UsecaseDiagrams", "Usecase Diagrams", 3) {
	};

	public static final CppModelElementType USECASEDIAGRAM = new CppModelElementType(
			"UsecaseDiagram", "Usecase Diagram", 1) {
	};

	private static final CppModelElementType[] MODELTYPES = { ATTRIBUTES,
			CLASS, CLASSES, COMPONENT, COMPONENTS, CONFIGURATION, MODEL,
			OPERATION, OPERATIONS, PACKAGE, PARAMETERS, RELATION, RELATIONS,
			SEQUENCE, SEQUENCES, STATE, TYPES, UNKNOWN, USECASEDIAGRAM,
			USECASEDIAGRAMS };

	public static CppModelElementType[] getTypes() {
		return MODELTYPES;
	}
}
