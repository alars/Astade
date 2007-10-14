if ((event.GetKeyCode()==9) && (event.GetModifiers() == 0))
    Tab();
else if ((event.GetKeyCode()=='F') && (event.GetModifiers() == wxMOD_CONTROL))
{
    wxCommandEvent aEvent(wxEVT_COMMAND_BUTTON_CLICKED, GeneratedFrame::SEARCH);
    GetParent()->AddPendingEvent(aEvent);
}
else
    event.Skip();