//~~ void CodeHandlePointer() [StateChartCoderC] ~~

spec << "\t//! @brief The pointer to the handler class." << std::endl;
spec << "\t"
	<< myAdeStatechart->GetName().utf8_str()
	<< "_impl* myHandler;\n"
	<< std::endl;
