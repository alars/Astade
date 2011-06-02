//~~ void OnKey(wxKeyEvent& event) [CodeEditControl] ~~

if (event.GetKeyCode() == 9 && event.GetModifiers() == 0)
{
    Tab();
}
else if (event.GetKeyCode() == 'F' && event.GetModifiers() == wxMOD_CONTROL)
{
    wxCommandEvent anEvent(wxEVT_COMMAND_BUTTON_CLICKED, GeneratedFrame::SEARCH);
    GetEventHandler()->ProcessEvent(anEvent);
}
else
    event.Skip();
