*pageSetupData = *printData;
wxPageSetupDialog pageSetupDialog(this, pageSetupData);
pageSetupDialog.ShowModal();
*printData = pageSetupDialog.GetPageSetupData().GetPrintData();
*pageSetupData = pageSetupDialog.GetPageSetupData();
