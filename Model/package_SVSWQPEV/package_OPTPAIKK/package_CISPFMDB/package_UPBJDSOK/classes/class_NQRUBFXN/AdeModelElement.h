//******************************************************
//** Coding is done with Astade Quick and Dirty Coder **
//** Filename: AdeModelElement.h                      **
//******************************************************

#ifndef ADEMODELELEMENT_H
#define ADEMODELELEMENT_H


class AdeModelElement
{
	public:
	int GetType();
	void Delete();

	protected:
	AdeModelElement(const wxString& theFileName);
	void SetType(int newType);
	wxString GetFeature(const wxString& theFeatureName);

	private:
	wxFileName	myFileName;
};

#endif
