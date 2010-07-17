//~~ wxString GetSortName() [AdeRelation] ~~
/* vi: set tabstop=4: */

switch (GetType() & ITEM_RELATION_MASK)
{
	case ITEM_IS_ASSOCIATION:
	case ITEM_IS_AGGREGATION:
	case ITEM_IS_COMPOSITION:
		return GetName();

	default:
		return GetPartnerName();
}
