#ifndef __ADEPROPERTYVALUE_H
#  define __ADEPROPERTYVALUE_H

class AdePropertyBaseValue;

class AdePropertyValue
{
    public:
        AdePropertyValue(AdePropertyBaseValue const & aBaseValue);

        AdePropertyValue(AdePropertyValue const & original);

        explicit AdePropertyValue(AdePropertyBaseValue * aBaseValue = 0);

        ~AdePropertyValue();

        AdePropertyValue& operator=(const AdePropertyValue& original);

		template <typename PlainT>
		PlainT GetValue() const;

    private:
        AdePropertyBaseValue * myValue;

};

#endif
