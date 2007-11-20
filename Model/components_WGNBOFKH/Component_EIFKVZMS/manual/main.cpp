#include "StateChartDrawer.h"
#include "AdeDefines.h"
#include "AdeState.h"
#include "AdeTransition.h"
#include <wx/app.h>
#include <wx/cmdline.h>

int main(int argc, char* const* argv)
{
	if (wxInitialize())
	{
		int rc = StateChartDrawer::doit(argc, argv);
		wxUninitialize();
		return rc;
	}
	return EXIT_FAILURE;
}
