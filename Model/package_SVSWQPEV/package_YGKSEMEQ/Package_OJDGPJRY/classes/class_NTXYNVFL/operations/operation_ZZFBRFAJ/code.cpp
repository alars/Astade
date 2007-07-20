while (!myRows.empty())
{
	ACRow* aRow = myRows.front();
	myRows.pop_front();
	delete aRow;
}
myRows.push_back(ACRow::GetBaseRow());
CalculateVirtualSize();