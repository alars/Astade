#include "AdePropertyValue.h"
#include "AdePropertyBaseValue.h"
#include "AdePropertyRealValue.h"

AdePropertyValue::AdePropertyValue(AdePropertyBaseValue const & aBaseValue) :
	myValue(aBaseValue.Clone())
{

}

AdePropertyValue::AdePropertyValue(AdePropertyValue const & original) :
	myValue(original.myValue ? original.myValue->Clone() : 0)
{

}

AdePropertyValue::AdePropertyValue(AdePropertyBaseValue* aBaseValue) :
	myValue(aBaseValue)
{

}

AdePropertyValue::~AdePropertyValue()
{
	delete myValue;
}

AdePropertyValue& AdePropertyValue::operator=(const AdePropertyValue& original)
{
	if (myValue)
	{
		if (original.myValue)
		{
			myValue->SetValue(original);
		}
		else
		{
			AdePropertyBaseValue * old = myValue;
			myValue = 0;
		delete old;
		}
	}
	else
	{
		myValue = (original.myValue ? original.myValue->Clone() : 0);
	}
	return *this;
}

template <typename PlainT>
PlainT AdePropertyValue::GetValue() const
{
	if (myValue)
	{
		AdePropertyRealValue<PlainT> const & aValue = dynamic_cast<AdePropertyRealValue<PlainT> const &>(*myValue);
		return aValue;
	}
	else
	{
		return PlainT();
	}
}
