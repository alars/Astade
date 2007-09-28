#include "AdePropertyRealValue.h"

template <typename PlainT>
AdePropertyRealValue<PlainT>::AdePropertyRealValue(PlainT aValue) :
	myValue(aValue)
{

}

template <typename PlainT>
AdePropertyRealValue<PlainT>* AdePropertyRealValue<PlainT>::Clone() const
{
	return new AdePropertyRealValue<PlainT>(*this);
}

template <typename PlainT>
AdePropertyRealValue<PlainT>::operator PlainT() const
{
	return myValue;
}

template <typename PlainT>
void AdePropertyRealValue<PlainT>::SetValue(AdePropertyValue const & aValue)
{
	myValue = aValue.GetValue<PlainT>();
}

