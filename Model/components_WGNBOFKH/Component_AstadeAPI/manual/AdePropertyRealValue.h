#ifndef __ADEPROPERTYREALVALUE_H
#  define __ADEPROPERTYREALVALUE_H

#include "AdePropertyValue.h"
#include "AdePropertyBaseValue.h"

template <typename PlainT>
class AdePropertyRealValue : public AdePropertyBaseValue
{
	public:
		AdePropertyRealValue<PlainT>(PlainT aValue);

      	AdePropertyRealValue<PlainT> * Clone() const;

        operator PlainT() const;

		void AdePropertyRealValue<PlainT>::SetValue(AdePropertyValue const & aValue);

    private:
        PlainT myValue;

};

#endif
