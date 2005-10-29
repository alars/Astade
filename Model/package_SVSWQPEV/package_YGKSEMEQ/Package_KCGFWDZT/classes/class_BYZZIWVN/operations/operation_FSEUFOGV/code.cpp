int elementType;

if (wxConfigBase::Get()->Read("Astade/Type",&elementType));
{
	switch(elementType&0x7ff00000)
	{
		case ITEM_IS_CLASS:         myBitmap->SetBitmap(wxIcon(Class));break;
		case ITEM_IS_COMPONENT:     myBitmap->SetBitmap(wxIcon(component));break;
		case ITEM_IS_COMPONENTS:    myBitmap->SetBitmap(wxIcon(components_xpm));break;
		case ITEM_IS_CONFIGURATION: myBitmap->SetBitmap(wxIcon(configuration_xpm));break;
		case ITEM_IS_PACKAGE:       myBitmap->SetBitmap(wxIcon(package));break;
		case ITEM_IS_TYPE:          myBitmap->SetBitmap(wxIcon(Type_xpm));break;
	}
}
