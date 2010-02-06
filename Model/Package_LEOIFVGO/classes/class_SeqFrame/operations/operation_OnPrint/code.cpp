wxPrintDialogData printDialogData(*printData);
wxPrinter printer(&printDialogData);
if (printer.Print(this, mySeqPrintout, true))
	*printData = printer.GetPrintDialogData().GetPrintData();
