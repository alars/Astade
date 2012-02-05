//~~ void OnSliderMove(wxScrollEvent& event) [glFrame] ~~

wxString aLabel;
aLabel.Printf(wxS("%d x %d pixel"), xPixelSlider->GetValue(), yPixelSlider->GetValue());

sliderSizer_staticbox->SetLabel(aLabel);

graphicPanel->SetVirtualSize(xPixelSlider->GetValue(), yPixelSlider->GetValue());
glGravityArea::setPanelSize(xPixelSlider->GetValue(), yPixelSlider->GetValue());
